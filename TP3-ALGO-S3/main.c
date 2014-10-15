/* 
 * File:   main.c
 * Author: Hector
 *
 * Created on 15 octobre 2014, 17:03
 */
/*definition of the struct cell (explain the state of the cell)*/
typedef enum { VIVANTE='¤', MORTE='*' } Cell;
typedef struct { int Line, Row ; } Coord; //position of a plan(or matrice)


void Init_Automate(Cell Automate[N][N]){
	int i, j;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			Automate[i][j]=MORT;
		}
	}
}

void Indicate_Cells(Cell Automate[N][N], Coord *PositionCell){
}

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
	Cell Automate[N][N];
	Coord PositionCell;
	
	Init_Automate(Automate);
	Indicate_Cells(Automate, &PositionCell);
	printf("Hello World!");
	return EXIT_SUCCESS;
}
