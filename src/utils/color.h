#ifndef COLOR_H
#define COLOR_H

typedef struct {
    float r, g, b, a;
} Color;

Color hex_to_rgb(const char *hex);

#define COLOR_RED (Color){255,0,0,255}
#define COLOR_GREEN (Color){0,255,0,255};
#define COLOR_BLUE (Color){0,0,255,255};
#define COLOR_WHITE (Color){255,255,255,255};
#define COLOR_BLACK (Color){0,0,0,0};

#endif // COLOR_H
