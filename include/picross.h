#define MAX_FIL 20
#define MAX_COL 20


void inicialitzar_taules(int index_col[MAX_FIL][MAX_COL], int index_fil[MAX_FIL][MAX_COL]);
void calcula_index (int matriu[MAX_FIL][MAX_COL], int index_col[MAX_FIL][MAX_COL], int index_fil[MAX_FIL][MAX_COL], int num_fil, int num_col, int *pixels,int *columnes_indexfil, int *files_indexcol);
void mostra_matriu(int index_col[MAX_FIL][MAX_COL], int index_fil[MAX_FIL][MAX_COL], int matriu[MAX_FIL][MAX_COL], int num_fil, int num_col, int errors, int pixels, int fila, int columna,int columnes_indexfil, int files_indexcol);
bool encertat(int fila, int columna, int matriu[MAX_FIL][MAX_COL], int num_fil, int num_col);
bool posicio_existeix(int fila, int columna, int num_fil, int num_col);
void actualitzar_matriu(int matriu[MAX_FIL][MAX_COL], int num_fil, int num_col, int *errors, int *pixels, int fila, int columna, bool *ya_elegida, bool *no_existe);
void mostra_matriu_derrota(int index_col[MAX_FIL][MAX_COL], int index_fil[MAX_FIL][MAX_COL], int matriu[MAX_FIL][MAX_COL], int num_fil, int num_col, int errors, int pixels, int fila, int columna,int columnes_indexfil, int files_indexcol);
