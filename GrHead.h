 
#ifndef __GRHEAD_H 
#define __GRHEAD_Н 
#include <stdio.h> 
#include <stdlib.h> 

 
 
// Структурный тип для ребра графа 
struct A 
{ 
	int first; // 1-я вершина ребра 
	int last; // 2-я вершина ребра 
	float weight; // Вес ребра 
}; 

// Структурный тип для графа 
struct GRAPH 
{ 
	int NumTop; // Число вершин 
	int NumArc; // Число ребер 
	A *pArc;	// Указатель на начало массива ребер 
				// в динамической памяти 
};
 
// Структурный тип пути до одной вершины 
struct W 
{ 
	int exist; // (!=0) в графе имеется путь 
				// до вершины 
	int ref; // Предыдущая вершина, через которую 
			// проходит путь до данной вершины
	float SumDist; // Суммарная длина минимального пути 
			// до данной вершины 
};


// Объявления внешних объектов 
extern GRAPH Gr; // Граф 
// Указатель на массив структур для хранения информации о 
// минимальном пути от start до finish 
extern W *pMinWay; 
extern int finish; // Вершина - финиш пути 
extern int start; // Вершина - старт пути 
// Прототипы функций 
void GrAllocDM( void ) ; 
void GrFreeDM( void ) ; 
void ForStep ( int, int, int ) ; 
void PassWay ( int ) ; 
void solution ( void ) ; 
void OutRes ( char*, char *pMode ) ; 
void ReadGraph ( char *pFlleInp ) ; 
void WriteGraph ( char *pFileOut, char *pMode ) ; 

#endif 
