#define BALL_R 5
#define MOVE_SPACE 2 //�ƶ�����
#define MOVE_TIME 10 //ÿ�����ƶ�ͣ�ٵ�ʱ��

void initBall();
void drawBall();
void moveBall();
void ballCheck();

int getBallX();
int getBallY();
int getBallR();

void setBallX_move(int x_move);
void setBallY_move(int y_move);