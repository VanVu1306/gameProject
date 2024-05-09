#include "levels.h"

using namespace std;

vector<GameMode1Level> levels;
vector<GameMode2Level> levelss;
Graphics graphic;

GameMode1Level::GameMode1Level(Player c, const vector<Bats>& b, const vector<Darts>& d, const vector<Puffer>& p, const vector<Teleporters>& t, vector<vector<char>> m) :
    player(c), bats(b), darts(d), puffers(p), teleporters(t), map(m) {}

const Player& GameMode1Level::getPlayer() {
    return player;
}

const vector<Bats>& GameMode1Level::getBats() {
    return bats;
}

const vector<Darts>& GameMode1Level::getDarts() {
    return darts;
}

const vector <Puffer>& GameMode1Level::getPuffer() {
    return puffers;
}

const vector <Teleporters>& GameMode1Level::getTeleporters() {
    return teleporters;
}

const vector<vector<char>>& GameMode1Level::getMap() {
    return map;
}

void GameMode1Level::createLevels (vector <GameMode1Level>& levels) {

    Player playerLevel1(graphic.playerTexture, TILE_SIZE * (W-8), TILE_SIZE * (H-7));
    vector <Bats> batsLevel1;
    vector <Darts> dartsLevel1;
    vector <vector<char>> mapLevel1 = map1;
    vector <Puffer> puffersLevel1;
    vector <Teleporters> teleportersLevel1;
    GameMode1Level level1(playerLevel1, batsLevel1, dartsLevel1, puffersLevel1, teleportersLevel1, mapLevel1);
    levels.push_back(level1);

    Player playerLevel2(graphic.playerTexture, TILE_SIZE * (W-2), TILE_SIZE * (H-2));
    vector <Bats> batsLevel2;
    vector <Darts> dartsLevel2;
    vector <vector<char>> mapLevel2 = map2;
    vector <Puffer> puffersLevel2;
    vector <Teleporters> teleportersLevel2;
    GameMode1Level level2(playerLevel2, batsLevel2, dartsLevel2, puffersLevel2, teleportersLevel2, mapLevel2);
    levels.push_back(level2);

    Player playerLevel3 (graphic.playerTexture, TILE_SIZE, TILE_SIZE * 6);
    vector<Bats> batsLevel3;
    vector<Darts> dartsLevel3;
    vector <vector<char>> mapLevel3 = map3;
    vector <Puffer> puffersLevel3;
    vector <Teleporters> teleportersLevel3;
    GameMode1Level level3(playerLevel3, batsLevel3, dartsLevel3, puffersLevel3, teleportersLevel3, mapLevel3);
    levels.push_back(level3);

    Player playerLevel4 (graphic.playerTexture, TILE_SIZE * 9, TILE_SIZE * (H-5));
    vector<Bats> batsLevel4 = {
        Bats(graphic.batTexture, TILE_SIZE * 12, TILE_SIZE * 3, 0, BAT_SPEED),
        Bats(graphic.batTexture, TILE_SIZE * 14, TILE_SIZE * 7, 0, BAT_SPEED),
        Bats(graphic.batTexture, TILE_SIZE * (W-7), TILE_SIZE * (H-11), BAT_SPEED , 0),
    };
    vector<Darts> dartsLevel4;
    vector <vector<char>> mapLevel4 = map4;
    vector <Puffer> puffersLevel4;
    vector <Teleporters> teleportersLevel4;
    GameMode1Level level4(playerLevel4, batsLevel4, dartsLevel4, puffersLevel4, teleportersLevel4, mapLevel4);
    levels.push_back(level4);

    Player playerLevel5 (graphic.playerTexture, TILE_SIZE * (W-6), TILE_SIZE * (H-2));
    vector<Bats> batsLevel5 = {
        Bats(graphic.batTexture, TILE_SIZE * 5, TILE_SIZE * (H-3), 0, BAT_SPEED),
        Bats(graphic.batTexture, TILE_SIZE * 10, TILE_SIZE * (H-3), 0, BAT_SPEED),
        Bats(graphic.batTexture, TILE_SIZE * 7, TILE_SIZE * 4, 0 , BAT_SPEED),
        Bats(graphic.batTexture, TILE_SIZE * (W-8), TILE_SIZE * 7, BAT_SPEED , 0),
    };
    vector<Darts> dartsLevel5;
    vector <vector<char>> mapLevel5 = map5;
    vector <Puffer> puffersLevel5;
    vector <Teleporters> teleportersLevel5;
    GameMode1Level level5(playerLevel5, batsLevel5, dartsLevel5, puffersLevel5, teleportersLevel5, mapLevel5);
    levels.push_back(level5);

    Player playerLevel6 (graphic.playerTexture, TILE_SIZE * 6, TILE_SIZE * (H-5));
    vector<Bats> batsLevel6;
    vector<Darts> dartsLevel6;
    vector <vector<char>> mapLevel6 = map6;
    vector <Puffer> puffersLevel6 = {
        Puffer(graphic.pufferTexture, TILE_SIZE * (W-8), TILE_SIZE * 7),
        Puffer(graphic.pufferTexture, TILE_SIZE * (W-10), TILE_SIZE * (H-8)),
    };
    vector <Teleporters> teleportersLevel6;
    GameMode1Level level6(playerLevel6, batsLevel6, dartsLevel6, puffersLevel6, teleportersLevel6, mapLevel6);
    levels.push_back(level6);

    Player playerLevel7(graphic.playerTexture, TILE_SIZE * (W-10), TILE_SIZE * (H-2));
    vector <Bats> batsLevel7;
    vector <Darts> dartsLevel7;
    vector <vector<char>> mapLevel7 = map7;
    vector <Puffer> puffersLevel7 = {
        Puffer(graphic.pufferTexture, TILE_SIZE * 11, TILE_SIZE * (H-10)),
        Puffer(graphic.pufferTexture, TILE_SIZE * 7, TILE_SIZE * (H-13)),
        Puffer(graphic.pufferTexture, TILE_SIZE * 11, TILE_SIZE * 7),
        Puffer(graphic.pufferTexture, TILE_SIZE * (W-11), TILE_SIZE * 3),
    };
    vector <Teleporters> teleportersLevel7;
    GameMode1Level level7(playerLevel7, batsLevel7, dartsLevel7, puffersLevel7, teleportersLevel7, mapLevel7);
    levels.push_back(level7);

    Player playerLevel8 (graphic.playerTexture, TILE_SIZE * 3, TILE_SIZE * 12);
    vector<Bats> batsLevel8;
    vector<Darts> dartsLevel8;
    vector <vector<char>> mapLevel8 = map8;
    vector <Puffer> puffersLevel8;
    vector <Teleporters> teleportersLevel8 = {
        Teleporters(graphic.teleporterTexture, TILE_SIZE , TILE_SIZE * 7, TILE_SIZE * (W-8), TILE_SIZE * 6),
        Teleporters(graphic.teleporterTexture, TILE_SIZE * (W-8), TILE_SIZE * 8, TILE_SIZE * (W-10), TILE_SIZE * 8),
        Teleporters(graphic.teleporterTexture, TILE_SIZE * (W-10), TILE_SIZE * 6, TILE_SIZE * (W-8), TILE_SIZE * (H-4)),
        Teleporters(graphic.teleporterTexture, TILE_SIZE * (W-8), TILE_SIZE *(H-2), TILE_SIZE * (W-10), TILE_SIZE * (H-2)),
        Teleporters(graphic.teleporterTexture, TILE_SIZE * (W-10), TILE_SIZE * (H-4), TILE_SIZE * 4, TILE_SIZE * (H-8)),
    };
    GameMode1Level level8(playerLevel8, batsLevel8, dartsLevel8, puffersLevel8, teleportersLevel8, mapLevel8);
    levels.push_back(level8);

    Player playerLevel9(graphic.playerTexture, TILE_SIZE * 9, TILE_SIZE * (H-4));
    vector <Bats> batsLevel9;
    vector <Darts> dartsLevel9 = {
        Darts (graphic.dartTexture, TILE_SIZE * 9, TILE_SIZE * 10, 4),
        Darts (graphic.dartTexture, TILE_SIZE * (W-8), TILE_SIZE * (H-6), 2),
        Darts (graphic.dartTexture, TILE_SIZE * 6, TILE_SIZE * 8, 1),
        Darts (graphic.dartTexture, TILE_SIZE * (W-7), TILE_SIZE * 9, 3),
    };
    vector <vector<char>> mapLevel9 = map9;
    vector <Puffer> puffersLevel9;
    vector <Teleporters> teleportersLevel9;
    GameMode1Level level9(playerLevel9, batsLevel9, dartsLevel9, puffersLevel9, teleportersLevel9, mapLevel9);
    levels.push_back(level9);

    Player playerLevel10(graphic.playerTexture, TILE_SIZE * 3, TILE_SIZE * (H-4));
    vector <Bats> batsLevel10;
    vector <Darts> dartsLevel10 = {
        Darts (graphic.dartTexture, TILE_SIZE * 6, TILE_SIZE * 9, 1),
        Darts (graphic.dartTexture, TILE_SIZE * 7, TILE_SIZE * 7, 2),
        Darts (graphic.dartTexture, TILE_SIZE * (W-8), TILE_SIZE * 10, 2),
        Darts (graphic.dartTexture, TILE_SIZE * (W-8), TILE_SIZE * 11, 2),
        Darts (graphic.dartTexture, TILE_SIZE * (W-11), TILE_SIZE * (H-6), 3),
        Darts (graphic.dartTexture, TILE_SIZE * (W-12), TILE_SIZE * (H-6), 3),
        Darts (graphic.dartTexture, TILE_SIZE * (W-13), TILE_SIZE * (H-6), 3),
        Darts (graphic.dartTexture, TILE_SIZE * (W-12), TILE_SIZE * (H-9), 4),
    };
    vector <vector<char>> mapLevel10 = map10;
    vector <Puffer> puffersLevel10;
    vector <Teleporters> teleportersLevel10 = {
        Teleporters(graphic.teleporterTexture, TILE_SIZE * (W-11) , TILE_SIZE * (H-3), TILE_SIZE * 8, TILE_SIZE * (H-3)),
        Teleporters(graphic.teleporterTexture, TILE_SIZE * 7, TILE_SIZE * (H-3), TILE_SIZE * (W-11), TILE_SIZE * (H-6)),
        //Teleporters(TILE_SIZE * (W-10), TILE_SIZE * 6, TILE_SIZE * (W-8), TILE_SIZE * (H-4)),
        //Teleporters(TILE_SIZE * (W-8), TILE_SIZE *(H-2), TILE_SIZE * (W-10), TILE_SIZE * (H-2)),
        //Teleporters(TILE_SIZE * (W-10), TILE_SIZE * (H-4), TILE_SIZE * 4, TILE_SIZE * (H-8)),
    };
    GameMode1Level level10(playerLevel10, batsLevel10, dartsLevel10, puffersLevel10, teleportersLevel10, mapLevel10);
    levels.push_back(level10);

    Player playerLevel11(graphic.playerTexture, TILE_SIZE * (W-10), TILE_SIZE * (H-2));
    vector <Bats> batsLevel11 = {
        Bats(graphic.batTexture, TILE_SIZE * (W-6), TILE_SIZE * (H-7), BAT_SPEED, 0),
        Bats(graphic.batTexture, TILE_SIZE * (W-6), TILE_SIZE * (H-12), BAT_SPEED, 0),
        Bats(graphic.batTexture, TILE_SIZE * 11, TILE_SIZE * (H-12), BAT_SPEED, 0),
        Bats(graphic.batTexture, TILE_SIZE * 4, TILE_SIZE * 4, BAT_SPEED , 0),
    };
    vector <Darts> dartsLevel11;
    vector <vector<char>> mapLevel11 = map11;
    vector <Puffer> puffersLevel11 = {
        Puffer(graphic.pufferTexture, TILE_SIZE * 9, TILE_SIZE * 2),
        Puffer(graphic.pufferTexture, TILE_SIZE * 7, TILE_SIZE * (H-7)),
    };
    vector <Teleporters> teleportersLevel11;
    GameMode1Level level11(playerLevel11, batsLevel11, dartsLevel11, puffersLevel11, teleportersLevel11, mapLevel11);
    levels.push_back(level11);

    Player playerLevel12(graphic.playerTexture, TILE_SIZE * 6, TILE_SIZE * (H-2));
    vector <Bats> batsLevel12 = {
        Bats (graphic.batTexture, TILE_SIZE * 6, TILE_SIZE * 4, 0, BAT_SPEED),
        Bats (graphic.batTexture, TILE_SIZE * 7, TILE_SIZE * 4, 0, BAT_SPEED),
    };
    vector <Darts> dartsLevel12 = {
        Darts (graphic.dartTexture, TILE_SIZE * 10, TILE_SIZE * (H-3), 1),
        Darts (graphic.dartTexture, TILE_SIZE * (W-10), TILE_SIZE * 6, 1),
        Darts (graphic.dartTexture, TILE_SIZE * (W-12), TILE_SIZE * 4, 2),
        Darts (graphic.dartTexture, TILE_SIZE * 11, TILE_SIZE * (H-9), 3),
        Darts (graphic.dartTexture, TILE_SIZE * 12, TILE_SIZE * (H-9), 3),
        Darts (graphic.dartTexture, TILE_SIZE * 13, TILE_SIZE * (H-9), 3),
        Darts (graphic.dartTexture, TILE_SIZE * 14, TILE_SIZE * (H-9), 3),
        Darts (graphic.dartTexture, TILE_SIZE * (W-6), TILE_SIZE * (H-11), 3),
        Darts (graphic.dartTexture, TILE_SIZE * 13, TILE_SIZE * 6, 3),
        Darts (graphic.dartTexture, TILE_SIZE * 11, TILE_SIZE * 10, 4),
        Darts (graphic.dartTexture, TILE_SIZE * 12, TILE_SIZE * 10, 4),
        Darts (graphic.dartTexture, TILE_SIZE * 13, TILE_SIZE * 10, 4),
        Darts (graphic.dartTexture, TILE_SIZE * 14, TILE_SIZE * 10, 4),
        Darts (graphic.dartTexture, TILE_SIZE * 15, TILE_SIZE * 4, 4),
    };
    vector <vector<char>> mapLevel12 = map12;
    vector <Puffer> puffersLevel12;
    vector <Teleporters> teleportersLevel12;
    GameMode1Level level12(playerLevel12, batsLevel12, dartsLevel12, puffersLevel12, teleportersLevel12, mapLevel12);
    levels.push_back(level12);
}

