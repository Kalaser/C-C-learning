#include <graphics.h>
#include <conio.h>
#include <cmath>

const double AU = 100.0;  // 天文单位（用于缩小尺度）
const double G = 6.67430e-11;  // 万有引力常数
const double SunMass = 1.989e30;  // 太阳质量

struct Planet {
    double semiMajorAxis;  // 长轴
    double eccentricity;   // 偏心率
    double angle;          // 角度
    double rotationAngle;  // 自转角度
    double radius;         // 半径
    COLORREF color;        // 颜色
    double mass;           // 质量
};

const int NumPlanets = 8;  // 包括冥王星
Planet planets[NumPlanets];

void InitializePlanets() {
    planets[0] = {0.0, 0.0, 0.0, 0.0, 20, YELLOW, SunMass};  // 太阳
    planets[1] = {0.1 * AU, 0.206, 0.0, 0.0, 4, RGB(255, 165, 0), 3.3011e23};  // 水星
    planets[2] = {0.2 * AU, 0.007, 0.0, 0.0, 8, RGB(255, 215, 0), 4.8675e24};  // 金星
    planets[3] = {0.3 * AU, 0.017, 0.0, 0.0, 9, RGB(0, 0, 255), 5.972e24};  // 地球
    planets[4] = {0.4 * AU, 0.094, 0.0, 0.0, 6, RGB(255, 0, 0), 6.4171e23};  // 火星
    planets[5] = {0.5 * AU, 0.049, 0.0, 0.0, 12, RGB(255, 69, 0), 1.8982e27};  // 木星
    planets[6] = {0.6 * AU, 0.248, 0.0, 0.0, 10, RGB(169, 169, 169), 5.683e26};  // 土星
    planets[7] = {0.7 * AU, 0.248, 0.0, 0.0, 5, RGB(192, 192, 192), 8.681e22};  // 冥王星
}

void DrawSolarSystem() {
    cleardevice();  // 清空屏幕

    for (int i = 0; i < NumPlanets; i++) {
        double x = getmaxx() / 2 + planets[i].semiMajorAxis * cos(planets[i].angle);
        double y = getmaxy() / 2 + planets[i].semiMajorAxis * sin(planets[i].angle);
        setfillcolor(planets[i].color);
        fillcircle(x, y, planets[i].radius);
        planets[i].angle += 0.01;  // 模拟公转

        // 自转
        setfillcolor(BLACK);
        fillcircle(x, y, planets[i].radius / 2);
        setlinecolor(BLACK);
        line(x, y, x + planets[i].radius / 2 * cos(planets[i].rotationAngle), y + planets[i].radius / 2 * sin(planets[i].rotationAngle));
        planets[i].rotationAngle += 0.05;  // 模拟自转
    }
}

double CalculateOrbitalPeriod(double semiMajorAxis, double mass) {
    // 根据开普勒第三定律计算轨道周期
    return 2 * M_PI * sqrt(pow(semiMajorAxis, 3) / (G * SunMass + mass));
}

int main() {
    initgraph(800, 600);  // 减小绘图窗口的大小

    InitializePlanets();
  int planetOrbitRadius[] = {10,20,30,40,50,60,70,80};
    for (int i = 1; i < NumPlanets; i++) {
        planets[i].semiMajorAxis = (i + 1) * AU * 0.2;  // 进一步减小轨道半长轴
        planets[i].eccentricity = 0.017;
        planets[i].rotationAngle = 0.0;
        planets[i].angle = i * 2 * M_PI / CalculateOrbitalPeriod(planets[i].semiMajorAxis, planets[i].mass);
    }
     for (int i = 0; i < NumPlanets; i++) {
        int left = getmaxx() / 2 - planetOrbitRadius[i];
        int top = getmaxy() / 2 - planetOrbitRadius[i];
        int right = getmaxx() / 2 + planetOrbitRadius[i];
        int bottom = getmaxy() / 2 + planetOrbitRadius[i];
        ellipse(left, top, right, bottom);
    }

    while (!kbhit()) {
        DrawSolarSystem();
        Sleep(20);
    }

    closegraph();
    return 0;
}
