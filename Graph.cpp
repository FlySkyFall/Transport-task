
#include "stdafx.h"
#include "GrHead.h"
#include <iostream>
 
int start; // Вершина - старт пути 

GRAPH Gr; // Граф 
W *pMinWay; // Указатель на массив структур с 
// информацией о наилучшем пути из 
// вершины start в finish 
int finish, // Вершина - финиш пути 
one, // 1-я вершина текущей дуги 
two; // 2-я вершина текущей дуги 


void ForStep ( 
	int top1, // Достигнутая вершина, из которой 
	// шагаем вперед 
	int IndArc, // Индекс ребра, по которому 
	// делается шаг вперед 
	int top2 )
	// Вершина на конце ребра 
{ 
	float NewDist; // Расстояние до top2 по пути через 
					// topi 
	NewDist = pMinWay[top1].SumDist + 
	Gr.pArc[IndArc].weight; 

	if( !pMinWay[top2]. exist ) 
	{ // Пока пути до top2 нет 
		pMinWay[top2].exist = 1; 
		pMinWay[top2].SumDist = NewDist; 
		pMinWay[top2].ref = top1; 
		PassWay(top2);
	} 
	else 
	{ // Путь до top2 уже существует 
		if( pMinWay[top2]. SumDist > NewDist ) 
		{ // Новый путь короче 
			pMinWay[top2].SumDist = NewDist;
			pMinWay[top2].ref = top1; 
			PassWay(top2) ; 
		} 
	}
	return;
} 


void PassWay ( 
	// Достигнутая вершина - отправная точка пути 
	int InterMediate ) 
{ 
	int k; // Индекс текущей дуги графа 
	if( InterMediate == finish ) 
	{  
		return; 
	} 
	else 
	{ 
		// Перебор ребер графа 
		for( k = 0; k < Gr.NumArc; k++ ) 
		{ 
			one = Gr.pArc[ k ].first; 
			two = Gr.pArc[ k ].last; 
			// Определения направления шага по ребру и 
			// выполнение шага в найденном направлении 
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
	int j;  // Индекс вершины 
	// Начальная подготовка массива структур с информацией о 
	// наилучшем пути 
	for( j = 0; j < Gr.NumTop; j++ ) 
	{ 
		pMinWay[ j ].exist = 0; 
	} 
	pMinWay [ start ]. exist = 1; 
	pMinWay[ start ].SumDist = 0.0f; 
	pMinWay[ start ].ref = -1; 
	// Рекурсивное определение требуемого пути 
	PassWay( start ); 
	return; 
} 

 
void OutRes ( 
	char *pFileOut, // Указатель на файл вывода 
	char *pMode ) // Указатель на режим вывода в файл 
{ 
FILE *pStrOut; // Указатель на структуру со 
// сведениями о файле результатов 
int TempTop, // Текуш,ая вершина пути 
	RetCode1; // Возвраш;аемое значение fclose ( ) 
	// Открытие файла вывода 
	fopen_s( &pStrOut, pFileOut, pMode); 
	if( pStrOut == NULL ) 
	{ 
		std::cout << "\n Ошибка 140. Файл %s для вывода не " 
		"открыт \n" << pFileOut << std::endl; 
		exit ( 140 ) ; 
	} 
	// Печать информации о найденном пути 
	if( !pMinWay[ finish ].exist ) 
	{ 
		std::cout << 
			"\n Искомого пути не существует \n" << std::endl; 
	} 
	else 
	{ 
		// Печать оптимального пути 
		TempTop = finish; 
		fprintf( pStrOut, 
		"\n Вершина-финиш: %d, вершина - старт: %d " 
		"\n Значение минимального пути: %g \n", finish, 
			start, pMinWay[ finish ].SumDist ); 
		fprintf ( pStrOut, "\n Список вершин, образуюш:их" 
			" этот путь (от finish до start): \n" ); 
		while ( TempTop != -1 ) 
		{ 
			fprintf( pStrOut, " %4d ", TempTop ); 
			TempTop = pMinWay [TempTop].ref; 
		} 
	} 

	// Закрытие файла результатов 
	RetCode1 = fclose( pStrOut ) ; 
	if( RetCode1 == EOF ) 
	{ 
		std::cout << "\n Ошибка 150. Файл %s не закрыт \n" << 
		pFileOut << std::endl; 
		exit ( 150 ) ; 
	} 
	// Освобождение динамической памяти 
	GrFreeDM( ) ; 
	return;
}