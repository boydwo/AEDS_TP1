#include "TAD_Matriz_Esparsa.h"

void InicializaMatriz(TMatriz *pMatriz, int i, int j){
    // inicializamos a Matriz pPrimeiro  apontando para ela msm tornando-a cicilica
    pMatriz->coluna->pPrimeiro = pMatriz->linha->pPrimeiro = (TCelula*)malloc(sizeof(TCelula));
    pMatriz->coluna->pPrimeiro->linha = pMatriz->linha->pPrimeiro->coluna = -1;
    pMatriz->coluna->pPrimeiro->direita = pMatriz->linha->pPrimeiro->abaixo = pMatriz->coluna->pPrimeiro;
    pMatriz->i = i;
    pMatriz->j = j;
    InicializaLinha(pMatriz->linha->pPrimeiro, i);
    InicializaColuna(pMatriz->coluna->pPrimeiro, j);
}
void InicializaLinha(TMatriz *pMatriz,int i){
    TCelula *pAUX;
    pAUX = (TCelula*)malloc(sizeof(TCelula));                       // aloca um espaco para nova celula
    pMatriz->linha->pPrimeiro->direita = pMatriz->linha->pPrimeiro;
    pMatriz->linha->pPrimeiro->direita = pAUX;
    pAUX->direita                      = pMatriz->linha->pPrimeiro; //aponta pra primeira celula fazendo o a ciclica
    pAUX->abaixo                       = pAUX;
}

void InicializaColuna(TMatriz *pMatriz,int j){
    TCelula *pAUX;
    pAUX = (TCelula*)malloc(sizeof(TCelula));                        // aloca um espaco para nova celula
    pMatriz->coluna->pPrimeiro->abaixo = pMatriz->coluna->pPrimeiro;
    pMatriz->coluna->pPrimeiro->abaixo = pAUX;
    pAUX->abaixo                       = pMatriz->coluna->pPrimeiro;  //aponta pra primeira celula fazendo-a ciclica
    pAUX->direita                      = pAUX;
}

void InsereMatriz(TMatriz *pMatriz, int i, int j, double valor){
}
