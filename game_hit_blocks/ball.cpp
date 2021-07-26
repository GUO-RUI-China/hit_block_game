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
	int x_move, y_move; //x����Ϊ���������ң�y����Ϊ����������;
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

//��ײ���
void ballCheck(){
	if (balls.x >= WINDOW_W - balls.r){
		balls.x_move = -MOVE_SPACE;  //�ұ�ײ����x��С
	}
	if (balls.x <= balls.r){
		balls.x_move = MOVE_SPACE;	//���ײ����x���
	}
	if (balls.y <= balls.r){
		balls.y_move = MOVE_SPACE;	//�±�ײ����y��С
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