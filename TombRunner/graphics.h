#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "defs.h"
#include "logics.h"
#include "maps.h"

struct Graphics {
	SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *wallTextureA, *wallTextureB, *wallTextureC, *wallTextureD, *wallTextureE, *wallTextureF, *spikeTexture,
                *playerTexture, *dartTexture, *batTexture, *pufferTexture, *teleporterTexture, *winTexture, *coinTexture, *coinLogoTexture,
                *dartWallTextureRight, *dartWallTextureLeft, *dartWallTextureUp, *dartWallTextureDown, *reviveScreen,
                *menuTexture, *normalButtonTexture, *lavaButtonTexture, *exitButtonTexture, *quitButtonTexture, *yesButtonTexture, *noButtonTexture,
                *quitScreen, *winScreen, *lostScreen, *spikeIntroScreen, *batIntroScreen, *pufferIntroScreen, *teleporterIntroScreen,*dartIntroScreen,
                *coinText, *lavaIntroScreen;
    TTF_Font* font;

    void init() {
        initSDL();
        wallTextureA = loadTexture("./assets/img/texture/wallA.png");
        wallTextureB = loadTexture ("./assets/img/texture/wallB.png");
        wallTextureC = loadTexture ("./assets/img/texture/wallC.png");
        wallTextureD = loadTexture ("./assets/img/texture/wallD.png");
        wallTextureE = loadTexture ("./assets/img/texture/wallE.png");
        wallTextureF = loadTexture ("./assets/img/texture/wallF.png");
        playerTexture = loadTexture ("./assets/img/texture/player.png");
        dartTexture = loadTexture ("./assets/img/texture/dart.png");
        batTexture = loadTexture ("./assets/img/texture/bat.png");
        winTexture = loadTexture ("./assets/img/texture/win.png");
        spikeTexture = loadTexture ("./assets/img/texture/spike.png");
        pufferTexture = loadTexture ("./assets/img/texture/puffer.png");
        teleporterTexture = loadTexture ("./assets/img/texture/teleporter.png");
        coinTexture = loadTexture ("./assets/img/texture/coin.png");
        coinLogoTexture = loadTexture ("./assets/img/texture/coinLogo.png");

        dartWallTextureRight = loadTexture ("./assets/img/texture/dart_wall_right.png");
        dartWallTextureLeft = loadTexture ("./assets/img/texture/dart_wall_left.png");
        dartWallTextureUp = loadTexture ("./assets/img/texture/dart_wall_up.png");
        dartWallTextureDown = loadTexture ("./assets/img/texture/dart_wall_down.png");

        menuTexture = loadTexture ("./assets/img/screens/menuBackground.png");
        quitScreen = loadTexture ("./assets/img/screens/quitBG.png");
        winScreen = loadTexture ("./assets/img/screens/winBG.png");
        lostScreen = loadTexture ("./assets/img/screens/lostBG.png");
        spikeIntroScreen = loadTexture ("./assets/img/screens/spikeIntroScreen.png");
        batIntroScreen = loadTexture ("./assets/img/screens/batIntroScreen.png");
        pufferIntroScreen = loadTexture ("./assets/img/screens/pufferIntroScreen.png");
        teleporterIntroScreen = loadTexture ("./assets/img/screens/teleporterIntroScreen.png");
        dartIntroScreen = loadTexture ("./assets/img/screens/dartIntroScreen.png");
        lavaIntroScreen = loadTexture ("./assets/img/screens/lavaIntroScreen.png");
        reviveScreen = loadTexture ("./assets/img/screens/reviveScreen.png");

        normalButtonTexture = loadTexture ("./assets/img/buttons/normalButton.png");
        lavaButtonTexture = loadTexture ("./assets/img/buttons/lavaButton.png");
        exitButtonTexture = loadTexture ("./assets/img/buttons/exitButton.png");
        quitButtonTexture = loadTexture ("./assets/img/buttons/quitButton.png");
        yesButtonTexture = loadTexture ("./assets/img/buttons/yesButton.png");
        noButtonTexture = loadTexture ("./assets/img/buttons/noButton.png");

        font = loadFont("./assets/font/tomb-of-the-mask.ttf", 20);
    }

    void renderPlayer1 (const Player& player) {
        const SDL_Rect* clip = player.getCurrentClip();
        SDL_Rect renderQuad = {player.rect.x, player.rect.y, clip->w, clip->h};
        SDL_RenderCopy (renderer, playerTexture, clip, &renderQuad);
    }

