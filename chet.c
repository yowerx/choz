#include <stdio.h>
#include <Windows.h>

void main() {
	int v1;
	int i = 1;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("¬ведите количество чисел N = ");
	scanf_s("%d", &v1);

	do {
		printf("%d ", 2*i);
		i++;
	} while (i <= v1);

}