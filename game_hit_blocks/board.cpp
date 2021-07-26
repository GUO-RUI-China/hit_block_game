#include "board.h"
#include "block.h"
#include "key.h"
#include <graphics.h>

struct board
{
	int x_pose;
	int y_pose;
	int board_w;
	int board_h;
	COLORREF color;
}board_user;

void initBoard(){
	board_user.board_h = BOARD_H;
	board_user.board_w = BOARD_W;
	board_user.x_pose = 0.5 * WINDOW_W - 0.5 * BOARD_W;
	board_user.y_pose = WINDOW_H - BOARD_H;
	board_user.color = WHITE;
}

void drawBoard(){
	setlinecolor(WHITE);
	setfillcolor(board_user.color);
	fillrectangle(board_user.x_pose, board_user.y_pose, board_user.x_pose+board_user.board_w, board_user.y_pose+board_user.board_h);
}

char checkBoard(){
	if (board_user.x_pose >= 0){
		if (board_user.x_pose <= WINDOW_W - BOARD_W){
			return	TRUE;
		}
		else{
			return FALSE;
		}
	}
	else{
		return FALSE;
	}
	
}

void moveBoard(){
	int order = keycheck();
	if (order == 2){
		if (checkBoard()){
			board_user.x_pose -= BOARD_MOVE;//板子左移
		}
		else{
			board_user.x_pose += (2 * BOARD_MOVE);//防止板子被锁死以及超界
		}
	}
	if (order == 1){
		if (checkBoard()){
			board_user.x_pose += BOARD_MOVE;//板子左移
		}
		else{
			board_user.x_pose -= (2 * BOARD_MOVE);//防止板子被锁死以及超界
		}
	}
}

int getBoardX(){
	return board_user.x_pose;
}

int getBoardY(){
	return board_user.y_pose;
}

