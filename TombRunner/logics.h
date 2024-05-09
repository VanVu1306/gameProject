#ifndef _LOGICS__H
#define _LOGICS__H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "maps.h"
#include "defs.h"
#include "audios.h"

using namespace std;

struct Sprite {
    SDL_Texture* texture;
    vector<SDL_Rect> clips;
    int currentFrame = 0;

    void init (SDL_Texture* _texture, int frames, const int _clips[][4]) {
        texture = _texture;
        SDL_Rect clip;
        for (int i=0; i< frames; i++) {
            clip.x = _clips[i][0];
            clip.y = _clips[i][1];
            clip.w = _clips[i][2];
            clip.h = _clips[i][3];
            clips.push_back(clip);
        }
    }
    void tick();

    const SDL_Rect* getCurrentClip() const {
        return &(clips[currentFrame]);
    }
};

struct Player : public Sprite {
    SDL_Rect rect;
    int dx, dy;
    bool win;
    bool die;

    Player () : dx(0), dy(0), win(false), die(false) {}

    Player (SDL_Texture*_texture, int startX, int startY) {
        init (_texture, playerFrames, playerClips);
        rect.x = startX;
        rect.y = startY;
        rect.w = PLAYER_SIZE;
        rect.h = PLAYER_SIZE;

        dx=0;
        dy=0;
        win = false;
        die = false;
    }

    void tick() {
        if (dx!=0 || dy !=0) {
            currentFrame =1;
        }
        else {
            currentFrame =0;
        }
    }

    void checkCollision(vector <vector<char>>&map, Audios& audio, int& coinsEarned) {
		for (int i = rect.y/TILE_SIZE; i < (rect.y+rect.h)/TILE_SIZE; i++){
			for (int j = rect.x/TILE_SIZE; j < (rect.x+rect.w)/TILE_SIZE; j++) {
				if (map[i][j] == 'A' || map[i][j] == 'B' || map[i][j] == 'C' || map[i][j] == 'D' || map[i][j] == 'E' || map[i][j] == 'F' || map[i][j] == '1' || map[i][j] == '2' || map[i][j] == '3' || map[i][j] == '4' ) {
					if (dx>0 && dy==0) {
						rect.x = j * TILE_SIZE - rect.w;
						dx = 0;
					}
					if (dx<0 && dy==0) {
						rect.x = j * TILE_SIZE + TILE_SIZE;
						dx = 0;
					}
					if (dy>0 && dx==0) {
						rect.y = i * TILE_SIZE - rect.h;
						dy = 0;
					}
					if (dy<0 && dx==0) {
						rect.y = i * TILE_SIZE + TILE_SIZE;
						dy = 0;
					}
				}
				if (map[i][j] == 'W') {
                    win = true;
                    audio.play(audio.winSound);
				}
				if (map[i][j] == 'S') {
                    die = true;
				}
				if (map[i][j] == '.') {
                    map[i][j] = ' ';
                    coinsEarned++;
                    audio.play(audio.coinSound);
				}
			}
		}

    }

    void move(vector <vector<char>>&map, Audios& audio, int& coinsEarned) {
        int prevX = rect.x;
        int prevY = rect.y;
        rect.x += dx;
        rect.y += dy;
        checkCollision(map, audio, coinsEarned);
        if (rect.x==prevX && rect.y==prevY) {
            dx=0;
            dy=0;
        }
    }

    void right() {
        dx = INITIAL_SPEED;
        dy=0;
    }
    void left () {
        dx = -INITIAL_SPEED;
        dy=0;
    }
    void down() {
        dx=0;
        dy=INITIAL_SPEED;
    }
    void up() {
        dx=0;
        dy=-INITIAL_SPEED;
    }
};

struct Bats : public Sprite {
    SDL_Rect rect;
    int dx;
    int dy;
    int timer;

    Bats () : dx (0), dy(0), timer(0) {}

