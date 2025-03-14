#include <iostream>
#include <cmath>
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
using namespace std;

struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(int X, int Y) : x(X), y(Y) {}
};

class Square {
private:
    Point vertices[4]; // A, B, C, D
public:
    Square(int x1, int y1, int x2, int y2) {
        vertices[0] = Point(x1, y1); // A
        vertices[1] = Point(x2, y2); // B
    }

    void drawEdge(int from, int to, int color) {
        setcolor(color);
        line(vertices[from].x, vertices[from].y, vertices[to].x, vertices[to].y);
    }

    /*
        vertices[targetIndex].x = vertices[from].x + dx;
        vertices[targetIndex].y = vertices[from].y + dy;


        vertices[2].x = vertices[1].x + dx;
        vertices[2].x = vertices[1].100 + 100;

        vertices[2].y = vertices[1].y + -dy;
        vertices[2].y = vertices[1].100 + -100;
    */

    void translateEdge(int from, int to, int dx, int dy, int targetIndex) {
        vertices[targetIndex].x = vertices[from].x + dx;
        vertices[targetIndex].y = vertices[from].y + dy;
    }

    double calculateDistance(int from, int to) {
        int dx = vertices[to].x - vertices[from].x;
        int dy = vertices[to].y - vertices[from].y;
        return sqrt(dx * dx + dy * dy);
    }

    bool isInWindow(int windowWidth, int windowHeight) {
        for (int i = 0; i < 4; i++) {
            if (vertices[i].x < 0 || vertices[i].x >= windowWidth ||
                vertices[i].y < 0 || vertices[i].y >= windowHeight) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int windowWidth = 1280, windowHeight = 720;
    initwindow(windowWidth, windowHeight, "Ve hinh vuong");

    int x1, y1, x2, y2;
    cout << "Nhap toa do diem A (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Nhap toa do diem B (x2, y2): ";
    cin >> x2 >> y2;

    if (x1 < 0 || x1 >= windowWidth || y1 < 0 || y1 >= windowHeight ||
        x2 < 0 || x2 >= windowWidth || y2 < 0 || y2 >= windowHeight) {
        cout << "Toa do diem A hoac B nam ngoai cua so do hoa!\n";
        closegraph();
        return 1;
    }

    Square square(x1, y1, x2, y2);

    if (square.calculateDistance(0, 1) == 0) {
        cout << "Diem A trung voi diem B!\n";
        closegraph();
        return 1;
    }

    // AB
    square.drawEdge(0, 1, YELLOW);
    delay(1000);

    // Tinh khoang cach
    int dx = x2 - x1; // 100
    int dy = y2 - y1; // 100

    // AB -> CD
    square.translateEdge(1, 2, -dy, dx, 2); // B + (0, 100) = 200, 200
    square.translateEdge(0, 3, -dy, dx, 3);
    square.drawEdge(2, 3, GREEN);
    delay(1000);

    square.drawEdge(0, 3, RED);
    delay(1000);

    square.drawEdge(1, 2, BLUE);

    if (!square.isInWindow(windowWidth, windowHeight)) {
        cout << "Hinh vuong nam ngoai cua so do hoa!\n";
        closegraph();
        return 1;
    }

    getch();
    closegraph();
    return 0;
}