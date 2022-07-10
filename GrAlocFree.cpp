#include "stdafx.h" 
#include "GrHead.h" 
#include <iostream>

 
void GrAllocDM( void ) 
{  
	// Контроль корректности количества вершин графа 
	if( Gr.NumTop < 2 ) 
	{ 
		std::cout <<
			"\n Предупреждение 10. Число вершин графа должно быть более" 
			" одной вершины" 
			"\n (задано число вершин, равное %d) . Принимается число" 
			" вершин, равное 2." 
			"\n Выполнение программы продолжается " << Gr.NumTop << std::endl ; 
		Gr.NumTop = 2; 
	} 
	// Контроль корректности количества ребер графа 
	if( Gr.NumArc < 1 ) 
	{ 
		std::cout <<
			"\n Предупреждение 20. Число ребер графа должно быть не"
			" менее одного ребра"
			"\n (задано число ребер, равное %d) . Принимается число"
			" ребер, равное 1. " << std::endl;
		Gr.NumArc = 1; 
	} 
	// Размещение массива ребер в динамической памяти 
	Gr.pArc = new A[Gr.NumArc] ; 
	if( Gr.pArc == NULL ) 
	{ 
		std::cout << "\n Ошибка 30. Массив ребер в динамической" 
		" памяти не размещен " << std::endl; 
		exit ( 30 ) ; 
	} 

	// Размещение массива структур с информацией о наилучшем 
	// пути в динамической памяти 
	pMinWay = new W[ Gr.NumTop ] ; 
	if( pMinWay == NULL ) 
	{ 
		std::cout << 
		"\n Ошибка 40. Массив структур с информацией о наилучшем" 
		" пути в \n" 
		"\n динамической памяти не размещен " << std::endl; 
		exit ( 40 ) ; 
	} 
	// Инициализация массивов, размещенных в динамической 
	// памяти, нулевыми значениями 
	for( int i = 0; i < Gr.NumArc; i++ ) 
	{ 
		Gr.pArc[ i ].first = 0; 
		Gr.pArc[ i ].last = 0; 
		Gr.pArc[ i ].weight = 0.0f; 
	} 
	for( int i = 0; i < Gr.NumTop; i++) 
	{ 
		pMinWay[ i ]. exist = 0; 
		pMinWay[ i ].ref = 0; 
		pMinWay[ i ]. SumDist = 0.0; 
	} 
	return; 
} 

// Освобождение динамическом памяти, занятой массивами ребер 
// и структур с информацией о наилучшем пути 
void GrFreeDM( void ) 
{ 
	if( Gr.pArc != NULL ) 
	{ 
		delete [ ] Gr.pArc; Gr.pArc = NULL; 
	} 

	if( pMinWay != NULL ) 
	{ 
		delete [ ] pMinWay; pMinWay = NULL; 
	} 
	return; 

} 
