#ifndef VAO_H
#define VAO_H

#include "glad/glad.h"

typedef struct {
    GLuint handle;
} VAO;

VAO vao_create();
void vao_destroy(VAO vao);
void vao_bind(VAO vao);

#endif // VAO_H
