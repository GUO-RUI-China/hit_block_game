#define BALL_R 5
#define MOVE_SPACE 2 //移动像素
#define MOVE_TIME 10 //每次球移动停顿的时间

void initBall();
void drawBall();
void moveBall();
void ballCheck();

int getBallX();
int getBallY();
int getBallR();

void setBallX_move(int x_move);
void setBallY_move(int y_move);