

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


void game_run(void) {
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: failed to initialize glfw window %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "sample window", NULL, NULL);

    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}


