#include <stdio.h>
const int NUMBER_TO_COMPARE = 3; // ����� ��� ���������

 int calculationAmount(int* mas, int n)
 {
 int sum = 0;
 for (int i = 0; i < n; i++)
 {
 sum += mas[i];
 }
 printf("Amount: %i \n", sum);
 return sum;

}
void countingDuplicates(int duplicates)
{
 printf("Count: %i \n", duplicates);
}

int main()
{
 int A[] = { 5, 7, 3, 1, 3, 8 }; // �������� ������
 int N = sizeof(A) / sizeof(int); // ���������� ��������� � �������
 calculationAmount(A, N);
 int count = 0;
 for (int i = 0; i < N; i++)
 {
 if (A[i] == NUMBER_TO_COMPARE)
 {
 count++;
 }
 }
 countingDuplicates(count);
};
