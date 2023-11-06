#ifndef _MINESWEEPER_H_
#define _MINESWEEPER_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int** initMinesBoard(int length, int mines) {
	int** board = (int**)malloc(length * sizeof(int*));
	for (int y = 0; y < length; y++) {
		board[y] = (int*)malloc(length * sizeof(int));
		for (int x = 0; x < length; x++) board[y][x] = 0;
	}
	while (mines) {
		srand(time(NULL));
		for (int y = 0; y < length; y++) {
			for (int x = 0; x < length; x++) {
				if (!board[y][x] && rand() % (length * length / mines) == 0) {
					board[y][x] = 9;
					if (--mines == 0) return board;
				}
			}
		}
	}
}

void initMinesBoardAgain(int** board, int length) {
	for (int y = 0; y < length; y++) {
		for (int x = 0; x < length; x++) {
			if (board[y][x] == 9) {
				if (x > 0 && board[y][x - 1] != 9) board[y][x - 1] += 1;
				if (x < 9 && board[y][x + 1] != 9) board[y][x + 1] += 1;
				if (y > 0 && board[y - 1][x] != 9) board[y - 1][x] += 1;
				if (y < 9 && board[y + 1][x] != 9) board[y + 1][x] += 1;
				if (y > 0 && x > 0 && board[y - 1][x - 1] != 9) board[y - 1][x - 1] += 1;
				if (y > 0 && x < 9 && board[y - 1][x + 1] != 9) board[y - 1][x + 1] += 1;
				if (y < 9 && x > 0 && board[y + 1][x - 1] != 9) board[y + 1][x - 1] += 1;
				if (y < 9 && x < 9 && board[y + 1][x + 1] != 9) board[y + 1][x + 1] += 1;
			}
		}
	}
}

void showMinesBoard(int** board, int length) {
	for (int y = 0; y < length; y++) {
		if (!y) {
			printf("r\\c \t");
			for (int i = 0; i < length; i++) {
				if (i < 9) printf("%d   ", i + 1);
				else if (i < 99) printf("%d  ", i + 1);
			}
			printf("\n\n\n");
		}
		for (int x = 0; x < length; x++) {
			if (!x && y < 9) printf("%d   \t", y + 1);
			else if (!x && y < 99) printf("%d  \t", y + 1);
			int temp = board[y][x];
			if (temp < 10 && temp > -1) printf("*   ");
			else if (temp == 10) printf("    ");
			else if (temp > 10 && temp < 19) printf("%d   ", temp - 10);
			else if (temp == 19) printf("@   ");
			else printf("%d   ", temp);
		}
		printf("\n\n");
	}
}

void changeMinesBoard(int** board, int length, int r, int c) {
	if (r < 0 || r >= length || c < 0 || c >= length || board[r][c] >= 9) return;

	board[r][c] += 10;
	if (board[r][c] != 10) return;

	changeMinesBoard(board, length, r - 1, c);
	changeMinesBoard(board, length, r + 1, c);
	changeMinesBoard(board, length, r, c - 1);
	changeMinesBoard(board, length, r, c + 1);
	changeMinesBoard(board, length, r - 1, c + 1);
	changeMinesBoard(board, length, r - 1, c - 1);
	changeMinesBoard(board, length, r + 1, c + 1);
	changeMinesBoard(board, length, r + 1, c - 1);
}
int minesSweep(int** board, int length) {
	int r = 0, c = 0;
	while (1) {
		printf("请输入您要清扫的格子(r c)");
		int itemsRead = scanf_s("%d %d", &r, &c, sizeof(r), sizeof(c));
		if (itemsRead == 2 && r > 0 && r <= length && c > 0 && c <= length && board[--r][--c] < 10) break;
		else {
			int trash;
			while ((trash = getchar()) != '\n' && trash != EOF);
		}
	}

	if (board[r][c] == 9) {
		board[r][c] += 10;
		return -1;
	}
	changeMinesBoard(board, length, r, c);
	return 0;
}

int checkMinesBoard(int** board, int length) {
	for (int y = 0; y < length; y++) {
		for (int x = 0; x < length; x++) {
			if (board[y][x] < 9) return 0;
		}
	}
	for (int y = 0; y < length; y++) {
		for (int x = 0; x < length; x++) {
			if (board[y][x] == 9) board[y][x] += 10;
		}
	}
	return 1;
}

#endif