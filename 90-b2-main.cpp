#include<iostream>
#include"cmd_console_tools.h"
#include<climits>
#include"90-b2.h"
using namespace std;
void print(arrays origin,char choice); //矩阵打印函数的声明

int menu()                                               //菜单函数
{
	cct_setconsoleborder(120, 30, 120, 9001);
	cout << "1.命令行找出可合成项并标识（非递归）\n";
	cout << "2.命令行找出可合成项并标识（递归）\n";
	cout << "3.命令行完成一次合成（分步骤显示）\n";
	cout << "4.命令行完整版（分步骤显示）\n";
	cout << "5.伪图形界面显示初始数组（无分隔线）\n";
	cout << "6.伪图形界面显示初始数组（有分隔线）\n";
	cout << "7.伪图形界面下用箭头键/鼠标选择当前色块\n";
	cout << "8.伪图形界面完成一次合成（分步骤）\n";
	cout << "9.伪图形界面完整版（支持鼠标）\n";
	cout << "-----------------------------------------\n";
	cout << "0.退出\n";
	cout << "-----------------------------------------\n";
	cout << "[请选择:]";
	int n = _getche()-'1'+1;
	return n;
}


int main()
{
	
		while (1)
		{
			cct_cls();
			int row, col;
			int n = menu();
			if (n == 0)
			{
				cct_cls();
				return 0;
			}
			else  if(n<0||n>9)
			{
				cct_cls();
				return 0;
			}
			else 
			{
				cct_cls();
				while (1)
				{
					cout << "请输入行数(5-8):\n";                            //获取行数和列数
					cin >> row;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');//清空缓冲区
						continue;
					}
					else
					{
						if (row < 5 || row>8)
							continue;
						else
							break;
					}
				}
				while (1)
				{
					cout << "请输入列数(5-10):\n";
					cin >> col;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');//清空缓冲区
						continue;
					}
					else
					{
						if (col < 5 || col>10)
							continue;
						else
							break;
					}
				}
				int final_target = 0;
				if (n == 3 || n == 4 || n == 8 || n == 9)                                      //获取最终合成目标
				{
					while (1)
					{
						cout << "请输入合成目标(5-20):\n";
						cin >> final_target;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(INT_MAX, '\n');//清空缓冲区
							continue;
						}
						else
						{
							if (final_target < 5 || final_target>20)
								continue;
							else
								break;
						}
					}

				}

				arrays origin_array = creat(row, col);   //    双矩阵结构体生成

				int sum_scores = 0;                   //初始化总分
				if (n == 1 || n == 2 || n == 3 || n == 4)   //由menu的选择进入不同的函数  1234
				{
					while (1)
					{
						if (find_a_max(origin_array) == final_target)        //判断是否达到合成目标
						{
							cct_setcolor(14, 4);
							cout << "已经合成到" << final_target;
							cct_setcolor(0, 7);
							cout << endl;
							cout << "按回车键继续向更高目标进发...\n";
							while (1)
							{
								int huiche = _getch();
								if (huiche == 13)
								{
									break;
								}
								else
								{
									continue;
								}
							}
							final_target++;
						}
						cout << endl;
						cout << "当前数组:\n";
						print(origin_array, 'a');
						cout << endl;
						new_b(origin_array);
						if (!judge_gameover(origin_array))              //判断游戏是否结束
						{
							cct_setcolor(14, 4);
							cout << "无相邻位置值相等，游戏结束\n";
							cct_setcolor(0, 7);
							break;
						}
						cout << "请以字母+数字形式[例:c2]输入矩阵坐标:";
						char s[2], * p = s;                          //定义字符数组装矩阵坐标
						while (1)
						{
							new_b(origin_array);            //刷新b,把b改回来
							cin >> p;
							*p = (*p < 'a') ? *p : *p - 'a' + 'A';        //行数转化为大写
							bool  judge = false;
							if (n == 2)
							{
								find_recursion(origin_array, *p - 'A', *(p + 1) - '1' + 1, judge);
								//判断相邻位置是否有值相等并改变b矩阵         调用递归函数
							}
							else
							{

								find_no_recursion(origin_array, *p - 'A', *(p + 1) - '1' + 1, judge);
								//判断相邻位置是否有值相等并改变b矩阵         调用非递归函数
							}
							if ((*p<'A' || *p>char('A' + row - 1)) || (*(p + 1) < '0' || *(p + 1) > char('0' + col - 1)))
							{
								cout << "输入错误,请重新输入:\n";
								continue;
							}
							else {
								if (judge)
									break;
								else
								{
									cout << "此坐标位置无相邻相邻相同数，请重新输入:\n";
									continue;
								}
							}
						}
						cout << "输入为" << *p << "行" << *(p + 1) << "列" << endl;
						cout << endl;
						cout << "查找结果数组:\n";
						print(origin_array, 'b');
						cout << endl;
						cout << "当前数组(不同色标识):\n";
						print(origin_array, 'c');
						cout << endl;

						//接第3小题
						if (n == 3 || n == 4)                      //接第3小题
						{
							char choice;
							cout << endl;
							cout << "请确认是否把相邻的相同值合并到" << *p << *(p + 1) << "中(Y/N/Q):";
							while (1)
							{
								choice = _getch();                   //获取选择,有回显
								if (choice == 'n' || choice == 'N' || choice == 'y' || choice == 'Y' || choice == 'Q' || choice == 'q') //判断是否输入正确
								{
									break;
								}
								else
								{
									continue;
								}
							}
							if (choice == 'n' || choice == 'N')
							{
								continue;                           //继续循环输入坐标
							}
							else if (choice == 'q' || choice == 'Q')   //结束循环，结束本小题
							{
								break;
							}
							else                                       //进行后续合并
							{
								cout << endl;
								cout << "相同值归并后的数组(不同色标识):\n";
								merge(origin_array, *p - 'A', *(p + 1) - '1' + 1);
								print(origin_array, 'c');
								cout << endl;
								int scores = score(origin_array, *p - 'A', *(p + 1) - '1' + 1);//  单次计分
								sum_scores += scores;                                         //  记录总分
								cout << "本次得分:" << scores << " 总得分:" << sum_scores << " 合成目标:" << final_target << endl;
								cout << endl;
								cout << "按回车键进行数组下落除0操作...";
								while (1)
								{
									int huiche = _getch();
									if (huiche == 13)
									{
										break;
									}
									else
									{
										continue;
									}
								}
								cout << endl;
								cout << "除0后的数组(不同色标识):\n";                      //除零
								remove_0(origin_array);
								print(origin_array, 'd');
								cout << endl;
								cout << "按回车键进行新值填充...";
								while (1)
								{
									int huiche = _getch();
									if (huiche == 13)
									{
										break;
									}
									else
									{
										continue;
									}
								}
								cout << endl;
								cout << "新值填充后的数组(不同色标识):\n";               //填充
								fill_new(origin_array);
								print(origin_array, 'e');
								cout << endl;
								if (n == 3)               //题目3结束
									break;
								else
								{
									cout << endl;
									cout << "本次合成结束，按回车键继续新一次的合成...\n";
									while (1)
									{
										int huiche = _getch();
										if (huiche == 13)
										{
											break;
										}
										else
										{
											continue;
										}
									}
								}
							}
						}
						else //n==1或2
						{
							break;
						}
					}          //----------------------------------->重新进入下一轮循环
				}

				//  调用伪图形界面的函数
				else
				{
					cct_cls();
					if (n == 5)
					{
						change_screen(row, col, false);
						draw_no_line(origin_array);              //选项5， 绘制无表框
					}
					else   //6 7 8 9
					{
						change_screen(row, col, true);
						draw_line(origin_array);               //选项6,绘制有表框
						if (n == 7 || n == 8 || n == 9)                   //进入选项7 8 9
						{
							int x, y;
							cct_getxy(x, y); //获取提示语的坐标
							cout << "箭头键/鼠标移动，回车键/单击左键选择并结束\n";
							cct_setcursor(CURSOR_INVISIBLE);    //消除光标
							if (n == 7)
								choose(origin_array, x, y, false, final_target, sum_scores, false);      //选择，无合并
							else  if (n == 8)
							{
								choose(origin_array, x, y, true, final_target, sum_scores, false);         //选择，有合并
							}
							else
							{
								int MX, MY, MAction, keycode1, keycode2;
								while (1)
								{
									if (find_a_max(origin_array) == final_target)        //判断是否达到合成目标
									{
										cct_setcolor(14, 4);
										cct_gotoxy(x, y);
										cout << "已经合成到" << final_target;
										cct_setcolor(0, 7);
										cout << "按回车键/单击左键继续向更高目标进发...";
										while (1)
										{
											cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
											if (keycode1 == 13 || MAction == MOUSE_LEFT_BUTTON_CLICK)
												break;
											else
												continue;
										}
										final_target++;
									}
									new_b(origin_array);
									if (!judge_gameover(origin_array))              //判断游戏是否结束
									{
										cct_setcolor(14, 4);
										cct_gotoxy(x, y);
										cout << "无相邻位置值相等，游戏结束              \n";
										cct_setcolor(0, 7);
										break;
									}
									new_b(origin_array);             //更新b矩阵
									choose(origin_array, x, y, true, final_target, sum_scores, true);
								}
							}

							cct_gotoxy(x, y + 1);
							cct_setcolor(0,7);  //恢复颜色
							cct_setcursor(CURSOR_VISIBLE_FULL);  //恢复光标
						}
					}
				}
				cout << "本小题结束,请输入End继续...";  //结束提示
				while (true)
				{
					char end[10], * pend = end;
					cin >> pend;
					if ((*pend == 'e' || *pend == 'E') && (*(pend + 1) == 'n' || *(pend + 1) == 'N') && (*(pend + 2) == 'd' || *(pend + 2) == 'D'))
						break;
					else
					{
						cout << "输入错误，请重新输入\n";
						continue;
					}
				}
			}
		}
	return 0;
}