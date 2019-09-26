#include <stdlib.h>
#include <stdio.h>

typedef int TipoChave;
typedef struct
{
  TipoChave Chave;
  char Data[11];
  int qntd;
} TItem;

typedef struct Celula *Apontador;
typedef struct Celula
{
  TItem Item;
  Apontador pProx;
} TCelula;

typedef struct
{
  Apontador pPrimeiro;
  Apontador pUltimo;
} TLista;

void FLVazia(TLista *pLista);
int LEhVazia(TLista *pLista);
int LInsere(TLista *pLista, TItem *pItem);
int LRetira(TLista *pLista, TItem *pItem);
void LImprime(TLista *pLista);
