#include <graphics.h>
#include <conio.h>
#include <cmath>

int main() {
    initgraph(800, 600);  // 初始化绘图窗口

    int centerX = 400;     // 球体的中心坐标
    int centerY = 300;
    int radius = 50;       // 球体的半径
    int angle = 0;         // 初始角度

    while (!kbhit()) {
        cleardevice();  // 清空屏幕

        // 计算球体的新位置
        int newX = centerX + int(radius * cos(angle * 3.1415926 / 180));
        int newY = centerY + int(radius * sin(angle * 3.1415926 / 180));

        // 绘制球体
        setfillcolor(RED);
        solidcircle(newX, newY, radius);

        angle += 5;  // 每次循环增加一定的角度，实现旋转效果

        Sleep(60);  // 控制帧率

        // 如果角度大于360度，重置为0
        if (angle >= 360) {
            angle = 0;
        }
    }

    closegraph();  // 关闭绘图窗口

    return 0;
}
