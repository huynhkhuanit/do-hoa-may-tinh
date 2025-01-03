#include "graphics.h"
#include <iostream>
#include <math.h>
#define PI 3.14159265359
#pragma comment(lib,"graphics.lib")

using namespace std;
float tinhgoc(float goc) {
    return (goc * PI / 180);
}

void vekhung(int xtam, int ytam, int bk) { //ham ve hinh tron tam (x,y) ban kinh 250
    int d, x1, y1, x2, y2;
    setlinestyle(0, 0, CYAN);
    setcolor(RED);
    circle(xtam, ytam, bk); //
    setcolor(YELLOW);
    circle(xtam, ytam, bk + 2); //
    setcolor(LIGHTCYAN);
    circle(xtam, ytam, bk + 4); //ve mat dong ho
    setcolor(MAGENTA);
    d = 270;
    while (d <= 630) {
        x1 = xtam + (int)bk * cos(tinhgoc(d));
        y1 = ytam + (int)bk * sin(tinhgoc(d));
        //circle(x,y,10);
        x2 = xtam + (int)(bk - 20) * cos(tinhgoc(d));
        y2 = xtam + (int)(bk - 20) * sin(tinhgoc(d));
        line(x1, y1, x2, y2);
        delay(10);
        d += 30;
    }
    d = 270;
    setcolor(LIGHTMAGENTA);
    setlinestyle(0, 0, GREEN);
    while (d <= 630) {
        x1 = xtam + (int)bk * cos(tinhgoc(d));
        y1 = ytam + (int)bk * sin(tinhgoc(d));
        //circle(x,y,10);
        x2 = xtam + (int)(bk - 8) * cos(tinhgoc(d));
        y2 = xtam + (int)(bk - 8) * sin(tinhgoc(d));
        line(x1, y1, x2, y2);
        delay(10);
        d += 6;
    }
}

void kimgiay(int bk, int cl, int goc) {
    //ve kim giay co ban kinh bk, mau cl, goc bat dau
    int xgiay, ygiay;

    setlinestyle(0, 0, BLUE);
    setcolor(cl);
    xgiay = 300 + (int)(bk - 50) * cos(tinhgoc(goc));
    ygiay = 300 + (int)(bk - 50) * sin(tinhgoc(goc));
    line(xgiay, ygiay, 300, 300);
}

void kimphut(int bk, int cl, int goc) {
    //ve kim phut
    int xphut, yphut;
    setlinestyle(0, 0, CYAN);
    setcolor(cl);
    xphut = 300 + (int)(bk - 100) * cos(tinhgoc(goc));
    yphut = 300 + (int)(bk - 100) * sin(tinhgoc(goc));
    line(xphut, yphut, 300, 300);
}

void kimgio(int bk, int cl, int goc) {
    //ve kim gio
    int xgio, ygio;
    setlinestyle(0, 0, CYAN);
    setcolor(cl);
    xgio = 300 + (int)(bk - 140) * cos(tinhgoc(goc));
    ygio = 300 + (int)(bk - 140) * sin(tinhgoc(goc));
    line(xgio, ygio, 300, 300);
}

void vekim(int bk, float d1, float d2, float d3) {
    while (!kbhit()) {
        kimgiay(bk, BLUE, d3); //ve kim giay ung voi goc d1
        if (d3 == d2) kimphut(bk, GREEN, d2); // may ve cac net chong len nhau nen phai ve lại net cu da mat
        if (d3 == d1) kimgio(bk, RED, d1);
        kimphut(bk, GREEN, d2);
        if (d2 == d1) kimgio(bk, RED, d1);
        kimgio(bk, RED, d1);
        delay(1000);
        kimphut(bk, BLACK, d2); //xoa di net cu, ve net moi de tao di chuyen
        kimgiay(bk, BLACK, d3);
        kimgio(bk, BLACK, d1);
        d3 += 6; d2 += 0.1; d1 += 1 / 120;
        setcolor(LIGHTCYAN); // dat mau cho tam
        circle(300, 300, RED);
    }
}
void gocdau(int gio, int phut, int giay, float& d1, float& d2, float& d3) {
    d3 = giay * 6 + 270; // 12h ung voi goc 270
    d2 = phut * 6 + giay * 0.1 + 270;
    d1 = gio * 30 + phut * 0.5 + giay * 1 / 120 + 270;
}
int main() {
    int bk, gio, phut, giay;
    float d1, d2, d3;
    cout << "CAM ON DA SU DUNG CHIEC DONG HO NAY :)))) ";
    cout << "\nHay lan luot nhap vao so gio, phut, giay\n (cach nhau boi phim space) roi enter: ";
    cin >> gio >> phut >> giay;
    gocdau(gio, phut, giay, d1, d2, d3);
    initwindow(600, 600);
    char clockText[] = "CLOCK in graphics";
    outtextxy(10, 10, clockText);
    bk = 250;
    vekhung(300, 300, bk);
    vekim(bk, d1, d2, d3);

    closegraph();//dong cua so do hoa
}