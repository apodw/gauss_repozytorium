#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){




	double* wyznacznik = malloc(sizeof(double)*mat->r);
	double* wiersz = malloc(sizeof(double)*mat->c);

	for(int wk = 0; wk < mat->r; wk++)
	{

	double* kolumna = malloc(sizeof(double)*mat->r);

	for(int i = wk; i < mat->r; i++)
		kolumna[i] = mat->data[i][wk];

	double max = fabs(kolumna[wk]);
	int k = wk;

	for(int j = wk+1; j < mat->r; j++)
	{
		double cur = fabs(kolumna[j]);
		printf("%lf\n", cur); /* kkk*/
		if (cur > max)
		{
			max = cur;
			k = j;
		}
	}
	double* tmp_w = malloc(sizeof(double)*mat->c);
	for(int x= wk; x < mat->c; x++)
	{
		if(k == wk)
			break;


		for (int y = wk; y < mat->c; y++)
			tmp_w[y] = mat->data[wk][y];

		mat->data[wk][x] = mat->data[k][x];
		mat->data[k][x] = tmp_w[x];	

	}
		free(tmp_w);
		free(kolumna);
		double* tmp_b = malloc(sizeof(double)*mat->c);

	if(k != wk )
	{
		for (int y = wk; y < b->r; y++)
			tmp_b[y] = b->data[y][0];

		b->data[wk][0] = b->data[k][0];
		b->data[k][0] = tmp_b[wk];
	}
	printToScreen(mat);
	printToScreen(b);
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

            b->data[w][0] -= b->data[wk][0]*wyznacznik[w];
		}
	}
    free(wyznacznik);
    free(wiersz);

	
	return 0;
}

