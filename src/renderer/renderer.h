#ifndef RENDERER_H
#define RENDERER_H

#include "glad/glad.h"
#include "shader.h"
#include "vao.h"
#include "vbo.h"
#include "color.h"

#define VERTEX_BUF_CAP (8 * 1024)

typedef struct {
    Shader shaders[SHADER_COUNT];
    Shader shader;
    VAO vao;
    VBO vbo, ibo;

    Color clear_color;
} Renderer;

void renderer_init(Renderer *r);
void renderer_shutdown(Renderer *r);
void renderer_update(Renderer *r);

#endif // RENDERER_H
