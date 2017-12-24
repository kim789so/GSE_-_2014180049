#pragma once

#include <time.h>
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

#include"CObject.h"
#include "SceneMgr.h"

#define RECT_SIZE  4

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 800

#define LIFE_TIME 3000

#define RED_CHARACTER_TIME 5000
#define BLUE_CHARACTER_TIME  7000

#define CHARACTER_LIFE 100
#define CHARACTER_SPEED 100.0f
#define CHARACTER_SIZE 70

#define BUILDING_LIFE 500
#define BUILDING_SPEED 0.0f
#define BUILDING_SIZE 100

#define BULLET_CREATE_TIME 5000
#define BULLET_LIFE 15
#define BULLET_SPEED 300.0f
#define BULLET_SIZE 4

#define ARROW_CREATE_TIME 3000
#define ARROW_LIFE 10
#define ARROW_SPEED 200.0f
#define ARROW_SIZE 4

#define SHIELD_ACTIVE_TIME 5000
#define SHILED_DURATION_TIME 2000
#define SHILED_LIFE 30

#define ROCKET_CREATE_TIME 10000
#define ROCKET_LIFE 150
#define ROCKET_SPEED 300.0f
#define ROCKET_SIZE 50
#define ROCKET_AREA 100

const float LEVEL_GOD = 0.0f;
const float LEVEL_SKY = 0.1f;
const float LEVEL_GROUND = 0.2f;
const float LEVEL_UNDERGROUND = 0.3f;

#define MAX_CHARACTER_NUM 10
