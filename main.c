#include <stdio.h>
#include <stdlib.h>
void buscarCuadrado(int **,int, int, int);

int main()
{
    FILE *fr = fopen("datos.in","r");
    int n,i;
    fscanf(fr, "%d", &n);
    int **cuadrado;

    cuadrado =  (int**) malloc(sizeof((*cuadrado))* n);

    for(i = 0; i < n; i++)
    {
        cuadrado[i] = (int *) malloc(sizeof(**cuadrado) * n);
    }

    printf("asdasfas\n");
    buscarCuadrado(cuadrado,n, 0, 0);


    fclose(fr);
    return 0;
}


void buscarCuadrado(int **cuadrado,int n, int i, int j)
{
    int solucion = 1, fila, columna, k,actI,actJ;

        for(k = 1; k < (n*n); k++)
        {
            cuadrado[i][j] = k;
            if(i + 1 < n)
            {
                if(j + 1 < n)
                {
                    buscarCuadrado(cuadrado, n, i, j + 1);
                }else
                {
                    buscarCuadrado(cuadrado, n, i + 1, 0);
                }

            }else
            {
                if(j + 1 < n)
                {
                    buscarCuadrado(cuadrado, n, i, j + 1);
                }else //solucion
                {

                    actI = 0;
                    solucion = 1;
                    while(actI < n && solucion)
                    {
                        fila = 0;
                        columna = 0;
                        for(actJ = 0; actJ < n; actJ++)
                        {
                            fila += cuadrado[actI][actJ];
                            columna += cuadrado[actJ][actI];
                        }
                        if(fila == columna && fila == ((n)*(((n*n) + 1)/2)) && columna == ((n)*(((n*n) + 1)/2)))
                        {
                            actI++;
                        }else
                        {
                            solucion = 0;
                        }
                    }
                    if(solucion)
                    {
                        for(actI = 0; actI < n; actI++)
                        {
                            for(actJ = 0; actJ < n; actJ++)
                            {
                                printf("%d ",cuadrado[actI][actJ]);
                            }
                            printf("\n");
                        }
                        printf("\n");
                    }
                }
            }
        }


}

