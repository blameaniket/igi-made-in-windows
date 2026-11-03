#ifndef VBO_H
#define VBO_H

#include "glad/glad.h"
#include <stdbool.h>

typedef struct {
    GLuint handle;
    GLuint type;
    bool dynamic;
} VBO;

VBO vbo_create(GLuint type, bool dynamic);
void vbo_destroy(VBO self);
void vbo_bind(VBO self);

#endif // VBO_H
