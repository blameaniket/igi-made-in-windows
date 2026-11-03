#ifndef STATE_H
#define STATE_H

#include "renderer.h"
#include "ui/ui.h"

typedef struct {
    Renderer renderer;
    UI ui;
} State;

#endif // STATE_H
