#include "MenuManager.h"

void handleNormalButton (SDL_Event* event, Button& normalButton, bool& openMenu, bool& normalPlay, bool& lavaPlay, bool& quit, Audios& audio) {
    if (event->type == SDL_QUIT) {
        quit = true;
    }
    else if (normalButton.mouseInside(event)) {
        if (event->type == SDL_MOUSEBUTTONDOWN) {
            openMenu = false;
            normalPlay = true;
            lavaPlay = false;
            quit = false;
            audio.play(audio.clickSound);
        }
    }
}

void handleLavaButton (SDL_Event* event, Button& lavaButton, bool& openMenu, bool& normalPlay, bool& lavaPlay, bool& quit, Audios& audio) {
    if (event->type == SDL_QUIT) {
        quit = true;
    }
    else if (lavaButton.mouseInside(event)) {
        if (event->type == SDL_MOUSEBUTTONDOWN) {
            openMenu = false;
            normalPlay = false;
            lavaPlay = true;
            quit = false;
            audio.play(audio.clickSound);
        }
    }
}

void handleExitButton (SDL_Event* event, Button& exitButton, bool& openMenu, bool& normalPlay, bool& lavaPlay, bool& quit, Audios& audio) {
    if (event->type == SDL_QUIT) {
        quit = true;
    }
    else if (exitButton.mouseInside(event)) {
        if (event->type == SDL_MOUSEBUTTONDOWN) {
            openMenu = false;
            normalPlay = false;
            lavaPlay = false;
            quit = true;
            audio.play(audio.clickSound);
        }
    }
}

void handleQuitButton(SDL_Event* event, Button& quitButton, Button& yesButton, Button& noButton, bool& playingState, bool& normalPlay, bool& lavaPlay, Graphics& graphic, Audios& audio) {
    if (quitButton.mouseInside(event)) {
        if (event->type == SDL_MOUSEBUTTONDOWN) {
            graphic.renderTexture (graphic.quitScreen, 0, 0);
            yesButton.renderButton(graphic.yesButtonTexture, graphic);
            noButton.renderButton(graphic.noButtonTexture, graphic);
            graphic.presentScene();
            audio.play(audio.clickSound);

            while (true) {
                if (SDL_WaitEvent(event) != 0) {
                    if (event->type == SDL_MOUSEBUTTONDOWN) {
                        if (yesButton.mouseInside(event)) {
                            playingState = false;
                            normalPlay = false;
                            lavaPlay = false;
                            audio.play(audio.clickSound);
                            break;
                        } else if (noButton.mouseInside(event)) {
                            playingState = true;
                            normalPlay = true;
                            lavaPlay = true;
                            audio.play(audio.clickSound);
                            break;
                        }
                    }
                }
            }
        }
    }
}
