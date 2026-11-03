
#include "color.h"
#include <stdio.h>

Color hex_to_rgb(const char *hex) {
    unsigned int value = 0;
    if (hex[0] == '#') {
        hex++;
    }

#ifdef _WIN32
    sscanf_s(hex, "%x", &value);
#else
    sscanf(hex, "%x", &value);
#endif

    Color col;
    col.r = ((value >> 16) & 0xFF) / 255.0f;
    col.g = ((value >> 8) & 0xFF) / 255.0f;
    col.b = (value & 0xFF) / 255.0f;
    col.a = 1.0;
    return col;
}

