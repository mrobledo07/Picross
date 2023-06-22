#include <stdbool.h>
#include "../include/picross.h"
#define MAX_FIL 20
#define MAX_COL 20


void actualitzar_matriu(int matriu[MAX_FIL][MAX_COL], int num_fil, int num_col, int *errors, int *pixels, int fila, int columna,bool *ya_elegida, bool *no_existe)
{
        if(encertat(fila,columna,matriu,num_fil,num_col) && posicio_existeix(fila,columna,num_fil,num_col)) // si el usuario acierta (solo en caso de que haya un 1 y la posicion exista) restamos pixels y actualizamos la matriz
        {
            matriu[fila-1][columna-1] = 2;
            *pixels = *pixels-1;

        }
        else
        {
            if(matriu[fila-1][columna-1] == 2 || matriu[fila-1][columna-1] == -1)   // si el valor ya habia sido actualizado es que ya habia sido elegido, actualizamos la variable
            {
                *ya_elegida = true;
            }

            else if(!posicio_existeix(fila,columna,num_fil,num_col)) // si la posicion no existe actualiza la variable
            {
                *no_existe = true;
            }

            if(!encertat(fila,columna,matriu,num_fil,num_col) && posicio_existeix(fila,columna,num_fil,num_col) && *ya_elegida == false) // si aun no ha sido elegido y es un 0 restamos un error y actualizamos la matriz
            {
                matriu[fila-1][columna-1] = -1;
                *errors = *errors-1;
            }

        }

}
