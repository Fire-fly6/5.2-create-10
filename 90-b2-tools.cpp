#include<iostream>
#include"90-b2.h"
#include<time.h>
using namespace std;


arrays  creat(const int M, const int N)  //���ɾ���
{
	srand((unsigned)time(NULL));   //��ʼ��ʱ������
	arrays juzhen;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			juzhen.a[i][j] = rand() % 3 + 1;
			juzhen.b[i][j] = juzhen.a[i][j];
		}
	}
	juzhen.rows = M;
	juzhen.cols = N;
	return juzhen;
}

 void find_no_recursion(arrays &origin, int row,int col,bool  &judge)           //�ǵݹ鷽��������ʵ��
{
	int target = origin.b[row][col],jishu=0;
	origin.b[row][col] = 0;
	for (int m = row; m >= 0; m--)                                        //��һ�����ϱ���                     
	{
		if (m == row)//��һ��
		{
			for (int n = col - 1; n >= 0; n--)//�������
			{
				if (origin.a[m][n] == target)
				{
					origin.b[m][n] = 0;
					jishu++;
				}
				else
				{
					break;
				}
			}//��0���

			for (int n = col + 1; n < origin.cols; n++)//���ұ���
			{
				if (origin.a[m][n] == target)
				{
					origin.b[m][n] = 0;
					jishu++;
				}   //��0���
				else
					break;
			}
		}
		else//������
		{
			for (int n = 0; n <origin.cols ;n++)
			{
				if (origin.a[m][n] == target)
				{
					if (origin.b[m+1][n]==0)   //ֱ������һ������
					{
						origin.b[m][n] = 0;
						jishu++;
						while( (origin.a[m][n]== target)&&(n< origin.cols))
						{
							origin.b[m][n] = 0;
							jishu++;
							n++;
						}
					}
					else
					{
						bool have = false;
						int i = n;
						while((origin.a[m][i] == target) && (i < origin.cols))//�������һ������
						{
							if (origin.b[m +1][i] == 0)
							{
								have = true;
								break;
							}
							i++;
						}
						if (have)
						{
							origin.b[m][n]=0;
							jishu++;
						}
					}
				}
			}
		}
	}
		for (int m =1; m<origin.rows; m++)                                     //���±���                    
		{
			for (int n = 0; n < origin.cols; n++)
			{
				if (origin.a[m][n] == target)
				{
					if (origin.b[m - 1][n] == 0)   //ֱ������һ������
					{
						origin.b[m][n] = 0;
						jishu++;
						while ((origin.a[m][n] == target) && (n < origin.cols))
						{
							origin.b[m][n] = 0;
							jishu++;
							n++;
						}
					}
					else
					{
						bool have = false;
						int i = n;
						while ((origin.a[m][i] == target) && (i < origin.cols))//�������һ������
						{
							if (origin.b[m - 1][i] == 0)
							{
								have = true;
								break;
							}
							i++;
						}
						if (have)
						{
							origin.b[m][n] = 0;
							jishu++;
						}
					}
				}
			}
		}

		for (int m =origin.rows-2;( m>=row)&&(m>=0); m--)                                     //�ڶ������ϱ���                    
		{
			for (int n = 0; n < origin.cols; n++)
			{
				if (origin.a[m][n] == target)
				{
					if (origin.b[m+1][n] == 0)   //ֱ������һ������
					{
						origin.b[m][n] = 0;
						jishu++;
						while ((origin.a[m][n] == target) && (n < origin.cols))
						{
							origin.b[m][n] = 0;
							jishu++;
							n++;
						}
					}
					else
					{
						bool have = false;
						int i = n;
						while((origin.a[m][i] == target) && (i < origin.cols))//�������һ������
						{
							if (origin.b[m + 1][i] == 0)
							{
								have = true;
								break;
							}
							i++;
						}
						if (have)
						{
							origin.b[m][n] = 0;
							jishu++;
						}
					}
				}
			}
		}
		judge=(jishu != 0)?  true :false;
 }

 void find_recursion(arrays &origin, int row, int col, bool& judge )              //�ݹ鷽��������ʵ��
 {
	 int target = origin.a[row][col];
	 origin.b[row][col] = 0;
	 bool lower = ((row + 1 < origin.rows) && (origin.a[row + 1][col] == target) && (origin.b[row + 1][col] != 0));
	 bool upper = ((row - 1 >= 0)&& (origin.a[row - 1][col] == target )&&( origin.b[row - 1][col] != 0));
	 bool left = ((col - 1 >= 0) && (origin.a[row][col - 1] == target) && (origin.b[row][col - 1] != 0));
	 bool right = ((col + 1 < origin.cols )&& (origin.a[row][col + 1] == target )&& (origin.b[row][col + 1] != 0));

	 if((row + 1 == origin.rows||origin.a[row + 1][col] != target)&&(row - 1 < 0 || origin.a[row - 1][col] != target)
		 && (col - 1 < 0 || origin.a[row][col - 1] != target) && (col + 1 == origin.cols || origin.a[row][col + 1] != target))
	 {
		 judge = false;
	 }
	 
	 else{
		 if (lower)    //���µݹ�,��ֹ����
		 {
			 judge = true;
			 find_recursion(origin, row + 1, col, judge);
		 }
		 if (upper)             // ���ϵݹ�
		 {
			 judge = true;
			find_recursion(origin, row - 1, col, judge);
		 }
		 if (left)             // ����ݹ�
		 {
			 judge = true;
			find_recursion(origin, row, col - 1, judge);
		 }
		 if (right)             // ���ҵݹ�
		 {
			 judge = true;
			 find_recursion(origin, row, col + 1, judge);
		 }
	 }
 }

 void merge(arrays& origin, int row, int col)           //��ֵͬ�����鲢
 {
	 origin.a[row][col]++;      //����λ����
	 for (int i = 0; i < origin.rows; i++)
	 {
		 for (int j = 0; j < origin.cols; j++)
		 {
			 if (origin.b[i][j] == 0 && (i != row || j != col))
			 {
				 origin.a[i][j] = 0;
			 }
		 }
	 }
 }
 int score(arrays origin, int row, int col)            //��¼���ε÷�
 {
	 int n = 0;
	 for (int i = 0; i < origin.rows; i++)
	 {
		 for (int j = 0; j < origin.cols; j++)
		 {
			 if (origin.b[i][j] == 0)
			 {
				 n++;
			 }
		 }
	 }
	 return (origin.a[row][col] - 1) * n * 3;
 }

 void  remove_0(arrays& after_merge)                               //����������
 {
		 for (int j = 0; j < after_merge.cols; j++)
		 {
			 for (int i = after_merge.rows - 1; i > 0; i--)
			 {
				 if (after_merge.a[i][j] == 0)
				 {
					 for (int k = i-1; k >= 0; k--)
					 {
						 if (after_merge.a[k][j] == 0)
						 {
							 continue;
						 }
						 else
						 {
							 after_merge.a[i][j] = after_merge.a[k][j];
							 after_merge.a[k][j] = 0;
							 break;
						 }
					 }
				 }
			 }
		 }
 }

 int find_a_max(arrays array)                 //Ѱ��a�е����ֵ
 {
	 int max = 0;
	 for (int i = 0; i < array.rows; i++)     //�������飬Ѱ�����ֵ
	 {
		 for (int j = 0; j < array.cols; j++)
		 {
			 if (array.a[i][j] > max)
			 {
				 max = array.a[i][j];
			 }
		 }
	 }
	 return max;
 }

 void fill_new(arrays& after_remove)                   //�����ֵ����-1������λ��
 {
	 int max = find_a_max(after_remove);
	 srand((unsigned)time(NULL));   //��ʼ���������
	 for (int i = 0; i < after_remove.rows; i++)     //�������飬������ֵ��������λ��
	 {
		 for (int j = 0; j < after_remove.cols; j++)
		 {
			 if (after_remove.a[i][j]==0)
			 {
				 int p = rand() % 100 + 1;//���1-100�ĵȸ���ֵ
				 switch (max)
				 {
				 case 3:
					 after_remove.a[i][j] = rand() % 3 + 1;
					 break;
				 case 4:
					 if (p <= 10)//10%
					 {
						 after_remove.a[i][j] = 4;
					 }
					 else {
						 after_remove.a[i][j] = rand() % 3 + 1;
					 }
					 break;
					 break;
				 case 5:
					 if (p <= 10)//10%
					 {
						 after_remove.a[i][j] = 5;
					 }
					 else if (p > 10 && p <= 25)//15%
					 {
						 after_remove.a[i][j] = 4;
					 }
					 else {
						 after_remove.a[i][j] = rand() % 3 + 1;
					 }
					 break;
				 case 6:
					 if (p <= 5)
					 {
						 after_remove.a[i][j] = 6;
					 }
					 else if (p > 5 && p <= 20)
					 {
						 after_remove.a[i][j] = 5;
					 }
					 else
					 {
						 after_remove.a[i][j] = rand() % 4 + 1;
					 }
					 break;
				 default:
					 if (p <= 5)
					 {
						 after_remove.a[i][j] = max;
					 }
					 else if (p > 5 && p <= 10)
					 {
						 after_remove.a[i][j] = max-1;
					 }
					 else if(p>10&&p<=20)
					 {
						 after_remove.a[i][j] = max-2;
					 }
					 else
					 {
						 after_remove.a[i][j] = rand() % (max-3)+ 1;
					 }
				 }

				 after_remove.b[i][j] = -1;     //��-1���b����
			 }
		 }
	 }

 }



 bool judge_gameover(arrays &after_fill)
 {
	 bool judge=false;
	 for (int i = 0; i < after_fill.rows; i++)
	 {
		 for (int j = 0; j < after_fill.cols; j++)
		 {
			 find_no_recursion(after_fill, i, j, judge);
			 if (judge == true)
			 {
				 break;
			 }
			 new_b(after_fill);
		 }
		 if (judge == true)
		 {
			 break;
		 }
	 }
	 return judge;
 }

 void new_b(arrays& after_fill)                    //����b����,ʹ����a��ͬ
 {
	 for (int i = 0; i < after_fill.rows; i++)
	 {
		 for (int j = 0; j < after_fill.cols; j++)
		 {
			 after_fill.b[i][j] = after_fill.a[i][j];
		 }
	 }
 }