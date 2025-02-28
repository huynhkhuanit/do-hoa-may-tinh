#define _CRT_SECURE_NO_WARNINGS
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

bool isTriangle(vector<pair<int, int>>& points) {
    if (points.size() != 3) return false;

    int x1 = points[0].first, y1 = points[0].second;
    int x2 = points[1].first, y2 = points[1].second;
    int x3 = points[2].first, y3 = points[2].second;

    float AB = pow(x2 - x1, 2) + pow(y2 - y1, 2);
    float BC = pow(x3 - x2, 2) + pow(y3 - y2, 2);
    float CA = pow(x1 - x3, 2) + pow(y1 - y3, 2);

    if (sqrt(AB) + sqrt(BC) <= sqrt(CA) || sqrt(AB) + sqrt(CA) <= sqrt(BC) || sqrt(BC) + sqrt(CA) <= sqrt(AB)) {
        return false;
    }

    string TriangleType = "";
    if (AB == BC && BC == CA)
    {
        TriangleType = "Tam Giac Deu";
    } else if (AB == BC || BC == CA || CA == AB) {
        TriangleType = "Tam giac can";
    } else if (AB + BC == CA || AB + CA == BC || BC + CA == AB) {
        TriangleType = "Tam giac vuong";
    } else {
        TriangleType = "Tam giac thuong";
    }
    
    char text[100];
    strcpy(text, TriangleType.c_str());
    outtextxy(10, 10, text);

    return true;
}

void drawTriangle() {
    // Nhap dinh
    int n; cout << "Nhap so dinh cua da giac (n >= 3): "; cin >> n;
    if (n != 3) {
        cout << "Chi ho tro kiem tra tam giac (n = 3).";
        return;
    }

    vector<pair<int, int>> points(n);

    // Nhap cac dinh x, y
    for (int i = 0; i < n; i++) {
        cout << "Nhap toa do dinh thu " << i + 1 << " (x, y): ";
        cin >> points[i].first >> points[i].second;
    }

    // Kiem tra tam giac
    if (!isTriangle(points)) {
        cout << "Day khong phai la tam giac.\n";
        char text[100] = "Day khong phai la tam giac";
        outtextxy(10, 10, text);
        return;
    }

    // Ve tam giac
    for (int i = 0; i < n; i++) {
        int x1 = points[i].first;
        int y1 = points[i].second;
        int x2 = points[(i + 1) % n].first;
        int y2 = points[(i + 1) % n].second;
        DDA(x1, y1, x2, y2);
    }
}

void drawTriangleForLoop() {
    int n;

    while (true) {
        cout << "Nhap so dinh cua da giac (n >= 3): ";
        cin >> n;

        if (n != 3) {
            cout << "Chi ho tro kiem tra tam giac (n = 3).\n";
            continue;
        }

        vector<pair<int, int>> points(n);

        for (int i = 0; i < n; i++) {
            cout << "Nhap toa do dinh thu " << i + 1 << " (x, y): ";
            cin >> points[i].first >> points[i].second;
        }

        if (!isTriangle(points)) {
            cout << "Day khong phai la tam giac. Vui long nhap lai.\n";
            char text[100] = "Day khong phai la tam giac";
            outtextxy(10, 10, text);
            cleardevice();
            continue;
        }

        cout << "Day la tam giac hop le.\n";
        char text[100] = "Day la tam giac hop le";
        outtextxy(10, 10, text);
        cleardevice();

        for (int i = 0; i < n; i++) {
            int x1 = points[i].first;
            int y1 = points[i].second;
            int x2 = points[(i + 1) % n].first;
            int y2 = points[(i + 1) % n].second;
            DDA(x1, y1, x2, y2);
        }
        break;
    }
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

    drawTriangle();

    getch();
    closegraph();

    return 0;
}