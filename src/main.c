#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/picross.h"

#define MAX_FIL 20
#define MAX_COL 20

int main()
{
    char nom_fit[50];
    int num_fil, num_col, num_errors, matriu[MAX_FIL][MAX_COL], index_col[MAX_FIL][MAX_COL],index_fil[MAX_FIL][MAX_COL], pixels, fila, columna,columnes_indexfil,files_indexcol;
    bool ya_elegida = false;
    bool no_existe = false;

    pixels = 0; columnes_indexfil = 0; files_indexcol = 0;

    FILE *fit;

    printf("introduce el nombre del fichero picross .txt: ");
    gets(nom_fit);
    fit = fopen(nom_fit, "r");

    if(fit != NULL)
    {
        fscanf(fit,"%d%d%d", &num_fil, &num_col, &num_errors);
         if(num_fil > 0 && num_col > 0 && num_errors > 0)
         {
            for(int i=0;i<num_fil;i++)
                for(int j=0;j<num_col;j++)
                    fscanf(fit,"%d", &matriu[i][j]);

            inicialitzar_taules(index_col,index_fil);
            calcula_index(matriu,index_col,index_fil,num_fil,num_col,&pixels,&columnes_indexfil,&files_indexcol);
            if(pixels>0)
            {

                do
                {



                    mostra_matriu(index_col,index_fil,matriu,num_fil,num_col,num_errors,pixels,fila,columna,columnes_indexfil,files_indexcol);
                    if(no_existe == true)  printf("\nLA POSICION ELEGIDA NO EXISTE. INTRODUCE OTRA: \n");
                    if(ya_elegida == true) printf("\nLA POSICION ELEGIDA YA HA SIDO SELECCIONADA. INTRODUCE OTRA: \n ");
                    ya_elegida = false;      // actualizamos a true la variable como una inicializaci�n nueva para cada bucle
                    no_existe = false;       // "        "           "       "       "

                    printf("\nFila: ");     scanf("%d", &fila);
                    printf("Columna: ");    scanf("%d", &columna);
                    //encertat(fila,columna,matriu);
                    actualitzar_matriu(matriu,num_fil,num_col,&num_errors,&pixels,fila,columna,&ya_elegida,&no_existe);

                    system("CLS");

                }while(num_errors>0 && pixels>0);

                if(num_errors == 0)
                {
                    printf("**********HAS AGOTADO LOS INTENTOS**********\n");
                    mostra_matriu_derrota(index_col,index_fil,matriu,num_fil,num_col,num_errors,pixels,fila,columna,columnes_indexfil,files_indexcol);
                }

                if(pixels == 0)
                {
                    printf("**********FELICIDADES HAS GANADO**********\n");
                    mostra_matriu(index_col,index_fil,matriu,num_fil,num_col,num_errors,pixels,fila,columna,columnes_indexfil,files_indexcol);
                }
            }
            else
            {
                printf("EL PICROSS DEBE CONTENER ALMENOS UN 1\n");
            }
        }
        else
        {
            printf("EL ARCHIVO DEL PICROSS NO PUEDE CONTENER 0 COMO NUMERO DE FILAS, COLUMNAS O ERRORES\n");
        }

    }else printf("Ha habido un error al abrir el fichero");


    fclose(fit);
    return 0;
}
