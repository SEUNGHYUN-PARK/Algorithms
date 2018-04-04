#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int N, L, countN = 0;
int map[100][100];
int row_arr[100];
bool labor[100];
const int RIGHT = 0;
const int DOWN = 1;
void check(int index) {
	if (index == N - 1) {
		countN++;
		return;
	}
	if (row_arr[index] == row_arr[index + 1]) {
		if (index + L<N) {
			if (row_arr[index] == row_arr[index + L]) {
				check(index + 1);
			}
			else {
				if (abs(row_arr[index] - row_arr[index + L]) >= 2) return;
				if (row_arr[index] < row_arr[index + L]) {
					for (int i = 0; i < L - 1; i++) {
						if (row_arr[index + i] != row_arr[index + i + 1]) return;
					}
					for (int i = 0; i < L; i++) {
						if (labor[index + i]) return;
						labor[index + i] = true;
					}
					check(index + L);
				}
				else {
					check(index + 1);
				}
			}
		}
		else
			check(index + 1);
	}
	else {
		if ((abs(row_arr[index] - row_arr[index + 1]) >= 2)) return;
		if (row_arr[index]>row_arr[index + 1]) {
			if (L == 1) {
				if (labor[index + 1]) return;
				labor[index + 1] = true;
				check(index + 1);
			}
			else {
				if (index + 2 >= N) return;
				for (int i = 0; i < L - 1; i++) {
					if (row_arr[index + i + 1] != row_arr[index + i + 2]) return;
				}
				for (int i = 0; i < L; i++) {
					if (labor[index + i + 1]) return;
					labor[index + i + 1] = true;
				}
				check(index + L);
			}
		}
		else if (row_arr[index]<row_arr[index] + 1) {
			if (L>1 || labor[index]) return;
			labor[index] = true;
			check(index + 1);
		}
	}
}
void go(int row, int col, int direction) {
	if (direction == RIGHT) {
		for (int i = 0; i < N; i++) {
			row_arr[i] = map[row][i];
			labor[i] = false;
		}
		check(0);
	}
	else {
		for (int i = 0; i < N; i++) {
			row_arr[i] = map[i][col];
			labor[i] = false;
		}
		check(0);
	}
}
int main() {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	for (int i = 0; i < N; i++)
		go(i, 0, RIGHT);
	for (int i = 0; i < N; i++)
		go(0, i, DOWN);
	printf("%d\n", countN);
}