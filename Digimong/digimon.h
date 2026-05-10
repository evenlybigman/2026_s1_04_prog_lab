#ifndef DIGIMON_H
#define DIGIMON_H

#define MAX_DIGIMON_SIZE 100
#define TICK_INTERVAL 0.1
#define SPRITE_W 32
#define SPRITE_H 16

typedef struct {
    int pixels[SPRITE_H][SPRITE_W];  // 0 = 배경, 1~n = 색상
} Sprite;

typedef enum {
    EGG, // 0 - 알
    BABY1, // 1 - 유년기1
    BABY2, // 2 - 유년기2
    ROOKIE, // 3 - 성장기
    CHAMPION, // 4 - 성숙기
    ULTIMATE, // 5 - 완전체
    MEGA // 6 - 궁극체
} Level;

typedef struct {
    char name[100];
    Level level;
    int weight;
    int hungry;
    int happy;
    int fatigue;
    int strength;
    int effort;
    int battles;
    int type;
    int dp;
    int atk;
}Digimon;

typedef struct {
    char name[100];
    Level max_level;
    int cleared;
}DigimonEntry;

typedef struct {
    char name[5];
    int battles;
}Tamer;

typedef struct {
    Tamer tamer;
    Digimon current;
    DigimonEntry dex[MAX_DIGIMON_SIZE];
    int game_time;
} GameData;

#endif