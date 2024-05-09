#ifndef _DEFS__H
#define _DEFS__H

const int SCREEN_WIDTH = 750;
const int SCREEN_HEIGHT = 660;
inline const char* WINDOW_TITLE = "Tomb Runner";
const int MENU_BUTTON_WIDTH = 200;
const int MENU_BUTTON_HEIGHT = 60;
const int OPT_BUTTON_WIDTH = 130;
const int OPT_BUTTON_HEIGHT = 100;

const int W = 25;
const int H = 22;
const int TILE_SIZE = 30;
const int PLAYER_SIZE=30;
const int INITIAL_SPEED=25;
const int DART_SPEED=10;
const int BAT_SPEED=8;
const int SAW_SPEED=8;

const int pufferClips[][4] = {
    {  0, 0, 90, 90},
    { 90, 0, 90, 90},
};
const int pufferFrames = sizeof(pufferClips)/sizeof(int)/4;

const int playerClips[][4] = {
    { 0, 0, 30, 30},
    {30, 0, 30, 30},
};
const int playerFrames = sizeof(playerClips)/sizeof(int)/4;

const int dartClips[][4] = {
    { 0, 0, 30, 30},
    {30, 0, 30, 30},
    {60, 0, 30, 30},
    {90, 0, 30, 30},
};
const int dartFrames = sizeof(dartClips)/sizeof(int)/4;

const int batClips[][4] = {
    { 0, 0, 30, 30},
    {30, 0, 30, 30},
    {60, 0, 30, 30},
};
const int batFrames = sizeof(batClips)/sizeof(int)/4;

const int teleporterClips[][4] = {
    { 0, 0, 30, 30},
    {30, 0, 30, 30},
    {60, 0, 30, 30},
    {90, 0, 30, 30},
    {120, 0, 30, 30},
    {150, 0, 30, 30},
    {180, 0, 30, 30},
    {210, 0, 30, 30},
    {240, 0, 30, 30},
};
const int teleporterFrames = sizeof(teleporterClips)/sizeof(int)/4;


#endif
