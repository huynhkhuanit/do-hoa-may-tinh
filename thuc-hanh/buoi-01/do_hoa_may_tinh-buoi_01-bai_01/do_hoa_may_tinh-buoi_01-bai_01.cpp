#include "graphics.h"
#include <iostream>
#pragma comment(lib,"graphics.lib")
using namespace std;

int main() {
    initwindow(1000, 1000);

    int x, y, color;

    cout << "Nhap toa do x: ";
    cin >> x;
    cout << "Nhap toa do y: ";
    cin >> y;

    cout << "Chon mau sac (0 den 15): ";
    cin >> color;

    if (color < 0 || color > 15) {
        cout << "Mau sac khong hop le! (Phai tu 0 den 15)" << endl;
    }
    else {
        putpixel(x, y, color);
        cout << "Da ve pixel tai (" << x << ", " << y << ") voi mau " << color << endl;
    }

    getch();
    closegraph();
    return 0;
}
