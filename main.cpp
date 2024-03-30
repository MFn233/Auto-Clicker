//Author:MFn

#include<iostream>
#include<windows.h>
#include<string.h>
#include<string>
#include<stdio.h>
#include<conio.h>
#include<ctime>
#include "VK_Controls.hpp"
#include "Console_Controls.hpp"

using namespace std;
int ptr=0;//pointer varible
int scene=1;//change scene
int state=0;//clicking state
int speed=20;//clicking speed(ms)
bool displayPtr=true;//if true,display ptr value after TextInterface
string ThemeColor[4]= {".0",".1"}; //theme color,it can changed in settings([0]:unselected,[1]:selected)

string getLoginUsernameByApi() {//get username
	char username[1024];
	DWORD usernameLength = sizeof username;
	GetUserName(username, &usernameLength);
	return username;
}

string USERNAME = getLoginUsernameByApi();

void MouseClick(int type) { //click the mouse
	int i=0;
	if(type==1) { //left
		Color(ThemeColor[1]);
		cout<<"Left Clicking...(Press X to stop)";
		while(state!=0) {
			VK_MouseLCLICK();//the functions are in VK_Controls.h
			if((getVK('X') or getVK('x'))) {
				state=0;
				break;
			}
			Sleep(speed);
		}
	} else if(type==2) { //right
		Color(ThemeColor[1]);
		cout<<"Right Clicking...(Press X to stop)";
		while(state!=0) {
			VK_MouseRCLICK();//the functions are in VK_Controls.h
			if(getVK('X') or getVK('x')) {
				state=0;
				break;
			}
			Sleep(speed);
		}
	} else if(type==0) { //none
		Color(ThemeColor[0]);
		cout<<"None";
	}
}

void TextInterface(int type) {
	if(type==0) { //big title
		SetConsoleTitle("AutoClicker | MainMenu");//set console title
		Color(ThemeColor[1]);//set title color to theme color.
		cout<<"   ___       __         ________     __          \n";
		cout<<"  / _ |__ __/ /____    / ___/ (_)___/ /_____ ____\n";
		cout<<" / __ / // / __/ _ \\  / /__/ / / __/  '_/ -_) __/\n";
		cout<<"/_/ |_\\_,_/\\__/\\___/  \\___/_/_/\\__/_/\\_\\\\__/_/   \n";
		cout<<"                                                 \n";
		Color(ThemeColor[0]);//set the color back
		cout<<"Hello, "<<USERNAME;
		cout<<".\n(Up and Down to select, Z to confirm)\n\n";
		//system("time /t");
		//This will display the time, I just want to use it to debug
	} else if(type==1) { //main menu
		const int MainKeyNum=5;
		string keys[MainKeyNum+1]= {"Left","Right","Stop","Settings","Exit"};//keys
		for(int i=0; i<=MainKeyNum-1; i++) { //for to output
			if(ptr==i) { //if ptr is pointing to this,change color
				Color(ThemeColor[1]);
			} else { //else change back
				Color(ThemeColor[0]);
			}
			cout<<keys[i]<<'\n';//output this
			Color(ThemeColor[0]);//change the color back however
		}
	} else if(type==2) { //settings
		if(ptr==-1) {
			ptr++;
		}
		SetConsoleTitle("AutoClicker | Settings");//set the console title
		Color(ThemeColor[1]);
		cout<<"Settings\n\n";//title
		Color(ThemeColor[0]);
		const int SettingsKeyNum=4;//the same as the type1
		string SettingsKeys[SettingsKeyNum+1]= {"Back","Set clicking speed","Set theme color","Toggle display ptr value"};
		for(int i=0; i<=SettingsKeyNum-1; i++) {
			if(ptr==i) {
				Color(ThemeColor[1]);
			} else {
				Color(ThemeColor[0]);
			}
			cout<<SettingsKeys[i];
			if(i==3) {
				cout<<" (Now:";
				if(displayPtr) {
					cout<<"True";
				} else {
					cout<<"False";
				}
				cout<<")";
			}
			cout<<'\n';
			Color(ThemeColor[0]);
		}
		if(displayPtr) { //display ptr var
			cout<<"\n("<<ptr<<")\n";
		}
	} else if(type==3) {//exit
		SetConsoleTitle("AutoClicker | Exit");//set the console title
		Color(ThemeColor[1]);
		cout<<"Are you sure to exit?\n\n";//title
		Color(ThemeColor[0]);
		const int SettingsKeyNum=2;//the same as the type1
		string SettingsKeys[SettingsKeyNum+1]= {"Yes","No"};
		for(int i=0; i<=SettingsKeyNum-1; i++) {
			if(ptr==i) {
				Color(ThemeColor[1]);
			} else {
				Color(ThemeColor[0]);
			}
			cout<<SettingsKeys[i]<<'\n';
			Color(ThemeColor[0]);
		}
		if(displayPtr) { //display ptr var
			cout<<"\n("<<ptr<<")\n";
		}
	} else if(type==4) { //clicking speed setting
		int temp;
		SetConsoleTitle("AutoClicker | Settings | Set clicking speed");//set the console title
		while(true) {
			cout << "\033c";
			Color(ThemeColor[1]);
			cout<<"Set the speed value. Now : "<<speed<<" ms.\n";
			Color(ThemeColor[0]);
			cout<<"type '-1' to go back to default, '-2' to do nothing.\n\n";
			cout<<"Input(Unit: ms):";
			cin>>temp;
			
			if(temp==-1) {
				temp=20;
			} else if(temp==-2) {
				temp=speed;
			}
			
			Color(ThemeColor[1]);
			cout<<"\nYou changed clicking speed into:"<<temp<<"ms.";
			Color(ThemeColor[0]);
			cout<<"\nIs this what you want?[Y/N]:";
			string confirm;
			cin>>confirm;
			if(confirm=="Y" || confirm=="y")
			{
				break;
			}
		}
		
		if(temp==-1) {
			speed=20;
		} else if(temp==-2) {
			speed=speed;//do nothing
		} else if(temp>0) {
			speed=temp;
		}
		
		cout<<"\nPress Z or Enter...";
		scene=2;
	} else if(type==5) { //themecolor setting
		SetConsoleTitle("AutoClicker | Settings | Set theme color");//set the console title
		string t0,t1;
		while(true) {
			Color(ThemeColor[0]);
			cout<<"Choose the color below:\n";
			Color(ThemeColor[1]);

			//cout<<"\n 0:white \n 1:aqua \n 2:green \n 3:purple \n 4:red \n 5:blue \n 6:yellow\n\n";
			string ColorsNamespace[9] = {"white","aqua","green","purple","red","blue","yellow"};
			Color(".0");
			cout << "\n 0:white";
			Color(".1");
			cout << "\n 1:aqua";
			Color(".2");
			cout << "\n 2:green";
			Color(".3");
			cout << "\n 3:purple";
			Color(".4");
			cout << "\n 4:red";
			Color(".5");
			cout << "\n 5:blue";
			Color(".6");
			cout << "\n 6:yellow\n\n";

			Color(ThemeColor[0]);
			cout<<"type '-1' to go back to default, '-2' to do nothing.\n\n";
			cout<<"Regular foreground color:";
			cin>>t0;
			cout<<"Highlighted foreground color:";
			cin>>t1;
			if(t0!="-2" && t0!="-1") {
				t0=t0;
			} else if(t0=="-1") {
				t0="0";
			} else if(t0=="-2") {
				t0=ThemeColor[0];
				t0=t0[1];
			}

			if(t1!="-2" && t1!="-1") {
				t1=t1;
			} else if(t1=="-1") {
				t1="1";
			} else if(t1=="-2") {
				t1=ThemeColor[1];
				t1=t1[1];
			}

			cout<<"\nYour changed colors into:\n";
			Color(ThemeColor[1]);
			cout<<ColorsNamespace[t0[0]-'0']<<"(Regular)\n"
			    <<ColorsNamespace[t1[0]-'0']<<"(Highlighted)\n";
			Color(ThemeColor[0]);
			cout<<"\nAre these what you want?[Y/N]:";
			string confirm;
			cin>>confirm;
			if(confirm == "Y" || confirm == "y") {
				break;
			} else {
				cout << "\033c";
			}
		}

		if(t0!="-2") {
			ThemeColor[0]="."+t0;
		}
		if(t1!="-2") {
			ThemeColor[1]="."+t1;
		}

		cout<<"\nPress Z or Enter...";
		scene=2;
	}
}

