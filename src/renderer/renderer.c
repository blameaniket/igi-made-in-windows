
#include "glad/glad.h"
#include "renderer.h"
#include "shader.h"
#include "vao.h"
#include "vbo.h"

#include <stdbool.h>

void renderer_init(Renderer *r) {
    *r = (Renderer){0};
    r->vao = vao_create();
    r->vbo = vbo_create(GL_ARRAY_BUFFER, true);
    r->ibo = vbo_create(GL_ELEMENT_ARRAY_BUFFER, true);
}

void renderer_shutdown(Renderer *r) {
    vao_destroy(r->vao);
    vbo_destroy(r->vbo);
    vbo_destroy(r->ibo);
}

void renderer_update(Renderer *r) {
}

