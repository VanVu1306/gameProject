#include <SDL_image.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <bits/stdc++.h>
#include "graphics.h"
#include "audios.h"
#include "defs.h"
#include "maps.h"
#include "logics.h"
#include "levels.h"
#include "button.h"
#include "menuManager.h"

using namespace std;

Button normalButton (275, 330, MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
Button lavaButton (275, 410, MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
Button exitButton (275, 490, MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
Button quitButton (672, 5, OPT_BUTTON_WIDTH, OPT_BUTTON_HEIGHT);
Button yesButton (235, 325, OPT_BUTTON_WIDTH, OPT_BUTTON_HEIGHT);
Button noButton (385, 325, OPT_BUTTON_WIDTH, OPT_BUTTON_HEIGHT);

int main(int argc, char* argv[]) {
    Graphics graphic;
    Audios audio;
    graphic.init();
    audio.init();

    bool quit = false;
    SDL_Event event;
    bool openMenu = true;
    bool normalPlay = false;
    bool lavaPlay = false;

    audio.play(audio.music);

    while (openMenu) {
        while (SDL_PollEvent(&event)!=0) {
            if (event.type == SDL_QUIT) quit = true;
            handleNormalButton(&event, normalButton, openMenu, normalPlay, lavaPlay, quit, audio);
            handleLavaButton (&event, lavaButton, openMenu, normalPlay, lavaPlay, quit, audio);
            handleExitButton (&event, exitButton, openMenu, normalPlay, lavaPlay, quit, audio);
        }

        graphic.renderTexture(graphic.menuTexture, 0, 0);
        normalButton.renderButton(graphic.normalButtonTexture, graphic);
        lavaButton.renderButton(graphic.lavaButtonTexture, graphic);
        exitButton.renderButton(graphic.exitButtonTexture, graphic);
        graphic.presentScene();
    }

    while (normalPlay && !quit) {
        int currentLevelIndex=1;
        vector<GameMode1Level> levels;
        GameMode1Level::createLevels(levels);
        bool playingState = true;
        bool displayIntroScreen = false;
        int coinsEarned = 0;

        while (!quit && currentLevelIndex <= static_cast<int>(levels.size())) {
            if (currentLevelIndex == 3) {
                graphic.renderTexture (graphic.spikeIntroScreen, 0, 0);
                displayIntroScreen = true;
            }
            else if (currentLevelIndex == 4) {
                graphic.renderTexture (graphic.batIntroScreen, 0, 0);
                displayIntroScreen = true;
            }
            else if (currentLevelIndex == 6) {
                graphic.renderTexture (graphic.pufferIntroScreen, 0, 0);
                displayIntroScreen = true;
            }
            else if (currentLevelIndex == 8) {
                graphic.renderTexture (graphic.teleporterIntroScreen, 0, 0);
                displayIntroScreen = true;
            }
            else if (currentLevelIndex == 9) {
                graphic.renderTexture (graphic.dartIntroScreen, 0, 0);
                displayIntroScreen = true;
            }
            else {displayIntroScreen = false;}
            graphic.presentScene();

            if (displayIntroScreen) {
                bool clicked=false;
                while (!clicked && SDL_WaitEvent(&event)) {
                    if (event.type == SDL_MOUSEBUTTONDOWN) {
                        clicked = true;
                        audio.play (audio.clickSound);
                    }
                }
            }

            GameMode1Level currentLevel = levels[currentLevelIndex-1];
            Player player = currentLevel.getPlayer();
            vector<Bats> bats = currentLevel.getBats();
            vector<Darts> darts = currentLevel.getDarts();
            vector<Puffer> puffers = currentLevel.getPuffer();
            vector <Teleporters> teleporters = currentLevel.getTeleporters();
            vector<vector<char>> map = currentLevel.getMap();

            while (!gameOverMode1(player, bats, darts, puffers, map)) {
                graphic.prepareScene();

                SDL_Color color = {255,255,0,255};
                graphic.coinText = graphic.renderText (to_string(coinsEarned).c_str(), graphic.font, color);
                graphic.renderTexture (graphic.coinText, 40, 615);
                graphic.renderTexture (graphic.coinLogoTexture, 10, 610);

                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    handleQuitButton (&event, quitButton, yesButton, noButton, playingState, normalPlay, lavaPlay, graphic, audio);
                }
                quitButton.renderButton(graphic.quitButtonTexture, graphic);
                if (!normalPlay && !playingState) {
                    quit = true;
                    break;
                }

                for (Bats& bat : bats) {
                    bat.move(map, audio);
                    bat.tick();
                    graphic.renderBat(bat);
                }
                for (Darts& dart : darts) {
                    dart.shoot(map, audio);
                    dart.tick();
                    graphic.renderDart(dart);
                }
                for (Puffer& puffer : puffers) {
                    puffer.tick(audio);
                    graphic.renderPuffer(puffer);
                }
                for (Teleporters& teleporter : teleporters) {
                    teleporter.teleport(player, audio);
                    teleporter.tick();
                    graphic.renderTeleporter(teleporter);
                }

                if (player.win) {
                    graphic.renderTexture (graphic.winScreen, 0, 0);
                    graphic.presentScene();
                    bool clicked=false;
                    while (!clicked && SDL_WaitEvent(&event)) {
                        if (event.type == SDL_MOUSEBUTTONDOWN) {
                            clicked = true;
                            audio.play (audio.clickSound);
                        }
                    }
                    currentLevelIndex++;
                    break;
                }

                const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
                if (currentKeyStates[SDL_SCANCODE_UP]) player.up();
                if (currentKeyStates[SDL_SCANCODE_DOWN]) player.down();
                if (currentKeyStates[SDL_SCANCODE_LEFT]) player.left();
                if (currentKeyStates[SDL_SCANCODE_RIGHT]) player.right();
                player.move(map, audio, coinsEarned);
                player.tick();

                graphic.renderPlayer1(player);
                graphic.renderTiles1(map);

                graphic.presentScene();
                SDL_Delay(10);
            }

            if (gameOverMode1 (player, bats, darts, puffers, map)) {
                audio.play(audio.deathSound);
                graphic.renderTexture (graphic.lostScreen, 0, 0);
                graphic.presentScene();
                bool clicked=false;
                while (!clicked && SDL_WaitEvent(&event)) {
                    if (event.type == SDL_MOUSEBUTTONDOWN) {
                        clicked = true;
                        audio.play (audio.clickSound);
                    }
                }
                if (currentLevelIndex >= 6 && coinsEarned >= currentLevelIndex * 50) {
                    graphic.renderTexture (graphic.reviveScreen, 0, 0);
                    graphic.presentScene();
                    bool payScreenClicked = false;
                    while (!payScreenClicked && SDL_WaitEvent(&event)) {
                        if (event.type == SDL_MOUSEBUTTONDOWN) {
                            coinsEarned -= currentLevelIndex * 50;
                            payScreenClicked = true;
                            audio.play (audio.clickSound);
                        }
                    }
                    continue;
                }
                else {
                    quit = false;
                    normalPlay = true;
                    currentLevelIndex = 1;
                    lavaPlay = false;
                    break;
                }
            }
        }
    }

    while (lavaPlay && !quit) {
        int offsetX = 0;
        int offsetY = 0;

        int currentLevelIndex=1;
        vector<GameMode2Level> levelss;
        GameMode2Level::createLevels(levelss);

        random_shuffle(levelss.begin(), levelss.end());

        bool playingState = true;
        bool displayIntroScreen = false;
        int coinsEarned =0;

        while (!quit && currentLevelIndex <= static_cast<int>(levelss.size())) {
            if (currentLevelIndex == 1) {
                graphic.renderTexture (graphic.lavaIntroScreen, 0, 0);
                displayIntroScreen = true;
            }
            else {displayIntroScreen = false;}
            graphic.presentScene();

            if (displayIntroScreen) {
                bool clicked=false;
                while (!clicked && SDL_WaitEvent(&event)) {
                    if (event.type == SDL_MOUSEBUTTONDOWN) {
                        clicked = true;
                        audio.play (audio.clickSound);
                    }
                }
            }

            GameMode2Level currentLevel = levelss[currentLevelIndex-1];
            Player player = currentLevel.getPlayer();
            vector<vector<char>> map = currentLevel.getMap();
            Lava lava (0, map.size()*TILE_SIZE - TILE_SIZE);

            while (!gameOverMode2 (player, lava)) {
                graphic.prepareScene();

                SDL_Color color = {255,255,0,255};
                graphic.coinText = graphic.renderText (to_string(coinsEarned).c_str(), graphic.font, color);
                graphic.renderTexture (graphic.coinText, 40, 615);
                graphic.renderTexture (graphic.coinLogoTexture, 10, 610);

                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        quit = true;
                    }
                    handleQuitButton (&event, quitButton, yesButton, noButton, playingState, normalPlay, lavaPlay, graphic, audio);
                }
                quitButton.renderButton(graphic.quitButtonTexture, graphic);
                if (!lavaPlay && !playingState) {
                    quit = true;
                    break;
                }

                lava.activate();
                lava.rise(map);

                if (player.win) {
                    graphic.renderTexture (graphic.winScreen, 0, 0);
                    graphic.presentScene();
                    bool clicked=false;
                    while (!clicked && SDL_WaitEvent(&event)) {
                        if (event.type == SDL_MOUSEBUTTONDOWN) {
                            clicked = true;
                            audio.play(audio.clickSound);
                        }
                    }
                    currentLevelIndex++;
                    break;
                }

                const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
                if (currentKeyStates[SDL_SCANCODE_UP]) player.up();
                if (currentKeyStates[SDL_SCANCODE_DOWN]) player.down();
                if (currentKeyStates[SDL_SCANCODE_LEFT]) player.left();
                if (currentKeyStates[SDL_SCANCODE_RIGHT]) player.right();
                player.move(map, audio, coinsEarned);
                player.tick();

                offsetX = player.rect.x - SCREEN_WIDTH/2;
                offsetY = player.rect.y - SCREEN_HEIGHT/2;
                offsetX = max(0, min(offsetX, static_cast<int>(map[0].size()) * TILE_SIZE - SCREEN_WIDTH));
                offsetY = max(0, min(offsetY, static_cast<int>(map.size()) * TILE_SIZE - SCREEN_HEIGHT));

                graphic.renderPlayer2(player, offsetX, offsetY);
                graphic.renderTiles2(map, offsetX, offsetY);

                graphic.renderLava(lava, offsetX, offsetY);
                graphic.presentScene();
                SDL_Delay(10);
            }

            if (gameOverMode2 (player, lava)) {
                audio.play(audio.deathSound);
                graphic.renderTexture (graphic.lostScreen, 0, 0);
                graphic.presentScene();
                bool clicked=false;
                while (!clicked && SDL_WaitEvent(&event)) {
                    if (event.type == SDL_MOUSEBUTTONDOWN) {
                        clicked = true;
                        audio.play (audio.clickSound);
                    }
                }
                if (coinsEarned >= currentLevelIndex * 100) {
                    graphic.renderTexture (graphic.reviveScreen, 0, 0);
                    graphic.presentScene();
                    bool payScreenClicked = false;
                    while (!payScreenClicked && SDL_WaitEvent(&event)) {
                        if (event.type == SDL_MOUSEBUTTONDOWN) {
                            coinsEarned -= currentLevelIndex * 100;
                            payScreenClicked = true;
                            audio.play (audio.clickSound);
                        }
                    }
                    continue;
                }
                else {
                    quit = false;
                    normalPlay = false;
                    currentLevelIndex = 1;
                    lavaPlay = true;
                    break;
                }
            }
        }
    }
    graphic.quit();
    audio.quit();
    return 0;
}
