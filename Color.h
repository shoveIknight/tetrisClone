#pragma once
class Color
{
public:
	bool check() {
		return check_x;
	}
	int getR() {
		return color_r;
	}
	int getG() {
		return color_g;
	}
	int getB() {
		return color_b;
	}
	void setR(int a) {
		color_r = a;
	}
	void setG(int a) {
		color_g = a;
	}
	void setB(int a) {
		color_b = a;
	}
	void setCheck() {
		check_x = 1;
	}
	void setUncheck() {
		check_x = 0;
	}
private:
	bool check_x = 0;
	int color_r;
	int color_g;
	int color_b;
};

