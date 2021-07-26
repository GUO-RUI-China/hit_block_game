//使用宏定义优化代码的可读性
#define BLOCK_W 40
#define BLOCK_H 20  //砖块参数（大小）

#define BLOCK_ROW_NUMBER 10
#define BLOCK_LINE_NUMBER 20 //砖块的个数参数（行与列）

#define WINDOW_W BLOCK_W * BLOCK_ROW_NUMBER  //窗口的横长
#define WINDOW_H_R 400 //窗口的剩余长度
#define WINDOW_H BLOCK_H * BLOCK_LINE_NUMBER + WINDOW_H_R //窗口的纵长

void drawBlock(int x_num, int y_num);
void drawAllBlock();
void initBlock();
void hitblockCheck();