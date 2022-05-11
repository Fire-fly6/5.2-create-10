#include<iostream>
#include"cmd_console_tools.h"
#include"90-b2.h"
#include<iomanip>
using namespace std;

void change_screen(int row, int col, bool line)
{
	
	int hang, lie;
	if (!line)          //�ޱ��
	{
		hang= 23 + (row - 5) * 4;
		lie = 38 + (col - 5) * 6;
	}
	else                       //�б��
	{
		hang = 33 + (row - 5) * 4;
		lie = 48 + (col - 5) * 8;
	}
	cct_setconsoleborder(lie, hang);
	cout << "��Ļ��ǰ����Ϊ:" << hang << "��" << lie << "��" << endl;
}

void draw_no_line(arrays origin)
{
	cct_setfontsize("������", 16,8 );            //�ı�����
	int x, y;
	cout << "    "; 
	for (int i = 0; i < origin.cols; i++)         //��ӡ������
	{
		cout << "  " << i << "   ";
	}
	cout << endl;
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "��";
	cct_getxy(x, y);
	cct_showstr(x, y, "��", 15, 0, 3 * origin.cols);
	cout << "��" << endl;            //���ϱ��
	for (int i = 0; i < origin.rows; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			cct_setcolor(0, 7);
			k==1? cout<<char('A' + i) : cout<<' ';
			cout << ' ';
			cct_setcolor(15, 0);
			cout << "��";
			for (int j = 0; j < origin.cols; j++)            
			{
				cct_setcolor(origin.a[i][j], 0);//һ�������ü���
				if (k == 0)
				{
					cout << "������";
					Sleep(10);
				}
				else if (k == 1)
				{
					cout << "��" <<setw(2)<<left<<origin.a[i][j]  << "��";
					Sleep(10);
				}
				else
				{
					cout << "������";
					Sleep(10);
				}
			}
			cct_setcolor(15, 0);
			cout << "��"<<endl;
		}
	}
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "��";
	cct_getxy(x, y);
	cct_showstr(x, y, "��", 15, 0, 3 * origin.cols);
	cout << "��" << endl;            //���±��
	cct_setcolor();         //��ɫ����
}

void draw_line(arrays origin)
{
	int bg_color, fg_color;
	cct_setfontsize("������", 16, 8);            //�ı�����
	cout << "    ";
	for (int i = 0; i < origin.cols; i++)         //��ӡ������
	{
		cout << "  " << i << "     ";
	}
	cout << endl;
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "��";
	for (int i = 0; i < origin.cols-1; i++)
	{
		cout << "��������";
	}
	cout << "��������" << endl;            //���ϱ��
	for (int i = 0; i < origin.rows; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			cct_setcolor(0, 7);
			k == 1 ? cout << char('A' + i) : cout << ' ';
			cout << ' ';
			cct_setcolor(15, 0);
			if (k < 3)
			{
				cout << "��";
			}
			else
			{
				if(i<origin.rows-1)
				   cout << "��";
			}
			for (int j = 0; j < origin.cols; j++)
			{
				if (origin.a[i][j] <= 12)
				{
					cct_setcolor(origin.a[i][j], 0);
				}
				else
				{
					cct_setcolor(origin.a[i][j] - 15, 12);
				}
				if (k == 0)
				{
					cout << "������";
					cct_getcolor(bg_color, fg_color);
					cct_setcolor(15, 0);
					cout << "��";
					cct_setcolor(bg_color, fg_color);
					Sleep(10);

				}
				else if (k == 1)
				{
					cout << "��" << setw(2) << left << origin.a[i][j] << "��";
					cct_getcolor(bg_color, fg_color);
					cct_setcolor(15, 0);
					cout << "��";
					cct_setcolor(bg_color, fg_color);
					Sleep(10);
				}
				else if(k==2)
				{
					cout << "������";
					cct_getcolor(bg_color, fg_color);
					cct_setcolor(15, 0);
					cout << "��";
					cct_setcolor(bg_color, fg_color);
					Sleep(10);
				}
				else
				{
					if (i < origin.rows - 1)
					{
						cct_setcolor(15, 0);
						cout << "������";
						if (j < origin.cols - 1)
						{
							cout << "��";
						}
					}
				}
			}
			if (k == 3)
			{
				if (i == origin.rows - 1)
					break;
				cct_setcolor(15, 0);
				cout << "��";
			}
			cout << endl;
		}
	}
	cct_setcolor(15, 0);
	cout << "��";
	for (int i = 0; i < origin.cols - 1; i++)
	{
		cout << "��������";
	}
	cout << "��������" << endl;           //���±��
	cct_setcolor();         //��ɫ����
}


