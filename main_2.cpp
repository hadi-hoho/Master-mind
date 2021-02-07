#include <iostream>
#include <stdlib.h>   //for using rand
#include <windows.h>  //for defining gotoxy
#include <stdlib.h>   //for exiting 
#include <unistd.h>   //for defining sleep
#include <conio.h>    //for getch and detection of pressing any key
#include <time.h>     //for using srand(time(0))

#define maxx	40
#define maxy	30
#define minx	0
#define miny	0

using namespace std;

//defing the array
char screen[maxy][maxx];

/*********************functions***************/
void gotoxy(int xpos, int ypos);
void welcome_page(void);
int Greater_Smaller(void);
void print_border(void);
void print_array(void);
int menu(void);

int main()
{
    welcome_page();
    menu();
}

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput,scrn);
}

void print_border(void)
{
	for (int i = miny; i < maxy; i++)
    {
        if (i==(maxy-1) || i==miny)
        {
            for (int j = minx; j < maxx; j++)
            {
                screen[i][j]= '_';
            }
        }
        else
		{
            for (int j = minx; j < maxx; j++)
            {
                screen[i][j]= ' ';
            }
        }
    }
    for (int i=miny+1;i<maxy;i++)
    {
     	screen[i][minx]='|';
    	screen[i][maxx-1]='|';
    }
}
void print_array(void)
{
	for (int i = miny; i < maxy; i++)
    {
    	
        for (int j = minx; j < maxx; j++)
        {
            cout<<screen[i][j];
        }
        cout<<'\n';
    }
}

int Greater_Smaller()
{
    system("cls");
    srand(time(0));
    int i, n = rand() % 100;
    do
    {
        cout << endl << "Please enter the correct number : ";
        cin >> i;
        if (i == n)
            break;
        if (n > i)
        {
            cout << "No, Try a greater number.";
            continue;
        }
        cout << "No, Try a smaller number.";
    } while (i!=n);
}

void instructions(void)
{
	system("cls");
    print_border();
    print_array();
    gotoxy(14,3);
    cout<<"MASTER MIND";
	sleep(1);
    gotoxy(14,5);
    cout<<"Instructions";
	sleep(1);
	gotoxy(1,10);
        cout<<"Greater & Smaller:";
    gotoxy(1,11);
        cout<<"Guess by giving smaller or larger";
    gotoxy(1,12);
        cout<<"numbers";
    gotoxy(1,14);
        cout<<"Similarity & Position:";
    gotoxy(1,15);
        cout<<"Guess by the number of similarities";
    gotoxy(1,16);
        cout<<"and their positions";
    gotoxy(1,18);
        cout<<"vs. computer:";
    gotoxy(1,19);
        cout<<"Guess the number computer has given";
	gotoxy(1,21);
		 cout<<"vs. friends";
    gotoxy(1,22);
        cout<<"Guess the number your friend has given";
	sleep(1);
    gotoxy(6,26);
    cout<<"Press 'Esc' to go back to menu";
      while(1)
	{
		if (kbhit)
		{
		char ch;
		ch = getch();
		if (int(ch) == 27)
		break;	
		}
	}
  menu();
} 

int menu(void)
{
	system("cls");
   while (true)
   {
   
    print_border();
    print_array();
    
    gotoxy(14,8);
    cout<<"MASTER MIND";
	sleep(1);
    gotoxy(18,11);
    cout<<"MENU";
	sleep(1);
    gotoxy(10,16);
    cout<<"1: Greater & Smaller";
	sleep(1);
    gotoxy(8,18);
    cout<<"2: Similarity & Position";
	sleep(1);
	gotoxy(6,20);
    cout<<"Press 'I' to see instructions";
	sleep(1);
    gotoxy(10,22);
    cout<<"Press 'Esc' to exit";
      while(1)
	{
		if (kbhit)
		{
			char ch;
			ch = getch();
			if (int(ch) == 49)
			Greater_Smaller();
			else if(int(ch) == 50)
            Similarity_Position();
            else if (int(ch) == 73 || int(ch) == 105)
			instructions();
			else if (int(ch) == 27)
			{
			gotoxy(1,31);
			exit(0);	
			}
			
		}	
		else
			system("cls");
	}
   }
} 

void welcome_page(void) 
{
   while (true)
   {
    print_border();
    print_array();
    
    gotoxy(9,8);
    cout<<"Welcome to MASTER MIND";
	sleep(1);
    gotoxy(15,16);
    cout<<"Producers:";
	sleep(1);
    gotoxy(14,17);
    cout<<"Hadi Firoozi";
	sleep(1);
    gotoxy(14,18);
    cout<<"Sanaz Motie";
	sleep(1);
    gotoxy(12,19);
    cout<<"Alireza Mikaeili";
      sleep(3);
	for (int i=3; i>0; i--){
	gotoxy(19,21);
    cout<<i;
      	sleep(1);
	}
	system("cls");
   	break;
   }
}
