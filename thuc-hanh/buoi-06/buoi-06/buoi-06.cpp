#include <iostream>
#include <stack>
#include <utility>
#include "graphics.h"
#pragma comment(lib, "graphics.lib")
#include "_hcn.h"

int main() {
	int x, y, width, height;

	std::cout << "Nhap toa do x cua goc trai tren mat ban: ";
	std::cin >> x;
	std::cout << "Nhap toa do y cua goc trai tren mat ban: ";
	std::cin >> y;
	std::cout << "Nhap chieu rong mat ban: ";
	std::cin >> width;
	std::cout << "Nhap chieu cao mat ban: ";
	std::cin >> height;

	initwindow(600, 400, "Hinh chu nhat");

	// Mat ban (x, y, chieu rong, dai)
	HCN tableTop(x, y, width, height);
	
	// dai / 5 (200 / 5) = 20
	int legWidth = width / 5;
	int legHeight = height * 2;

	HCN leftLeg(x, y + height, legWidth, legHeight);
	HCN rightLeg(x + width - legWidth, y + height, legWidth, legHeight);

	tableTop.drawHCN();
	tableTop.fillRect();

	leftLeg.drawHCN();
	leftLeg.fillRect();

	rightLeg.drawHCN();
	rightLeg.fillRect();

	getch();
	closegraph();
}