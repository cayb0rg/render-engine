#include "defs.h"
#include <iostream>

#include "Rasterizer.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix44.h"
#include "GenMath.h"

int main(void){
	Vector3 value;
	initscr();
	raw();
	noecho();

    Rasterizer rasterizer(WW, WH);

	float angle = 0;

	Vector2 v1(0, 0);
	Vector2 v2(0, 41);
	Vector2 v3(100, 43);

	rasterizer.rasterizeTriangle(v1, v2, v3);

	while (angle < 360) {
		Matrix44 transformation;
		transformation.scale(Vector3(2, 1, 1));
		transformation.rotate(Vector3(0, 0, 1), GenMath::toRadians(angle));

		Vector4 v1(10, 10, 1, 1);
		Vector4 v2(20, 10, 1, 1);
		Vector4 v3(15, 20, 1, 1);

		v1 = transformation * v1;
		v2 = transformation * v2;
		v3 = transformation * v3;

		rasterizer.rasterizeTriangle(Vector2(v1.x, v1.y), Vector2(v2.x, v2.y), Vector2(v3.x, v3.y));

		getch();
		clear();
		angle += 5;
	}

	int row, col;
	getmaxyx(stdscr, row, col);
	printf("Width: %d ", row);
	printf("Height: %d ", col);
	//printw("this is a test of ncurses\n");
	getch();
    clear();

	endwin();

	return 0;
}