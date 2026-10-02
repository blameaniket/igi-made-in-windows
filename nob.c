
#define NOB_IMPLEMENTATION
#include "nob.h"

int main(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);
    Nob_Cmd cmd = {0};
    nob_cmd_append(&cmd, 
            "tcc", 
            "-Wall", "-Wextra", 
            "-I", "external/glfw-3.5.1.bin.WIN64/include",
            "-o", "build/app.exe", 

            "src/main.c",
            "src/game.c",

            "-L", "external/glfw-3.5.1.bin.WIN64/lib-mingw-w64",
            "-lglfw3",
            "-lopengl32",
        );

    if (!nob_cmd_run(&cmd)) {
        return 1;
    }

    return 0;
}


