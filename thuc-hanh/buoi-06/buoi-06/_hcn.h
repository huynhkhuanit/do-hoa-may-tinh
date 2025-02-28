#pragma once


struct Point {
	int x, y;
	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}
};

class HCN {
private:
	Point p[4];
	int width, height;

public:
	HCN() {
		for (Point x : p) {
			x.x = 0;
			x.y = 0;
		}
		width = height = 0;
	}

	HCN(int x, int y, int w, int h) {
		p[0] = Point(x, y);
		p[1] = Point(x + w, y);
		p[2] = Point(x + w, y + h);
		p[3] = Point(x, y + h);
		
		width = w, height = h;
	}

	// Getter
	Point getPoint(int index) { return p[index]; }
	int getWidth() { return width; }
	int getHeight() { return height; }

	// Setter
	void setPoint(int index, int x, int y) { p[index].x = x; p[index].y = y; }
	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }

	// Methods
	// draw
	void drawHCN();
	/// <summary>
	/// fill reactangle
	/// </summary>
	void fillRect();
};

void HCN::drawHCN() {
	for (int i = 0; i < 4; i++) {
		int nextPoint = (i + 1) % 4;
		line(p[i].x, p[i].y, p[nextPoint].x, p[nextPoint].y);
	}
}

// Su dung stack de tranh loi Stack Overflow
void boundaryFill(int startX, int startY, int fillColor, int boundaryColor) {
	std::stack<std::pair<int, int>> pixelStack;
	pixelStack.push({ startX, startY });
	while (!pixelStack.empty()) {
		// Lấy điểm trên cùng của stack
		std::pair<int, int> current = pixelStack.top();
		pixelStack.pop();

		int x = current.first;
		int y = current.second;

		// Kiểm tra pixel hiện tại
		int currentColor = getpixel(x, y);
		if (currentColor != boundaryColor && currentColor != fillColor) {
			// Tô pixel
			putpixel(x, y, fillColor);

			// Thêm 4 điểm lân cận vào stack
			pixelStack.push({ x, y - 1 }); // Tren
			pixelStack.push({ x, y + 1 }); // Duoi
			pixelStack.push({ x + 1, y }); // Phai
			pixelStack.push({ x - 1, y }); // Trai
		}
	}
}

void HCN::fillRect() {
	int startX = p[0].x + 1;
	int startY = p[0].y + 1;
	int fillColor = RED;
	int boundaryColor = WHITE;
	boundaryFill(startX, startY, fillColor, boundaryColor);
}