    void renderTiles1 (const vector <vector<char>>& map) {
        for (int i = 0; i < H; i++){
                for (int j = 0; j < W; j++) {
                    if (map[i][j] == 'A') {
                        SDL_Rect wallRect;
                        wallRect.x = j * TILE_SIZE;
                        wallRect.y = i * TILE_SIZE;
                        wallRect.w = TILE_SIZE;
                        wallRect.h = TILE_SIZE;
                        renderTexture(wallTextureA, wallRect.x, wallRect.y);
                    }
                    if (map[i][j] == 'B') {
                        SDL_Rect wallRect;
                        wallRect.x = j * TILE_SIZE;
                        wallRect.y = i * TILE_SIZE;
                        wallRect.w = TILE_SIZE;
                        wallRect.h = TILE_SIZE;
                        renderTexture(wallTextureB, wallRect.x, wallRect.y);
                    }
                    if (map[i][j] == 'C') {
                        SDL_Rect wallRect;
                        wallRect.x = j * TILE_SIZE;
                        wallRect.y = i * TILE_SIZE;
                        wallRect.w = TILE_SIZE;
                        wallRect.h = TILE_SIZE;
                        renderTexture(wallTextureC, wallRect.x, wallRect.y);
                    }
                    if (map[i][j] == 'D') {
                        SDL_Rect wallRect;
                        wallRect.x = j * TILE_SIZE;
                        wallRect.y = i * TILE_SIZE;
                        wallRect.w = TILE_SIZE;
                        wallRect.h = TILE_SIZE;
                        renderTexture(wallTextureD, wallRect.x, wallRect.y);
                    }
                    if (map[i][j] == 'E') {
                        SDL_Rect wallRect;
                        wallRect.x = j * TILE_SIZE;
                        wallRect.y = i * TILE_SIZE;
                        wallRect.w = TILE_SIZE;
                        wallRect.h = TILE_SIZE;
                        renderTexture(wallTextureE, wallRect.x, wallRect.y);
                    }
                    if (map[i][j] == 'F') {
                        SDL_Rect wallRect;
                        wallRect.x = j * TILE_SIZE;
                        wallRect.y = i * TILE_SIZE;
                        wallRect.w = TILE_SIZE;
                        wallRect.h = TILE_SIZE;
                        renderTexture(wallTextureF, wallRect.x, wallRect.y);
                    }
                    if (map[i][j] == 'S') {
                        SDL_Rect wallRect;
                        wallRect.x = j * TILE_SIZE;
                        wallRect.y = i * TILE_SIZE;
                        wallRect.w = TILE_SIZE;
                        wallRect.h = TILE_SIZE;
                        renderTexture(spikeTexture, wallRect.x, wallRect.y);
                    }
                    if (map[i][j] == '1') {
                        SDL_Rect dartWallRect;
                        dartWallRect.x = j * TILE_SIZE;
                        dartWallRect.y = i * TILE_SIZE;
                        dartWallRect.w = TILE_SIZE;
                        dartWallRect.h = TILE_SIZE;
                        renderTexture(dartWallTextureRight, dartWallRect.x, dartWallRect.y);
                    }
                    if (map[i][j] == '2') {
                        SDL_Rect dartWallRect;
                        dartWallRect.x = j * TILE_SIZE;
                        dartWallRect.y = i * TILE_SIZE;
                        dartWallRect.w = TILE_SIZE;
                        dartWallRect.h = TILE_SIZE;
                        renderTexture(dartWallTextureLeft, dartWallRect.x, dartWallRect.y);
                    }
                    if (map[i][j] == '3') {
                        SDL_Rect dartWallRect;
                        dartWallRect.x = j * TILE_SIZE;
                        dartWallRect.y = i * TILE_SIZE;
                        dartWallRect.w = TILE_SIZE;
                        dartWallRect.h = TILE_SIZE;
                        renderTexture(dartWallTextureDown, dartWallRect.x, dartWallRect.y);
                    }
                    if (map[i][j] == '4') {
                        SDL_Rect dartWallRect;
                        dartWallRect.x = j * TILE_SIZE;
                        dartWallRect.y = i * TILE_SIZE;
                        dartWallRect.w = TILE_SIZE;
                        dartWallRect.h = TILE_SIZE;
                        renderTexture(dartWallTextureUp, dartWallRect.x, dartWallRect.y);
                    }
                    if (map[i][j] == 'W') {
                        SDL_Rect winRect;
                        winRect.x = j * TILE_SIZE;
                        winRect.y = i * TILE_SIZE;
                        winRect.w = TILE_SIZE;
                        winRect.h = TILE_SIZE;
                        renderTexture(winTexture, winRect.x, winRect.y);
                    }
                    if (map[i][j] == '.') {
                        SDL_Rect coinRect;
                        coinRect.x = j * TILE_SIZE;
                        coinRect.y = i * TILE_SIZE;
                        coinRect.w = TILE_SIZE;
                        coinRect.h = TILE_SIZE;
                        renderTexture(coinTexture, coinRect.x, coinRect.y);
                    }
                }
            }
        SDL_RenderPresent(renderer);
    }

