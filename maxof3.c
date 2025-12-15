#include <stdio.h>
#include <Windows.h>

void main() {
	int v1,v2,v3,max;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("¬ведите 3 числа через пробел = ");
	scanf_s("%d%d%d", &v1,&v2,&v3);
	max = v1;
	if (v2 > max)
		max = v2;
	if (v3 > max)
		max = v3;
	printf("Max = %d\n", max);
}