    Bats (SDL_Texture*_texture, int startX, int startY, int startDx, int startDy) {
        init (_texture, batFrames, batClips);
        rect.x = startX;
        rect.y = startY;
        rect.w = PLAYER_SIZE;
        rect.h = PLAYER_SIZE;
        dx = startDx;
        dy = startDy;
        timer = 1000;
    }

    void tick() {
        timer -=100;
        if (timer == 0) {
            currentFrame = (currentFrame + 1) % clips.size();
            timer = 1000;
        }
    }

    void checkCollision (vector <vector<char>>&map, Audios& audio) {
        for (int i = rect.y/TILE_SIZE; i < (rect.y+rect.h)/TILE_SIZE; i++){
			for (int j = rect.x/TILE_SIZE; j < (rect.x+rect.w)/TILE_SIZE; j++) {
				if (map[i][j] == 'A' || map[i][j] == 'B' || map[i][j] == 'C' || map[i][j] == 'D' || map[i][j] == 'E' || map[i][j] == 'F' || map[i][j] == 'S') {
					if (dx>0 && dy==0) {
						dx *= -1;
						audio.play(audio.batSound);
					}
					else if (dx<0 && dy==0) {
						dx *= -1;
						audio.play(audio.batSound);
					}
					else if (dy>0 && dx==0) {
						dy *= -1;
						audio.play(audio.batSound);
					}
					else if (dy<0 && dx==0) {
						dy *= -1;
						audio.play(audio.batSound);
					}
				}
			}
        }
    }

    void move(vector <vector<char>>&map, Audios& audio){
        rect.x += dx;
        rect.y += dy;
        checkCollision(map, audio);
    }
};

struct Darts : public Sprite {
    SDL_Rect rect;
    int prevX, prevY;
    int dx, dy;
    int timer;
    bool launch;
    int r;

    Darts () : dx(0), dy(0), timer (0), launch (false), r(0) {}

    Darts (SDL_Texture* _texture, int startX, int startY, int _r) {
        init (_texture, dartFrames, dartClips);
        rect.x = startX;
        rect.y = startY;
        rect.w = TILE_SIZE;
        rect.h = TILE_SIZE;
        r = _r;

        if (r ==1) {
            dx = DART_SPEED;
            dy = 0;
        }
        else if (r==2) {
            dx = -DART_SPEED;
            dy = 0;
        }
        else if (r==3) {
            dx=0;
            dy = DART_SPEED;
        }
        else if (r==4) {
            dx=0;
            dy = -DART_SPEED;
        }

        prevX = rect.x;
        prevY = rect.y;
        timer = 3000;
        launch = false;
    }

    void tick() {
        if (r==1) currentFrame = 0;
        else if (r==2) currentFrame =1;
        else if (r==3) currentFrame =2;
        else if (r==4) currentFrame =3;
    }

    void shoot (const vector <vector<char>>&map, Audios& audio) {
        if (timer >0 && !launch) {
            timer = timer -100;
            if (timer == 0) {
                timer = 3000;
                launch = true;
            }
        }
        if (launch) {
            rect.x += dx;
            rect.y += dy;
            audio.play(audio.dartSound);
            checkCollision(map);
        }
    }

    void checkCollision(const vector <vector<char>>&map) {
		for (int i = rect.y/TILE_SIZE; i < (rect.y+rect.h)/TILE_SIZE; i++){
			for (int j = rect.x/TILE_SIZE; j < (rect.x+rect.w)/TILE_SIZE; j++) {
				if (map[i][j] == 'A' || map[i][j] == 'B' || map[i][j] == 'C' || map[i][j] == 'D' || map[i][j] == 'E' || map[i][j] == 'F' || map[i][j] == 'S') {
					if (dx>0 && dy==0) {
						rect.x = prevX;
						launch = false;
					}
					else if (dx<0 && dy==0) {
						rect.x = prevX;
						launch = false;
					}
					else if (dy>0 && dx==0) {
						rect.y = prevY;
						launch = false;
					}
					else if (dy<0 && dx==0) {
						rect.y = prevY;
						launch = false;
					}
				}
			}
		}
    }
};

