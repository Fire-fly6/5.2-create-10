#include<iostream>
#include"cmd_console_tools.h"
#include<climits>
#include"90-b2.h"
using namespace std;
void print(arrays origin,char choice); //�����ӡ����������

int menu()                                               //�˵�����
{
	cct_setconsoleborder(120, 30, 120, 9001);
	cout << "1.�������ҳ��ɺϳ����ʶ���ǵݹ飩\n";
	cout << "2.�������ҳ��ɺϳ����ʶ���ݹ飩\n";
	cout << "3.���������һ�κϳɣ��ֲ�����ʾ��\n";
	cout << "4.�����������棨�ֲ�����ʾ��\n";
	cout << "5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�\n";
	cout << "6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�\n";
	cout << "7.αͼ�ν������ü�ͷ��/���ѡ��ǰɫ��\n";
	cout << "8.αͼ�ν������һ�κϳɣ��ֲ��裩\n";
	cout << "9.αͼ�ν��������棨֧����꣩\n";
	cout << "-----------------------------------------\n";
	cout << "0.�˳�\n";
	cout << "-----------------------------------------\n";
	cout << "[��ѡ��:]";
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
					cout << "����������(5-8):\n";                            //��ȡ����������
					cin >> row;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');//��ջ�����
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
					cout << "����������(5-10):\n";
					cin >> col;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');//��ջ�����
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
				if (n == 3 || n == 4 || n == 8 || n == 9)                                      //��ȡ���պϳ�Ŀ��
				{
					while (1)
					{
						cout << "������ϳ�Ŀ��(5-20):\n";
						cin >> final_target;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(INT_MAX, '\n');//��ջ�����
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

				arrays origin_array = creat(row, col);   //    ˫����ṹ������

				int sum_scores = 0;                   //��ʼ���ܷ�
				if (n == 1 || n == 2 || n == 3 || n == 4)   //��menu��ѡ����벻ͬ�ĺ���  1234
				{
					while (1)
					{
						if (find_a_max(origin_array) == final_target)        //�ж��Ƿ�ﵽ�ϳ�Ŀ��
						{
							cct_setcolor(14, 4);
							cout << "�Ѿ��ϳɵ�" << final_target;
							cct_setcolor(0, 7);
							cout << endl;
							cout << "���س������������Ŀ�����...\n";
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
						cout << "��ǰ����:\n";
						print(origin_array, 'a');
						cout << endl;
						new_b(origin_array);
						if (!judge_gameover(origin_array))              //�ж���Ϸ�Ƿ����
						{
							cct_setcolor(14, 4);
							cout << "������λ��ֵ��ȣ���Ϸ����\n";
							cct_setcolor(0, 7);
							break;
						}
						cout << "������ĸ+������ʽ[��:c2]�����������:";
						char s[2], * p = s;                          //�����ַ�����װ��������
						while (1)
						{
							new_b(origin_array);            //ˢ��b,��b�Ļ���
							cin >> p;
							*p = (*p < 'a') ? *p : *p - 'a' + 'A';        //����ת��Ϊ��д
							bool  judge = false;
							if (n == 2)
							{
								find_recursion(origin_array, *p - 'A', *(p + 1) - '1' + 1, judge);
								//�ж�����λ���Ƿ���ֵ��Ȳ��ı�b����         ���õݹ麯��
							}
							else
							{

								find_no_recursion(origin_array, *p - 'A', *(p + 1) - '1' + 1, judge);
								//�ж�����λ���Ƿ���ֵ��Ȳ��ı�b����         ���÷ǵݹ麯��
							}
							if ((*p<'A' || *p>char('A' + row - 1)) || (*(p + 1) < '0' || *(p + 1) > char('0' + col - 1)))
							{
								cout << "�������,����������:\n";
								continue;
							}
							else {
								if (judge)
									break;
								else
								{
									cout << "������λ��������������ͬ��������������:\n";
									continue;
								}
							}
						}
						cout << "����Ϊ" << *p << "��" << *(p + 1) << "��" << endl;
						cout << endl;
						cout << "���ҽ������:\n";
						print(origin_array, 'b');
						cout << endl;
						cout << "��ǰ����(��ͬɫ��ʶ):\n";
						print(origin_array, 'c');
						cout << endl;

						//�ӵ�3С��
						if (n == 3 || n == 4)                      //�ӵ�3С��
						{
							char choice;
							cout << endl;
							cout << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���" << *p << *(p + 1) << "��(Y/N/Q):";
							while (1)
							{
								choice = _getch();                   //��ȡѡ��,�л���
								if (choice == 'n' || choice == 'N' || choice == 'y' || choice == 'Y' || choice == 'Q' || choice == 'q') //�ж��Ƿ�������ȷ
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
								continue;                           //����ѭ����������
							}
							else if (choice == 'q' || choice == 'Q')   //����ѭ����������С��
							{
								break;
							}
							else                                       //���к����ϲ�
							{
								cout << endl;
								cout << "��ֵͬ�鲢�������(��ͬɫ��ʶ):\n";
								merge(origin_array, *p - 'A', *(p + 1) - '1' + 1);
								print(origin_array, 'c');
								cout << endl;
								int scores = score(origin_array, *p - 'A', *(p + 1) - '1' + 1);//  ���μƷ�
								sum_scores += scores;                                         //  ��¼�ܷ�
								cout << "���ε÷�:" << scores << " �ܵ÷�:" << sum_scores << " �ϳ�Ŀ��:" << final_target << endl;
								cout << endl;
								cout << "���س����������������0����...";
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
								cout << "��0�������(��ͬɫ��ʶ):\n";                      //����
								remove_0(origin_array);
								print(origin_array, 'd');
								cout << endl;
								cout << "���س���������ֵ���...";
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
								cout << "��ֵ���������(��ͬɫ��ʶ):\n";               //���
								fill_new(origin_array);
								print(origin_array, 'e');
								cout << endl;
								if (n == 3)               //��Ŀ3����
									break;
								else
								{
									cout << endl;
									cout << "���κϳɽ��������س���������һ�εĺϳ�...\n";
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
						else //n==1��2
						{
							break;
						}
					}          //----------------------------------->���½�����һ��ѭ��
				}

				//  ����αͼ�ν���ĺ���
				else
				{
					cct_cls();
					if (n == 5)
					{
						change_screen(row, col, false);
						draw_no_line(origin_array);              //ѡ��5�� �����ޱ��
					}
					else   //6 7 8 9
					{
						change_screen(row, col, true);
						draw_line(origin_array);               //ѡ��6,�����б��
						if (n == 7 || n == 8 || n == 9)                   //����ѡ��7 8 9
						{
							int x, y;
							cct_getxy(x, y); //��ȡ��ʾ�������
							cout << "��ͷ��/����ƶ����س���/�������ѡ�񲢽���\n";
							cct_setcursor(CURSOR_INVISIBLE);    //�������
							if (n == 7)
								choose(origin_array, x, y, false, final_target, sum_scores, false);      //ѡ���޺ϲ�
							else  if (n == 8)
							{
								choose(origin_array, x, y, true, final_target, sum_scores, false);         //ѡ���кϲ�
							}
							else
							{
								int MX, MY, MAction, keycode1, keycode2;
								while (1)
								{
									if (find_a_max(origin_array) == final_target)        //�ж��Ƿ�ﵽ�ϳ�Ŀ��
									{
										cct_setcolor(14, 4);
										cct_gotoxy(x, y);
										cout << "�Ѿ��ϳɵ�" << final_target;
										cct_setcolor(0, 7);
										cout << "���س���/����������������Ŀ�����...";
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
									if (!judge_gameover(origin_array))              //�ж���Ϸ�Ƿ����
									{
										cct_setcolor(14, 4);
										cct_gotoxy(x, y);
										cout << "������λ��ֵ��ȣ���Ϸ����              \n";
										cct_setcolor(0, 7);
										break;
									}
									new_b(origin_array);             //����b����
									choose(origin_array, x, y, true, final_target, sum_scores, true);
								}
							}

							cct_gotoxy(x, y + 1);
							cct_setcolor(0,7);  //�ָ���ɫ
							cct_setcursor(CURSOR_VISIBLE_FULL);  //�ָ����
						}
					}
				}
				cout << "��С�����,������End����...";  //������ʾ
				while (true)
				{
					char end[10], * pend = end;
					cin >> pend;
					if ((*pend == 'e' || *pend == 'E') && (*(pend + 1) == 'n' || *(pend + 1) == 'N') && (*(pend + 2) == 'd' || *(pend + 2) == 'D'))
						break;
					else
					{
						cout << "�����������������\n";
						continue;
					}
				}
			}
		}
	return 0;
}