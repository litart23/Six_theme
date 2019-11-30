#include <stdio.h>
#include <stdbool.h>
#include "windows.h" //for sleep
#include <time.h>   //Для nanosleep
enum ConsoleColor {
Black = 0,
Blue = 1,
Green = 2,
Cyan = 3,
Red = 4,
Magenta = 5,
Brown = 6,
LightGray = 7,
DarkGray = 8,
LightBlue = 9,
LightGreen = 10,
LightCyan = 11,
LightRed = 12,
LightMagenta = 13,
Yellow = 14,
White = 15
};

#define TRUE 1
#define FALSE 0

//сигнал детектора цвета
#define D0 // empty
#define D1 //red
#define D2 //green
#define D3 //blue

//начальное состояние системы
#define Q0 1
//состояние после сортировки
#define Q1  5
//состояние окончания работы
#define Q2 9
//состояние остановки
#define STOP 0

//состояния распределяющей пластины
#define P0  2//red
#define P1  3//green
#define P2  4//blue

//сигнал датчика прохождения нужной детали
char R1; //red
char R2; //green
char R3; //blue 

//сигнал готовности к упаковке деталей 
int U=1;
int U1=0; //red
int U2=0; //green
int U3=0; //blue

// сигнал того что деталь упакована
int F1;  //r
int F2;	//g
int F3;	//b

//сигнал того, что деталь отсортирована правильно
int Y;

//сигнал того, что детали кончились
#define Z
//сигнал подачи новой детали
#define N

//состояние сортировки деталей
#define E1	 6//r
#define E2	 7//g
#define E3	 8//b

bool end_package = false; 

char details[10] = {'R','G','B','R','B','R','R','R','G','B'};

int current_state;

void out_mass(){
	Y=0;
	printf("Out_mass function \n");
	int count=0;
	for(count=0;count<10;count++){
	detect_colour(count);
		}
}
	
void detect_colour(int i){
	//	printf("state is  %c\n",current_state);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (current_state==Q0){
		//###
		printf("\rColour detecting.");
		sleep(1);
		printf("\rColour detecting..");
		sleep(1);
		printf("\rColour detecting...\n");
		sleep(1);
		//###
		printf("Colour is - %c\n",details[i]);
	switch (details[i]){
		case 'R':
	current_state=P1;
	sleep(1);
	R1='R';
	//printf("current_state will P1 \n");
		break;
		case 'G':
	current_state=P0;
	sleep(1);
	R2='G';
	//printf("current_state will P0 \n");
		break;
		case 'B':
	current_state=P2;
	sleep(1);
	R3='B';
	//printf("current_state will P2 \n");
		break;
	default: ERROR;
	printf("state will ERROR \n");
	break;			
		}
		
} else current_state=ERROR;

	if(current_state==P1){ //состояние Р1 (+)
	SetConsoleTextAttribute(hConsole, (WORD) ((12 << 4) | 15));
	printf("SORT RED DETAIL \n");
	SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 14 ));
		if(R1=='R'){
	current_state=P0;
				Y=1;
			sleep(1);
			U1=1; //датчик 
			}
	else current_state==ERROR;
		}
		
		if(current_state==P2){ //состояние Р2 (+)
	SetConsoleTextAttribute(hConsole, (WORD) ((9 << 4) | 15));
	printf("SORT Blue DETAIL \n");
	SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 14));
		if(R3=='B'){
	current_state=P0;
				Y=1;
			sleep(1);
			U3=1; //датчик 
			}
	else current_state==ERROR;
		}
		
		if(current_state==P0){ //состояние Р1 (+)
		if(R2=='G'&&Y==0){
			SetConsoleTextAttribute(hConsole, (WORD) ((2 << 4) | 15));
	printf("SORT Green DETAIL \n");
	SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 14 ));
	current_state=P0;
		Y=1;
		sleep(1);
			U2=1; //датчик 
		}
			if(Y==1){
	current_state=Q1;
				Y=0;
				}
	else current_state=ERROR;
		}
		
		if(current_state==Q1&&U==U1||U2||U3){
			printf(" State is Q1 \n");
					if(U1==1){
				printf	(" will pack Red \n");
				sleep(1);
				current_state=E1;
				F1=U1;
				U1=0;
				}
					if(U2==1){
				printf	(" will pack Green \n");
				current_state=E2;
				F2=U2;
				U2=0;
				}
					if(U3==1){
				printf	(" will pack Blue \n");
				current_state=E3;
				F3=U3;
				U3=0;
				}
			}
			else current_state=ERROR;
	
	if (current_state==E1&&F1==1){
		printf	(" Packed Red. \n");
		worms(12);
		current_state=Q2;
		F1=0;
		}
		if (current_state==E2&&F2==1){
		printf	(" Packed Green.  \n");
		worms(2);
		current_state=Q2;
		F2=0;
		}
		if (current_state==E3&&F3==1){
		printf	(" Packed Blue.  \n");
		worms(9);
		current_state=Q2;
		F3=0;
		}
		
		if(current_state==Q2){
			printf	(" Detail arrived. \n");
			current_state=Q0;
		}
		
	
		
		if(current_state==ERROR){
			printf("THE END \n");
			printf("\r3");
			sleep(1);
			printf("\r2");
			sleep(1);
			printf("\r1");
			sleep(1);
			printf("\r3");
			sleep(1);
			printf("\r2");
			sleep(1);
			printf("\r1");
			sleep(1);
			  exit(1);  
			}
}



