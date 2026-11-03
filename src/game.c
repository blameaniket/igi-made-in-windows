
#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#if defined(_WIN32)
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#ifndef DWMWA_USE_IMMERSIVE_DARK_MODE
#define DWMWA_USE_IMMERSIVE_DARK_MODE 20
#endif
#endif

#include "game.h"
#include "state.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define SCALE 60
#define WINDOW_WIDTH (SCALE * 16)
#define WINDOW_HEIGHT (SCALE * 10)

static State state = {0};

void _game_init() {
    renderer_init(&state.renderer);
}

void _game_shutdown() {
    renderer_shutdown(&state.renderer);
}

void _game_on_update() {
    renderer_update(&state.renderer);
}

void _game_on_render() {
}

static void _glfw_error_callback(int code, const char *description) {
    fprintf(stderr, "GLFW error %d: %s\n", code, description);
}

void game_run(int argc, char *argv[]) {
    glfwSetErrorCallback(_glfw_error_callback);

    if (!glfwInit()) {
        fprintf(stderr, "ERROR: failed to initialize glfw window %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "sample window", NULL, NULL);
    if (!window) {
        fprintf(stderr, "ERROR: failed to create GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

#if defined(_WIN32)
    HWND hwnd = glfwGetWin32Window(window);

    HMODULE hUser32 = LoadLibraryA("user32.dll");
    if (hUser32) {
        typedef BOOL (WINAPI *PFNSYSTEMPARAMETERSINFOA)(UINT, UINT, PVOID, UINT);
        typedef BOOL (WINAPI *PFNSETWINDOWPOS)(HWND, HWND, int, int, int, int, UINT);

        PFNSYSTEMPARAMETERSINFOA pSystemParametersInfoA = (PFNSYSTEMPARAMETERSINFOA)GetProcAddress(hUser32, "SystemParametersInfoA");
        PFNSETWINDOWPOS pSetWindowPos = (PFNSETWINDOWPOS)GetProcAddress(hUser32, "SetWindowPos");

        if (pSystemParametersInfoA && pSetWindowPos) {
            RECT rcArea;
            pSystemParametersInfoA(SPI_GETWORKAREA, 0, &rcArea, 0);
            
            int screenWidth = rcArea.right - rcArea.left;
            int screenHeight = rcArea.bottom - rcArea.top;
            int winX = rcArea.left + (screenWidth - WINDOW_WIDTH) / 2;
            int winY = rcArea.top + (screenHeight - WINDOW_HEIGHT) / 2;
            pSetWindowPos(hwnd, NULL, winX, winY, WINDOW_WIDTH, WINDOW_HEIGHT, SWP_NOZORDER | SWP_NOACTIVATE);
        }

        FreeLibrary(hUser32);
    }
    
    HMODULE hDwmapi = LoadLibraryA("dwmapi.dll");
    if (hDwmapi) {
        typedef HRESULT (WINAPI *PFNDWMSETWINDOWATTRIBUTE)(HWND, DWORD, LPCVOID, DWORD);
        PFNDWMSETWINDOWATTRIBUTE pDwmSetWindowAttribute = (PFNDWMSETWINDOWATTRIBUTE)GetProcAddress(hDwmapi, "DwmSetWindowAttribute");
        
        if (pDwmSetWindowAttribute) {
            BOOL useDark = TRUE;
            pDwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, &useDark, sizeof(useDark));
        }

        FreeLibrary(hDwmapi);
    }
#endif

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        fprintf(stderr, "%s", "error initializing GLAD\n");
        glfwTerminate();
        exit(1);
    }
    // both and glfw opengl is initialized

    _game_init();

    while (!glfwWindowShouldClose(window)) {
        _game_on_update();
        _game_on_render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    _game_shutdown();
    glfwDestroyWindow(window);
    glfwTerminate();
}

