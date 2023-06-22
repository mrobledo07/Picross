#include <stdio.h>
#define MAX_FIL 20
#define MAX_COL 20

/*aquest procediment es igual al de mostrar matriu pero se canvien les condicions
de quan es printa un quadre blanc per tal que al perdre l'usuari vegui tot el dibuix*/
void mostra_matriu_derrota(int index_col[MAX_FIL][MAX_COL], int index_fil[MAX_FIL][MAX_COL], int matriu[MAX_FIL][MAX_COL], int num_fil, int num_col, int errors, int pixels, int fila, int columna,int columnes_indexfil, int files_indexcol)
{


    // bucle per printar index de les columnes

    for(int i=0;i<files_indexcol*2;i++)
    {
        printf("   ");//aquests espais han sigut escollits com a desicio de disseny per deixar separacio amb el marc de la consola
        for(int k=0;k<columnes_indexfil;k++)
        {
            printf("   ");//son els espais que s'han de deixar en funcio dels index de les files perque els index de les columnes es printen amb la corresponent columna(ben estructurat)
        }

        for(int j=0;j<num_col;j++)
        {
            if(i==0)
            {
                if(j==0)
                {
                    if(num_col>1)
                        printf("%c%c%c%c%c",218,196,196,196,194);
                    else
                        printf("%c%c%c%c%c",218,196,196,196,191); //si solo hay una columna que se printe la esquina de la tabla
                }

                if(j!=0 && j!=num_col-1)
                    printf("%c%c%c%c",196,196,196,194);
                if(j==num_col-1 && j!=0)
                    printf("%c%c%c%c",196,196,196,191);
            }
            else if(i%2!=0)
            {

                if(index_col[i/2][j]!=0)
                {
                    printf("%c %d ",179,index_col[i/2][j]);
                }
                else
                {
                    printf("%c   ",179);
                }
                if(j==num_col-1)
                    printf("%c",179);

            }
            else if(i!=0 && i%2==0)
            {
                if(j==0)
                    printf("%c%c%c%c%c",179,255,255,255,179);
                if(j!=0 && j!=num_col-1)
                    printf("%c%c%c%c",255,255,255,179);
                if(j==num_col-1 && j!=0)
                    printf("%c%c%c%c",255,255,255,179);
            }

        }
        printf("\n");
    }




    //ara comencen els bucles principals per printar el tauler(entre mig tenim els bucles per printar els index de les files)
    for(int i=0;i<=num_fil*2;i++)
    {
        //fins el for amb variable de control j tot es per printar els index de les files
        printf("   ");
        if(i%2==0)
        {
            for(int k=0;k<columnes_indexfil;k++)
            {
                if(k==0 && i==0)
                    printf("%c%c%c",218,196,196);

                if(k!=0)
                    printf("%c%c%c",196,196,196);

                if(k==0 && i!=0 && i!=num_fil*2)
                    printf("%c%c%c",195,196,196);

                if(k==0 && i==num_fil*2)
                {
                    printf("%c%c%c",192,196,196);
                }

            }
        }
        else
        {
               // printf("%c",179);
                for(int k=0;k<columnes_indexfil;k++)
                {
                        if(index_fil[i/2][k]!=0)
                        {
                            printf("%c%d ",179,index_fil[i/2][k]);
                        }
                        else
                        {
                            printf("%c%c ",179,255);
                        }
                }
        }
        for(int j=0;j<num_col;j++)
        {

            if(i==0)
            {
                if(j==0)
                {
                    if(num_col>1)
                    {
                        printf("%c", 197);
                        printf("%c%c%c",196,196,196);
                        printf("%c",197);
                    }
                    else
                    {
                        printf("%c", 197);
                        printf("%c%c%c",196,196,196);
                        printf("%c",180);
                    }

                }else if(j != 0 && j!=num_col-1)
                {
                    printf("%c%c%c",196,196,196);
                    printf("%c",197);
                }
                else if(j == num_col-1 && j!=0)
                {
                    printf("%c%c%c",196,196,196);
                    printf("%c",180);

                }
            }
            else if(i%2 != 0)   //si la fila es imparella printem els corresponents simbols per mostrar el dibuix per pantalla
            {

                if(j==0)
                {
                    printf("%c",179);

                    if(matriu[i/2][j]==2)
                    {
                        printf(" %c ",219 );
                    }else if(matriu[i/2][j]==-1)
                    {
                        printf(" %c ",176);
                    }else if(matriu[i/2][j]==0 || matriu[i/2][j]==1)
                    {
                        if(matriu[i/2][j] == 0)
                            printf(" %c ",255);
                        else
                            printf(" %c ",219);
                    }
                    if(num_col == 1)
                        printf("%c",179);
                }
                else if(j!=0 && j!=num_col-1)
                {
                       printf("%c",179);

                    if(matriu[i/2][j]==2)
                    {
                        printf(" %c ",219);

                    }else if(matriu[i/2][j]==-1)
                    {
                        printf(" %c ",176);
                    }else if(matriu[i/2][j]==0 || matriu[i/2][j]==1)
                    {
                        if(matriu[i/2][j] == 0)
                            printf(" %c ",255);
                        else
                            printf(" %c ",219);
                    }
                }
                else if(j==num_col-1)
                {
                    printf("%c",179);
                    if(matriu[i/2][j]==2)
                    {
                        printf(" %c ",219 );

                    }else if(matriu[i/2][j]==-1)
                    {
                        printf(" %c ",176);
                    }else if(matriu[i/2][j]==0 || matriu[i/2][j]==1)
                    {
                        if(matriu[i/2][j] == 0)
                            printf(" %c ",255);
                        else
                            printf(" %c ",219);
                    }
                    printf("%c",179);


                }
            }
            else if(i%2 == 0 && i!=num_fil*2 && i!=0)   //si la fila es parella printem els caracters corresponents per separar cada fila i casella
            {

                if(j==0)
                {
                    if(num_col>1)
                    {
                        printf("%c",197);
                        printf("%c%c%c",196,196,196);
                        printf("%c",197);
                    }
                    else
                    {
                        printf("%c",197);
                        printf("%c%c%c",196,196,196);
                        printf("%c",180);
                    }


                }else if(j!=0 && j!=num_col-1)
                {

                        printf("%c%c%c",196,196,196);
                        printf("%c",197);


                }else if(j==num_col-1 && j!=0)
                {


                    printf("%c%c%c",196,196,196);
                    printf("%c",180);

                }

            }
            else if(i==(num_fil*2)) // si estem a la ultima fila printem els limits del tauler per baix
            {

                if(j==0)
                {
                    if(num_col>1)
                    {
                        printf("%c",193);
                        printf("%c%c%c",196,196,196);
                        printf("%c",193);
                    }
                    else
                    {
                        printf("%c",193);
                        printf("%c%c%c",196,196,196);
                        printf("%c",217);
                    }

                }
                else if(j!=0 && j!=num_col-1)
                {
                        printf("%c%c%c",196,196,196);
                        printf("%c",193);

                }
                else if(j==num_col-1 && j!=0)
                {
                    printf("%c%c%c",196,196,196);
                    printf("%c",217);

                }
            }


        }
        printf("\n");
    }

    //cos per printar els index per pantalla



    printf("\nTE HAN FALTADO %d PIXELS POR ACERTAR", pixels);
    printf("\nTE HAS QUEDADO CON %d ERRORES POR GASTAR\n", errors);
}