//Really important!!!
void SwitchPtr_old(void) { //switch by up,left or down,right
	int n;//in different scene, there are different keynums
	if(scene==1)
	{
		n=5;
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
				scene=2;
			}
			else if(ptr==4)//exit
			{
				ptr=0;//initialize the ptr var
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
				Color(ThemeColor[0]);
				cout<<"Exited."<<endl;
				exit(0);
			}
		}
	}
}

void SwitchPtr(void) { //switch by up,left or down,right
	int n;//in different scene, there are different keynums
	if(scene==1)
	{
		n=5;
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
				scene=2;
			}
			else if(ptr==4)//exit
			{
				ptr=0;//initialize the ptr var
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
				Color(ThemeColor[0]);
				cout<<"Exited."<<endl;
				exit(0);
			}
		}
	}
}

int main(int argc, char** argv) { //main function
	//unselectable console window
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE;
	mode &= ~ENABLE_INSERT_MODE;
	mode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdin, mode);

	//cin.tie(0),cout.tie(0);
	ptr=0;//initialize the ptr var
	int tempptr=ptr+1;//a way of optimizing
	while(true) { //main loop
		if(getVK(VK_ESC)) {
			break;
		}
		cout << "\033c";
		switch(scene) {
			case 1:
				TextInterface(0);
				TextInterface(1);
				cout<<"\nCurrent:";
				MouseClick(state);
				Color(ThemeColor[0]);
				if(displayPtr) { //display ptr var
					cout<<"\n\n("<<ptr<<")\n";
				}
				break;

			case 2:
				TextInterface(2);
				break;

			case 3:
				TextInterface(3);
				break;

			case 4:
				TextInterface(4);
				break;

			case 5:
				TextInterface(5);
				break;
		}
		SwitchPtr();
		Sleep(1);//also a way of optimizing(i found this in csdn
	}
	exit(0);
}
