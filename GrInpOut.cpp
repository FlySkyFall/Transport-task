#include "stdafx.h" 
#include "GrHead.h" 
#include <iostream>

void ReadGraph ( 
	// ��������� �� ���� ������ 
	char *pFileInp ) 
{ 
	FILE *pStrInp; // ��������� �� ��������� �� 
	// ���������� � ����� ����� 
	int i , // ������ ����� 
	RetCode, // ������������ �������� fscanf_s( ) 
				// ��� �� ����� 
	RetCode1; // ������������ �������� fclose( ) 
	// �������� ����� ����� 
	fopen_s(&pStrInp, pFileInp, "r" ); 
	if( pStrInp == NULL ) 
	{ 
		std::cout << "\n ������ 50, ���� %s ��� ������ �� " 
		"������ \n" << pFileInp << std::endl; 
		exit ( 50 ) ; 
	} 

	// ������ ���������� ������ � ���������� ����� 
	RetCode = fscanf_s( pStrInp, "%d", &Gr.NumTop ) ; 
	if( RetCode != 1 ) 
	{ 
		std::cout << "\n ������ 60, ������ ��� ������ ����� "
		"������ ����� \n" << std::endl;
		exit ( 60 ); 
	} 
	RetCode = fscanf_s ( pStrInp, " %d", &Gr.NumArc ) ; 
	if( RetCode !=1) 
	{ 
		std::cout << "\n ������ 70, ������ ��� ������ ����� "
		"����� ����� \n" << std::endl;
		exit ( 70 ) ; 
	} 

	// ���������� �������� ������ ����� � ������������ ������ 
	GrAllocDM( ) ; 
	// ���������� ������� ����� ����� 
	RetCode = 0; 
	for( i = 0; i < Gr.NumArc; i++) 
	{ 
		RetCode += fscanf_s( pStrInp, " %d %d %g", 
			&Gr.pArc[i].first, &Gr.pArc[i].last, 
			&Gr.pArc[i].weight ) ; 
		if( ( Gr.pArc[i].first < 0 ) || 
			( Gr.pArc[i].first >= Gr.NumTop ) || 
			( Gr.pArc[i].last < 0 ) || 
			( Gr.pArc[i].last >= Gr.NumTop ) ) 
		{ 
			std::cout << "\n ������ 75. ������� ������ �.�. � "
			"��������� �. . %d \n " << Gr.NumTop-1 << std::endl;
			exit ( 75 ); 
		} 
	} 
	if( RetCode < 3*Gr.NumArc ) 
	{ 
		std::cout << "\n ������ 80. ������ ������ ��������� "
		"������� ����� \n" << std::endl;
		exit ( 80 ) ; 
	} 
	// ������ ���������� � �������� - ������ � ������ ���� 
	RetCode = fscanf_s ( pStrInp, "%d", &start ) ; 
	if( RetCode != 1 ) 
	{ 
		std::cout << "\n ������ 90. ������ ��� ������ ���������"
		" ������� ���� \n" << std::endl;
		exit ( 90 ) ; 
	} 
	RetCode = fscanf_s ( pStrInp, " %d", &finish ) ; 
	if( RetCode != 1 ) 
	{ 
		std::cout << "\n ������ 100. ������ ��� ������ ��������"
		" ������� ���� \n" << std::endl;
		exit ( 100 ) ; 
	} 
	// �������� ����� ����� 
	RetCode1 = fclose( pStrInp ) ; 
	if( RetCode1 == EOF ) 
	{ 
		std::cout << "\n ������ 110. ������ �������� ����� %s \n" <<
		pFileInp << std::endl;
		exit ( 110 ) ; 
	} 
	return;
}

void WriteGraph ( 
	char *pFileOut,// ��������� �� ���� ����������� 
	char *pMode ) // ��������� �� ����� �������� ����� 
{ 
	FILE *pStrOut; // ��������� �� ��������� �� 
	// ���������� � ����� ����������� 
	int i, // ������ �������� ������� ����� 
	RetCode1; // ������������ �������� fclose( ) 
	// �������� ����� ������ 
	fopen_s( &pStrOut, pFileOut, pMode ); 
	if( pStrOut == NULL ) 
	{ 
		std::cout << "\n ������ 120, ���� %s ��� ������ �� "
		"������ \n" << pFileOut << std::endl;
		exit ( 120 ) ; 
	} 
	// ������ ���������� � ����� 
	fprintf ( pStrOut, "\n ����� ������ �����: %d," 
		" ����� �����: %d \n", Gr.NumTop, Gr.NumArc ); 
	fprintf ( pStrOut, 
	"\n*********************************************************"
	"\n ������ ����� 1-� ������� 2-� ������� ��� �����" 
	"\n********************^**************************^*********" 
	"\n" ) ; 
	for( i = 0; i < Gr.NumArc; i++ ) 
	{ 
		fprintf( pStrOut, "%10d %14d %14d %17f \n", i, 
			Gr.pArc[ i ].first, Gr.pArc[ i ].last, 
			Gr.pArc[ i ].weight ); 
	} 
	// �������� ����� ������ 
	RetCode1 = fclose( pStrOut ); 
	if( RetCode1 == EOF ) 
	{ 
		std::cout << "\n ������ 150. ���� %s �� ������ \n " <<
		pFileOut << std::endl; 
		exit ( 150 ); 
	} 
	return; 
} 
