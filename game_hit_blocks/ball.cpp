#include "main.h"
#include "ball.h"
#include "block.h"
#include "board.h"
#include <graphics.h>

struct ball{
	int x;
	int y;
	int r;
	COLORREF color;
	int x_move, y_move; //x方向为正就是往右，y方向为正就是往下;
}balls;

int getBallX(){
	return balls.x;
}

int getBallY(){
	return balls.y;
}

int getBallR(){
	return balls.r;
}

void setBallX_move(int x_move){
	balls.x_move = x_move;
}

void setBallY_move(int y_move){
	balls.y_move = y_move;
}

void initBall(){
	balls.r = BALL_R;
	balls.y = WINDOW_H - BOARD_H - BALL_R;
	balls.x = 0.5 * WINDOW_W;
	balls.color = WHITE;
	balls.x_move = MOVE_SPACE;
	balls.y_move = -MOVE_SPACE;
}

void drawBall(){
	setlinecolor(WHITE);
	setfillcolor(balls.color);
	fillcircle(balls.x, balls.y, balls.r);
}

void moveBall(){
	balls.x += balls.x_move;
	balls.y += balls.y_move;
	Sleep(MOVE_TIME);
}

//碰撞检测
void ballCheck(){
	if (balls.x >= WINDOW_W - balls.r){
		balls.x_move = -MOVE_SPACE;  //右边撞到，x变小
	}
	if (balls.x <= balls.r){
		balls.x_move = MOVE_SPACE;	//左边撞到，x变大
	}
	if (balls.y <= balls.r){
		balls.y_move = MOVE_SPACE;	//下边撞到，y变小
	}
	
	if (balls.y >= WINDOW_H - BOARD_H){
		if (balls.x > getBoardX() && balls.x <= (getBoardX() + BOARD_W)){
			balls.y_move = -MOVE_SPACE;
		}
	}
	
	if (balls.y >= WINDOW_H - balls.r){
		setisOver(TRUE);
	}
	
}