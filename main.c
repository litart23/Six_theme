#include <stdio.h>
#include <stdbool.h>
#include "windows.h" //for sleep
#define TRUE 1
#define FALSE 0

//сигнал детектора цвета
#define D0 // empty
#define D1 //red
#define D2 //green
#define D3 //blue

//начальное состояние системы
#define Q0
//состояние после сортировки
#define Q1
//состояние окончания работы
#define Q2

//состояния распределяющей пластины
#define P0 //red
#define P2 //green
#define P3 //blue

//сигнал датчика прохождения нужной детали
#define R1 //red
#define R2 //green
#define R3 //blue 

//сигнал готовности к упаковке деталей 
#define U1 //red
#define U2 //green
#define U3 //blue

// сигнал того что деталь упакована
#define F1  //r
#define F2	//g
#define F3	//b

//сигнал того, что деталь отсортирована правильно
#define Y
//сигнал того, что детали кончились
#define Z
//сигнал подачи новой детали
#define N

//состояние сортировки деталей
#define E1	//r
#define E2	//g
#define E3	//b

bool end_package = false; 

char details[10] = {'R','G','B','B','B','G','R','R','G','B'};



void out_mass(){
	printf("Out_mass function \n");
	int count=0;
	for(count=0;count<10;count++){
		print_char(count);
		}
	}

void print_char(int get_num)
{ printf("Print_char function \n");
	printf("num is %c\n", details[get_num]);
}
int main()
{	int five=5;
	printf("Lets begin start our curse work\n");
	out_mass();
	system("pause");
	return 0;
}
// ok, we have some conveer, we have details (rgb), than we need a mass with this details
// detail will save in char mass, but how conv will move? doesn't matter We are only sort and pack details use them colour
// step one: CREATE MASS with 10 details (+)
// work as automata, (use some state, change some state, mb draw some graph) 
// so, i wrote all states, first of all we take first symbol of char mass and work with them
//creating function of take new symbol, and mb will find delay func 
