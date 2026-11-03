
#include "glad/glad.h"
#include "vao.h"

VAO vao_create() {
    VAO vao;
    glGenVertexArrays(1, &vao.handle);
    return vao;
}

void vao_destroy(VAO vao) {
    glDeleteVertexArrays(1, &vao.handle);
}

void vao_bind(VAO vao) {
    glBindVertexArray(vao.handle);
}

