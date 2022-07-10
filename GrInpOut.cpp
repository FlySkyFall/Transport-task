#include "stdafx.h" 
#include "GrHead.h" 
#include <iostream>

void ReadGraph ( 
	// Указатель на файл данных 
	char *pFileInp ) 
{ 
	FILE *pStrInp; // Указатель на структуру со 
	// сведениями о файле ввода 
	int i , // Индекс ребра 
	RetCode, // Возвращаемые значения fscanf_s( ) 
				// или их сумма 
	RetCode1; // Возвращаемое значение fclose( ) 
	// Открытие файла ввода 
	fopen_s(&pStrInp, pFileInp, "r" ); 
	if( pStrInp == NULL ) 
	{ 
		std::cout << "\n Ошибка 50, Файл %s для чтения не " 
		"открыт \n" << pFileInp << std::endl; 
		exit ( 50 ) ; 
	} 

	// Чтение количества вершин и количества ребер 
	RetCode = fscanf_s( pStrInp, "%d", &Gr.NumTop ) ; 
	if( RetCode != 1 ) 
	{ 
		std::cout << "\n Ошибка 60, Ошибка при чтении числа "
		"вершин графа \n" << std::endl;
		exit ( 60 ); 
	} 
	RetCode = fscanf_s ( pStrInp, " %d", &Gr.NumArc ) ; 
	if( RetCode !=1) 
	{ 
		std::cout << "\n Ошибка 70, Ошибка при чтении числа "
		"ребер графа \n" << std::endl;
		exit ( 70 ) ; 
	} 

	// Размещение структур данных графа в динамической памяти 
	GrAllocDM( ) ; 
	// Заполнение массива ребер графа 
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
			std::cout << "\n Ошибка 75. Индексы вершин д.б. в "
			"диапазоне О. . %d \n " << Gr.NumTop-1 << std::endl;
			exit ( 75 ); 
		} 
	} 
	if( RetCode < 3*Gr.NumArc ) 
	{ 
		std::cout << "\n Ошибка 80. Ошибка чтения элементов "
		"массива ребер \n" << std::endl;
		exit ( 80 ) ; 
	} 
	// Чтение информации о вершинах - старте и финише пути 
	RetCode = fscanf_s ( pStrInp, "%d", &start ) ; 
	if( RetCode != 1 ) 
	{ 
		std::cout << "\n Ошибка 90. Ошибка при чтении начальной"
		" вершины пути \n" << std::endl;
		exit ( 90 ) ; 
	} 
	RetCode = fscanf_s ( pStrInp, " %d", &finish ) ; 
	if( RetCode != 1 ) 
	{ 
		std::cout << "\n Ошибка 100. Ошмбка при чтении конечной"
		" вершины пути \n" << std::endl;
		exit ( 100 ) ; 
	} 
	// Закрытие файла ввода 
	RetCode1 = fclose( pStrInp ) ; 
	if( RetCode1 == EOF ) 
	{ 
		std::cout << "\n Ошибка 110. Ошибка закрытия файла %s \n" <<
		pFileInp << std::endl;
		exit ( 110 ) ; 
	} 
	return;
}

void WriteGraph ( 
	char *pFileOut,// Указатель на файл результатов 
	char *pMode ) // Указатель на режим открытия файла 
{ 
	FILE *pStrOut; // Указатель на структуру со 
	// сведениями о файле результатов 
	int i, // Индекс элемента массива ребер 
	RetCode1; // Возвращаемое значение fclose( ) 
	// Открытие файла вывода 
	fopen_s( &pStrOut, pFileOut, pMode ); 
	if( pStrOut == NULL ) 
	{ 
		std::cout << "\n Ошибка 120, Файл %s для вывода не "
		"открыт \n" << pFileOut << std::endl;
		exit ( 120 ) ; 
	} 
	// Печать информации о графе 
	fprintf ( pStrOut, "\n Число вершин графа: %d," 
		" число ребер: %d \n", Gr.NumTop, Gr.NumArc ); 
	fprintf ( pStrOut, 
	"\n*********************************************************"
	"\n Индекс ребра 1-я вершина 2-я вершина Вес ребра" 
	"\n********************^**************************^*********" 
	"\n" ) ; 
	for( i = 0; i < Gr.NumArc; i++ ) 
	{ 
		fprintf( pStrOut, "%10d %14d %14d %17f \n", i, 
			Gr.pArc[ i ].first, Gr.pArc[ i ].last, 
			Gr.pArc[ i ].weight ); 
	} 
	// Закрытие файла вывода 
	RetCode1 = fclose( pStrOut ); 
	if( RetCode1 == EOF ) 
	{ 
		std::cout << "\n Ошибка 150. Файл %s не закрыт \n " <<
		pFileOut << std::endl; 
		exit ( 150 ); 
	} 
	return; 
} 
