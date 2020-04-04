#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <math.h>

int main()
{
#define LINE 10
#define COLUMN 10
	printf("Generation number 1\n");
	int arr[LINE][COLUMN] = {0};
	srand(time(0));
	rand();
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < COLUMN; j++) {
			arr[i][j] = rand() % 2;
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	int sum = 0;
	int dop[LINE][COLUMN] = { 0 };
	int k = 0;
	int t = 0;
	int point = 0;
	int round = 2;
	while (point == 0) {
		printf("Generation number %d\n", round);
		round++;
		for (int i = 0; i < LINE; i++) {
			for (int j = 0; j < COLUMN; j++) {
				if (arr[i][j] == 0) {
					sum += arr[(i - 1) % LINE][j] + arr[(i + 1) % LINE][j] + arr[i][(j - 1) % LINE] + arr[i][(j + 1) % LINE] + arr[(i - 1) % LINE][(j - 1) % LINE] + arr[(i - 1) % LINE][(j + 1) % LINE] + arr[(i + 1) % LINE][(j + 1) % LINE] + arr[(i + 1) % LINE][(j - 1) % LINE];
					if (sum == 3) {
						dop[i][j] = 1;
					}
				}
				else {
					sum += arr[(i - 1) % LINE][j] + arr[(i + 1) % LINE][j] + arr[i][(j - 1) % LINE] + arr[i][(j + 1) % LINE] + arr[(i - 1) % LINE][(j - 1) % LINE] + arr[(i - 1) % LINE][(j + 1) % LINE] + arr[(i + 1) % LINE][(j + 1) % LINE] + arr[(i + 1) % LINE][(j - 1) % LINE];
					if ((sum == 3) || (sum == 2)) {
						dop[i][j] = 1;
					}
				}
				sum = 0;
			}
		}
		for (int i = 0; i < LINE; i++) {
			for (int j = 0; j < COLUMN; j++) {
				if (arr[i][j] == dop[i][j]) {
					k++;
				}
				if (dop[i][j] == 0) {
					t++;
				}
			}
		}
		if ((t == LINE * LINE) || (k == LINE * LINE)) {
			point++;
		}
			for (int i = 0; i < LINE; i++) {
				for (int j = 0; j < COLUMN; j++) {
					arr[i][j] = dop[i][j];
					dop[i][j] = 0;
					printf("%d  ", arr[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			if (t == LINE * LINE) {
			printf("And Then There Were None\n");
			printf("\n");
		}
			else {
				if (k == LINE * LINE) {
					printf("We have reached a balance\n");
					printf("\n");
				}
			}
		t = 0; k = 0;
	}
	printf("END\n");
	return 0;
}
