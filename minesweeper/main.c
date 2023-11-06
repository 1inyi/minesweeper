// Lin Yi
// 1inyi@mail.com
// 2023/10/30 21:38

#include <stdio.h>
#include "minesweeper.h"
#define ly 10

int main() {
	printf("��ʼ��Ϸ��1��\t�˳���0��\n");
	int option = -1;
	while (1) {
		printf("�������Ӧ��������ţ�");
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
		printf("���ڳ�ʼ�����̡��������Ժ󡣡���\n");
		int** minesBoard = initMinesBoard(len, mines);
		initMinesBoardAgain(minesBoard, len);

		while (1) {
			showMinesBoard(minesBoard, len);
			int flag = minesSweep(minesBoard, len);

			if (flag == -1) {
				showMinesBoard(minesBoard, len);
				printf("�ȵ������ˡ�������Ϸ����������");
				break;
			}

			flag = checkMinesBoard(minesBoard, len);
			if (flag) {
				showMinesBoard(minesBoard, len);
				printf("��ϲ��ͨ���ˣ�����\n");
				break;
			}
		}

		printf("������Ϸ��1��\t�˳���0��\n");
		while (1) {
			printf("�������Ӧ��������ţ�");
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