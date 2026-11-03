#ifndef SHADER_H
#define SHADER_H

#include "glad/glad.h"
#include <stdbool.h>

struct VertexAttr {
    GLuint index;
    const GLchar *name;
};

typedef struct {
    GLuint handle, vs_handle, fs_handle;
} Shader;

enum ShaderProgram {
    SHADER_BASIC,
    SHADER_TEXT,
    SHADER_LIGHTING,
    SHADER_COUNT
};

Shader shader_create(const char *vertex_shader_path, const char *fragment_shader_path, size_t n, struct VertexAttr attributes[]);

#endif // SHADER_H
