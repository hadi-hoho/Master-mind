#include <iostream>
#include <math.h>     //for using pow()
#include <stdlib.h>   //for using rand
#include <windows.h>  //for defining gotoxy
#include <stdlib.h>   //for exiting 
#include <unistd.h>   //for defining sleep
#include <conio.h>    //for getch and detection of pressing any key
#include <time.h>     //for using srand(time(0))
#include <string>     //for working with entered numbers

#define maxx	40
#define maxy	30
#define minx	0
#define miny	0

#define computer_mode 1
#define friend_mode 2

using namespace std;

//defing the array
char screen[maxy][maxx];

/*********************functions***************/
void gotoxy(int xpos, int ypos);
string int_to_string (int n);
int get_digit_num();
int get_game_mode();
int get_number_fuser(int digit_num);
int correct_digits_finder(int n1,int n2);
int similar_digits_finder(int n1,int n2);
void welcome_page(void);
int Greater_Smaller(void);
int Similarity_Position();
void print_border(void);
void print_array(void);
int menu(void);
/*********************************************/


int main()
{
    print_border();
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

string int_to_string (int n)
{
    string s;
    while (n !=0)
    {
        s.push_back(n%10 + '0');
        n /= 10;
    }
    //reversing the string
    for (int i = 0; i < s.length()/2; i++)
    {
        char temp= s[i];
        s[i] = s[s.length()-1 - i];
        s[s.length()-1 - i] = temp;
    }
    
    return s;
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
   
}


int Similarity_Position()
{
    int digit_num = get_digit_num();
    int game_mode = get_game_mode();
    int guess_this_number;
    if (game_mode == computer_mode)
    {
        srand(time(0));
        guess_this_number = rand() % int(pow(10,digit_num)) + 1;
    }
    else if (game_mode == friend_mode)
    {
        guess_this_number = get_number_fuser(digit_num);
    }

    system("cls");
    cout<<"The number is between 1 and "<<pow(10,digit_num)-1<<endl;
    int guessed_number = 0 , lose = 0 , max_lose_times = digit_num * 2;
    while (guessed_number != guess_this_number && lose != max_lose_times)
    {  
        guessed_number =0;
        cout<<"enter your guess here :";
        cin>>guessed_number;
        if (guessed_number != guess_this_number)
        {
            lose ++ ;
            int similar_digits = similar_digits_finder(guess_this_number , guessed_number);
            int correct_digits = correct_digits_finder(guess_this_number , guessed_number);
            similar_digits = similar_digits - correct_digits ;
            
            cout<<"You guessed "<<similar_digits<<" similar digits"<<endl;
            
            cout<<"and "<<correct_digits<<" correct digits in your last guess !"<<endl<<endl;
        }
        
    }
    system("cls");
    if (lose == max_lose_times)
    {
        cout<<"You lost !!"<<endl<<"the number was "<<guess_this_number<<endl;
    }
    else
    {
        cout<<"You won !!!";
    }
    sleep(5);
    exit(0);
}

//correct_digits_finder returns the number of correct digits in two integers
int correct_digits_finder(int n1,int n2)
{
    int correct_digits=0;
    string sn1 = int_to_string(n1) , sn2 = int_to_string(n2);
    for (int i = 0; i < sn1.length(); i++)
    {
        if (sn1[i]==sn2[i])
        {
            correct_digits ++;
        }
    }
    return correct_digits;
}

//similar_digits_finder returns the number of similar digits in two integers
int similar_digits_finder(int n1,int n2)
{
    int similar_digits=0;
    string sn1 = int_to_string(n1) , sn2 = int_to_string(n2);
    for (int i = 0; i < sn1.length(); i++)
    {
        for (int j = 0; j < sn2.length(); j++)
        {
            if (sn1[i]==sn2[j])
            {
                similar_digits ++;
                sn2[j]=' ';
                break;
            }   
        }   
    }
    return similar_digits;
}

//get_digit_num returns the user's preferable number of digits
int get_digit_num()
{
    system("cls");
    print_array();
    int digit_num =0 ;
    gotoxy(1,16);
    cout<<"Please enter your preferable";
    gotoxy(4 , 17);
    cout<<"number of digits (3-5)";
    while (digit_num == 0)
    {
        if (kbhit)
        {
            char ch;
            ch = getch();
            switch (ch)
            {
            case '3':
                digit_num = 3;
                break;
            
            case '4':
                digit_num = 4;
                break;
            case '5':
                digit_num = 5;
                break;
            }
        } 
    }
    return digit_num;
}

//get_game_mode returns the game mode user wants to pleay camputer_mode or friend_mode
int get_game_mode()
{
    system("cls");
    print_array();
    int game_mode =0;
    gotoxy(7,16);
    cout<<"What game mode ";
    gotoxy(5,17);
    cout<<"do you want to play ?";
    gotoxy(7,18);
    cout<<"1 - vs. computer";
    gotoxy(8,19);
    cout<<"2 - vs. friend";
    while (game_mode ==0)
    {
        if (kbhit)
        {
            char ch;
            ch = getch();
            switch (ch)
            {
            case '1':
                game_mode = computer_mode;
                break;
            
            case '2':
                game_mode = friend_mode;
                break;
            }
        } 
    }
    return game_mode;
}

int get_number_fuser(int digit_num)
{
    system("cls");
    print_array();
    int number_fuser;
    gotoxy(6,16);
    cout<<"This item should be";
    gotoxy(5,17);
    cout<<"entered by your friend!";
    gotoxy(7,18);
    cout<<"Please enter a ";
    gotoxy(7,19);
    cout<<digit_num<<" digit number :";
    cin>>number_fuser;
    return number_fuser;
}