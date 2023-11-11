#include <graphics.h>
#include <conio.h>
#include <cmath>

int main() {
    initgraph(800, 600);  // 初始化绘图窗口

    int centerX = 400;     // 球的中心坐标
    int centerY = 300;
    int radius = 50;       // 球的半径
    double angle = 0;      // 初始角度
    double angularSpeed = 1; // 自旋转的角速度

    while (!kbhit()) {
        cleardevice();  // 清空屏幕

        // 绘制球体，实现自旋转
        setfillcolor(RED);

        for (int i = 0; i < 360; i += 10) {
            double x = centerX + radius * cos((angle + i) * 3.1415926 / 180);
            double y = centerY + radius * sin((angle + i) * 3.1415926 / 180);
            solidcircle(int(x), int(y), 5);
        }

        angle += angularSpeed;  // 每次循环增加一定的角度，实现自旋转效果

        Sleep(60);  // 控制帧率
    }

    closegraph();  // 关闭绘图窗口

    return 0;
}
