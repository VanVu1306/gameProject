#ifndef _AUDIOS__H
#define _AUDIOS__H

#include <SDL.h>
#include <SDL_mixer.h>

struct Audios {
    Mix_Music* music = nullptr;
    Mix_Chunk* batSound = nullptr;
    Mix_Chunk* clickSound = nullptr;
    Mix_Chunk* winSound = nullptr;
    Mix_Chunk* deathSound = nullptr;
    Mix_Chunk* dartSound = nullptr;
    Mix_Chunk* puffOnSound = nullptr;
    Mix_Chunk* puffOffSound = nullptr;
    Mix_Chunk* teleporterSound = nullptr;
    Mix_Chunk* coinSound = nullptr;
    void init () {
        initSDL ();
        music = loadMusic ("./assets/audio/music.mp3");

        batSound = loadSound("./assets/audio/bat_sound.wav");
        clickSound = loadSound ("./assets/audio/mouse_click_sound.wav");
        winSound = loadSound ("./assets/audio/win_sound.wav");
        deathSound = loadSound ("./assets/audio/death_sound.wav");
        dartSound = loadSound ("./assets/audio/dart_sound.wav");
        puffOnSound = loadSound ("./assets/audio/puff_on_sound.wav");
        puffOffSound = loadSound ("./assets/audio/puff_off_sound.wav");
        teleporterSound = loadSound ("./assets/audio/teleporter_sound.wav");
        coinSound = loadSound ("./assets/audio/coin_sound.wav");
    }
    void initSDL () {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            logErrorAndExit("SDL_Init", SDL_GetError());
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
            logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        }
    }
    void logErrorAndExit(const char* msg, const char* error){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
        SDL_Quit();
    }

    Mix_Music *loadMusic(const char* path){
        Mix_Music *gMusic = Mix_LoadMUS(path);
        if (gMusic == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                           "Could not load music! SDL_mixer Error: %s", Mix_GetError());
        }
        return gMusic;
    }

    void play(Mix_Music *gMusic){
        if (gMusic == nullptr) return;

        if (Mix_PlayingMusic() == 0) {
            Mix_PlayMusic( gMusic, -1 );
        }
        else if( Mix_PausedMusic() == 1 ) {
            Mix_ResumeMusic();
        }
    }

    Mix_Chunk* loadSound(const char* path) {
        Mix_Chunk* gChunk = Mix_LoadWAV(path);
        if (gChunk == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
        }
        return gChunk;
    }

    void play(Mix_Chunk* gChunk) {
        if (gChunk != nullptr) {
            Mix_PlayChannel( -1, gChunk, 0 );
        }
    }

    void quit() {
        Mix_FreeMusic (music);

        Mix_FreeChunk (batSound);
        Mix_FreeChunk (clickSound);
        Mix_FreeChunk (winSound);
        Mix_FreeChunk (deathSound);
        Mix_FreeChunk (dartSound);
        Mix_FreeChunk (puffOnSound);
        Mix_FreeChunk (puffOffSound);
        Mix_FreeChunk (teleporterSound);
        Mix_FreeChunk (coinSound);
        Mix_Quit();
    }
};
#endif
