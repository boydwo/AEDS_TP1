#ifndef TAD_PRODUTO_H_INCLUDED
#define TAD_PRODUTO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
typedef struct{
  char Data[11];
  int qntd;
  int QntdTotalCompraPorProd;
  int QntdTotalCompraPorpessoa;
} TItem;

typedef struct CItem *AptItem;
typedef struct CItem{
  TItem Item;
  AptItem pProx;
} TCItem;

typedef struct
{
  AptItem pPri;
  AptItem pUlt;
} TListaItem;

void FLVazia(TListaItem *pListaItem);
int LEhVazia(TListaItem *pListaItem);
void LInsere(TListaItem *pListaItem, TItem *pItem);
int LRetira(TListaItem *pListaItem, TItem *pItem);
void LImprime(TListaItem *pListaItem);


#endif // TAD_PRODUTO_H_INCLUDED
