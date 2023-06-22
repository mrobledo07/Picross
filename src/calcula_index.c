#include <stdio.h>
#include <stdlib.h>
#define MAX_FIL 20
#define MAX_COL 20

void calcula_index (int matriu[MAX_FIL][MAX_COL], int index_col[MAX_FIL][MAX_COL], int index_fil[MAX_FIL][MAX_COL], int num_fil, int num_col, int *pixels, int *columnes_indexfil, int *files_indexcol)
{
    int x = 0, y = 0, cont = 0, max = 0;

    /*el primer cojunto de bucles recorre las filas  para calcular sus correspondientes indices*/
	for(int i=0;i<num_fil;i++)
	{
		for(int j=0;j<num_col;j++)
		{
			if(matriu[i][j] == 1)
			{
                cont++;
                *pixels = *pixels+1;
                if(j == num_col-1)
                {
                    index_fil[x][y] = cont;
                    cont = 0;
                }

			}

            if(matriu[i][j] == 0)
			{
			    if(cont != 0)
                {
                    index_fil[x][y] = cont;
                    y++;
                }
                cont=0;
			}
		}
        if(*columnes_indexfil<y)    //calcula el numero maximo de columnas para los indices de las filas
        {
            *columnes_indexfil = y;
            max = x;
        }                                                                //si el numero de columnas es 0 no realizamos la resta
        if(index_fil[max][*columnes_indexfil]==0 && columnes_indexfil>0)//si en la ultima posicion que hemos calculado hay un 0 quiere decir que se ha sumado 1 columna sin tener que sumarse; la restamos
            *columnes_indexfil = *columnes_indexfil-1;

		y=0;
		x++;
	}

	x=0;
	y=0;
	cont = 0;

	//este conjunto de bucles recorre de columna en columna para calcular sus indices
	for(int z=0;z<num_col;z++)
	{
        for(int i=0;i<num_fil;i++)
		{
			for(int j=0;j<1;j++)
			{
				if(matriu[i][j+z] == 1)
				{
				    cont++;
				    if(i == num_fil-1)
                    {
                       index_col[x][y] = cont;
                       cont = 0;
                    }
				}


				if(matriu[i][j+z] == 0)
				{
				    if(cont != 0)
                    {
                        index_col[x][y] = cont;
                        x++;
                    }
                    cont=0;
				}
			}
		}

        if(*files_indexcol<x)   //calcula el maximo de filas que habrá para los indices de las columnas
        {
            *files_indexcol = x;
            max = y;
        }                                                           //si el numero de filas es 0 no realizamos la resta
        if(index_col[*files_indexcol][max]==0 && *files_indexcol>0)//si en la ultima posicion de la tabla hay un 0 quiere decir que se ha sumado 1 al numero de filas sin que haya un indice más, de manera que restamos 1
            *files_indexcol = *files_indexcol -1;


		x=0;
        y++;
	}
	*files_indexcol=*files_indexcol+1;
	*columnes_indexfil = *columnes_indexfil+1;
	/*sumamos 1 ya que queremos el valor absoluto de filas y columnas para despues poder
	hacer bien el bucle, o sea, como las filas y columnas empezaban a contar desde 0
	sumamos 1*/
}