    void renderDart (const Darts& dart) {
        if (dart.launch) {
            const SDL_Rect* clip = dart.getCurrentClip();
            SDL_Rect renderQuad = {dart.rect.x, dart.rect.y, clip->w, clip->h};
            SDL_RenderCopy (renderer, dartTexture, clip, &renderQuad);
        }
    }

    void renderBat (const Bats& bat) {
        const SDL_Rect* clip = bat.getCurrentClip();
        SDL_Rect renderQuad = {bat.rect.x, bat.rect.y, clip->w, clip->h};
        SDL_RenderCopy (renderer, batTexture, clip, &renderQuad);
    }
    void renderPuffer (const Puffer& puffer) {
        const SDL_Rect* clip = puffer.getCurrentClip();
        SDL_Rect renderQuad = {puffer.rect.x, puffer.rect.y, clip->w, clip->h};
        SDL_RenderCopy (renderer, pufferTexture, clip, &renderQuad);
    }
    void renderTeleporter (const Teleporters& teleporter) {
        const SDL_Rect* clip = teleporter.getCurrentClip();
        SDL_Rect renderQuad = {teleporter.rect.x, teleporter.rect.y, clip->w, clip->h};
        SDL_RenderCopy (renderer, teleporterTexture, clip, &renderQuad);
    }
    void renderLava (const Lava& lava, int offsetX, int offsetY) {
        SDL_Rect lavaRect = {lava.rect.x - offsetX, lava.rect.y - offsetY, lava.rect.w, lava.rect.h};
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set lava color to red (adjust as needed)
        SDL_RenderFillRect(renderer, &lavaRect);
        presentScene();
    }
    void renderPlayer2 (const Player& player, int offsetX, int offsetY) {
        const SDL_Rect* clip = player.getCurrentClip();
        SDL_Rect renderQuad = {player.rect.x-offsetX, player.rect.y-offsetY, clip->w, clip->h};
        SDL_RenderCopy (renderer, playerTexture, clip, &renderQuad);
    }
    void renderTiles2(const vector<vector<char>>& map, int offsetX, int offsetY) {
        for (int i = 0; i < static_cast<int>(map.size()); i++) {
            for (int j = 0; j < static_cast<int>(map[0].size()); j++) {
                if (map[i][j] == 'B') {
                    renderTexture(wallTextureB, j * TILE_SIZE - offsetX, i * TILE_SIZE - offsetY);
                }
                else if (map[i][j] == 'W') {
                    renderTexture(winTexture, j * TILE_SIZE - offsetX, i * TILE_SIZE - offsetY);
                }
                else if (map[i][j] == 'F') {
                    renderTexture(wallTextureF, j * TILE_SIZE - offsetX, i * TILE_SIZE - offsetY);
                }
                else if (map[i][j] == 'D') {
                    renderTexture(wallTextureD, j * TILE_SIZE - offsetX, i * TILE_SIZE - offsetY);
                }
                else if (map[i][j] == 'E') {
                    renderTexture(wallTextureE, j * TILE_SIZE - offsetX, i * TILE_SIZE - offsetY);
                }
                else if (map[i][j] == '.') {
                    renderTexture(coinTexture, j * TILE_SIZE - offsetX, i * TILE_SIZE - offsetY);
                }
            }
        }
    }

    void logErrorAndExit(const char* msg, const char* error){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
        SDL_Quit();
    }

    void initSDL() {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            logErrorAndExit("SDL_Init", SDL_GetError());

        window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        //full screen
        //window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
        if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

        if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
            logErrorAndExit( "SDL_image error:", IMG_GetError());

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
        //Khi chạy trong máy ảo (ví dụ phòng máy ở trường)
        //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

        if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
        if (TTF_Init() == -1) {
            logErrorAndExit("SDL_ttf could not initialize! SDL_ttf Error: ",
                             TTF_GetError());
        }

    }

