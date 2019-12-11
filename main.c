#include <stdio.h>
#include <stdbool.h>
#include "windows.h" //for sleep
#include <time.h>   //Для nanosleep
#include <string.h>
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

//start state
#define Q0 1
//after sorting state
#define Q1  5
//finish state
#define Q2 9
//stop state
#define STOP 0

//sorting machine state
#define P0  2//red
#define P1  3//green
#define P2  4//blue


//sort details state
#define E1	 6//r
#define E2	 7//g
#define E3	 8//b

bool end_package = false; 



int current_state;

void out_mass(){
	printf(" Start \n");
	int count=0;
	for(count=0;count<10;count++){
	detect_colour(count);
		}
}
	
void detect_colour(int i){
	
	
	    FILE *fin; 

char st0[14];
char st1[14];
char st2[14];
char st3[14];
char st4[14];
char st5[14];
char st6[14];

char set0[14] = "00000000000001";
char set1R[14] = "10000000000000";
char set1G[14] = "01000000000000";
char set1B[14] = "00100000000000";

char set2R[14] = "00010000000000";
char set2G[14] = "00001000000000";
char set2B[14] = "00000100000000";

char set3Y[14] = "00000010000000";

char set4R[14] = "00000001000000";
char set4G[14] = "00000000100000";
char set4B[14] = "00000000010000";

char set5R[14] = "00000000001000";
char set5G[14] = "00000000000100";
char set5B[14] = "00000000000010";
char set6Z[1]="\0";


fin = fopen("signals.txt", "r");
fgets ( st0, 20, fin );
fgets ( st1, 20, fin );
fgets ( st2, 20, fin );
fgets ( st3, 20, fin );
fgets ( st4, 20, fin );
fgets ( st5, 20, fin );
fgets ( st6, 20, fin );
st0[strlen(st0)-1] = '\0';
 st1[strlen(st1)-1] = '\0';
 st2[strlen(st2)-1] = '\0';
 st3[strlen(st3)-1] = '\0';
 st4[strlen(st4)-1] = '\0';
 st5[strlen(st5)-1] = '\0';
st6[strlen(st6)-1] = '\0';
 
   
//   // Сравниваем две строки
//   if (strcmp (set1, st1)==0){
//      printf("good\n");
//     }
//    else {
//      printf("bad\n");
//        }
//		
	//	printf("state is  %c\n",current_state);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (current_state==Q0){
		//###
		printf("\r Colour detecting.");
		sleep(1);
		printf("\r Colour detecting..");
		sleep(1);
		printf("\r Colour detecting...\n");
		sleep(1);
		//printf(" Colour is - %c\n",details[i]);

	}
	else current_state=ERROR;
		
	
if (strcmp (set1R, st1)==0){
	current_state=P1;
	sleep(1);
	
	printf("Red detail has been detecting\n");
}
if (strcmp (set1G, st1)==0){
	current_state=P2;
	sleep(1);
	
	printf("Green detail has been detecting\n");
}
if (strcmp (set1B, st1)==0){
	current_state=P0;
	sleep(1);
	
	printf("Blue detail has been detecting\n");
}	
//else current_state=ERROR;

	if(current_state==P1){ //состояние Р1 (+)
	SetConsoleTextAttribute(hConsole, (WORD) ((12 << 4) | 15));
	printf(" SORT RED DETAIL \n");
	SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 14 ));
		if (strcmp (set2R, st2)==0){
	current_state=P0;
			sleep(1);
			//U1=1; //датчик 
			}
	else current_state==ERROR;
		}
		
		if(current_state==P2){ //состояние Р2 (+)
	SetConsoleTextAttribute(hConsole, (WORD) ((9 << 4) | 15));
	printf(" SORT Blue DETAIL \n");
	SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 14));
		if (strcmp (set2B, st2)==0){
	current_state=P0;
			sleep(1);
			//U3=1; //датчик 
			}
	else current_state==ERROR;
		}
		
		if(current_state==P0){ //состояние Р1 (+)
		if (strcmp (set2G, st2)==0){
			SetConsoleTextAttribute(hConsole, (WORD) ((2 << 4) | 15));
	printf(" SORT Green DETAIL \n");
	SetConsoleTextAttribute(hConsole, (WORD) ((8 << 4) | 14 ));
	current_state=P0;
		sleep(1);
			//U2=1; //датчик 
		}
			if (strcmp (set3Y, st3)==0){
	current_state=Q1;
				}
	else current_state=ERROR;
		}
		
		if(current_state==Q1){
			printf(" State is Q1 \n");
					if (strcmp (set4R, st4)==0 && strcmp (set2R, st2)==0 ){
				printf	(" Will pack Red \n");
				current_state=E1;
				}
					if (strcmp (set4G, st4)==0 && strcmp (set2G, st2)==0 ){
				printf	(" Will pack Green \n");
				current_state=E2;
				}
					if (strcmp (set4B, st4)==0 && strcmp (set2B, st2)==0){
				printf	(" Will pack Blue \n");
				current_state=E3;
				}
				
			}
			else current_state=ERROR;
			
	
	if (current_state==E1){
		if (strcmp (set5R, st5)==0&&strcmp (set4R, st4)==0){
		printf	(" Packed Red. \n");
		worms(12);
		current_state=Q2;
		}
		}
		if (current_state==E2&&strcmp (set4G, st4)==0){
		if (strcmp (set5G, st5)==0 && strcmp (set4G, st4)==0){
		printf	(" Packed Green.  \n");
		worms(2);
		current_state=Q2;
		}
		}
		if (current_state==E3 ){
		if (strcmp (set5B, st5)==0&& strcmp (set4B, st4)==0){
		printf	(" Packed Blue.  \n");
		worms(9);
		current_state=Q2;
		}
	}
	if (current_state!=Q2){
		current_state=ERROR;
		}

		if(current_state==Q2){
			printf	(" Detail arrived. \n");
			sleep(1);
			if (strcmp (set6Z, st6)==0){

				printf	(" Conveer has empty. \n");
				current_state=ERROR;
			}
			else current_state=Q0;
		}
		
	
		
		if(current_state==ERROR){
			printf(" THE END \n");
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
	
	
		
	