struct Puffer : public Sprite {
    SDL_Rect rect;
    int timer;
    bool puff;

    Puffer() : timer(0), puff(false) {}

    Puffer (SDL_Texture* _texture, int startX, int startY) {
        init(_texture, pufferFrames, pufferClips);
        rect.x = startX;
        rect.y = startY;
        rect.w = TILE_SIZE*3;
        rect.h = TILE_SIZE*3;

        timer = 5000;
        puff = false;
    }

    void tick (Audios& audio) {
        timer = timer-100;

        if (timer == 0) {
            if (!puff) {
                puff = true;
                currentFrame = 1;
                timer = 3000;
                audio.play (audio.puffOnSound);
            }
            else {
                puff = false;
                currentFrame = 0;
                timer = 5000;
                audio.play (audio.puffOffSound);
            }
        }
    }
};

inline bool overlap (const SDL_Rect& rectA, const SDL_Rect& rectB) {
  return (rectA.x < rectB.x + rectB.w && rectA.x + rectA.w > rectB.x && rectA.y < rectB.y + rectB.h && rectA.y + rectA.h > rectB.y);
}

struct Teleporters : public Sprite {
    SDL_Rect rect;
    int destinationX, destinationY;
    int timer;

    Teleporters () : destinationX (0), destinationY (0), timer (0) {}

    Teleporters (SDL_Texture* _texture, int startX, int startY, int destX, int destY) {
        init(_texture, teleporterFrames, teleporterClips);
        rect.x = startX;
        rect.y = startY;
        rect.w = TILE_SIZE;
        rect.h = TILE_SIZE;
        destinationX = destX;
        destinationY = destY;
        timer = 500;
    }

    void tick () {
        timer -=100;
        if (timer ==0) {
            currentFrame = (currentFrame + 1) % clips.size();
            timer = 400;
        }
    }

    void teleport (Player& player, Audios& audio) {
        if (overlap(player.rect, rect)) {
            player.rect.x = destinationX;
            player.rect.y = destinationY;
            audio.play (audio.teleporterSound);
        }
    }
};

inline bool gameOverMode1(const Player& player, const vector <Bats>& bats, const vector <Darts> darts, const vector <Puffer> puffers, const vector <vector<char>>& map) {
    SDL_Rect playerRect = player.rect;

    for (const Bats& bat : bats) {
        SDL_Rect batRect = bat.rect;
        if (overlap(playerRect, batRect)) return true;
    }

    for (const Darts& dart : darts) {
        SDL_Rect dartRect = dart.rect;
        if (dart.launch && overlap(playerRect, dartRect)) return true;
    }

    for (const Puffer& puffer : puffers) {
        SDL_Rect pufferRect = puffer.rect;
        if (puffer.puff == true &&
				pufferRect.x <= playerRect.x && playerRect.x <= pufferRect.x + 2 * TILE_SIZE &&
				pufferRect.y <= playerRect.y && playerRect.y <= pufferRect.y + 2 * TILE_SIZE)
				return true;
    }

    if (player.die) return true;
    return false;
}

struct Lava {
    SDL_Rect rect;
    int speed;
    int timeBeforeStart;
    bool activated;

    Lava (int x, int y) {
        rect.x = x;
        rect.y = y;
        rect.w = SCREEN_WIDTH;
        rect.h = TILE_SIZE;
        speed = rand() % 5 +1;
        timeBeforeStart = 20000;
        activated = false;
    }

    void activate () {
        timeBeforeStart -=100;
        if (timeBeforeStart == 0) activated = true;
    }

    void rise(vector<vector<char>>& map) {
        if (activated) {
            rect.y -= speed;
            rect.h = static_cast<int>(map.size()) * TILE_SIZE - rect.y;

            if (rect.h >= static_cast<int>(map.size()) * TILE_SIZE) {
            activated = false;
            }
        }
    }
};

inline bool gameOverMode2 (Player& player, Lava& lava) {
    return (lava.rect.y < player.rect.y + player.rect.h);
}

#endif

