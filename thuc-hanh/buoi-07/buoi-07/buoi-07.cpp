#include <iostream>
#include <string>
#include <algorithm>
#include "graphics.h"
#pragma comment(lib, "graphics.lib")

struct Point {
    int x;
    int y;

    Point() : x(0), y(0) {}
    Point(int X, int Y) : x(X), y(Y) {}
};

class DuongThang {
private:
    Point p[2];
public:
    DuongThang() {
        p[0] = Point(0, 0);
        p[1] = Point(0, 0);
    }

    DuongThang(int x1, int y1, int x2, int y2) {
        p[0] = Point(x1, y1);
        p[1] = Point(x2, y2);
    }

    Point getPoint(int index) { return p[index]; }
    void setPoint(int index, int x, int y) { p[index].x = x; p[index].y = y; }

    void drawLine() {
        line(p[0].x, p[0].y, p[1].x, p[1].y);
    }

    void translate(int dx, int dy) {
        p[0].x += dx;
        p[0].y += dy;
        p[1].x += dx;
        p[1].y += dy;
    }

    bool isValidLine() {
        return p[0].x != p[1].x || p[0].y != p[1].y;
    }
};

bool isInWindow(int x, int y, int windowWidth, int windowHeight) {
    return (x >= 0 && x <= windowWidth && y >= 0 && y <= windowHeight);
}

void drawLabel(const char* label, int x1, int y1, int x2, int y2) {
    int midX = (x1 + x2) / 2;
    int midY = (y1 + y2) / 2;
    outtextxy(midX + 20, midY + 20, (char*)label);
}

int main() {
    int windowWidth = 600, windowHeight = 800;
    initwindow(windowWidth, windowHeight, "Ve hinh binh hanh");

    int x1, y1, x2, y2;
    std::cout << "Nhap toa do diem A (x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Nhap toa do diem B (x2, y2): ";
    std::cin >> x2 >> y2;

    if (!isInWindow(x1, y1, windowWidth, windowHeight) || !isInWindow(x2, y2, windowWidth, windowHeight)) {
        std::cout << "Toa do A hoac B nam ngoai cua so do hoa! Vui long nhap lai.\n";
        closegraph();
        return 1;
    }

    DuongThang* AB = new DuongThang(x1, y1, x2, y2);

    if (!AB->isValidLine()) {
        std::cout << "Diem A trung voi diem B! Vui long nhap lai.\n";
        delete AB;
        closegraph();
        return 1;
    }

    int dx, dy;
    std::cout << "Nhap vector tinh tien (dx, dy): ";
    std::cin >> dx >> dy;

    // Kiểm tra vector tịnh tiến không phải (0, 0)
    if (dx == 0 && dy == 0) {
        std::cout << "Vector tinh tien khong duoc la (0, 0)! Vui long nhap lai.\n";
        delete AB;
        closegraph();
        return 1;
    }

    int maxX = (std::max)((std::max)(x1, x2), (std::max)(x1 + dx, x2 + dx));
    int maxY = (std::max)((std::max)(y1, y2), (std::max)(y1 + dy, y2 + dy));
    int minX = (std::min)((std::min)(x1, x2), (std::min)(x1 + dx, x2 + dx));
    int minY = (std::min)((std::min)(y1, y2), (std::min)(y1 + dy, y2 + dy));

    if (!isInWindow(minX, minY, windowWidth, windowHeight) || !isInWindow(maxX, maxY, windowWidth, windowHeight)) {
        std::cout << "Hinh binh hanh sau khi tinh tien se nam ngoai cua so do hoa! Vui long nhap lai.\n";
        delete AB;
        closegraph();
        return 1;
    }

    setcolor(YELLOW);
    AB->drawLine();
    drawLabel("AB", AB->getPoint(0).x, AB->getPoint(0).y, AB->getPoint(1).x, AB->getPoint(1).y);

    DuongThang* CD = new DuongThang(AB->getPoint(0).x, AB->getPoint(0).y, AB->getPoint(1).x, AB->getPoint(1).y);
    CD->translate(dx, dy);
    if (!CD->isValidLine()) {
        std::cout << "Doan thang CD khong hop le (do dai = 0)! Vui long nhap lai.\n";
        delete AB;
        delete CD;
        closegraph();
        return 1;
    }
    setcolor(GREEN);
    CD->drawLine();
    drawLabel("CD", CD->getPoint(0).x, CD->getPoint(0).y, CD->getPoint(1).x, CD->getPoint(1).y);

    DuongThang* AD = new DuongThang(AB->getPoint(0).x, AB->getPoint(0).y, CD->getPoint(0).x, CD->getPoint(0).y);
    if (!AD->isValidLine()) {
        std::cout << "Doan thang AD khong hop le (do dai = 0)! Vui long nhap lai.\n";
        delete AB;
        delete CD;
        delete AD;
        closegraph();
        return 1;
    }
    setcolor(RED);
    AD->drawLine();
    drawLabel("AD", AD->getPoint(0).x, AD->getPoint(0).y, AD->getPoint(1).x, AD->getPoint(1).y);

    DuongThang* BC = new DuongThang(AB->getPoint(1).x, AB->getPoint(1).y, CD->getPoint(1).x, CD->getPoint(1).y);
    if (!BC->isValidLine()) {
        std::cout << "Doan thang BC khong hop le (do dai = 0)! Vui long nhap lai.\n";
        delete AB;
        delete CD;
        delete AD;
        delete BC;
        closegraph();
        return 1;
    }
    setcolor(BLUE);
    BC->drawLine();
    drawLabel("BC", BC->getPoint(0).x, BC->getPoint(0).y, BC->getPoint(1).x, BC->getPoint(1).y);

    delete AB;
    delete CD;
    delete AD;
    delete BC;

    getch();
    closegraph();

    return 0;
}