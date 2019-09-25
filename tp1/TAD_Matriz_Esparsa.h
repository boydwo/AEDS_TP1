#include <stdlib.h>
#include <stdio.h>

typedef double TChave;
typedef struct {
  TChave Chave;
}TItem;

typedef struct Celula *Apontador;
typedef struct Celula{
    Apontador direita, abaixo;
    int linha, coluna;
    TItem Item;
}TCelula;

typedef struct{
    Apontador pPrimeiro;
}TLista;

typedef struct{
    TLista *linha, *coluna;
    int i, j;
}TMatriz;

//funcoes da matriz
void InicializaMatriz(TMatriz *pMatriz, int i, int j);
void InicializaLinha(TMatriz *pMatriz, int i);
int VerListaVazia();
void InicializaColuna(TMatriz *pMatriz, int j);

void InsereMatriz(TMatriz *pMatriz, int i, int j, double valor);