void print_char(int get_num)
{ printf("Print_char function \n");
	printf("num is %c\n", details[get_num]);
}
int main()
{   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
system("color 8E");
//SetConsoleTextAttribute(hConsole, (WORD) ((LightGray << 4) | Black ));
//sleep(5);
	//printf("Lets begin start our curse work\n");
	current_state=Q0;
	out_mass();
	
	//download();
	system("pause");
	return 0;
}
// ok, we have some conveer, we have details (rgb), than we need a mass with this details
// detail will save in char mass, but how conv will move? doesn't matter We are only sort and pack details use them colour
// step one: CREATE MASS with 10 details (+)
// work as automata, (use some state, change some state, mb draw some graph) 
// so, i wrote all states, first of all we take first symbol of char mass and work with them
//creating function of take new symbol, and mb will find delay func 
void worms(int colo){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	if (current_state==E1){
	int a = 100000;
	for(int i=0;i<3;i++){
		SetConsoleTextAttribute(hConsole, (WORD) ((colo << 4) | 15));
		//printf	("Packed fucking red detail\n");
		printf("\r|~      |");
		usleep(a);
		printf("\r| ~      |");
		usleep(a);
		printf("\r|  ~     |");
		usleep(a);
		printf("\r|   ~    |");
		usleep(a);
		printf("\r|    ~   |");	
		usleep(a);
		printf("\r|     ~  |");	
		usleep(a);
		printf("\r|      ~ |");	
		usleep(a);
		printf("\r|       ~|");	
		usleep(a);
		printf("\r|      ~ |");	
		usleep(a);
		printf("\r|     ~  |");	
		usleep(a);
		printf("\r|    ~   |");
		usleep(a);
		printf("\r|   ~    |");
		usleep(a);
		printf("\r|  ~     |");
		usleep(a);
		printf("\r| ~      |");
		usleep(a);
		printf("\r|~       |");
		}
		
		printf("\r|FINISHED|");
	SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 14 ));
	//system("color F15");
		printf("\n");
}

void download(){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int a = 200000;
	sleep(3);
		SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2));
		//printf	("Packed fucking red detail\n");
		int s=32;
		int r=219;
			printf("\r	%c%c%c%c%c%c%c%c%c%c%c%c%c%c",r,s,s,s,s,s,s,s,s,s,s,s,s,s);
			usleep(a);
			printf("\r	%c%c%c%c%c%c%c%c%c%c%c%c%c%c",r,s,s,s,s,s,s,s,s,s,s,s,s,s);
			usleep(a);
			printf("\r	%c%c%c%c%c%c%c%c%c%c%c%c%c%c",r,r,s,s,s,s,s,s,s,s,s,s,s,s);
			usleep(a);
			printf("\r	%c%c%c%c%c%c%c%c%c%c%c%c%c%c",r,r,r,s,s,s,s,s,s,s,s,s,s,s);
			usleep(a);
			printf("\r	%c%c%c%c%c%c%c%c%c%c%c%c%c%c",r,r,r,r,s,s,s,s,s,s,s,s,s,s);
			usleep(a);
			printf("\r	%c%c%c%c%c%c%c%c%c%c%c%c%c%c",r,r,r,r,r,s,s,s,s,s,s,s,s,s);
			usleep(a);
			printf("\r	%c%c%c%c%c%c%c%c%c%c%c%c%c%c",r,r,r,r,r,r,s,s,s,s,s,s,s,s);
			usleep(a);
			printf("\r	%c%c%c%c%c%c%c%c%c%c%c%c%c%c",r,r,r,r,r,r,r,s,s,s,s,s,s,s);
			usleep(a);
			printf("\r	%c%c%c%c%c%c%c%c%c%c%c%c%c%c",r,r,r,r,r,r,r,r,s,s,s,s,s,s);
			usleep(a);
			printf("\r	%c%c%c%c%c%c%c%c%c%c%c%c%c%c",r,r,r,r,r,r,r,r,r,s,s,s,s,s);
			usleep(a);
			printf("\r	%c%c%c%c%c%c%c%c%c%c%c%c%c%c",r,r,r,r,r,r,r,r,r,r,s,s,s,s);
			usleep(a);
			printf("\r	%c%c%c%c%c%c%c%c%c%c%c%c%c%c",r,r,r,r,r,r,r,r,r,r,s,s,s,s);
			usleep(a);
			printf("\r	%c%c%c%c%c%c%c%c%c%c%c%c%c%c",r,r,r,r,r,r,r,r,r,r,r,s,s,s);
			usleep(a);
			printf("\r	%c%c%c%c%c%c%c%c%c%c%c%c%c%c",r,r,r,r,r,r,r,r,r,r,r,r,s,s);
			usleep(a);
			printf("\r	%c%c%c%c%c%c%c%c%c%c%c%c%c%c",r,r,r,r,r,r,r,r,r,r,r,r,r,r);
			usleep(500000);
			printf("\n");
			}
	
	
		
	

