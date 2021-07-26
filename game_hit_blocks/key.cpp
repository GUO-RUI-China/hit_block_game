#include<stdio.h>
#include<conio.h>

int keycheck(){
	int ch;
	if (_kbhit()){
		ch = _getch();
		switch (ch){
		case 75:
		case 97:
			return 2;
			break;
		case 77:
		case 100:
			return 1;
			break;
		}
	}
}