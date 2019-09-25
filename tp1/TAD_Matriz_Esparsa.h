#include <stdlib.h>
#include <stdio.h>

typedef double TChave;
typedef struct {
  TChave Chave;
}TItem;

typedef struct Celula* Apontador;
typedef struct Celula{
    Apontador direita, abaixo;
    int linha, coluna;
    TItem Item;
}TCelula;

typedef struct{
    Apontador pPrimeiro;
}TLista;

typedef struct{
    int i, j;
    TLista *linha, *coluna;    
}TMatriz;

//funcoes da matriz
void InicializaMatriz(TMatriz *pMatriz, int QuantidadeLinhas, int QuantidadeColunas);
void InicializaLinha(TLista *pLista, int QuantidadeLinhas);
void InicializaColuna(TLista *pLista, int QuantidadeColunas);

void InsereMatriz(TMatriz *pMatriz, int i, int j, TItem valor);
