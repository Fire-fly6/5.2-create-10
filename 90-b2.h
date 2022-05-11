#pragma once
#define MAX_ROW 8
#define MAX_COL 10
#include<windows.h>
#include<conio.h>


typedef struct arrays    //定义双数组结构体，放置矩阵
{
	int rows;  //行数
	int cols;   //列数
	int a[MAX_ROW][MAX_COL];
	int b[MAX_ROW][MAX_COL];
}arrays;

arrays  creat(const int M, const int N);             //结构体生成函数的声明
void find_no_recursion(arrays& origin, int row, int col, bool& judge);  //非递归方式寻找声明
void   find_recursion(arrays &origin, int row, int col, bool& judge);  //递归方式寻找函数的声明
void merge(arrays& origin, int row, int col);      //相同值归并函数的声明
int score(arrays origin, int row, int col);            //单次计分函数的声明
void  remove_0(arrays& origin);                        //除零函数的声明
void fill_new(arrays& after_remove);                   //填充函数的声明
void new_b(arrays& after_fill);                       //b矩阵更新函数的声明
bool judge_gameover(arrays& after_fill);                //判断游戏是否结束函数的声明
int find_a_max(arrays array);                            //寻找a矩阵最大值函数的声明



void change_screen(int row, int col,bool line);           //改变屏幕大小函数的声明
void draw_no_line(arrays origin);                     //画图函数(无表框)声明
void draw_line(arrays origin);                        //画图函数(有表框)声明
void change_shade(arrays origin ,const int x, const int y, char color); //改变颜色函数声明
void draw_box(arrays origin, int row, int col, bool remove);
void arrow(arrays origin, int keycode2, int& row, int& col);
void choose(arrays &origin, int tipx, int tipy,bool together,int target, int &sum_scores, bool ninth); //选择格子函数声明
bool merge_box (arrays &origin, int row, int col, int  tipx, int  tipy, int &key2, int target,int &sum_scores, bool ninth);  //合并函数声明