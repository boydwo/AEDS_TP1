#include "TAD_Produto.h"
typedef struct Celula *Apontador;
typedef struct Celula{
    Apontador direita, abaixo;
    int linha, coluna;
    double valor;
} TCelula;

typedef struct{
    Apontador pPrimeiro;
} TLista;

typedef struct{
    int i, j;
    TLista linha, coluna;
} TMatriz;

//funcoes da matriz
void InicializaMatriz(TMatriz *pMatriz, int QuantidadeLinhas, int QuantidadeColunas);
void InicializaLinha(TLista *pLista, int QuantidadeLinhas);
void InicializaColuna(TLista *pLista, int QuantidadeColunas);

TCelula *PercorreLinha(TLista *pLista, int PosLinha);
TCelula *PercorreColuna(TLista *pLista, int PosColuna);

void inserirListaLinha(TCelula *pCelula, TCelula *pCelulaAinserir);
void inserirListaColuna(TCelula *pCelula, TCelula *pCelulaAinserir);
void InsereMatriz(TMatriz *pMatriz, int i, int j, double valor);

void leArquivo(TMatriz* pMatriz);
void ImprimeMatriz (TMatriz *pMatriz);

