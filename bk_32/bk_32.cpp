#define N 10
#include <stdio.h>

void printArray(int A[], int n);
void calc(int val, int A[], int n);
//val заданное число
//A - массив простых множителей
//n - размерность массива
void calc1(int val, int A[], int n);
//val заданное число
//A - массив простых множителей
//n - размерность массива
int calc3();


int main() {

	//int A[N] = {0};
	int B[N] = { 0 };
	calc(72, B, N);
	printArray(B, N);
	return 0;
}

void printArray(int A[], int n)
{
	for (int i = 0; i < n && A[i] != 0; i++)
	{
		printf("%3d", A[i]);
	}
}

//Простые множители
//Сформировать массив простых множителей заданного числа.
//Простые множители числа - простые числа, произведение которых дает заданное число, 
//например: 72 = 2 * 2 * 2 * 3 * 3.
void calc(int val, int A[], int n)
{
	int i; //количество множителей
	int m;  //значение множителя
	for ( i = 0; i < n-1 && val != 1; i++)
	{
		// получить значение множителя в массив
		for (m = 2; val % m != 0; m++);
		val /= m;
		A[i] = m;
	}
	A[i] = 0;
}

//Простые числа
//Сформировать массив простых чисел, не превышающих заданное.
//Простое число - число, которое делится нацело только на 1 и на само себя.

void calc1(int val, int A[], int n) 
{
	int i; // номер очередного простого числа
	int m; // очередное проверяемое число
	int k;
	for ( i = 0, m = 2; i < n-1 && m < val; i++)
	{
		for (k = 0; k < i; k++)
			if (m % A[k] == 0) break;
		if (i == k)
			A[i++] = m;

	}
	A[i] = 0;
}

//Счастливые билеты
//“Счастливым” называется билет, в котором в шестизначном номере 
//сумма первых трех цифр равна сумме последних трех.
int	calc3()
{
	int	n, B[6];
	long	v;
	for (n = 0, v = 0; v < 1000000; v++)
	{
		int	m;
		long 	vv;
		for (vv = v, m = 0; m < 6; m++, vv /= 10)
			B[m] = vv % 10;
		if (B[0] + B[1] + B[2] == B[3] + B[4] + B[5]) n++;
	}
	return n;
}

//------------------------------------------------ 1
int	F1(int c[], int n)
{
	int s, i;
	for (s = 0, i = 0; i < n; i++) s += c[i];  return s;
}
//------------------------------------------------ 2
int	F2(int c[], int n)
{
	int m, i, k;
	for (m = c[0], i = 1, k = 0; i < n; i++) {
		if (c[i] > m) {
			m = c[i]; k = i; 
		}
	}
	return k;
}
//------------------------------------------------ 3
int	F3(int c[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (c[i] == c[j]) return i;
	return -1;
}
//------------------------------------------------ 4
int	F4(int n)
{
	int k, m;
	for (k = 0, m = 1; m <= n; k++, m = m * 2);
	return k - 1;
}
//------------------------------------------------ 5
void	F5(int c[], int n)
{
	int i, j, k;
	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		k = c[i]; c[i] = c[j]; c[j] = k;
	}
}
//------------------------------------------------ 6
int	F6(int c[], int n)
{
	int i, j, k1, k2;
	for (i = 0; i < n; i++)
	{
		for (j = k1 = k2 = 0; j < n; j++)
			if (c[i] != c[j])
			{
				if (c[i] < c[j]) k1++; else k2++;
			}
		if (k1 == k2) return i;
	}
	return -1;
}
//------------------------------------------------ 7
int	F7(int c[], int n)
{
	int i, j, m, s;
	for (s = 0, i = 0; i < n - 1; i++)
	{
		for (j = i + 1, m = 0; j < n; j++)
			if (c[i] == c[j]) m++;
		if (m > s) s = m;
	}
	return s;
}
//------------------------------------------------ 8
int	F8(int c[], int n)
{
	int i, j, k, m;
	for (i = k = m = 0; i < n - 1; i++)
		if (c[i] < c[i + 1])
			k++;
		else
		{
			if (k > m) m = k;
			k = 0;
		}
	return m;
}
//------------------------------------------------ 9
int	F9(int n)
{
	int i, k, c[6];
	for (i = 0; n != 0; i++, n /= 10) c[i] = n % 10;
	for (k = 0; k < i; k++) n = n * 10 + c[k];
	return n;
}
//------------------------------------------------ 10
int	F10(int n)
{
	int m, k;
	for (m = 0; n != 0; n /= 10)
		if ((k = n % 10) > m) m = k;
	return m;
}

