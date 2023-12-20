#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){

	double* wyznacznik = malloc(sizeof(double)*mat->r);
	double* wiersz = malloc(sizeof(double)*mat->c);
	for(int wk = 0; wk < mat->r; wk++)
	{
		double elem = mat->data[wk][wk];

		for(int i = wk+1; i < mat->r; i++)
			wyznacznik[i] = mat->data[i][wk]/elem;

		for(int w = wk+1; w < mat->r; w++)
		{
			for(int i = wk; i < mat->c; i++){
				wiersz[i] = wyznacznik[w]*mat->data[wk][i];
			}
			for(int i = wk; i < mat->c; i++)
				mat->data[w][i] -= wiersz[i];	
		}
	}
	printToScreen(mat);
	return 0;
}

