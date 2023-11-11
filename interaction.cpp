#include <easyx.h>
#include <cmath>
#include<conio.h>
#define G 9.8
#define K 0.01
const double dt=0.1;
const double g = 9.8; // 重力加速度
struct ball
{
    double x ; // 初始位置
    double y ;
    double radius; //初始半径
    double vy; // 初始速度
    double vx;
    double m;  //小球的质量
    COLORREF color;//小球颜色
    double angle ;//小球角度
};
void wall()
{
        line(1,590,799,590);
        line(1,10,799,10);
        line(1,10,1,590);
        line(799,10,799,590);

}
int main()
{
    initgraph(800, 600);
    ball ball1;
    ball1.color=GREEN;
    ball1.m=0.9;
    ball1.x=430;
    ball1.y=120;
    ball1.radius=20;
    ball1.vx=5;
    ball1.vy=5;
    ball1.angle=0;

/*
    double x = 400; // 初始位置
    double y = 100;
    double vy = 0; // 初始速度
    const double g = 9.8; // 重力加速度
    double dt = 0.1; // 时间步长
    double vx=4;  //x轴方向的初速度
    double m=0.5;//小球的质量
*/
    while (!kbhit())
    {
        // 清除屏幕
        cleardevice();
        BeginBatchDraw();
        // 计算下一个时间步的位置
        ball1.y=ball1.y+ball1.vy*dt+0.5 * G * dt * dt;
        ball1.x=ball1.x+ball1.vx*dt;
        ball1.vy=ball1.vy*exp(-(0.01)*dt/ball1.m)+G * dt;
        ball1.vx=ball1.vx*exp(-(0.01)*dt/ball1.m);
        for (int i = 0; i < 360; i += 1) {
            double x = ball1.x + ball1.radius * cos((ball1.angle) * 3.1415926 / 180);
            double y = ball1.y + ball1.radius * sin((ball1.angle) * 3.1415926 / 180);
            setfillcolor(BLUE);
            solidcircle(int(x), int(y), 2);
        }
        ball1.angle+=atan(ball1.vy/ball1.vx);
        //y = y + vy * dt + 0.5 * g * dt * dt;
        //x=x+vx*dt;
        //vy = vy*exp(-(0.01*dt/m)) + g * dt;
        wall();
        if (ball1.x <=21 || ball1.x >=779)
        {
            ball1.vx = -ball1.vx; // 反弹
        }

        if (ball1.y >=570||ball1.y<=20)
        {
             // 防止小球下落过程中穿透底边界
            ball1.vy = -ball1.vy; // 反弹
        }
        // 绘制小球
        setfillcolor(ball1.color);
        solidcircle(ball1.x, ball1.y, ball1.radius);
        FlushBatchDraw();
        EndBatchDraw();

        // 延时
        Sleep(5);

    }

    closegraph();

    return 0;
}