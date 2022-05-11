#include<iostream>
#include"cmd_console_tools.h"
#include"90-b2.h"
#include<iomanip>
using namespace std;

void change_screen(int row, int col, bool line)
{
	
	int hang, lie;
	if (!line)          //无表框
	{
		hang= 23 + (row - 5) * 4;
		lie = 38 + (col - 5) * 6;
	}
	else                       //有表框
	{
		hang = 33 + (row - 5) * 4;
		lie = 48 + (col - 5) * 8;
	}
	cct_setconsoleborder(lie, hang);
	cout << "屏幕当前设置为:" << hang << "行" << lie << "列" << endl;
}

void draw_no_line(arrays origin)
{
	cct_setfontsize("新宋体", 16,8 );            //改变字体
	int x, y;
	cout << "    "; 
	for (int i = 0; i < origin.cols; i++)         //打印列坐标
	{
		cout << "  " << i << "   ";
	}
	cout << endl;
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "┏";
	cct_getxy(x, y);
	cct_showstr(x, y, "━", 15, 0, 3 * origin.cols);
	cout << "┓" << endl;            //画上表框
	for (int i = 0; i < origin.rows; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			cct_setcolor(0, 7);
			k==1? cout<<char('A' + i) : cout<<' ';
			cout << ' ';
			cct_setcolor(15, 0);
			cout << "┃";
			for (int j = 0; j < origin.cols; j++)            
			{
				cct_setcolor(origin.a[i][j], 0);//一次性设置即可
				if (k == 0)
				{
					cout << "┏━┓";
					Sleep(10);
				}
				else if (k == 1)
				{
					cout << "┃" <<setw(2)<<left<<origin.a[i][j]  << "┃";
					Sleep(10);
				}
				else
				{
					cout << "┗━┛";
					Sleep(10);
				}
			}
			cct_setcolor(15, 0);
			cout << "┃"<<endl;
		}
	}
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "┗";
	cct_getxy(x, y);
	cct_showstr(x, y, "━", 15, 0, 3 * origin.cols);
	cout << "┛" << endl;            //画下表框
	cct_setcolor();         //颜色修正
}

void draw_line(arrays origin)
{
	int bg_color, fg_color;
	cct_setfontsize("新宋体", 16, 8);            //改变字体
	cout << "    ";
	for (int i = 0; i < origin.cols; i++)         //打印列坐标
	{
		cout << "  " << i << "     ";
	}
	cout << endl;
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "┏";
	for (int i = 0; i < origin.cols-1; i++)
	{
		cout << "━━━┳";
	}
	cout << "━━━┓" << endl;            //画上表框
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
				cout << "┃";
			}
			else
			{
				if(i<origin.rows-1)
				   cout << "┣";
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
					cout << "┏━┓";
					cct_getcolor(bg_color, fg_color);
					cct_setcolor(15, 0);
					cout << "┃";
					cct_setcolor(bg_color, fg_color);
					Sleep(10);

				}
				else if (k == 1)
				{
					cout << "┃" << setw(2) << left << origin.a[i][j] << "┃";
					cct_getcolor(bg_color, fg_color);
					cct_setcolor(15, 0);
					cout << "┃";
					cct_setcolor(bg_color, fg_color);
					Sleep(10);
				}
				else if(k==2)
				{
					cout << "┗━┛";
					cct_getcolor(bg_color, fg_color);
					cct_setcolor(15, 0);
					cout << "┃";
					cct_setcolor(bg_color, fg_color);
					Sleep(10);
				}
				else
				{
					if (i < origin.rows - 1)
					{
						cct_setcolor(15, 0);
						cout << "━━━";
						if (j < origin.cols - 1)
						{
							cout << "╋";
						}
					}
				}
			}
			if (k == 3)
			{
				if (i == origin.rows - 1)
					break;
				cct_setcolor(15, 0);
				cout << "┫";
			}
			cout << endl;
		}
	}
	cct_setcolor(15, 0);
	cout << "┗";
	for (int i = 0; i < origin.cols - 1; i++)
	{
		cout << "━━━┻";
	}
	cout << "━━━┛" << endl;           //画下表框
	cct_setcolor();         //颜色修正
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
			cout << "┏━┓";
		else if (i == 1)
			cout << "┃" << setw(2) << left << origin.a[row][col] << "┃";
		else
			cout << "┗━┛";
		cct_gotoxy(4 + 8 * col, 3 + 4* row + i+1);
	}
	cct_gotoxy(4 + 8 * col, 3 + 4 * row);  //光标归位
}


