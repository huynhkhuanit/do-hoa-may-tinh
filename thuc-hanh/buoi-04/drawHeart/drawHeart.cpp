#include <bits/stdc++.h>
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
#define M_PI 3.14159265358979323846
using namespace std;

void drawStar(int cx, int cy, int R, int r) {
    vector<pair<int, int>> points(10);

    float angle = -M_PI / 2;
    float step = M_PI / 5;

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            points[i].first = cx + R * cos(angle);
            points[i].second = cy + R * sin(angle);
        }
        else {
            points[i].first = cx + r * cos(angle);
            points[i].second = cy + r * sin(angle);
        }
        angle += step;
    }

    for (int i = 0; i < 10; i++) {
        int x1 = points[i].first;
        int y1 = points[i].second;
        int x2 = points[(i + 1) % 10].first;
        int y2 = points[(i + 1) % 10].second;
        line(x1, y1, x2, y2);
    }
}

void drawHeart(int cx, int cy, int size) {
    float x, y;

    for (float t = 0; t <= 2 * M_PI; t += 0.001) {
        x = size * 16 * pow(sin(t), 3);
        y = -size * (13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t));
        putpixel(cx + x, cy + y, RED);
    }

    int centerX = cx;
    int centerY = cy - size * 5;

    char centerText[100] = "Rat xinh dep tuyet voi";
    outtextxy(centerX / 1.25, centerY * 1.25, centerText);
}


int main() {
    int screenWidth = 640, screenHeight = 480;
    initwindow(screenWidth, screenHeight);

    int cx = 320, cy = 240;
    int size = 10;

    drawHeart(cx, cy, size);

    getch();
    closegraph();

    return 0;
}

