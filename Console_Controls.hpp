#ifndef CONSOLE_CONTROLS_H
#define CONSOLE_CONTROLS_H

#include<wincon.h>
#include<processenv.h>
#include<winbase.h>
using namespace std;

void Color(string color)//Simple color changing function (That's pretty LONGGGGG)
{

	/*
	*0=white
	*1=aqua
	*2=green
	*3=purple
	*4=red
	*5=blue
	*6=yellow
	*.X=foreground color
	*X.=background color
	*/
	if(color==".0") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	if(color==".1") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
	if(color==".2") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
	if(color==".3") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
	if(color==".4") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
	if(color==".5") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
	if(color==".6") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
	if(color=="0.") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
	if(color=="1.") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_BLUE);
	if(color=="2.") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_GREEN);
	if(color=="3.") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE);
	if(color=="4.") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED);
	if(color=="5.") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_BLUE);
	if(color=="6.") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN);
}

int Arrow(void)//A simple way to get Arrow keys, based on getch()
{
	/*
	*224,75=left
	*224,72=up
	*224,80=down
	*224,77=right
	*/
	int vk=getch();
	if(vk==224)
	{
		vk=getch();
		if(vk==75)//left
		{
			return 1;
		}
		else if(vk==72)//up
		{
			return 2;
		}
		else if(vk==80)//down
		{
			return 3;
		}
		else if(vk==77)//right
		{
			return 4;
		}
		/*
		*return value:
		*1=left
		*2=up
		*3=down
		*4=right
		*/
	}
	else if(vk=='z' or vk=='Z')
	{
		return 5;
	}
	return 0;
}

#endif