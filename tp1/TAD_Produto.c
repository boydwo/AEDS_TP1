#include "TAD_Produto.h"
void FLVazia(TListaItem *pListaItem)
{
pListaItem->pPri = (AptItem) malloc(sizeof(TCItem));
pListaItem->pUlt = pListaItem->pPri;
pListaItem->pPri->pProx = NULL;
}
int LEhVazia(TListaItem *pListaItem)
{
return (pListaItem->pPri == pListaItem->pUlt);
}

void LInsere(TListaItem *pListaItem,TItem* pItem)
{
pListaItem->pUlt->pProx = (AptItem) malloc(sizeof(TCItem));
pListaItem->pUlt = pListaItem->pUlt->pProx;
pListaItem->pUlt->Item = *pItem;
pListaItem->pUlt->pProx = NULL;
}
int LRetira(TListaItem *pListaItem, TItem* pItem)
{
TCItem* pAux;
if (LEhVazia(pListaItem))
return 0;
*pItem = pListaItem->pPri->pProx->Item;
pAux = pListaItem->pPri;
pListaItem->pPri = pListaItem->pPri->pProx;
free(pAux);
return 1;
}
void LImprime(TListaItem *pListaItem)
{
AptItem pAux;
pAux = pListaItem->pPri->pProx;
while (pAux != NULL)
{
printf("%s\n", pAux->Item.Data);
printf("%d\n", pAux->Item.qntd);
pAux = pAux->pProx; /* próxima célula */
}
}
int quantidadeComprasPorCliente(TListaItem *pListaItem,TItem *pItem){
    void ImprimeMatriz (TMatriz *pMatriz){
    TCelula *pAUX, *Cabeca;

    double matriz[pMatriz->i][pMatriz->j];
    int i, j;
    while (Cabeca->abaixo != pMatriz->linha.pPrimeiro){
        pAUX = Cabeca->direita;
        while(pAUX != Cabeca){
            matriz[pAUX->linha][pAUX->coluna] = pAUX->valor;
            pAUX = pAUX->direita;

        }
        Cabeca = Cabeca->abaixo;
    }
}

}
