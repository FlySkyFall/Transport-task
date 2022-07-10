 
#ifndef __GRHEAD_H 
#define __GRHEAD_� 
#include <stdio.h> 
#include <stdlib.h> 

 
 
// ����������� ��� ��� ����� ����� 
struct A 
{ 
	int first; // 1-� ������� ����� 
	int last; // 2-� ������� ����� 
	float weight; // ��� ����� 
}; 

// ����������� ��� ��� ����� 
struct GRAPH 
{ 
	int NumTop; // ����� ������ 
	int NumArc; // ����� ����� 
	A *pArc;	// ��������� �� ������ ������� ����� 
				// � ������������ ������ 
};
 
// ����������� ��� ���� �� ����� ������� 
struct W 
{ 
	int exist; // (!=0) � ����� ������� ���� 
				// �� ������� 
	int ref; // ���������� �������, ����� ������� 
			// �������� ���� �� ������ �������
	float SumDist; // ��������� ����� ������������ ���� 
			// �� ������ ������� 
};


// ���������� ������� �������� 
extern GRAPH Gr; // ���� 
// ��������� �� ������ �������� ��� �������� ���������� � 
// ����������� ���� �� start �� finish 
extern W *pMinWay; 
extern int finish; // ������� - ����� ���� 
extern int start; // ������� - ����� ���� 
// ��������� ������� 
void GrAllocDM( void ) ; 
void GrFreeDM( void ) ; 
void ForStep ( int, int, int ) ; 
void PassWay ( int ) ; 
void solution ( void ) ; 
void OutRes ( char*, char *pMode ) ; 
void ReadGraph ( char *pFlleInp ) ; 
void WriteGraph ( char *pFileOut, char *pMode ) ; 

#endif 