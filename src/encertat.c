#include <stdbool.h>
#define MAX_FIL 20
#define MAX_COL 20

bool encertat(int fila, int columna, int matriu[MAX_FIL][MAX_COL], int num_fil, int num_col)
{
    // si en la posicion introducida hay un pixel entonces el usuario ha acertado
    if(matriu[fila-1][columna-1] == 1) return true;
    else return false;
}

bool posicio_existeix(int fila, int columna, int num_fil, int num_col)
{
    // la fila y columna introducida deben estar entre 0 y el numero leído del fichero para que la posición exista
    if((fila-1>=0 && fila-1<num_fil)&&(columna-1>=0 && columna-1<num_col)) return true;
    else return false;
}
