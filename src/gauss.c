#include "gauss.h"
#include <stdlib.h>
#include <math.h>
#define DOKL 0.00001 //Dokładność do 5 cyfr po przecinku

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

void pivot(Matrix *mat, Matrix *b, int k)
{
    int max = k;
    double maxval = fabs(mat->data[k][k]);
    for(int i = k+1; i < mat->r; i++)
    {
        if(fabs(mat->data[i][k]) > maxval) {
            max = i;
            maxval = fabs(mat->data[i][k]);
        }
    }
    double* temp = mat->data[k];
    mat->data[k] = mat->data[max];
    mat->data[max] = temp;

    temp = b->data[k];
    b->data[k] = b->data[max];
    b->data[max] = temp;
}

int eliminate(Matrix *mat, Matrix *b){

	double* wyznacznik = malloc(sizeof(double)*mat->r);
	double* wiersz = malloc(sizeof(double)*mat->c);

	for(int wk = 0; wk < mat->r; wk++)
	{
        pivot(mat, b, wk);
		double elem = mat->data[wk][wk];
        if(fabs(elem) < DOKL)
            return 1;

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



