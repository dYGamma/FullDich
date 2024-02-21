#include <iostream>

//������� ���������� ��������� �������� �� l �� r
int randRange(int l, int r) {
    return l + rand() % ((r - l) + 1);
}

//��������� ������ ���������� ����������
void fillArr(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = randRange(-(n / 2 - 1), n / 2);
    }
}

//������� ����� �������������
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

//����� �������
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
    srand(time(NULL)); //������������� �������� ��� ��������� ���������

    int n = 10; //������ �������
    int* a = new int[n];
    fillArr(a, n); //���������              O(n)
    printArr(a, n); //�������               O(n)

    //������� ���-�� ������
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
        countEven(count);  //���������� ���-��   O(1)
    }
    else if (cmd > 2) {
        printf("Error!\n ");
    }
    return 0;
}
