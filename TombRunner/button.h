#ifndef BUTTON_H_
#define BUTTON_H_

#include "graphics.h"

class Button {
    SDL_Rect rect;

public:
    Button();

    Button (int x, int y, int width, int height);

    bool mouseInside(SDL_Event* event);

    void renderButton (SDL_Texture* texture, Graphics& graphic);
};

#endif
