#include <stdio.h>
#include <graphics.h>
#include "block.h"
#include "board.h"
#include "ball.h"
#include "key.h"
#include "windows.h"

/* https://blog.csdn.net/quanquanxiaobu/article/details/79598550 */

bool isOver;

bool setisOver(bool isOver_new){
	isOver = isOver_new;
	return isOver;
}

int  main(){
	//初始化窗口界面
	initgraph(WINDOW_W, WINDOW_H, SHOWCONSOLE);
	initBlock();
	initBoard();
	initBall();
	isOver = FALSE;
	while (!isOver){
		BeginBatchDraw();//防止闪烁 在绘图/贴图之前(缓存)
		
		cleardevice();//清屏，防止出现之前的轨迹
		drawAllBlock();
		drawBoard();
		drawBall();
		hitblockCheck();
		ballCheck();
		moveBall();
		moveBoard();
		EndBatchDraw();//防止闪烁 在绘图/贴图之后

	}
	//outtextxy(WINDOW_W / 2 - 10, WINDOW_H / 2 -10, "游戏结束");
	printf("游戏结束");
	Sleep(10 * 1000);
	return 0;
}