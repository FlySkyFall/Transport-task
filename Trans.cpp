

#include "stdafx.h"
#include <iostream>
#include <string.h> 
#include "GrHead.h"


int main ( int ArgC, char *ArgV[ ] )
{
	setlocale(LC_ALL, "Russian");
	char NameExeFile[100] = "Trans.exe";
	char NameFileDate[100] = "Data.txt";
	char NameFileGraph[100] = "Graph.txt";
	char NameFileRes[100] = "Res.txt";
	// Чтение информации о графе 
	ReadGraph ( NameFileDate) ; 
	// Печать информации о графе 
	WriteGraph( NameFileGraph, "w" ) ; 
	solution ( ) ; // Решение транспортной задачи 
	// Вывод результатов решения 
	OutRes ( NameFileRes, "w" ) ; 
	return 0; 
} 
