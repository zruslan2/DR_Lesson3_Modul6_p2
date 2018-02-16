#include <vector>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int i, j;

void head(char mas[])
{
	int len, third, s1_len, s2_len, s3_len, maks;
	len = strlen(mas);
	third = len / 3;
	s1_len = third;
	for (int i = s1_len; i < len; i++)
	{
		if (mas[s1_len] != ' ') s1_len++;
		else break;
	}
	s2_len = third;
	for (int i = s1_len + s2_len; i < len; i++)
	{
		if (mas[s1_len + s2_len] != ' ') s2_len++;
		else break;
	}
	s3_len = len - (s1_len + s2_len);
	vector<char>str1(s1_len);
	vector<char>str2(s2_len);
	vector<char>str3(s3_len);
	for (int i = 0; i < s1_len; i++)
	{
		str1[i] = mas[i];
	}
	for (int i = s1_len + 1; i < s1_len + s2_len; i++)
	{
		str2[i - (s1_len + 1)] = mas[i];
	}
	for (int i = s1_len + s2_len + 1; i < len; i++)
	{
		str3[i - (s1_len + s2_len + 1)] = mas[i];
	}
	maks = s1_len;
	if (s2_len > maks)maks = s2_len;
	if (s3_len > maks)maks = s3_len;
	system("cls");
	SetConsoleTextAttribute(hConsole, 11);
	setlocale(LC_ALL, ".866");
	cout << " Ú";
	for (int i = 0; i <= maks + 1; i++)cout << "Ä";
	cout << "¿\n";
	cout << " ³ "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s1_len; i++) cout << str1[i];
	if (s1_len < maks)
	{
		for (int i = 0; i < maks - s1_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " ³\n";
	cout << " ³ "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s2_len; i++) cout << str2[i];
	if (s2_len < maks)
	{
		for (int i = 0; i < maks - s2_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " ³\n";
	cout << " ³ "; setlocale(LC_ALL, ".1251");
	for (int i = 0; i<s3_len; i++) cout << str3[i];
	if (s3_len < maks)
	{
		for (int i = 0; i < maks - s3_len; i++)cout << " ";
	}
	setlocale(LC_ALL, ".866"); cout << " ³\n";
	cout << " À";
	for (int i = 0; i <= maks + 1; i++)cout << "Ä";
	cout << "Ù\n";
	SetConsoleTextAttribute(hConsole, 15);
	setlocale(LC_ALL, ".1251");
}

void yellow()
{
	SetConsoleTextAttribute(hConsole, 14);
}

void white()
{
	SetConsoleTextAttribute(hConsole, 15);
}

void red()
{
	SetConsoleTextAttribute(hConsole, 12);
}

void green()
{
	SetConsoleTextAttribute(hConsole, 11);
}

int fgp(int f, int zn,int n)
{
	int z=f*zn;;
	if (n <= 2)
	{
		return z;
	}
		n--;
	z=fgp(f, zn, n);	
	z *= zn;
	return z;
}

int fgpSum(int f, int zn, int n, int sum)
{		
	sum += f;
	if (n <= 1)
		return sum;

	n--;
	f *= zn;

	sum = fgpSum(f, zn, n, sum);

	return sum;
}

int maxArr(int* arr, int r, int max, int nach)
{
	if (*arr > max) max = *arr;
	if (nach > r)
	{			
		return max;
	}
	nach++;
	arr++;
	max = maxArr(arr, r, max, nach);
	return max;
}

int maxIndArr(int* arr, int r, int max, int nach, int ind)
{
	if (*arr > max)
	{
		max = *arr;	
		ind = nach;
	}
	if (nach > r)
	{
		return ind;
	}
	nach++;
	arr++;
	ind = maxIndArr(arr, r, max, nach,ind);
	return ind;
}

void randArr(int * mas, int r, int start, int end)
{
	srand(time(0));

	for (int i = 0; i < r; i++)
	{
		*mas = start + rand() % end;
		mas++;
	}
}

void printArr(int *mas, int r)
{
	for (int i = 0; i < r; i++)
		cout << mas[i] << "\t";
	cout << endl;
}

int Sum(int *arr, int r, bool pol)
{
	int sum = 0;
	if (pol == true)
	{
		for (int i = 0; i < r; i++)
		{
			if (arr[i] > 0) sum += arr[i];
		}
		return sum;
	}
	else
	{
		for (int i = 0; i < r; i++)
		{
			if (arr[i] < 0) sum += arr[i];
		}
		return sum;
	}
}

int algEvq(int x, int y)
{
	int ost=1;
	if (x > y)
	{
		while (ost > 0)
		{
			ost = x%y;
			if (ost != 0)
			{
				x = y;
				y = ost;
			}
			else break;
		}		
		return y;
	}
	else
	{
		while (ost > 0)
		{
			ost = y%x;
			if (ost != 0)
			{
				y = x;
				x = ost;
			}
			else break;
		}
		return x;
	}
}