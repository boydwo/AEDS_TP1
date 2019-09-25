#include "TAD_Matriz_Esparsa.h"

void InicializaMatriz(TMatriz *pMatriz, int QuantidadeLinhas, int QuantidadeColunas){
    pMatriz->coluna->pPrimeiro = pMatriz->linha->pPrimeiro = (TCelula*)malloc(sizeof(TCelula));     //malloc para primeira celula das duas listas
    pMatriz->coluna->pPrimeiro->coluna = pMatriz->linha->pPrimeiro->linha = -1;     //Inicializando celulas cabeça
    pMatriz->coluna->pPrimeiro->direita = pMatriz->linha->pPrimeiro->abaixo = pMatriz->coluna->pPrimeiro;   //Tratanto a Lista Circular
    pMatriz->i = QuantidadeLinhas;
    pMatriz->j = QuantidadeColunas;
    InicializaLinha(pMatriz->linha, QuantidadeLinhas);
    InicializaColuna(pMatriz->coluna, QuantidadeColunas);
}

void InicializaLinha(TLista *pLista, int QuantidadeLinhas){     //Cria células cabeça para lista Linha
    TCelula *pAUX, *pAUX2;      //pAUX percorre e pAUX2 será a nova célula 
    int i;
    pAUX = pLista->pPrimeiro;   //pAUX receberá a primeira célula para criar pAUX2 a partir dele

    for(i=0;i<QuantidadeLinhas;i++){
        pAUX2 = (TCelula*)malloc(sizeof(TCelula));
        pAUX2->linha = i;
        pAUX2->coluna = -1;
        pAUX2->abaixo = pLista->pPrimeiro;
        pAUX2->direita = pAUX2;
        pAUX->abaixo = pAUX2;
        pAUX = pAUX->abaixo;

    }       
}

void InicializaColuna(TLista *pLista, int QuantidadeColunas){       //Cria células cabeça para lista Coluna
    TCelula *pAUX, *pAUX2;
    int j;
    pAUX = pLista->pPrimeiro;

    for(j=0;j<QuantidadeColunas;j++){
        pAUX2 = (TCelula*)malloc(sizeof(TCelula));
        pAUX2->coluna = j;
        pAUX2->linha = -1;
        pAUX2->direita = pAUX;
        pAUX2->abaixo = pAUX2;
        pAUX->direita = pAUX2;
        pAUX = pAUX->direita;

    }       
}

int PercorreLinha(TLista* pLista, int PosLinha){
    TCelula *pAUX;
    pAUX->
}


void InsereMatriz(TMatriz *pMatriz, int i, int j, TItem valor){
    TCelula *pAUX, *pAUX;
}
