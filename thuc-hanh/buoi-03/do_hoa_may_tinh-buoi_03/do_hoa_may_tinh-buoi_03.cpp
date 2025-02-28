#include <bits/stdc++.h>
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
using namespace std;

void DDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;

    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    }
    else {
        steps = abs(dy);
    }

    float Xincrement = dx / (float)steps;
    float Yincrement = dy / (float)steps;

    float X = x1;
    float Y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(X), round(Y), WHITE);
        X += Xincrement;
        Y += Yincrement;
    }
}

bool arePointsCollinear(vector<pair<int, int>>& points) {
    if (points.size() < 3) return false;
    int x1 = points[0].first, y1 = points[0].second;
    int x2 = points[1].first, y2 = points[1].second;

    for (int i = 2; i < points.size(); i++) {
        int x3 = points[i].first, y3 = points[i].second;

        int area = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);

        if (area != 0) return false;
    }

    return true; // Thang hang
}

void drawPolygon() {
    int n; cout << "Nhap so dinh cua da giac (n >= 3): "; cin >> n;
    if (n < 3) {
        cout << "Da giac phai co it nhat 3 dinh!";
        return;
    }

    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; i++) {
        cout << "Nhap toa do dinh thu " << i + 1 << " (x, y): ";
        cin >> points[i].first >> points[i].second;
    }

    if (arePointsCollinear(points)) {
        cout << "Tat ca cac diem nam tren mot duong thang. Day khong phai la da giac hop le.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        int x1 = points[i].first;
        int y1 = points[i].second;
        int x2 = points[(i + 1) % n].first; 
        int y2 = points[(i + 1) % n].second;
        DDA(x1, y1, x2, y2);
    }
}

int main() {
    int screenWidth = 640, screenHeight = 480;
    initwindow(screenWidth, screenHeight);

    drawPolygon();

    getch();
    closegraph();

    return 0;
}