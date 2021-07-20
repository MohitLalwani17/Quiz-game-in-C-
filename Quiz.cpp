#include<fstream.h>
#include<conio.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
char name[15];
class questions
{
	int qno;
	char q[150],a1[25],a2[25],a3[25],a4[25],r;
	public:
	void intro();
	void input();
	void rules();
	void upload();
	void play();
	void menu();
	void display();
	void admin();
}ques;
void questions::intro()
{
	cout<<"\n\n             QUIZ ";
	cout<<"\n\n              DESIGNED BY    ";
	cout<<"\n\n                     MOHIT LALWANI    ";
	cout<<"\n\n\npress any key to continue  ";
	getch();
}
void questions::input()
{
	char place[15];
	cout<<"\t\t\t           welcome to the quiz:     \n";
	cout<<"  enter your name :";
	cin>>name;
	cout<<"\n enter the place you are from: ";
	gets(place);
	clrscr();
	cout<<"\n\n";
	cout<<" \n                Q U I Z ";
	cout<<"\n\n\nwelcome "<<name<<"  to quiz";
	cout<<"so lets start the quiz game";
	cout<<"\n\n press any key to continue ";
	getch();
	clrscr();
}
void questions::rules()
{
	cout<<"\n RULES /INSTRUCTIONS ";
	cout<<"\n\n   * There are total 13 Multiple choice questions ";
	cout<<"\n\n   * The 1st question is worth rs 5000.  ";
	cout<<"\n\n   *with the correct answer of each question the amout gets doubled";
	cout<<"\n\n   *question 13 is the jackpot question worth RS 5 crore  ";
	cout<<"\n\n\n press any key to continue  ";
	getch();
}
void questions::menu()
{
	textbackground(1);
	clrscr();
	b:
	cout<<"\n\n               **********main   menu******** ";
	cout<<"\n                  1 - ADMIN";
	cout<<"\n                  2 - play  ";
	cout<<"\n                  3 - exit ";
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1: admin();
			break;
		case 2:play();
			break;
		case 3:exit(0);
			break;
	}
}
void questions::upload()
{
	clrscr();
	char choice;
	ofstream fout("quiz.dat",ios::app);
	ques.qno=1;
	do
	{
		cout<<"\n                    ADMIN PAGE      ";
		cout<<"\n\n     enter the new question to be uploaded\nQ ";
		gets(ques.q);
		cout<<"\n  Enter options :\n";
		cout<<"\n  a) ";
		gets(ques.a1);
		cout<<"\n  b) ";
		gets(ques.a2);
		cout<<"\n  c) ";
		gets(ques.a3);
		cout<<"\n  d) ";
		gets(ques.a4);
		cout<<"\n  Enter the correct option ";
		cin>>ques.r;
		fout.write((char*)&ques,sizeof(ques));
		ques.qno+=1;
		cout<<"\n\ndo you want to upload another question Y\N";
		cin>>choice;
		clrscr();
	}while(choice=='y'||choice=='Y');
	fout.close();
	menu();
}
void questions::admin()
{
		char pass[10];
		int choice;
		textbackground(5);
		a:clrscr();
		cout<<"\n\n\n\n\b\b         QUIZ ADMIN     ";
		cout<<"\n\n\b\b        ENTER PASSWORD :";
		cin>>pass;
		if(strcmp(pass,"ADMIN"))
		{
				cout<<"\n\n\n   WRONG PASSWORD ";
				cout<<"\n     press 1 to try again ";
				cout<<"\n\n press 2 to go to main menu  ";
				cin>>choice;
				if(choice==1)
				goto a;
			else menu();
		}
		clrscr();
		cout<<"\n\n\t\t             ADMIN MENU  \n\n";
		cout<<"\n\t\t     1   -  display questions ";
		cout<<"\n\n\t\t   2   -  upload questions ";
		cout<<"\n\n\t\t    3   - main menu  ";
		cin>>choice;
		switch(choice)
		{
			case 1:display();
				break;
			case 2:upload();
				break;

			case 3:menu();
				break;
		}
}
void questions::display()
{
	int i=0;
	char p[150],c1[25],c2[25],c3[25],c4[25],ans;
	ifstream fin("quiz.dat",ios::binary);
	while(fin.eof()==0&&i<5)
	{
		textbackground(0);
		clrscr();
		fin.read((char *) &ques,sizeof(ques));
		strcpy(p,ques.q);
		strcpy(c1,ques.a1);
		strcpy(c2,ques.a2);
		strcpy(c3,ques.a3);
		strcpy(c4,ques.a4);
		ans=ques.r;
		cout<<"                 ***********QUIZ*********";
		cout<<"\n\n q"<<ques.qno;
		puts(p);
		cout<<"\n options are : \n a)";
		puts(c1);
		cout<<"\n options are : \n b)";
		puts(c2);
		cout<<"\n options are : \n c)";
		puts(c3);
		cout<<"\n options are : \n d)";
		puts(c4);
		cout<<"\n correct option "<<ans;
		i++;
		if(i<4)
			cout<<"\n\n   press any key for next question";
		else
			cout<<"\n\n   press any key for admin page";
			getch();
	}
	fin.close();
		admin();
}
void questions::play()
{
	clrscr();
	input();
	clrscr();
	rules();
	textbackground(6);
	clrscr();
	long am=0;
	int i=0,d=0,no,r,l=0;
	char p[150],c1[25],c2[25],c3[25],c4[25],ans;
	ifstream fin("quiz.dat",ios::binary);
       while(l<6)
{
		time_t t;
		srand((unsigned) time(&t));
		r=rand()%8;
		for(i=0;i<r;i++)
		fin.read((char *)&ques,sizeof(ques));

		strcpy(p,ques.q);
		strcpy(c1,ques.a1);
		strcpy(c2,ques.a2);
		strcpy(c3,ques.a3);
		strcpy(c4,ques.a4);
		int no=ques.qno;
		cout<<"\n         ************quiz**********";
		if(am==0)
			cout<<"\nquestion amount: RS 5000"<<"                       in hand amount:0";
		else
			cout<<"\nquestion amount: RS "<<am*2<<"      in hand amount :"<<am;
		cout<<"\n\n Q."<<no<<" ";
		puts(p);
		cout<<"options are  : a)";
		puts(c1);
		cout<<"options are  : b)";
		puts(c2);
		cout<<"options are  : c)";
		puts(c3);
		cout<<"options are  : d)";
		puts(c4);
		cout<<"\n\nENTER YOUR ANSWER ";
		cin>>ans;
		ans=tolower(ans);
		if(ques.r==ans)
		{
			cout<<"\n YES....!!!!THATS A WRITE ANSWER ";
			if(am==0)
				am=5000;
			else
				am=2*am;
			cout<<"\n you have won Rs"<<am;
			cout<<"ENTER ANY KEY TO continue";
			getch();
			clrscr();
			textbackground(6);
		       fin.seekg(0,ios::beg);

		}
	else
	{
			cout<<"\n    wrong answer.\n\n correct answer is "<<ques.r;
			cout<<"you are takiing home an amount of Rs: "<<am;
			cout<<"\nPress any key to go to main menu";
			getch();
			menu();
	}
	l++;
	}
	textbackground(1);
	cout<<"\n\nCONGRATULATIONS!!!!  "<<name<<" YOU HAVE WON RS: "<<am;
	ofstream f1;
	f1.open("name.txt",ios::out);
	f1<<name<<am;
	f1.close();
}
void main()
{

	textbackground(0);
	clrscr();
	ques.intro();
	clrscr();
	ques.menu();
	getch();