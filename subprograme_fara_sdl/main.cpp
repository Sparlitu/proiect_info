#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdlib.h>

const int width = 51;
const int height = 101;
const int dx[] = { 0,-1,-1,-1,0,1,1,1 };
const int dy[] = { -1,-1,0,1,1,1,0,-1 };

std::ifstream fin("input.in");

bool field[width][height], aux[width][height];

int neighbours(int i, int j) {
	int cnt = 0;
	for (int d = 0; d < 8; ++d) {
		int inew = i + dx[d];
		int jnew = j + dy[d];
		if (aux[inew][jnew] == true)
			cnt++;
	}
	return cnt;
}

void init() {
	field[width-1][height-1] = { 0 };
	aux[width - 1][height - 1] = { 0 };
	int i, j;
	while (fin>>i>>j) {
		field[i][j] = 1;
	}
}

void draw() {
	for (int i = 1; i < width; ++i) {
		for (int j = 1; j < height; ++j) {
			if (field[i][j] == false)
				std::cout << (char)177;
			else
				std::cout << (char)178;
		}
		std::cout << "\n";
	}
}

void update() {
	for (int i = 1; i < width; ++i) {
		for (int j = 1; j < height; ++j) {
			aux[i][j] = field[i][j];
		}
	}
	for (int i = 1; i < width; ++i) {
		for (int j = 1; j < height; ++j) {
			int k = neighbours(i, j);
			if (aux[i][j] == true && (k == 2 || k == 3))
				field[i][j] = 1;
			else if (aux[i][j] == false && k == 3)
				field[i][j] = 1;
			else
				field[i][j] = 0;
		}
	}
}

int main() {
	system("color f0");
	init();
	system("pause");
	while (1) {
		draw();
		update();
		//Sleep(300);
		system("cls");
	}
	return 0;
}
