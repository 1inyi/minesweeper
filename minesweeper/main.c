// Lin Yi
// 1inyi@mail.com
// 2023/10/30 21:38

#include <stdio.h>
#include "minesweeper.h"
#define ly 10

int main() {
	printf("开始游戏（1）\t退出（0）\n");
	int option = -1;
	while (1) {
		printf("请输入对应的数字序号：");
		int temp = scanf_s("%d", &option, sizeof(option));
		if (temp == 1 && option == 1 || option == 0) break;
		else {
			int trash;
			while ((trash = getchar()) != '\n' && trash != EOF);
		}
	}
	while (1) {
		if (!option) break;

		int len = 10, mines = 10;
		printf("正在初始化棋盘。。。请稍后。。。\n");
		int** minesBoard = initMinesBoard(len, mines);
		initMinesBoardAgain(minesBoard, len);

		while (1) {
			showMinesBoard(minesBoard, len);
			int flag = minesSweep(minesBoard, len);

			if (flag == -1) {
				showMinesBoard(minesBoard, len);
				printf("踩到地雷了。。。游戏结束。。。");
				break;
			}

			flag = checkMinesBoard(minesBoard, len);
			if (flag) {
				showMinesBoard(minesBoard, len);
				printf("恭喜你通关了！！！\n");
				break;
			}
		}

		printf("继续游戏（1）\t退出（0）\n");
		while (1) {
			printf("请输入对应的数字序号：");
			int temp = scanf_s("%d", &option, sizeof(option));
			if (temp == 1 && option == 1 || option == 0) break;
			else {
				int trash;
				while ((trash = getchar()) != '\n' && trash != EOF);
			}
		}
		if (!option) break;
	}

	return 0;
}