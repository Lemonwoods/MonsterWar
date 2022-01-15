#pragma once

//关于方向的定义
#define STOP 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

//关于方块的定义
#define BRICK 1
#define ICE 2
#define JELLY 3
#define SPIKEROCK 4

#define CUBE_WIDTH 70
#define CUBE_HEIGHT 70
#define CUBE_REDIUS 35

#define REAL_WIDTH 60
#define REAL_HEIGHT 60 

#define	CUBE_ACOUNT 200

//文件读取中mode的含义
#define MONSTER 5
#define PLAYER 6
#define END 7
#define FILE_CODE 20010414

//游戏打开模式
#define MAP_ARCHIVE 1
#define DEFAULT_MAP 2

//关于玩家的相关信息定义
#define PLAYER_SPEED 6
#define PLAYER_HP 100
#define PLAYER_ARMOR 0

//关于怪物的相关信息的定义
#define MONSTER_SPEED 1
#define MONSTER_ATTACK 20
#define MONSTER_HP 70

//关于子弹的相关信息的定义
#define BULLET_SPEED 20
#define BULLET_ATTACK 35

//关于道具的定义
#define NORMAL 0
#define	MEDICINE 1
#define ACCELERATOR 2
#define FROZEN 3
#define BOMB 4

//关于道具效果的定于
#define PROP_INTERVAL 10
#define MEDICINE_EFFECT 20
#define MEDICINE_DURATION 1
#define ACCELERATOR_EFFECT 10
#define ACCELERATOR_DURATION 3
#define FROZEN_DURATION 3
#define FROZEN_EFFECT 1
#define BOMB_MAX_REDIUS 100
#define BOMB_DURATION 2

//子弹的类型
#define BULLET_BOUNCE 5
#define BULLET_NORMAL 1
#define BULLET_FROZEN 3
#define BULLET_BOMB 4

//怪物的状态
#define MONSTER_NORMAL 1
#define MONSTER_FROZEN 3

//关于地图大小的定义
#define MAP_LEFT 480
#define MAP_TOP 129
#define MAP_RIGHT 1441
#define MAP_BUTTOM 949

//游戏结束状态
#define LOSE 1
#define WIN 2