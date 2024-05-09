#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "button.h"

void handleNormalButton (SDL_Event* event, Button& normalButton, bool& openMenu, bool& normalPlay, bool& lavaPlay, bool& quit, Audios& audio);
void handleLavaButton (SDL_Event* event, Button& hardButton, bool& openMenu, bool& normalPlay, bool& lavaPlay, bool& quit, Audios& audio);
void handleExitButton (SDL_Event* event, Button& exitButton, bool& openMenu, bool& normalPlay, bool& lavaPlay, bool& quit, Audios& audio);
void handleQuitButton (SDL_Event* event, Button& quitButton, Button& yesButton, Button& noButton, bool& playingState, bool& normalPlay, bool& lavaPlay, Graphics& graphic, Audios& audio);

#endif
