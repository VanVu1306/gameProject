#include "button.h"

Button::Button() {
    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;
}

Button::Button (int x, int y, int width, int height) {
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
}

bool Button::mouseInside (SDL_Event* event) {
    if (event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (x < rect.x || x > rect.x + rect.w || y < rect.y || y > rect.y + rect.h) {
            return false;
        }
    }
    return true;
}

void Button::renderButton(SDL_Texture* texture, Graphics& graphic) {
    graphic.renderTexture(texture, rect.x, rect.y);
}
