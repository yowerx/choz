#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define NUM_ELEMENTS 10
int arr[NUM_ELEMENTS];
int n = 0;

void printElements() {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
void keyboardInput() {
    printf("n = ");
    scanf_s("%d", &n);

    printf("input %d values: ", n);
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }
}

void oddsX10() {
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 1) arr[i] = arr[i] * 10;
    }
}

int findMin() {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

int elementsBigger10() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 10) count += 1;
    }
    return count;
}
int findLastEven() {
    int lastEvenIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            lastEvenIndex = i;
        }
    }

    if (lastEvenIndex == -1)
        return -1;   // нет четных

    return arr[lastEvenIndex] * 2;
}

int findIndexMin() {
    int min = arr[0];
    int minindex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minindex = i;
        }
    }
    return minindex;

}

int findIndexMax() {
    int max = arr[0];
    int maxindex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxindex = i;
        }
    }
    return maxindex;
}

int findMax() {
    int max = arr[0];
    int maxindex = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxindex = i;
        }
    }
    return max;
}

int findFirstEven() {
    int firstelement;
    int firsteven = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            firsteven = i;
            break;
        }
    }
    return -1; //net 4entix
}

void deleteElement(int delIndex) {
    for (int i = delIndex; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}





void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int item;
    do {
        printf("\n");
        printf("-------------------------------\n");
        printf("Содержимое массива: ");
        printElements();
        printf("\n");
        printf("Введите нужную вам операцию:\n");
        printf("1: Ввести с клавиатуры массив\n");
        printf("2: x10 для всех нечетных элементов\n");
        printf("3: Найти минимальный элемент\n");
        printf("4: Кол-во элементов больше 10\n");
        printf("5: Последнее четное умноженное на 2\n");
        printf("6: Кол-во четных левее минимального:\n");
        printf("7: Умножить на 10 все элементы правее минимального\n");
        printf("8: переставить местами min и max\n");
        printf("9: все четные * -1\n");
        printf("10: все эл. меньше 4 заменить на 4\n");
        printf("11: заменить все перед макс. на 0\n");
        printf("\n");
        printf("0: Выйти из программы\n");
        printf("Выбранная вами операция >>> ");
        printf("\n");
        scanf_s("%d", &item);

        switch (item) {
        case 1:
            keyboardInput();
            break;
        case 2:
            oddsX10();
            break;
        case 3:
        {
            int min = findMin();
            printf("min = %d\n", min);
        }
        break;
        case 4:
        {
            int count = elementsBigger10();
            printf("more than 10 = %d\n", count);
        }
        break;
        case 5:
        {
            int x2 = findLastEven();
            printf("last even * 2 = %d\n", x2);
        }
        break;
        case 6:
        {
            int index = findIndexMin();
            printf("Индекс минимального элемента - %d\n", index);

            int cnt = 0;
            for (int i = 0; i < index; i++) {
                if (arr[i] % 2 == 0) cnt++;

            }
            printf("Левее минимального %d четных элементов\n", cnt);
        }
        break;
        case 7:
        {
            int index1 = findIndexMin();
            for (int i = index1 + 1; i < n; i++) {
                if (arr[i] % 2 == 1) arr[i] *= 10;
            }
        }
        break;
        case 8:
        {
            int indexMin = findIndexMin();
            printf("Index min = %d\n", indexMin);
            int indexMax = findIndexMax();
            printf("Index max = %d\n", indexMax);


            int temp = arr[indexMin];
            arr[indexMin] = arr[indexMax];
            arr[indexMax] = temp;
        }
        break;
        case 9:
        {
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 == 0) arr[i] *= -1;
            }
        }
        break;
        case 10:
        {
            for (int i = 0; i < n; i++) {
                if (arr[i] < 4) arr[i] = 4;
            }
        }
        break;
        case 11:
        {
            int indexMax = findIndexMax();
            for (int i = 0; i < indexMax; i++) {
                arr[i] = 0;
            }
        }
        break;
        case 12:
        {
            int indexMax = findIndexMax();
            int indexMin = findIndexMin();
            for (int i = 0; i < n; i++) {
                int index = i;
                if ((i < indexMax && i > indexMin) || (i > indexMax && i < indexMin)) {
                    arr[i] *= 10;
                }

            }
        }
        break;
        case 13:
        {
            int firstEven = findFirstEven();
            int lastEven = findLastEven();
            for (int i = 0; i < n; i++) {
                int index = i;
                if (i > firstEven && i < lastEven) arr[i] *= 100;
            }
        }
        }


    } while (item != 0);

}
