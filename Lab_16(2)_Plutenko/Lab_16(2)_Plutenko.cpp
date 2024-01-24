#include <stdio.h>
#include <locale>
#include <stdlib.h>
#include <time.h>

void main() {
	setlocale(LC_ALL, "");
	int i, j, m, n;
	int** a;
	int* vector;

	do {
		printf("Введiть розмiр матрицi (N x N), при N <= 10: ");
		scanf_s("%d", &m);
		if (m > 10)
			printf("N > 10\n");
	} while (m > 10);

	n = m;

	a = (int**)malloc(m * sizeof(int*));
	for (i = 0; i < m; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}

	vector = (int*)malloc(m * sizeof(int));

	srand(time(NULL));

	printf("Початкова матриця:\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = rand() % 21 - 10;
			printf("%4d ", a[i][j]);
		}
		printf("\n");
	}

	int d = 1;

	for (i = 0; i < m; i++) {
		vector[i] = 1;
		for (j = 0; j < n; j++) {
			vector[i] *= a[i][j];
		}
	}

	printf("\nВектор з добутку елементiв рядкiв:\n");
	for (i = 0; i < m; i++) {
		printf("%4d\n", vector[i]);
	}
	printf("\n");
}