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
	//��ʼ�����ڽ���
	initgraph(WINDOW_W, WINDOW_H, SHOWCONSOLE);
	initBlock();
	initBoard();
	initBall();
	isOver = FALSE;
	while (!isOver){
		BeginBatchDraw();//��ֹ��˸ �ڻ�ͼ/��ͼ֮ǰ(����)
		
		cleardevice();//��������ֹ����֮ǰ�Ĺ켣
		drawAllBlock();
		drawBoard();
		drawBall();
		hitblockCheck();
		ballCheck();
		moveBall();
		moveBoard();
		EndBatchDraw();//��ֹ��˸ �ڻ�ͼ/��ͼ֮��

	}
	//outtextxy(WINDOW_W / 2 - 10, WINDOW_H / 2 -10, "��Ϸ����");
	printf("��Ϸ����");
	Sleep(10 * 1000);
	return 0;
}