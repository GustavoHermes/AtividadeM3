#include <iostream>
#include "raylib.h"
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define SPEED 250.0f
#define RADIUS 10.0f

void Colisao(Vector2 &pos, int &lastPosY, int&lastPosX, Rectangle player){
  if(pos.x < RADIUS){
    pos.x=RADIUS;
    lastPosX=RIGHT;
  }
  if(pos.x > SCREEN_WIDTH-RADIUS){
    pos.x=SCREEN_WIDTH-RADIUS;
    lastPosX=LEFT;
  }
  if(pos.y < RADIUS){
    pos.y=RADIUS;
    lastPosY=DOWN;
  }
  if(pos.y > SCREEN_HEIGHT-RADIUS){
    pos.y=SCREEN_HEIGHT-RADIUS;
    lastPosY=UP;
  }
  if(CheckCollisionCircleRec(pos, RADIUS, player)){
    if(lastPosY==UP){
        lastPosY=DOWN;
    }
    if(lastPosY==DOWN){
        lastPosY=UP;
    }
  }
}

void MovimentacaoBola(Vector2 &pos, const int lastPosY, const int lastPosX, const float dt){
  /*switch(lastPos){
    case UP:{
      pos.y -= SPEED * dt;
      break;
    }
    case DOWN:{
      pos.y += SPEED * dt;
      break;
    }
    case LEFT:{
      pos.x -= SPEED * dt;
      break;
    }
    case RIGHT:{
      pos.x += SPEED * dt;
      break;
    }
  }*/
 if(lastPosY==UP){
    pos.y -= SPEED * dt;
 }
 if(lastPosY==DOWN){
    pos.y += SPEED * dt;
 }
 if(lastPosX==LEFT){
    pos.x -= SPEED * dt;
 }
 if(lastPosX==RIGHT){
    pos.x += SPEED * dt;
 }
}

int main(){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Arkanoid");
    SetTargetFPS(60);

    Vector2 posBall = {SCREEN_WIDTH/2.0f , SCREEN_HEIGHT/2.0f};
    int lastPosY = DOWN;
    int lastPosX = RIGHT;
    Rectangle player = {SCREEN_WIDTH/2.0f-50.0f, 600.0f, 100, 30};

    while(!WindowShouldClose()){
    float dt = GetFrameTime();

    if(IsKeyDown(KEY_LEFT)||IsKeyDown(KEY_A)){
      player.x -= SPEED * dt;
    }
    if(IsKeyDown(KEY_RIGHT)||IsKeyDown(KEY_D)){
      player.x += SPEED * dt;
    }
    
    MovimentacaoBola(posBall, lastPosY, lastPosX, dt);
    Colisao(posBall, lastPosY, lastPosX, player);
    BeginDrawing();
    ClearBackground(BLACK);
    DrawCircle(posBall.x, posBall.y, RADIUS, WHITE);
    DrawRectangle(player.x, player.y, 100, 30, RED);
    DrawFPS(SCREEN_WIDTH - 90, 10);
    EndDrawing();
    }
CloseWindow();
return 0;
}