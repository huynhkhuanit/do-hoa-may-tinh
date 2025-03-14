#include <iostream>
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
using namespace std;

struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(int X, int Y) : x(X), y(Y) {}
};

void drawSquareAnimated(Point center, int size, int color) {
    int halfSize = size / 2;
    int left = center.x - halfSize;
    int right = center.x + halfSize;
    int top = center.y - halfSize;
    int bottom = center.y + halfSize;

    setcolor(color);

    for (int i = 0; i <= halfSize; i += 2) {
        line(left, top, left + i * 2, top);
        delay(10);
    }
    for (int i = 0; i <= halfSize; i += 2) {
        line(right, top, right, top + i * 2);
        delay(10);
    }
    for (int i = 0; i <= halfSize; i += 2) {
        line(right, bottom, right - i * 2, bottom);
        delay(10);
    }
    for (int i = 0; i <= halfSize; i += 2) {
        line(left, bottom, left, bottom - i * 2);
        delay(10);
    }
}

void scaleSquareAnimated(Point center, int initialSize, int scaleFactor) {
    int finalSize = initialSize * scaleFactor;
    int steps = 30;
    float stepScale = (float)(scaleFactor - 1) / steps;

    int halfSize = initialSize / 2;
    Point topLeft(center.x - halfSize, center.y - halfSize);
    Point topRight(center.x + halfSize, center.y - halfSize);
    Point bottomRight(center.x + halfSize, center.y + halfSize);
    Point bottomLeft(center.x - halfSize, center.y + halfSize);

    float currentScale = 1.0;

    for (int i = 0; i <= steps; i++) {
        cleardevice();

        int dx = (int)((center.x - topLeft.x) * currentScale);
        int dy = (int)((center.y - topLeft.y) * currentScale);

        Point newTopLeft(center.x - dx, center.y - dy);
        Point newTopRight(center.x + dx, center.y - dy);
        Point newBottomRight(center.x + dx, center.y + dy);
        Point newBottomLeft(center.x - dx, center.y + dy);

        setcolor(GREEN);
        line(newTopLeft.x, newTopLeft.y, newTopRight.x, newTopRight.y);
        line(newTopRight.x, newTopRight.y, newBottomRight.x, newBottomRight.y);
        line(newBottomRight.x, newBottomRight.y, newBottomLeft.x, newBottomLeft.y);
        line(newBottomLeft.x, newBottomLeft.y, newTopLeft.x, newTopLeft.y);

        delay(50);
        currentScale += stepScale;
    }
}

int main() {
    initwindow(640, 480, "Square Animation");

    Point center(320, 240);
    int initialSize;
    int scaleFactor;

    cout << "Nhap do dai canh ban dau cua hinh vuong: ";
    cin >> initialSize;
    cout << "Nhap he so scale (n): ";
    cin >> scaleFactor;

    drawSquareAnimated(center, initialSize, YELLOW);

    delay(2000);

    scaleSquareAnimated(center, initialSize, scaleFactor);

    getch();
    closegraph();

    return 0;
}