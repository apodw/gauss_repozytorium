#include <math.h>
#include "backsubst.h"
#define DOKL 0.00001 //Dokładność do 5 cyfr po przecinku

/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */


int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    int i, j;

    if(mat->r != mat->c || b->c != 1 || x->c != 1)
        return 2;

    for(i = mat->r - 1; i >= 0; i--)
    {
        double val = b->data[i][0];
        for(j = mat->c - 1; j >= i; j--)
        {
            if(i == j)
            {
                if(fabs(mat->data[i][j]) < DOKL)
                    return 1;

                x->data[i][0] = val/mat->data[i][j];

            } else {
                val -= x->data[j][0] * mat->data[i][j];
            }
        }
    }
    return 0;
}


