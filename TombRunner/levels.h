#ifndef LEVELS_H
#define LEVELS_H

#include <bits/stdc++.h>
#include "logics.h"
#include "defs.h"
#include "graphics.h"
using namespace std;

class GameMode1Level {
    Player player;
    vector <Bats> bats;
    vector <Darts> darts;
    vector <Puffer> puffers;
    vector <Teleporters> teleporters;
    vector <vector<char>> map;
public:
    GameMode1Level(Player c, const vector<Bats>& b, const vector<Darts>& d, const vector<Puffer>& p, const vector<Teleporters>& t, vector<vector<char>> m);
    const Player& getPlayer();
    const vector <Bats>& getBats();
    const vector <Darts>& getDarts();
    const vector <Puffer>& getPuffer();
    const vector <Teleporters>& getTeleporters();
    const vector<vector<char>>& getMap();

    GameMode1Level getCurrentLevel (int levelIndex);
    static void createLevels(vector <GameMode1Level>& levels);

};

class GameMode2Level {
    vector<vector<char>> map;
    Player player;

public:
    GameMode2Level (const vector<vector<char>> m, Player c);
    const Player& getPlayer();
    const vector<vector<char>>& getMap();

    GameMode2Level getCurrentLevel (int levelIndex);
    static void createLevels(vector<GameMode2Level>& levelss);
};
#endif


