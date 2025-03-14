#include <iostream>
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
    Point vertices[4];
public:
    Square(int x1, int y1, int size) {
        vertices[0] = Point(x1, y1); // Ve dinh A
        vertices[1] = Point(x1 + size, y1); // Ve dinh B
        vertices[2] = Point(x1 + size, y1 + size); // Ve dinh C
        vertices[3] = Point(x1, y1 + size); // Ve dinh D
    }

    // Ve canh tu form -> to (A to B)
    void drawEdge(int from, int to, int color) {
        setcolor(color);
        line(vertices[from].x, vertices[from].y, vertices[to].x, vertices[to].y);
    }

    /*
        vertices[0].x = vertices[3].x + dx = vertices[A].x  = vertices[D].x + dx
        vertices[0].x = vertices[3].x + dx = vertices[A].x  = vertices[D].0 + 150
        vertices[0].y = vertices[3].y + dy = vertices[A].150  = vertices[D].150 + 150
    */
    void translateEdge(int from, int to, int dx, int dy) {
        vertices[to].x = vertices[from].x + dx;
        vertices[to].y = vertices[from].y + dy;
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
    int windowWidth = 640, windowHeight = 480;
    initwindow(windowWidth, windowHeight, "Ve hinh vuong voi tinh tien");

    int x1, y1, size;
    cout << "Nhap toa do diem A (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Nhap do dai canh hinh vuong: ";
    cin >> size;

    if (x1 < 0 || x1 >= windowWidth || y1 < 0 || y1 >= windowHeight) {
        cout << "Toa do diem A nam ngoai cua so do hoa!\n";
        closegraph();
        return 1;
    }

    if (size <= 0) {
        cout << "Do dai canh phai lon hon 0!\n";
        closegraph();
        return 1;
    }

    Square square(x1, y1, size);

    if (!square.isInWindow(windowWidth, windowHeight)) {
        cout << "Hinh vuong nam ngoai cua so do hoa!\n";
        closegraph();
        return 1;
    }

    // Ve A B
    square.drawEdge(0, 1, YELLOW);
    delay(1000);

    // Ve A D
    square.translateEdge(0, 3, 0, size);
    square.drawEdge(0, 3, GREEN);
    delay(1000);

    // Ve B C
    square.translateEdge(1, 2, 0, size);
    square.drawEdge(1, 2, RED);
    delay(1000);

    // Ve C D
    square.drawEdge(2, 3, BLUE);

    getch();
    closegraph();
    return 0;
}