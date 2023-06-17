//作者:MFn

#include<iostream>
#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<ctime>
#include "VK_Controls.h"
#include "Console_Controls.h"

#define endl '\n'
#define Title SetConsoleTitle

using namespace std;
int ptr=0;//pointer varible
int scene=1;//change scene
int state=0;//clicking state
int speed=20;//clicking speed(ms)
bool displayPtr=true;//if true,display ptr value after TextInterface
const int keynum=5;//const main menu key number
string ThemeColor[4]= {".0",".1"}; //theme color,it can changed in settings([0]:unselected,[1]:selected)

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void GetNowTime(void)//not used
{
	time_t nowtime;
	struct tm* p;;
	time(&nowtime);
	p = localtime(&nowtime);//get now time
	cout<<p->tm_hour<<" : "<<p->tm_min<<" : "<<p->tm_sec;//output
}

void MouseClick(int type)//click the mouse
{
	int i=0,flag=false;
	if(type==1)//left
	{
		Color(ThemeColor[1]);
		cout<<"左键连点(按 X 以停止)";
		while(state!=0)
		{
			VK_MouseLCLICK();//the functions are in VK_Controls.h
			if((getVK('X') or getVK('x')) and flag==true)
			{
				state=0;
				break;
			}
			i++;
			if(i>1)
			{
				flag=true;
			}
			Sleep(speed);
		}
	}
	else if(type==2)//right
	{
		Color(ThemeColor[1]);
		cout<<"右键连点(按 X 以停止)";
		while(state!=0)
		{
			VK_MouseRCLICK();//the functions are in VK_Controls.h
			if((getVK('X') or getVK('x')) and flag==true)
			{
				state=0;
				break;
			}
			i++;
			if(i>1)
			{
				flag=true;
			}
			Sleep(speed);
		}
	}
	else if(type==0)//none
	{
		Color(ThemeColor[0]);
		cout<<"无";
	}
}

void TextInterface(int type)
{
	if(type==0)//big title
	{
		Title("AutoClicker | 主页");//set console title
		char RSlash=92;//a method to print rslash.too stupid
		Color(ThemeColor[1]);//set title color to theme color.Visuals
		cout<<"   ___       __         ________     __          "<<endl;
		cout<<"  / _ |__ __/ /____    / ___/ (_)___/ /_____ ____"<<endl;
		cout<<" / __ / // / __/ _ "<<RSlash<<"  / /__/ / / __/  '_/ -_) __/"<<endl;
		cout<<"/_/ |_"<<RSlash<<"_,_/"<<RSlash<<"__/"<<RSlash<<"___/  "<<RSlash<<"___/_/_/"<<RSlash<<"__/_/"<<RSlash<<"_"<<RSlash<<""<<RSlash<<"__/_/   "<<endl;
		cout<<"                                                 "<<endl;
		Color(ThemeColor[0]);//set the color back
		cout<<"(按 ↑或 ↓来选择,按 Z 确认)"<<endl<<endl;
	}
	else if(type==1)//main menu
	{
		string keys[keynum+1]= {"左键连点","右键连点","停止所有连点","设置","退出"};//keys
		for(int i=0; i<=keynum-1; i++)//for to output
		{
			if(ptr==i)//if ptr is pointing to this,change color
			{
				Color(ThemeColor[1]);
			}
			else//else change back
			{
				Color(ThemeColor[0]);
			}
			cout<<keys[i]<<endl;//output this
			Color(ThemeColor[0]);//change the color back however
		}
	}
	else if(type==2)
	{
		GetNowTime();//not used
	}
	else if(type==3)//settings
	{
		if(ptr==-1)
		{
			ptr++;
		}
		Title("AutoClicker | 设置");//set the console title
		cout<<"设置"<<endl<<endl;//title
		const int SettingsKeyNum=4;//the same as the type1
		string SettingsKeys[SettingsKeyNum+1]= {"返回","设定点击速度","设定主题颜色","开关显示指针数值"};
		for(int i=0; i<=SettingsKeyNum-1; i++)
		{
			if(ptr==i)
			{
				Color(ThemeColor[1]);
			}
			else
			{
				Color(ThemeColor[0]);
			}
			cout<<SettingsKeys[i];
			if(i==3)
			{
				cout<<" (当前:";
				if(displayPtr)
				{
					cout<<"[开启]";
				}
				else
				{
					cout<<"[关闭]";
				}
				cout<<")";
			}
			cout<<endl;
			Color(ThemeColor[0]);
		}
		if(displayPtr)//display ptr var
		{
			cout<<endl<<ptr<<endl;
		}
	}
	else if(type==4)
	{
		Title("AutoClicker | 退出");//set the console title
		cout<<"真的要退出吗?"<<endl<<endl;//title
		const int SettingsKeyNum=2;//the same as the type1
		string SettingsKeys[SettingsKeyNum+1]= {"是","否"};
		for(int i=0; i<=SettingsKeyNum-1; i++)
		{
			if(ptr==i)
			{
				Color(ThemeColor[1]);
			}
			else
			{
				Color(ThemeColor[0]);
			}
			cout<<SettingsKeys[i]<<endl;
			Color(ThemeColor[0]);
		}
		if(displayPtr)//display ptr var
		{
			cout<<endl<<ptr<<endl;
		}
	}
	else if(type==5)//clicking speed setting
	{
		Title("AutoClicker | 设置 | 设定点击速度");//set the console title
		Color(ThemeColor[1]);
		cout<<"设置两次点击之间的间隔。 当前 : "<<speed<<" 毫秒。"<<endl;
		Color(ThemeColor[0]);
		cout<<"输入“-1”以返回默认值。"<<endl<<endl;
		cout<<"输入:";
		cin>>speed;
		if(speed==-1)
		{
			speed=20;
		}
		cout<<endl<<"按 Z 以继续...";
		scene=2;
	}
	else if(type==6)//themecolor setting
	{
		Title("AutoClicker | 设置 | 设定主题颜色");//set the console title
		Color(ThemeColor[0]);
		cout<<"选择以下的颜色:"<<endl;
		Color(ThemeColor[1]);
		cout<<endl<<" 0:白 \n 1:青 \n 2:绿 \n 3:紫 \n 4:红 \n 5:蓝 \n 6:黄"<<endl<<endl;
		Color(ThemeColor[0]);
		cout<<"文字颜色(正常):";
		cin>>ThemeColor[0];
		cout<<"文字颜色(高亮):"; 
		cin>>ThemeColor[1];
		ThemeColor[0]="."+ThemeColor[0];
		ThemeColor[1]="."+ThemeColor[1];
		cout<<endl<<"按 Z 以继续...";
		scene=2;
	}
}

