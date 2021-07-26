#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include "block.h"
#include "ball.h"

struct block{
	//左上角坐标
	int x_pose;
	int y_pose;
	//宽高
	int width;
	int height;
	COLORREF color;
	bool exist;
};

block blocks[BLOCK_ROW_NUMBER][BLOCK_LINE_NUMBER] = { 0 };//生成砖块数组

//绘画一个砖块
void drawBlock(int x_num, int y_num){
	if (blocks[x_num][y_num].exist){
		setlinecolor(WHITE);
		setfillcolor(blocks[x_num][y_num].color);
		fillrectangle(blocks[x_num][y_num].x_pose, blocks[x_num][y_num].y_pose, blocks[x_num][y_num].x_pose + BLOCK_W, blocks[x_num][y_num].y_pose + BLOCK_H);
	}
}

//画所有砖块
void drawAllBlock(){
	int i = 0, j = 0;
	for (i = 0; i < BLOCK_ROW_NUMBER; i++){
		for (j = 0; j < BLOCK_LINE_NUMBER; j++){
			
			drawBlock(i, j);
		}
		j = 0;
	}
}

//初始化砖块函数
void initBlock(){
	int i = 0, j = 0;
	srand((unsigned int)time(0));//生成随机

	for (i = 0; i < BLOCK_ROW_NUMBER; i++){
		for (j = 0; j < BLOCK_LINE_NUMBER; j++){
			blocks[i][j].x_pose = i * BLOCK_W;
			blocks[i][j].y_pose = j * BLOCK_H;
			blocks[i][j].width = BLOCK_W;
			blocks[i][j].height = BLOCK_H;
			blocks[i][j].color = RGB(rand() % 256, rand() % 256, rand() % 256);//根据随机数调用不同颜色
			blocks[i][j].exist = TRUE;
		}
		j = 0;
	}
}

void hitblockCheck(){
	int i = 0, j = 0;
	for (i = 0; i < BLOCK_ROW_NUMBER; i++){
		for (j = 0; j < BLOCK_LINE_NUMBER; j++){
			if (blocks[i][j].exist){
				if (getBallX() >= blocks[i][j].x_pose &&
					getBallX() <= (blocks[i][j].x_pose + blocks[i][j].width) &&
					(blocks[i][j].y_pose + blocks[i][j].height + getBallR()>getBallY())){
					setBallY_move(MOVE_SPACE);
					blocks[i][j].exist = FALSE;//下边缘碰撞
				}
			}
		}
	}
}

