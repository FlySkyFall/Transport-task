
#include "stdafx.h"
#include "GrHead.h" 
 
int start; // ������� - ����� ���� 

GRAPH Gr; // ���� 
W *pMinWay; // ��������� �� ������ �������� � 
// ����������� � ��������� ���� �� 
// ������� start � finish 
int finish, // ������� - ����� ���� 
one, // 1-� ������� ������� ���� 
two; // 2-� ������� ������� ���� 


void ForStep ( 
	int top1, // ����������� �������, �� ������� 
	// ������ ������ 
	int IndArc, // ������ �����, �� �������� 
	// �������� ��� ������ 
	int top2 )
	// ������� �� ����� ����� 
{ 
	float NewDist; // ���������� �� top2 �� ���� ����� 
					// topi 
	NewDist = pMinWay[top1].SumDist + 
	Gr.pArc[IndArc].weight; 

	if( !pMinWay[top2]. exist ) 
	{ // ���� ���� �� top2 ��� 
		pMinWay[top2].exist = 1; 
		pMinWay[top2].SumDist = NewDist; 
		pMinWay[top2].ref = top1; 
		PassWay(top2);
	} 
	else 
	{ // ���� �� top2 ��� ���������� 
		if( pMinWay[top2]. SumDist > NewDist ) 
		{ // ����� ���� ������ 
			pMinWay[top2].SumDist = NewDist;
			pMinWay[top2].ref = top1; 
			PassWay(top2) ; 
		} 
	}
	return;
} 


void PassWay ( 
	// ����������� ������� - ��������� ����� ���� 
	int InterMediate ) 
{ 
	int k; // ������ ������� ���� ����� 
	if( InterMediate == finish ) 
	{  
		return; 
	} 
	else 
	{ 
		// ������� ����� ����� 
		for( k = 0; k < Gr.NumArc; k++ ) 
		{ 
			one = Gr.pArc[ k ].first; 
			two = Gr.pArc[ k ].last; 
			// ����������� ����������� ���� �� ����� � 
			// ���������� ���� � ��������� ����������� 
			if( one == InterMediate ) 
			{ 
				ForStep( one, k, two ); 
			} 
			else if( two == InterMediate ) 
			{ 
				ForStep ( two, k, one ); 
			} 
		} 
		return; 
	} 
} 


void solution ( void ) 
{ 
	int j;  // ������ ������� 
	// ��������� ���������� ������� �������� � ����������� � 
	// ��������� ���� 
	for( j = 0; j < Gr.NumTop; j++ ) 
	{ 
		pMinWay[ j ].exist = 0; 
	} 
	pMinWay [ start ]. exist = 1; 
	pMinWay[ start ].SumDist = 0.0f; 
	pMinWay[ start ].ref = -1; 
	// ����������� ����������� ���������� ���� 
	PassWay( start ); 
	return; 
} 

 
void OutRes ( 
	char *pFileOut, // ��������� �� ���� ������ 
	char *pMode ) // ��������� �� ����� ������ � ���� 
{ 
FILE *pStrOut; // ��������� �� ��������� �� 
// ���������� � ����� ����������� 
int TempTop, // �����,�� ������� ���� 
	RetCode1; // �������;����� �������� fclose ( ) 
	// �������� ����� ������ 
	fopen_s( &pStrOut, pFileOut, pMode); 
	if( pStrOut == NULL ) 
	{ 
		printf( "\n ������ 140. ���� %s ��� ������ �� " 
		"������ \n" , pFileOut ); 
		exit ( 140 ) ; 
	} 
	// ������ ���������� � ��������� ���� 
	if( !pMinWay[ finish ].exist ) 
	{ 
		printf ( 
			"\n �������� ���� �� ���������� \n" ) ; 
	} 
	else 
	{ 
		// ������ ������������ ���� 
		TempTop = finish; 
		fprintf( pStrOut, 
		"\n �������-�����: %d, ������� - �����: %d " 
		"\n �������� ������������ ����: %g \n", finish, 
			start, pMinWay[ finish ].SumDist ); 
		fprintf ( pStrOut, "\n ������ ������, ��������:��" 
			" ���� ���� (�� finish �� start): \n" ); 
		while ( TempTop != -1 ) 
		{ 
			fprintf( pStrOut, " %4d ", TempTop ); 
			TempTop = pMinWay [TempTop].ref; 
		} 
	} 

	// �������� ����� ����������� 
	RetCode1 = fclose( pStrOut ) ; 
	if( RetCode1 == EOF ) 
	{ 
		printf( "\n ������ 150. ���� %s �� ������ \n", 
		pFileOut ) ; 
		exit ( 150 ) ; 
	} 
	// ������������ ������������ ������ 
	GrFreeDM( ) ; 
	return;
}