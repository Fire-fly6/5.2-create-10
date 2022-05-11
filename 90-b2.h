#pragma once
#define MAX_ROW 8
#define MAX_COL 10
#include<windows.h>
#include<conio.h>


typedef struct arrays    //����˫����ṹ�壬���þ���
{
	int rows;  //����
	int cols;   //����
	int a[MAX_ROW][MAX_COL];
	int b[MAX_ROW][MAX_COL];
}arrays;

arrays  creat(const int M, const int N);             //�ṹ�����ɺ���������
void find_no_recursion(arrays& origin, int row, int col, bool& judge);  //�ǵݹ鷽ʽѰ������
void   find_recursion(arrays &origin, int row, int col, bool& judge);  //�ݹ鷽ʽѰ�Һ���������
void merge(arrays& origin, int row, int col);      //��ֵͬ�鲢����������
int score(arrays origin, int row, int col);            //���μƷֺ���������
void  remove_0(arrays& origin);                        //���㺯��������
void fill_new(arrays& after_remove);                   //��亯��������
void new_b(arrays& after_fill);                       //b������º���������
bool judge_gameover(arrays& after_fill);                //�ж���Ϸ�Ƿ��������������
int find_a_max(arrays array);                            //Ѱ��a�������ֵ����������



void change_screen(int row, int col,bool line);           //�ı���Ļ��С����������
void draw_no_line(arrays origin);                     //��ͼ����(�ޱ��)����
void draw_line(arrays origin);                        //��ͼ����(�б��)����
void change_shade(arrays origin ,const int x, const int y, char color); //�ı���ɫ��������
void draw_box(arrays origin, int row, int col, bool remove);
void arrow(arrays origin, int keycode2, int& row, int& col);
void choose(arrays &origin, int tipx, int tipy,bool together,int target, int &sum_scores, bool ninth); //ѡ����Ӻ�������
bool merge_box (arrays &origin, int row, int col, int  tipx, int  tipy, int &key2, int target,int &sum_scores, bool ninth);  //�ϲ���������