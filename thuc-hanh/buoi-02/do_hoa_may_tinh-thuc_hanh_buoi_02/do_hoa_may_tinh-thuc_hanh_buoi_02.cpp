#include <iostream>
#include <conio.h>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#define M_PI 3.14159265358979323846

bool isInRange(int value, int min, int max) {
	return value >= 0 && value <= max;
}

/// <summary>
/// Check point X, Y and Color
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="color"></param>
/// <param name="screenWidth"></param>
/// <param name="screenHeight"></param>
/// <returns>true or false</returns>
bool isValidInput(int x, int y, int color, int screenWidth, int screenHeight) {
	if (x < 0 || x > screenWidth || y < 0 || y > screenHeight || color < 0 || color > 15) {
		std::cout << "Nhap sai, vui long nhap lai!\n";
		std::cout << "Luu y: \n";
		std::cout << "- Toa do X phai trong khoang (0, " << screenWidth << ")\n";
		std::cout << "- Toa do Y phai trong khoang (0, " << screenHeight << ")\n";
		std::cout << "- Mau sac phai trong khoang (0 - 15)\n";

		return false;
	}
	return true;
}

/// <summary>
/// isValidInput - overloading (4 param)
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="x2"></param>
/// <param name="y2"></param>
/// <param name="color"></param>
/// <param name="screenWidth"></param>
/// <param name="screenHeight"></param>
/// <returns></returns>
bool isValidInput(int x, int y, int x2, int y2, int color, int screenWidth, int screenHeight) {
	if (!isInRange(x, 0, screenWidth) || !isInRange(y, 0, screenHeight) ||
		!isInRange(x2, 0, screenWidth) || !isInRange(y2, 0, screenHeight) ||
		!isInRange(color, 0, 15)) {
		std::cout << "Nhap sai, vui long nhap lai!\n";
		std::cout << "Luu y: \n";
		std::cout << "- Toa do X phai trong khoang (0, " << screenWidth << ")\n";
		std::cout << "- Toa do Y phai trong khoang (0, " << screenHeight << ")\n";
		std::cout << "- Toa do X2 phai trong khoang (0, " << screenWidth << ")\n";
		std::cout << "- Toa do Y2 phai trong khoang (0, " << screenHeight << ")\n";
		std::cout << "- Mau sac phai trong khoang (0 - 15)\n";

		return false;
	}
	return true;
}

bool isValidInput(int x, int y, int sideLength, int color, int screenWidth, int screenHeight) {
	if (!isInRange(x, 0, screenWidth) || !isInRange(y, 0, screenHeight) ||
		!isInRange(sideLength, 0, screenWidth) || !isInRange(color, 0, 15)) {
		std::cout << "Nhap sai, vui long nhap lai!\n";
		std::cout << "Luu y: \n";
		std::cout << "- Toa do X phai trong khoang (0, " << screenWidth << ")\n";
		std::cout << "- Toa do Y phai trong khoang (0, " << screenHeight << ")\n";
		std::cout << "- Chieu dai canh phai trong khoang (0, " << screenHeight << ")\n";
		std::cout << "- Mau sac phai trong khoang (0 - 15)\n";

		return false;
	}
	return true;
}

/// <summary>
/// Draw Arrow can help user look at the point
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="x2"></param>
/// <param name="y2"></param>
void drawArrow(int x, int y, int x2, int y2) {
	line(x, y, x2, y2);

	float angle = atan2(y2 - y, x2 - x);

	int arrowLength = 10;
	int arrowWidth = 5;

	int x1 = x2 - arrowLength * cos(angle - M_PI / 6);
	int y1 = y2 - arrowLength * sin(angle - M_PI / 6);

	int x2_ = x2 - arrowLength * cos(angle + M_PI / 6);
	int y2_ = y2 - arrowLength * sin(angle + M_PI / 6);

	line(x2, y2, x1, y1);
	line(x2, y2, x2_, y2_);
}

/// <summary>
/// Draw point - exercise 1
/// </summary>
/// <param name="screenWidth"></param>
/// <param name="screenHeight"></param>
void drawPointWithXYColor(int screenWidth, int screenHeight) {
	int pointX, pointY, pointColor;

	do {
		std::cout << "Nhap toa do X: "; std::cin >> pointX;
		std::cout << "Nhap toa do Y: "; std::cin >> pointY;
		std::cout << "Nhap mau sac (0 - 15): "; std::cin >> pointColor;
	} while (!isValidInput(pointX, pointY, pointColor, screenWidth, screenHeight));

	drawArrow(pointX - 50, pointY - 50, pointX - 5, pointY - 5);
	putpixel(pointX, pointY, pointColor);
}