void SwitchPtr(void)//switch by up,left or down,right
{
	int n;//in different scene, there are different keynums
	if(scene==1)
	{
		n=keynum;
	}
	else if(scene==2)
	{
		n=4;
	}
	else if(scene==3)
	{
		n=2;
	}
	int ar=Arrow();//arrow var.the function is in Console_Controls.h
	if(ar==2 or ar==1)//you can quickly understand the following code without any comments
	{
		if(ptr>0)
		{
			ptr--;
		}
		else
		{
			ptr=n-1;
		}
	}
	else if(ar==3 or ar==4)
	{
		if(ptr<n-1)
		{
			ptr++;
		}
		else
		{
			ptr=0;
		}
	}
	else if(ar==5)//main thing.Controls the behavior after confirm what you selected
	{
		if(scene==1)//Main menu
		{
			if(ptr==0)
			{
				ptr=2;
				state=1;
			}
			else if(ptr==1)
			{
				ptr=2;
				state=2;
			}
			else if(ptr==2)
			{
				state=0;
			}
			else if(ptr==3)//goto settings
			{
				ptr=0;//initialize the ptr var
				system("cls");
				scene=2;
			}
			else if(ptr==4)//exit
			{
				ptr=0;//initialize the ptr var
				system("cls");
				scene=3;
			}
		}
		else if(scene==2)//Settings scene
		{
			if(ptr==0)
			{
				ptr=3;
				scene=1;
			}
			else if(ptr==1)
			{
				ptr=-1;
				scene=4;//4 is Clicking speed setting
			}
			else if(ptr==2)
			{
				ptr=-1;
				scene=5;//5 is theme color settings
			}
			else if(ptr==3)
			{
				if(displayPtr==true)
				{
					displayPtr=false;	
				}
				else
				{
					displayPtr=true;
				}
			}
		}
		else if(scene==3)//Exit scene
		{
			if(ptr==1)
			{
				scene=1;
			}
			else if(ptr==0)
			{
				system("cls");
				Color(ThemeColor[0]);
				cout<<"已退出。"<<endl;
				exit(0);
			}
		}
	}
}

int main(int argc, char** argv)//main function
{
	//unselectable console window(Fuck you CSDN)
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	mode &= ~ENABLE_INSERT_MODE;
	mode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdin, mode);

	cin.tie(0),cout.tie(0);
	ptr=0;//initialize the ptr var
	while(true)//main loop
	{
		if(getVK(VK_ESC))
		{
			break;
		}
		system("cls");
		if(scene==1)
		{
			TextInterface(0);
			TextInterface(1);
			cout<<endl<<"当前状态:";
			MouseClick(state);
			Color(ThemeColor[0]);
			if(displayPtr)//display ptr var
			{
				cout<<endl<<endl<<ptr<<endl;
			}
		}
		else if(scene==2)
		{
			system("cls");
			TextInterface(3);
		}
		else if(scene==3)
		{
			system("cls");
			TextInterface(4);
		}
		else if(scene==4)
		{
			system("cls");
			TextInterface(5);
		}
		else if(scene==5)
		{
			system("cls");
			TextInterface(6);
		}
		SwitchPtr();
	}
	exit(0);
}
