//ʹ�ú궨���Ż�����Ŀɶ���
#define BLOCK_W 40
#define BLOCK_H 20  //ש���������С��

#define BLOCK_ROW_NUMBER 10
#define BLOCK_LINE_NUMBER 20 //ש��ĸ��������������У�

#define WINDOW_W BLOCK_W * BLOCK_ROW_NUMBER  //���ڵĺ᳤
#define WINDOW_H_R 400 //���ڵ�ʣ�೤��
#define WINDOW_H BLOCK_H * BLOCK_LINE_NUMBER + WINDOW_H_R //���ڵ��ݳ�

void drawBlock(int x_num, int y_num);
void drawAllBlock();
void initBlock();
void hitblockCheck();