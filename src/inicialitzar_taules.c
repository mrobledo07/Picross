#define MAX_FIL 20
#define MAX_COL 20


void inicialitzar_taules(int index_col[MAX_FIL][MAX_COL], int index_fil [MAX_FIL][MAX_COL])
{
    for(int i=0;i<MAX_FIL;i++)
    {
        for(int j=0;j<MAX_COL;j++)
        {
            index_col[i][j] = 0;
            index_fil[i][j] = 0;
        }
    }

}