void change_shade(arrays origin, const int row, const int col,char color)
{
	if (origin.a[row][col] <= 12)
	{
		if(color=='w')
		   cct_setcolor(origin.a[row][col], 15);
		else if(color=='b')
		{
			cct_setcolor(origin.a[row][col], 0);
		}
		else
		{
			cct_setcolor(origin.a[row][col], 13);
		}
	}
	else
	{
		if(color=='w')
		   cct_setcolor(origin.a[row][col] - 15, 15);
		else  if(color=='b')
		{
			cct_setcolor(origin.a[row][col]-15, 0);
		}
		else
		{
			cct_setcolor(origin.a[row][col]-15, 13);
		}
	}
	cct_gotoxy(4 + 8 * col, 3 + 4 * row);
	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
			cout << "������";
		else if (i == 1)
			cout << "��" << setw(2) << left << origin.a[row][col] << "��";
		else
			cout << "������";
		cct_gotoxy(4 + 8 * col, 3 + 4* row + i+1);
	}
	cct_gotoxy(4 + 8 * col, 3 + 4 * row);  //����λ
}


void arrow(arrays origin, int keycode2, int &row, int  &col)
{

	if (keycode2 == KB_ARROW_DOWN)            //���¼�ͷ�ƶ�
	{
		if (row + 1 < origin.rows)
		{
			change_shade(origin, row, col, 'b');
			row++;
			change_shade(origin, row, col, 'w');
		}
		else
		{
			change_shade(origin, row, col, 'b');
			row = 0;
			change_shade(origin, row, col, 'w');
		}
	}
	else if (keycode2 == KB_ARROW_UP)         //���ϼ�ͷ�ƶ�
	{
		if (row - 1 >= 0)
		{
			change_shade(origin, row, col, 'b');
			row--;
			change_shade(origin, row, col, 'w');
		}
		else
		{
			change_shade(origin, row, col, 'b');
			row = origin.rows - 1;
			change_shade(origin, row, col, 'w');
		}
	}
	else if (keycode2 == KB_ARROW_LEFT)
	{
		if (col - 1 >= 0)
		{
			change_shade(origin, row, col, 'b');
			col--;
			change_shade(origin, row, col, 'w');
		}
		else
		{
			change_shade(origin, row, col, 'b');
			col = origin.cols - 1;
			change_shade(origin, row, col, 'w');
		}
	}
	else if (keycode2 == KB_ARROW_RIGHT)
	{
		if (col + 1 < origin.cols)
		{
			change_shade(origin, row, col, 'b');
			col++;
			change_shade(origin, row, col, 'w');
		}
		else
		{
			change_shade(origin, row, col, 'b');
			col = 0;
			change_shade(origin, row, col, 'w');
		}
	}
}
//���һ��bool�����ж�Ҫ��Ҫ�ֲ�
void  choose(arrays &origin,int tipx,int tipy,bool together,int target,int &sum_scores, bool ninth)
{
	int row = 0, col = 0,x,y,tempx,tempy,tempr=0,tempc=0;
	change_shade(origin, 0, 0, 'w');
	cct_enable_mouse();
	int MX=0, MY=0, MAction, keycode1, keycode2;
	while(1)
	{
		tempx = (MX - 4) / 8;
		tempy = (MY - 3) / 4;
		if (cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2)== CCT_MOUSE_EVENT)               //��ȡ���̺������¼�
		{
			

		  if (MAction == MOUSE_ONLY_MOVED)
		  {
			change_shade(origin, row, col, 'b');    //��ռ��̵�ֵ
			cct_getxy(x, y);    //��ȡ��ǰλ��
			if (((MX - 4) / 8 != tempx || (MY - 3) / 4 != tempy) && tempy >= 0 && tempx >= 0 && tempy < origin.rows && tempx < origin.cols)
			{
				change_shade(origin, tempy, tempx, 'b');   //����ϴεĿ�
			}
			if ((MY - 3)< 0 || (MY - 3) / 4 >= origin.rows || (MX - 4)< 0 || (MX - 4) / 8 >= origin.cols)
			{

				cct_gotoxy(tipx, tipy);
				cct_setcolor();
				cout << "[��ǰ���] λ�÷Ƿ�";
				cct_gotoxy(x, y);
			}
			else 
			{
				change_shade(origin, (MY - 3) / 4, (MX - 4) / 8, 'w');  //ѡ���µĿ�
				cct_gotoxy(tipx, tipy);
				cct_setcolor();
				cout << "[��ǰ���] " <<char('A'+ (MY - 3) / 4 )<< "��" << (MX - 4) / 8 << "��                             ";
				cct_gotoxy(x, y);
			}
		   }
		  else if (MAction == MOUSE_LEFT_BUTTON_CLICK)                 //������
		  {
			  if (!together)
			  {
				  cct_getxy(x, y);    //��ȡ��ǰλ��
				  cct_gotoxy(tipx, tipy);
				  cct_setcolor();
				  cout << "ѡ����" << char('A' + row) << "��" << col << "��                                ";
				  cct_gotoxy(x, y);
				  break;
			  }
			  else
			  {
				  int key2=0;
				  if (!merge_box(origin, row, col, tipx, tipy, key2,target, sum_scores,ninth))  //���ú����ϲ�����
				  {
					  for (int i = 0; i < origin.rows; i++)
					  {
						  for (int j = 0; j < origin.cols; j++)
						  {
							  if (origin.b[i][j] == 0)
							  {
								  change_shade(origin, i, j, 'b');//������ֵѡ��
							  }
						  }
					  }
					  arrow(origin, key2, row, col);
					  cct_getxy(x, y);    //��ȡ��ǰλ��
					  cct_gotoxy(tipx, tipy);
					  cct_setcolor();
					  cout << "[��ǰ����] " << char('A' + row) << "��" << col << "��                             ";
					  cct_gotoxy(x, y);
					  tempr = row;
					  tempc = col;  //��¼row��col��ֵ
					  new_b(origin);
					  continue;
				  }
				  else
				  {
					  break;
				  }
			  }

		  }
		  else          
		  {
			 continue;
		  }
		  if (((MY - 3) >= 0 && (MY - 3) / 4 < origin.rows && (MX - 4) >= 0 && (MX - 4) / 8 < origin.cols))//���̺����ͳһ
		  {
			  
				  row = (MY - 3) / 4;
				  col = (MX - 4) / 8;
		  }
		}

		// �����¼�

		else
	    {
			if ((MY - 3) >= 0 && (MY - 3) / 4< origin.rows && (MX - 4) >= 0 && (MX - 4) / 8 < origin.cols)//���λ�úϷ�
			{
				change_shade(origin, (MY - 3) / 4, (MX - 4) / 8, 'b');
			}          //�����
			if (((MY - 3)>= 0 && (MY - 3) / 4< origin.rows && (MX - 4) >= 0 && (MX - 4) / 8 < origin.cols))//���̺����ͳһ
			{
				if (tempr != row || tempc != col)
				{
					row = (MY - 3) / 4;
					col = (MX - 4) / 8;
				}
			}
			
		if (keycode2 == KB_ARROW_DOWN || keycode2 == KB_ARROW_UP || keycode2 == KB_ARROW_LEFT || keycode2 == KB_ARROW_RIGHT)
		{

			arrow(origin, keycode2, row, col);  //���ü�ͷ����

			cct_getxy(x, y);    //��ȡ��ǰλ��
			cct_gotoxy(tipx, tipy);
			cct_setcolor();
			cout << "[��ǰ����] " << char('A' + row) << "��" << col << "��                             ";
			cct_gotoxy(x, y);
			tempr = row;
			tempc = col;  //��¼row��col��ֵ
		}
		else if (keycode1 ==13  )                  //�س���
		{
			if (!together)
			{
				cct_getxy(x, y);    //��ȡ��ǰλ��
				cct_gotoxy(tipx, tipy);
				cct_setcolor();
				cout << "ѡ����" << char('A' + row) << "��" << col << "��                                ";
				cct_gotoxy(x, y);
				break;
			}
			else
			{
				int key2=0;
				if (!merge_box(origin, row, col, tipx, tipy,key2,target,sum_scores,ninth))  //���ú����ϲ�����
				{
					for (int i = 0; i < origin.rows; i++)
					{
						for (int j = 0; j < origin.cols; j++)
						{
							if (origin.b[i][j] == 0)
							{
								change_shade(origin, i, j, 'b');//������ֵѡ�лָ�
							}
						}
					}
					arrow(origin, key2, row, col);
					cct_getxy(x, y);    //��ȡ��ǰλ��
					cct_gotoxy(tipx, tipy);
					cct_setcolor();
					cout << "[��ǰ����] " << char('A' + row) << "��" << col << "��                             ";
					cct_gotoxy(x, y);
					tempr = row;
					tempc = col;  //��¼row��col��ֵ
					new_b(origin);            //����b
					continue;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			continue;
		}
	 }

	}
}


void draw_box(arrays origin, int row, int col,bool remove)
{
	if (remove)
	{
		cct_setcolor(15, 15);
	}
	else
	{
		if (origin.a[row][col] <= 12)
		{
			cct_setcolor(origin.a[row][col], 0);
		}
		else
		{
			cct_setcolor(origin.a[row][col] - 15, 12);
		}
	}
	cct_gotoxy(4 + 8 * col, 3 + 4 * row);
		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
				cout << "������";
			else if (i == 1)
				cout << "��" << setw(2) << left << origin.a[row][col] << "��";
			else
				cout << "������";
			cct_gotoxy(4 + 8 * col, 3 + 4 * row + i + 1);
		}
		cct_gotoxy(4 + 8 * col, 3 + 4 * row);  //����λ
}