/// <summary>
/// Show Info - Exercise 2
/// </summary>
void showInfoInConsole() {
	int pointX = 10, pointY = 10;

	std::cin.ignore();
	std::string name; std::cout << "Nhap ho ten: "; std::getline(std::cin, name);

	char nameCharArray[100];

	for (int i = 0; i < name.length(); i++) {
		nameCharArray[i] = name[i];
	}

	nameCharArray[name.length()] = '\0';

	outtextxy(pointX, pointY, nameCharArray);
}

/// <summary>
/// drawRandomPoints - Exercise 3
/// </summary>
/// <param name="screenWidth"></param>
/// <param name="screenHeight"></param>
void drawRandomPoints(int screenWidth, int screenHeight) {
	srand(static_cast<unsigned int>(time(0)));

	for (int i = 0; i < 100; i++) {
		int x = rand() % screenWidth;
		int y = rand() % screenHeight;

		int color = rand() % 16;

		putpixel(x, y, color);
	}
}

/// <summary>
/// drawLine - Exercise 4
/// </summary>
/// <param name="screenWidth"></param>
/// <param name="screenHeight"></param>
void drawLine(int screenWidth, int screenHeight) {
	int pointX, pointX2, pointY, pointY2, pointColor;

	do {
		std::cout << "Nhap toa do X: "; std::cin >> pointX;
		std::cout << "Nhap toa do Y: "; std::cin >> pointY;
		std::cout << "Nhap toa do X2: "; std::cin >> pointX2;
		std::cout << "Nhap toa do Y2: "; std::cin >> pointY2;
		std::cout << "Nhap mau sac (0 - 15): "; std::cin >> pointColor;
	} while (!isValidInput(pointX, pointY, pointX2, pointY2, pointColor, screenWidth, screenHeight));

	line(pointX, pointY, pointX2, pointY2);
}

/// <summary>
/// drawRetangle - Excersie 5	
/// </summary>
/// <param name="screenWidth"></param>
/// <param name="screenHeight"></param>
void drawRetangle(int screenWidth, int screenHeight) {
	int pointX, pointX2, pointY, pointY2, pointColor;

	do {
		std::cout << "Nhap toa do X: "; std::cin >> pointX;
		std::cout << "Nhap toa do Y: "; std::cin >> pointY;
		std::cout << "Nhap toa do X2: "; std::cin >> pointX2;
		std::cout << "Nhap toa do Y2: "; std::cin >> pointY2;
		std::cout << "Nhap mau sac (0 - 15): "; std::cin >> pointColor;
	} while (!isValidInput(pointX, pointY, pointX2, pointY2, pointColor, screenWidth, screenHeight));

	rectangle(pointX, pointY, pointX2, pointY2);
	setfillstyle(SOLID_FILL, pointColor);
	floodfill(pointX + 1, pointY + 1, WHITE);
}

/// <summary>
/// drawSquare - Exercise 6
/// </summary>
/// <param name="screenWidth"></param>
/// <param name="screenHeight"></param>
void drawSquare(int screenWidth, int screenHeight) {
	int pointX, pointY, sideLength, pointColor;
	do {
		std::cout << "Nhap toa do X: "; std::cin >> pointX;
		std::cout << "Nhap toa do Y: "; std::cin >> pointY;
		std::cout << "Nhap chieu dai canh: "; std::cin >> sideLength;
		std::cout << "Nhap mau sac (0 - 15): "; std::cin >> pointColor;
	} while (!isValidInput(pointX, pointY, sideLength, pointColor, screenWidth, screenHeight));

	// Top side
	line(pointX, pointY, pointX + sideLength, pointY);
	// Right side
	line(pointX + sideLength, pointY, pointX + sideLength, pointY + sideLength);
	// Bottom side
	line(pointX, pointY + sideLength, pointX + sideLength, pointY + sideLength);
	// Left side
	line(pointX, pointY, pointX, pointY + sideLength);
	setfillstyle(SOLID_FILL, pointColor);
	floodfill(pointX + 1, pointY + 1, WHITE);
}

