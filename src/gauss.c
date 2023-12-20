#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){

	int nr = mat->r;
	int nc = mat->c;

	double *rzedy = malloc(sizeof(double) * nr);
	double *wyz_r = malloc(sizeof(double) * nr);

	for(int k = 0; k < nc; k++)
	{
  		for(int i = 0; i < nr; i++)
			rzedy[i] = mat->data[i][k];
	
		for(int j = 0; j < nr; j++)
		{
			wyz_r[j] = rzedy[k+j+1] / rzedy[k];

			for(int l=0; l < nr; l++)
			{
				for(int p = 0; p < nc; p++)
				{
					if (k + p + 1 < nc && l < nr) 
					{
                        mat->data[k+p+1][l] -= mat->data[k+p+1][l] * wyz_r[p];
					}
				}
			}
		}
	}
		return 0;
}

