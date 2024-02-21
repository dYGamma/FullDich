#include <iostream>

//функция возвращает случайное значение от l до r
int randRange(int l, int r) {
    return l + rand() % ((r - l) + 1);
}

//заполняем массив случайными значениями
void fillArr(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = randRange(-(n / 2 - 1), n / 2);
    }
}

//считаем сумму отрицательных
int sumNeg(int* a, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0) {
            sum += a[i];
        }
    }
    printf("Amount: %i\n", sum);
    return sum;
}

//вывод массива
void printArr(int* a, int n) {
    printf("Array: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void countEven(int cnt) {
    printf("Count: %i\n", cnt);
}

int main() {
    srand(time(NULL)); //устанавливаем значение для случайной генерации

    int n = 10; //размер массива
    int* a = new int[n];
    fillArr(a, n); //заполняем              O(n)
    printArr(a, n); //выводим               O(n)

    //считаем кол-во четных
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            ++count;
        }
    }

    printf("1-\tSum\n2-\tCount\nSelect function: ");
    int cmd;
    std::cin >> cmd;
    if (cmd == 1) {
        sumNeg(a, n);
    }
    else if (cmd == 2) {
        countEven(count);  //определяем кол-во   O(1)
    }
    else if (cmd > 2) {
        printf("Error!\n ");
    }
    return 0;
}