/// <summary>
/// drawCircle - Excersie 7
/// </summary>
/// <param name="screenWidth"></param>
/// <param name="screenHeight"></param>
void drawCircle(int screenWidth, int screenHeight) {
	int pointX, pointY, radius, pointColor;

	do {
		std::cout << "Nhap toa do X: "; std::cin >> pointX;
		std::cout << "Nhap toa do Y: "; std::cin >> pointY;
		std::cout << "Nhap chieu ban kinh: "; std::cin >> radius;
		std::cout << "Nhap mau sac (0 - 15): "; std::cin >> pointColor;
	} while (!isValidInput(pointX, pointY, radius, pointColor, screenWidth, screenHeight));

	circle(pointX, pointY, radius);
	setfillstyle(SOLID_FILL, pointColor);
	floodfill(pointX + 1, pointY + 1, WHITE);
}

/// <summary>
/// drawEllipse - Exercise 9
/// </summary>
/// <param name="screenWidth"></param>
/// <param name="screenHeight"></param>
void drawEllipse(int screenWidth, int screenHeight) {
	int pointX, pointY, xRadius, yRadius, pointColor;

	do {
		std::cout << "Nhap toa do X: "; std::cin >> pointX;
		std::cout << "Nhap toa do Y: "; std::cin >> pointY;
		std::cout << "Nhap toa do xRadius: "; std::cin >> xRadius;
		std::cout << "Nhap toa do yRadius: "; std::cin >> yRadius;
		std::cout << "Nhap mau sac (0 - 15): "; std::cin >> pointColor;
	} while (!isValidInput(pointX, pointY, xRadius ,yRadius, pointColor, screenWidth, screenHeight));
	setcolor(WHITE);
	ellipse(pointX, pointY, 0, 360, xRadius, yRadius);
	setfillstyle(SOLID_FILL, pointColor);
	floodfill(pointX + 1, pointY + 1, WHITE);
}

void DDA(int x1, int y1, int x2, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	int buocnNhay;

	if (abs(dx) > abs(dy)) buocnNhay = abs(dx);
	else buocnNhay = abs(dy);

	float Xincrement = dx / (float)buocnNhay;
	float Yincrement = dy / (float)buocnNhay;

	float X = x1, Y = y1;

	for (int i = 0; i <= buocnNhay; i++) {
		putpixel(round(X), round(Y), WHITE);
		X += Xincrement;
		Y += Yincrement;
	}
}

void showMenu() {
	std::cout << "\n************* MENU *************\n";
	std::cout << "1. Draw Point\n";
	std::cout << "2. Show Info\n";
	std::cout << "3. Draw Random Points\n";
	std::cout << "4. Draw Line\n";
	std::cout << "5. Draw Rectangle\n";
	std::cout << "6. Draw Square\n";
	std::cout << "7. Draw Circle\n";
	std::cout << "8. Draw Ellipse\n";
	std::cout << "0. Exit\n";
	std::cout << "*******************************\n";
	std::cout << "Nhap lua chon: ";
}

void clearScreen() {
	system("cls");
}

int main() {
	int screenWidth = 640, screenHeight = 480;

	// Init window
	initwindow(screenWidth, screenHeight);

	//int x1, y1, x2, y2;
	//std::cout << "Nhap toa do diem dau (x1, y1): ";
	//std::cin >> x1 >> y1;
	//std::cout << "Nhap toa do diem cuoi (x2, y2): ";
	//std::cin >> x2 >> y2;

	//// Gọi hàm DDA để vẽ đoạn thẳng
	//DDA(x1, y1, x2, y2);

	int choice = -1;

	do {
		clearScreen();
		showMenu();
		std::cin >> choice;

		switch (choice) {
		case 1:
			// Draw Point - Exercise 1
			drawPointWithXYColor(screenWidth, screenHeight);
			break;
		case 2:
			// Show Info - Exercise 2
			showInfoInConsole();
			break;
		case 3:
			// Draw random points - Exercise 3
			drawRandomPoints(screenWidth, screenHeight);
			break;
		case 4:
			// Draw Line - Exercise 4
			drawLine(screenWidth, screenHeight);
			break;
		case 5:
			// Draw Rectangle - Exercise 5
			drawRetangle(screenWidth, screenHeight);
			break;
		case 6:
			// Draw Square - Exercise 6
			drawSquare(screenWidth, screenHeight);
			break;
		case 7:
			// Draw Circle - Exercise 7
			drawCircle(screenWidth, screenHeight);
			break;
		case 8:
			// Draw Ellipse - Exercise 9
			drawEllipse(screenWidth, screenHeight);
			break;
		case 0:
			// Exit
			std::cout << "Exiting the program...\n";
			break;
		default:
			std::cout << "Invalid choice, please try again.\n";
			break;
		}

		std::cout << "\nPress any key to continue...";
		_getch();

	} while (choice != 0);

	return 0;
}