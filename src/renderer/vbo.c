
#include "vbo.h"

VBO vbo_create(GLuint type, bool dynamic) {
    VBO self = {
        .type = type,
        .dynamic = dynamic
    };
    glGenBuffers(1, &self.handle);
    return self;
}

void vbo_destroy(VBO self) {
    glDeleteBuffers(1, &self.handle);
}

void vbo_bind(VBO self) {
    glBindBuffer(self.type, self.handle);
}