GameMode1Level GameMode1Level::getCurrentLevel(int levelIndex) {
    if (levelIndex >= 1 && levelIndex <= static_cast<int>(levels.size())) {
       return levels[levelIndex-1];
   }
   return levels[0];
}


//mode2
GameMode2Level::GameMode2Level(vector<vector<char>> m, Player c) :
    map(m), player(c) {}

const Player& GameMode2Level::getPlayer() {
    return player;
}

const vector<vector<char>>& GameMode2Level::getMap() {
    return map;
}

void GameMode2Level::createLevels (vector <GameMode2Level>& levelss) {
    vector <vector<char>> mapLevel1 = map1mode2;
    Player playerLevel1 (graphic.playerTexture, TILE_SIZE * 7, TILE_SIZE * (mapLevel1.size()-5));
    GameMode2Level level1(mapLevel1, playerLevel1);
    levelss.push_back(level1);

    vector <vector<char>> mapLevel2 = map2mode2;
    Player playerLevel2 (graphic.playerTexture, TILE_SIZE * 12, TILE_SIZE * (mapLevel2.size()-9));
    GameMode2Level level2(mapLevel2, playerLevel2);
    levelss.push_back(level2);

    vector <vector<char>> mapLevel3 = map3mode2;
    Player playerLevel3 (graphic.playerTexture, TILE_SIZE * 3, TILE_SIZE * (mapLevel3.size()-13));
    GameMode2Level level3(mapLevel3, playerLevel3);
    levelss.push_back(level3);

    vector <vector<char>> mapLevel4 = map4mode2;
    Player playerLevel4 (graphic.playerTexture, TILE_SIZE * 12, TILE_SIZE * (mapLevel4.size()-9));
    GameMode2Level level4(mapLevel4, playerLevel4);
    levelss.push_back(level4);
}