void arrow(arrays origin, int keycode2, int &row, int  &col)
{

	if (keycode2 == KB_ARROW_DOWN)            //向下箭头移动
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
	else if (keycode2 == KB_ARROW_UP)         //向上箭头移动
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
//最后一个bool量来判断要不要分布
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
		if (cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2)== CCT_MOUSE_EVENT)               //获取键盘和鼠标的事件
		{
			

		  if (MAction == MOUSE_ONLY_MOVED)
		  {
			change_shade(origin, row, col, 'b');    //清空键盘的值
			cct_getxy(x, y);    //获取当前位置
			if (((MX - 4) / 8 != tempx || (MY - 3) / 4 != tempy) && tempy >= 0 && tempx >= 0 && tempy < origin.rows && tempx < origin.cols)
			{
				change_shade(origin, tempy, tempx, 'b');   //清空上次的框
			}
			if ((MY - 3)< 0 || (MY - 3) / 4 >= origin.rows || (MX - 4)< 0 || (MX - 4) / 8 >= origin.cols)
			{

				cct_gotoxy(tipx, tipy);
				cct_setcolor();
				cout << "[当前鼠标] 位置非法";
				cct_gotoxy(x, y);
			}
			else 
			{
				change_shade(origin, (MY - 3) / 4, (MX - 4) / 8, 'w');  //选中新的框
				cct_gotoxy(tipx, tipy);
				cct_setcolor();
				cout << "[当前鼠标] " <<char('A'+ (MY - 3) / 4 )<< "行" << (MX - 4) / 8 << "列                             ";
				cct_gotoxy(x, y);
			}
		   }
		  else if (MAction == MOUSE_LEFT_BUTTON_CLICK)                 //点击左键
		  {
			  if (!together)
			  {
				  cct_getxy(x, y);    //获取当前位置
				  cct_gotoxy(tipx, tipy);
				  cct_setcolor();
				  cout << "选中了" << char('A' + row) << "行" << col << "列                                ";
				  cct_gotoxy(x, y);
				  break;
			  }
			  else
			  {
				  int key2=0;
				  if (!merge_box(origin, row, col, tipx, tipy, key2,target, sum_scores,ninth))  //调用后续合并函数
				  {
					  for (int i = 0; i < origin.rows; i++)
					  {
						  for (int j = 0; j < origin.cols; j++)
						  {
							  if (origin.b[i][j] == 0)
							  {
								  change_shade(origin, i, j, 'b');//将相邻值选中
							  }
						  }
					  }
					  arrow(origin, key2, row, col);
					  cct_getxy(x, y);    //获取当前位置
					  cct_gotoxy(tipx, tipy);
					  cct_setcolor();
					  cout << "[当前键盘] " << char('A' + row) << "行" << col << "列                             ";
					  cct_gotoxy(x, y);
					  tempr = row;
					  tempc = col;  //记录row和col的值
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
		  if (((MY - 3) >= 0 && (MY - 3) / 4 < origin.rows && (MX - 4) >= 0 && (MX - 4) / 8 < origin.cols))//键盘和鼠标统一
		  {
			  
				  row = (MY - 3) / 4;
				  col = (MX - 4) / 8;
		  }
		}

		// 键盘事件

		else
	    {
			if ((MY - 3) >= 0 && (MY - 3) / 4< origin.rows && (MX - 4) >= 0 && (MX - 4) / 8 < origin.cols)//鼠标位置合法
			{
				change_shade(origin, (MY - 3) / 4, (MX - 4) / 8, 'b');
			}          //消鼠标
			if (((MY - 3)>= 0 && (MY - 3) / 4< origin.rows && (MX - 4) >= 0 && (MX - 4) / 8 < origin.cols))//键盘和鼠标统一
			{
				if (tempr != row || tempc != col)
				{
					row = (MY - 3) / 4;
					col = (MX - 4) / 8;
				}
			}
			
		if (keycode2 == KB_ARROW_DOWN || keycode2 == KB_ARROW_UP || keycode2 == KB_ARROW_LEFT || keycode2 == KB_ARROW_RIGHT)
		{

			arrow(origin, keycode2, row, col);  //调用箭头函数

			cct_getxy(x, y);    //获取当前位置
			cct_gotoxy(tipx, tipy);
			cct_setcolor();
			cout << "[当前键盘] " << char('A' + row) << "行" << col << "列                             ";
			cct_gotoxy(x, y);
			tempr = row;
			tempc = col;  //记录row和col的值
		}
		else if (keycode1 ==13  )                  //回车键
		{
			if (!together)
			{
				cct_getxy(x, y);    //获取当前位置
				cct_gotoxy(tipx, tipy);
				cct_setcolor();
				cout << "选中了" << char('A' + row) << "行" << col << "列                                ";
				cct_gotoxy(x, y);
				break;
			}
			else
			{
				int key2=0;
				if (!merge_box(origin, row, col, tipx, tipy,key2,target,sum_scores,ninth))  //调用后续合并函数
				{
					for (int i = 0; i < origin.rows; i++)
					{
						for (int j = 0; j < origin.cols; j++)
						{
							if (origin.b[i][j] == 0)
							{
								change_shade(origin, i, j, 'b');//将相邻值选中恢复
							}
						}
					}
					arrow(origin, key2, row, col);
					cct_getxy(x, y);    //获取当前位置
					cct_gotoxy(tipx, tipy);
					cct_setcolor();
					cout << "[当前键盘] " << char('A' + row) << "行" << col << "列                             ";
					cct_gotoxy(x, y);
					tempr = row;
					tempc = col;  //记录row和col的值
					new_b(origin);            //更新b
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
				cout << "┏━┓";
			else if (i == 1)
				cout << "┃" << setw(2) << left << origin.a[row][col] << "┃";
			else
				cout << "┗━┛";
			cct_gotoxy(4 + 8 * col, 3 + 4 * row + i + 1);
		}
		cct_gotoxy(4 + 8 * col, 3 + 4 * row);  //光标归位
}






bool merge_box(arrays &origin, int row, int col,int  tipx,int  tipy, int &key2, int target, int &sum_scores,bool ninth)
{
	bool judge;
	int x, y, MX, MY, MAction,key1;
	find_no_recursion(origin, row, col, judge);  //非递归寻找相邻值
	if (!judge)
	{
		cct_getxy(x, y);    //获取当前位置
		cct_gotoxy(tipx, tipy);
		cct_setcolor();
		cout << "此坐标位置无相邻相邻相同数，请换个位置";
		cct_gotoxy(x, y);
		while (1)
		{
			cct_read_keyboard_and_mouse(MX, MY, MAction, key1, key2);
			if (key2 == KB_ARROW_DOWN || key2 == KB_ARROW_UP || key2 == KB_ARROW_LEFT || key2 == KB_ARROW_RIGHT)  //按箭头键
			{

				return false;
			}
			else if (MAction == MOUSE_ONLY_MOVED)              //移动鼠标
			{
				if ((MY - 3) / 4 != row || (MX - 4) / 8 != col)          //鼠标超过一小格
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
					change_shade(origin, i, j, 'p');//将相邻值选中
				}
			}
		}
		cct_getxy(x, y);    //获取当前位置
		cct_gotoxy(tipx, tipy);
		cct_setcolor();
		cout << "箭头键/鼠标移动取消当前选择，回车键/单击左键";
		cct_gotoxy(x, y);
	}
	while (1)
	{
		cct_read_keyboard_and_mouse(MX, MY, MAction, key1, key2);
		if (key1 == 13 || MAction == MOUSE_LEFT_BUTTON_CLICK)
		{
			merge(origin, row, col);  //融合
			int scores = score(origin, row, col); 
			sum_scores += scores;                //获取单次得分及总分
			cct_gotoxy(0, 0);
			cct_setcolor();
			cout << "本次得分:" << scores << ' ' << "总分:" << sum_scores << ' ' << "合成目标:" << target<<"      ";
			draw_box(origin, row, col, false);//画融合后的先前选中框
			Sleep(50);
			draw_box(origin, row, col, true);               //闪烁效果
			Sleep(50);
			draw_box(origin, row, col, false);
			Sleep(50);
			draw_box(origin, row, col, true);               //闪烁效果
			Sleep(50);
			draw_box(origin, row, col, false);

			for (int i = 0; i < origin.rows; i++) 
			{
				for (int j = 0; j < origin.cols; j++)
				{
					if (origin.a[i][j] == 0)
					{
						draw_box(origin, i, j, true);//清除其他先前相同框
					}
				}
			}
			cct_gotoxy(tipx, tipy);
			cct_setcolor();
			cout << "合成完成，回车键/单击左键下落0                      ";
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
												origin.a[f + 1][j] = origin.a[f][j];   //模拟下落效果
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
			cout << "下落0完成，回车键/单击左键填充新值         ";
			while (1)
			{
				if (!ninth)
				{
					cct_read_keyboard_and_mouse(MX, MY, MAction, key1, key2);
				}
				if (ninth||key1 == 13 || MAction == MOUSE_LEFT_BUTTON_CLICK)
				{
					Sleep(50);
					fill_new(origin);              //填充新值并标记填充位置
					for (int i = 0; i < origin.rows; i++)
					{
						for (int j = 0; j < origin.cols; j++)
						{
							if (origin.b[i][j] == -1)
							{
								draw_box(origin, i, j, false);     //画出填充的新值
							}
						}
					}
					if (!ninth)
					{
						cct_gotoxy(tipx, tipy);
						cct_setcolor();
						cout << "本次合成结束，按C/单击左键继续新一次的合成  ";
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
		else if (key2 == KB_ARROW_DOWN || key2 == KB_ARROW_UP || key2 == KB_ARROW_LEFT || key2 == KB_ARROW_RIGHT)  //按箭头键
		{
			
			return false;
		}
		else if (MAction == MOUSE_ONLY_MOVED)              //移动鼠标
		{
			if((MY - 3) / 4!=row ||(MX - 4) / 8!=col)          //鼠标超过一小格
			    return false;
		}
		else
		{
			continue;
		}
	}
}




