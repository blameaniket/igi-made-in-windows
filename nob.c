#define NOB_IMPLEMENTATION
#include "nob.h"

int main(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);
    Nob_Cmd cmd = {0};
    nob_cmd_append(&cmd, 
            "tcc", 
            "-Wall", "-Wextra", 
            "-Iexternal/glfw-3.5.1.bin.WIN64/include",
            "-Iexternal/glad/include",
            "-Iexternal/cglm/include",
            "-Isrc",
            "-Isrc/renderer",
            "-Isrc/utils",
            "-Isrc/game_objects",
            "-o", "build/app.exe", 
            "src/main.c",
            "src/game.c",
            "src/renderer/renderer.c",
            "src/renderer/shader.c",
            "src/renderer/vao.c",
            "src/renderer/vbo.c",
            "src/game_objects/block/block.c",
            "src/utils/color.c",
            "external/glad/src/glad.c",
            "-Lexternal/glfw-3.5.1.bin.WIN64/lib-mingw-w64",
            "-lglfw3",
            "-lopengl32",
        );

    if (!nob_cmd_run(&cmd)) {
        return 1;
    }

    return 0;
}

