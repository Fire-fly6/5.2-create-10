#include<iostream>
#include"90-b2.h"
#include<time.h>
using namespace std;


arrays  creat(const int M, const int N)  //生成矩阵
{
	srand((unsigned)time(NULL));   //初始化时间种子
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

 void find_no_recursion(arrays &origin, int row,int col,bool  &judge)           //非递归方法函数的实现
{
	int target = origin.b[row][col],jishu=0;
	origin.b[row][col] = 0;
	for (int m = row; m >= 0; m--)                                        //第一次向上遍历                     
	{
		if (m == row)//第一行
		{
			for (int n = col - 1; n >= 0; n--)//向左遍历
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
			}//用0标记

			for (int n = col + 1; n < origin.cols; n++)//向右遍历
			{
				if (origin.a[m][n] == target)
				{
					origin.b[m][n] = 0;
					jishu++;
				}   //用0标记
				else
					break;
			}
		}
		else//其他行
		{
			for (int n = 0; n <origin.cols ;n++)
			{
				if (origin.a[m][n] == target)
				{
					if (origin.b[m+1][n]==0)   //直接与下一行相连
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
						while((origin.a[m][i] == target) && (i < origin.cols))//间接与下一行相连
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
		for (int m =1; m<origin.rows; m++)                                     //向下遍历                    
		{
			for (int n = 0; n < origin.cols; n++)
			{
				if (origin.a[m][n] == target)
				{
					if (origin.b[m - 1][n] == 0)   //直接与上一行相连
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
						while ((origin.a[m][i] == target) && (i < origin.cols))//间接与上一行相连
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

		for (int m =origin.rows-2;( m>=row)&&(m>=0); m--)                                     //第二次向上遍历                    
		{
			for (int n = 0; n < origin.cols; n++)
			{
				if (origin.a[m][n] == target)
				{
					if (origin.b[m+1][n] == 0)   //直接与下一行相连
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
						while((origin.a[m][i] == target) && (i < origin.cols))//间接与下一行相连
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

 void find_recursion(arrays &origin, int row, int col, bool& judge )              //递归方法函数的实现
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
		 if (lower)    //向下递归,防止返回
		 {
			 judge = true;
			 find_recursion(origin, row + 1, col, judge);
		 }
		 if (upper)             // 向上递归
		 {
			 judge = true;
			find_recursion(origin, row - 1, col, judge);
		 }
		 if (left)             // 向左递归
		 {
			 judge = true;
			find_recursion(origin, row, col - 1, judge);
		 }
		 if (right)             // 向右递归
		 {
			 judge = true;
			 find_recursion(origin, row, col + 1, judge);
		 }
	 }
 }

 void merge(arrays& origin, int row, int col)           //相同值函数归并
 {
	 origin.a[row][col]++;      //坐标位自增
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
 int score(arrays origin, int row, int col)            //记录单次得分
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

 void  remove_0(arrays& after_merge)                               //下落消除零
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

 int find_a_max(arrays array)                 //寻找a中的最大值
 {
	 int max = 0;
	 for (int i = 0; i < array.rows; i++)     //遍历数组，寻找最大值
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

 void fill_new(arrays& after_remove)                   //填充新值并用-1标记填充位置
 {
	 int max = find_a_max(after_remove);
	 srand((unsigned)time(NULL));   //初始化随机种子
	 for (int i = 0; i < after_remove.rows; i++)     //遍历数组，填充随机值并标记填充位置
	 {
		 for (int j = 0; j < after_remove.cols; j++)
		 {
			 if (after_remove.a[i][j]==0)
			 {
				 int p = rand() % 100 + 1;//获得1-100的等概率值
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

				 after_remove.b[i][j] = -1;     //用-1标记b数组
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

 void new_b(arrays& after_fill)                    //更新b矩阵,使其与a相同
 {
	 for (int i = 0; i < after_fill.rows; i++)
	 {
		 for (int j = 0; j < after_fill.cols; j++)
		 {
			 after_fill.b[i][j] = after_fill.a[i][j];
		 }
	 }
 }