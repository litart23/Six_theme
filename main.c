#include <stdio.h>
#include <stdbool.h>
#include "windows.h" //for sleep
#define TRUE 1
#define FALSE 0

//������ ��������� �����
#define D0 // empty
#define D1 //red
#define D2 //green
#define D3 //blue

//��������� ��������� �������
#define Q0
//��������� ����� ����������
#define Q1
//��������� ��������� ������
#define Q2

//��������� �������������� ��������
#define P0 //red
#define P2 //green
#define P3 //blue

//������ ������� ����������� ������ ������
#define R1 //red
#define R2 //green
#define R3 //blue 

//������ ���������� � �������� ������� 
#define U1 //red
#define U2 //green
#define U3 //blue

// ������ ���� ��� ������ ���������
#define F1  //r
#define F2	//g
#define F3	//b

//������ ����, ��� ������ ������������� ���������
#define Y
//������ ����, ��� ������ ���������
#define Z
//������ ������ ����� ������
#define N

//��������� ���������� �������
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
