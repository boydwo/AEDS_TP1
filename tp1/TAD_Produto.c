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

int LRetira(TLista *pLista, TItem *pItem)
{
  TCelula *pAux;
  if (LEhVazia(pLista))
    return 0;
  *pItem = pLista->pPrimeiro->pProx->Item;
  pAux = pLista->pPrimeiro;
  pLista->pPrimeiro = pLista->pPrimeiro->pProx;
  free(pAux);
  return 1;
}

void LImprime(TLista *pLista)
{
  Apontador pAux;
  pAux = pLista->pPrimeiro->pProx;
  while (pAux != NULL)
  {
    printf("%d\n", pAux->Item.Chave);
    pAux = pAux->pProx;
  }
}