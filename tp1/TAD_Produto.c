#include "TAD_Matriz_Esparsa.h"

void FLVazia(TLista *pLista)
{
  pLista->pPrimeiro = (Apontador)malloc(sizeof(TCelula));
  pLista->pUltimo = pLista->pPrimeiro;
  pLista->pPrimeiro->pProx = NULL;
}

int LEhVazia(TLista *pLista)
{
  return (pLista->pPrimeiro == pLista->pUltimo);
}

void LInsere(TLista *pLista, TItem *pItem)
{
  pLista->pUltimo->pProx = (Apontador)malloc(sizeof(TCelula));
  pLista->pUltimo = pLista->pUltimo->pProx;
  pLista->pUltimo->Item = *pItem;
  pLista->pUltimo->pProx = NULL;
}
