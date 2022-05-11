#include<iostream>
#include"cmd_console_tools.h"
#include"90-b2.h"
#include<iomanip>
using namespace std;


void print(arrays origin,char choice)  //根据choice的值选择打印当前数组a,查找结果数组b,不同色标识的当前数组c,除零后的数组d, 填充后的数组e
{
	int x, y;
	cout << "  |  ";
	for (int i = 0; i < origin.cols; i++)
	{
		cout << i << "  ";
	}
	cout << endl;
	cout << "--|--";
	cct_getxy(x, y);
	cct_showch(x, y, '-', 0, 7, 3 * origin.cols); //打印表框
	cout << endl;
	for (int i = 0; i < origin.rows; i++)
	{
		cout << char('A' + i) << " |  ";
		for (int j = 0; j < origin.cols; j++)
		{
			if (choice == 'a')
			{
				cout <<setw(2)<<left<< origin.a[i][j] << " ";
			}
			else if (choice == 'b')
			{
				if (origin.b[i][j] == 0)
				{
					cout << "*  ";
				}
				else
				{
					cout << 0 << "  ";
				}
			}
			else if(choice=='c')
			{
				if (origin.b[i][j] == 0)
				{
					cct_setcolor(6, 0);
				}
				if (origin.a[i][j] < 10)
				{
					cout << origin.a[i][j];
					cct_setcolor(0, 7);
					cout << "  ";
				}
				else
				{
					cout<<origin.a[i][j];
					cct_setcolor(0, 7);
					cout << " ";
				}
			}
			else if (choice == 'd')
			{
				if (origin.a[i][j] == 0)
				{
					cct_setcolor(6, 0);
				}
				if (origin.a[i][j] < 10)
				{
					cout << origin.a[i][j];
					cct_setcolor(0, 7);
					cout << "  ";
				}
				else
				{
					cout << origin.a[i][j];
					cct_setcolor(0, 7);
					cout << " ";
				}
			}
			else
			{
				if (origin.b[i][j] == -1)
				{
					cct_setcolor(6, 0);
				}
				if (origin.a[i][j] < 10)
				{
					cout << origin.a[i][j];
					cct_setcolor(0, 7);
					cout << "  ";
				}
				else
				{
					cout << origin.a[i][j];
					cct_setcolor(0, 7);
					cout << " ";
				}
			}
		}
		cout << endl;
	}
}