bool merge_box(arrays &origin, int row, int col,int  tipx,int  tipy, int &key2, int target, int &sum_scores,bool ninth)
{
	bool judge;
	int x, y, MX, MY, MAction,key1;
	find_no_recursion(origin, row, col, judge);  //�ǵݹ�Ѱ������ֵ
	if (!judge)
	{
		cct_getxy(x, y);    //��ȡ��ǰλ��
		cct_gotoxy(tipx, tipy);
		cct_setcolor();
		cout << "������λ��������������ͬ�����뻻��λ��";
		cct_gotoxy(x, y);
		while (1)
		{
			cct_read_keyboard_and_mouse(MX, MY, MAction, key1, key2);
			if (key2 == KB_ARROW_DOWN || key2 == KB_ARROW_UP || key2 == KB_ARROW_LEFT || key2 == KB_ARROW_RIGHT)  //����ͷ��
			{

				return false;
			}
			else if (MAction == MOUSE_ONLY_MOVED)              //�ƶ����
			{
				if ((MY - 3) / 4 != row || (MX - 4) / 8 != col)          //��곬��һС��
					return false;
			}
			else
			{
				continue;
			}
		}
	}
	else
	{
		change_shade(origin, row, col, 'w');
		for (int i = 0; i < origin.rows; i++)
		{
			for (int j = 0; j < origin.cols; j++)
			{
				if (origin.b[i][j] == 0&&(i!=row||j!=col))
				{
					change_shade(origin, i, j, 'p');//������ֵѡ��
				}
			}
		}
		cct_getxy(x, y);    //��ȡ��ǰλ��
		cct_gotoxy(tipx, tipy);
		cct_setcolor();
		cout << "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/�������";
		cct_gotoxy(x, y);
	}
	while (1)
	{
		cct_read_keyboard_and_mouse(MX, MY, MAction, key1, key2);
		if (key1 == 13 || MAction == MOUSE_LEFT_BUTTON_CLICK)
		{
			merge(origin, row, col);  //�ں�
			int scores = score(origin, row, col); 
			sum_scores += scores;                //��ȡ���ε÷ּ��ܷ�
			cct_gotoxy(0, 0);
			cct_setcolor();
			cout << "���ε÷�:" << scores << ' ' << "�ܷ�:" << sum_scores << ' ' << "�ϳ�Ŀ��:" << target<<"      ";
			draw_box(origin, row, col, false);//���ںϺ����ǰѡ�п�
			Sleep(50);
			draw_box(origin, row, col, true);               //��˸Ч��
			Sleep(50);
			draw_box(origin, row, col, false);
			Sleep(50);
			draw_box(origin, row, col, true);               //��˸Ч��
			Sleep(50);
			draw_box(origin, row, col, false);

			for (int i = 0; i < origin.rows; i++) 
			{
				for (int j = 0; j < origin.cols; j++)
				{
					if (origin.a[i][j] == 0)
					{
						draw_box(origin, i, j, true);//���������ǰ��ͬ��
					}
				}
			}
			cct_gotoxy(tipx, tipy);
			cct_setcolor();
			cout << "�ϳ���ɣ��س���/�����������0                      ";
			while (1)
			{
				if (!ninth)
				{
					cct_read_keyboard_and_mouse(MX, MY, MAction, key1, key2);
				}
					if (key1 == 13 || MAction == MOUSE_LEFT_BUTTON_CLICK || ninth)
					{
						for (int j = 0; j < origin.cols; j++)
						{
							for (int i = origin.rows - 1; i > 0; i--)
							{
								if (origin.a[i][j] == 0)
								{
									for (int k = i - 1; k >= 0; k--)
									{
										if (origin.a[k][j] == 0)
										{
											continue;
										}
										else
										{
											for (int f = k; f < i; f++)
											{
												origin.a[f + 1][j] = origin.a[f][j];   //ģ������Ч��
												origin.a[f][j] = 0;
												Sleep(50);
												draw_box(origin, f, j, true);
												draw_box(origin, f + 1, j, false);
											}
											break;
										}
									}
								}
							}
						}
						break;
					}
				else
				{
					continue;
				}
			}
			cct_gotoxy(tipx, tipy);
			cct_setcolor();
			cout << "����0��ɣ��س���/������������ֵ         ";
			while (1)
			{
				if (!ninth)
				{
					cct_read_keyboard_and_mouse(MX, MY, MAction, key1, key2);
				}
				if (ninth||key1 == 13 || MAction == MOUSE_LEFT_BUTTON_CLICK)
				{
					Sleep(50);
					fill_new(origin);              //�����ֵ��������λ��
					for (int i = 0; i < origin.rows; i++)
					{
						for (int j = 0; j < origin.cols; j++)
						{
							if (origin.b[i][j] == -1)
							{
								draw_box(origin, i, j, false);     //����������ֵ
							}
						}
					}
					if (!ninth)
					{
						cct_gotoxy(tipx, tipy);
						cct_setcolor();
						cout << "���κϳɽ�������C/�������������һ�εĺϳ�  ";
						while (1)
						{
							cct_read_keyboard_and_mouse(MX, MY, MAction, key1, key2);
							if (key1 == 'c' || key1 == 'C' || MAction == MOUSE_LEFT_BUTTON_CLICK)
								break;
							else
								continue;
						}
					}
					break;
				}
				else
				{
					continue;
				}
			}
			return true;
		}
		else if (key2 == KB_ARROW_DOWN || key2 == KB_ARROW_UP || key2 == KB_ARROW_LEFT || key2 == KB_ARROW_RIGHT)  //����ͷ��
		{
			
			return false;
		}
		else if (MAction == MOUSE_ONLY_MOVED)              //�ƶ����
		{
			if((MY - 3) / 4!=row ||(MX - 4) / 8!=col)          //��곬��һС��
			    return false;
		}
		else
		{
			continue;
		}
	}
}