    void quit(){
        SDL_DestroyTexture(wallTextureA);
        wallTextureA = nullptr;
        SDL_DestroyTexture(wallTextureB);
        wallTextureB = nullptr;
        SDL_DestroyTexture(wallTextureC);
        wallTextureC = nullptr;
        SDL_DestroyTexture(wallTextureD);
        wallTextureD = nullptr;
        SDL_DestroyTexture (wallTextureE);
        wallTextureE = nullptr;
        SDL_DestroyTexture(wallTextureF);
        wallTextureF = nullptr;
        SDL_DestroyTexture(spikeTexture);
        spikeTexture = nullptr;
        SDL_DestroyTexture(playerTexture);
        playerTexture = nullptr;
        SDL_DestroyTexture (dartTexture);
        dartTexture = nullptr;
        SDL_DestroyTexture (batTexture);
        batTexture = nullptr;
        SDL_DestroyTexture (pufferTexture);
        pufferTexture = nullptr;
        SDL_DestroyTexture (teleporterTexture);
        teleporterTexture = nullptr;
        SDL_DestroyTexture (coinTexture);
        coinTexture = nullptr;
        SDL_DestroyTexture (coinLogoTexture);
        coinLogoTexture = nullptr;

        SDL_DestroyTexture(dartWallTextureRight);
        dartWallTextureRight = nullptr;
        SDL_DestroyTexture(dartWallTextureLeft);
        dartWallTextureLeft = nullptr;
        SDL_DestroyTexture(dartWallTextureDown);
        dartWallTextureDown = nullptr;
        SDL_DestroyTexture(dartWallTextureUp);
        dartWallTextureUp = nullptr;

        SDL_DestroyTexture (menuTexture);
        menuTexture = nullptr;
        SDL_DestroyTexture (quitScreen);
        quitScreen = nullptr;
        SDL_DestroyTexture(winScreen);
        winScreen = nullptr;
        SDL_DestroyTexture (lostScreen);
        lostScreen = nullptr;
        SDL_DestroyTexture (spikeIntroScreen);
        spikeIntroScreen = nullptr;
        SDL_DestroyTexture (batIntroScreen);
        batIntroScreen = nullptr;
        SDL_DestroyTexture (pufferIntroScreen);
        pufferIntroScreen = nullptr;
        SDL_DestroyTexture (teleporterIntroScreen);
        teleporterIntroScreen = nullptr;
        SDL_DestroyTexture (dartIntroScreen);
        dartIntroScreen = nullptr;
        SDL_DestroyTexture (lavaIntroScreen);
        lavaIntroScreen = nullptr;
        SDL_DestroyTexture (reviveScreen);
        reviveScreen = nullptr;

        SDL_DestroyTexture (normalButtonTexture);
        normalButtonTexture = nullptr;
        SDL_DestroyTexture (lavaButtonTexture);
        lavaButtonTexture = nullptr;
        SDL_DestroyTexture (exitButtonTexture);
        exitButtonTexture = nullptr;
        SDL_DestroyTexture (quitButtonTexture);
        quitButtonTexture = nullptr;
        SDL_DestroyTexture (yesButtonTexture);
        yesButtonTexture = nullptr;
        SDL_DestroyTexture (noButtonTexture);
        noButtonTexture = nullptr;

        SDL_DestroyTexture (coinText);
        TTF_CloseFont(font);
        coinText = nullptr;

        IMG_Quit();
        TTF_Quit();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void renderTexture(SDL_Texture *texture, int x, int y){
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

        SDL_RenderCopy(renderer, texture, NULL, &dest);
	}

	//void renderSprite (const Sprite& sprite, int x, int y) {
	    //const SDL_Rect* clip = sprite.getCurrentClip();
	    //SDL_Rect renderQuad = {x, y, clip->w, clip->h};
	    //SDL_RenderCopy (renderer, sprite.texture, clip, &renderQuad);
	//}

	SDL_Texture *loadTexture(const char *filename){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

        SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
        if (texture == NULL)
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

        return texture;
    }
    TTF_Font* loadFont(const char* path, int size) {
        TTF_Font* gFont = TTF_OpenFont( path, size );
        if (gFont == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load font %s", TTF_GetError());
        }
        return gFont;
    }

    SDL_Texture* renderText(const char* text, TTF_Font* font, SDL_Color textColor){
        SDL_Surface* textSurface = TTF_RenderText_Solid( font, text, textColor );
        if( textSurface == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Render text surface %s", TTF_GetError());
            return nullptr;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, textSurface );
        if( texture == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Create texture from text %s", SDL_GetError());
        }

        SDL_FreeSurface( textSurface );
        return texture;
    }

    void prepareScene(){
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
    }

    void presentScene(){
        SDL_RenderPresent(renderer);
    }
};
#endif // _GRAPHICS__H
