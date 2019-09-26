#include "TAD_Matriz_Esparsa.h"

void InicializaMatriz(TMatriz *pMatriz, int QuantidadeLinhas, int QuantidadeColunas)
{
    pMatriz->coluna->pPrimeiro = pMatriz->linha->pPrimeiro = (TCelula *)malloc(sizeof(TCelula));          //malloc para primeira celula das duas listas, que chamaremos de Célula cabeça Mestra
    pMatriz->coluna->pPrimeiro->coluna = pMatriz->linha->pPrimeiro->linha = -1;                           //Inicializando celulas cabeça com -1 em seus campos linha e coluna do tipo int
    pMatriz->coluna->pPrimeiro->direita = pMatriz->linha->pPrimeiro->abaixo = pMatriz->coluna->pPrimeiro; //Tratanto a Lista Circular: Inicialmente um próprio item aponta para si mesma
    pMatriz->i = QuantidadeLinhas;
    pMatriz->j = QuantidadeColunas;
    InicializaLinha(pMatriz->linha, QuantidadeLinhas);    //Agora e hora de inicializar 'QuantidadeLinhas'(valor) linhas
    InicializaColuna(pMatriz->coluna, QuantidadeColunas); //E também inicializar 'QuantidadeColunas'(valor) colunas
}

void InicializaLinha(TLista *pLista, int QuantidadeLinhas)
{                          //Cria células cabeça para lista Linha
    TCelula *pAUX, *pAUX2; //pAUX percorre a lista para indicar onde pAUX2 deverá ser inserido
    int i;
    pAUX = pLista->pPrimeiro; //pAUX receberá a primeira célula para criar pAUX2 a partir dele

    for (i = 0; i < QuantidadeLinhas; i++)
    { //Laço de repetição para criar 'QuantidadeLinhas'
        pAUX2 = (TCelula *)malloc(sizeof(TCelula));
        pAUX2->linha = i;
        pAUX2->coluna = -1;
        pAUX2->abaixo = pLista->pPrimeiro; //pAUX2 (inserida no final) aponta para pPrimeiro por meio de abaixo
        pAUX2->direita = pAUX2;            //direita aponta para a propria pAUX2
        pAUX->abaixo = pAUX2;
        pAUX = pAUX->abaixo;
    }
}

void InicializaColuna(TLista *pLista, int QuantidadeColunas)
{                          //Cria células cabeça para lista Coluna
    TCelula *pAUX, *pAUX2; //pAUX percorre a lista para indicar onde pAUX2 deverá ser inserido
    int j;
    pAUX = pLista->pPrimeiro;

    for (j = 0; j < QuantidadeColunas; j++)
    { //Laço de repetição para criar 'QuantidadeColunas'
        pAUX2 = (TCelula *)malloc(sizeof(TCelula));
        pAUX2->coluna = j;
        pAUX2->linha = -1;
        pAUX2->direita = pAUX; //pAUX2 (inserida no final) aponta para pPrimeiro por meio de direita
        pAUX2->abaixo = pAUX2; //abaixo aponta para a propria pAUX2
        pAUX->direita = pAUX2;
        pAUX = pAUX->direita;
    }
}

TCelula *PercorreLinha(TLista *pLista, int PosLinha)
{ //Função que percorre a lista linha para retornar o endereço da célula cabeça referente àquela posição
    TCelula *pAUX;
    int i;
    pAUX = pLista->pPrimeiro;

    for (i = -1; i < PosLinha + 1; i++)
    {
        if (pAUX->linha + 1 == PosLinha)
        {
            return pAUX;
        }
        pAUX = pAUX->abaixo;
    }

    return NULL;
}

TCelula *PercorreColuna(TLista *pLista, int PosColuna)
{
    TCelula *pAUX;
    int i;
    pAUX = pLista->pPrimeiro;

    for (i = -1; i < PosColuna + 1; i++)
    {
        if (pAUX->coluna + 1 == PosColuna)
        {
            return pAUX;
        }
        pAUX = pAUX->direita;
    }

    return NULL;
}

void inserirListaLinha(TCelula *pCelula, TCelula *pCelulaAinserir)
{
    TCelula *pAux;
    pAux = pCelula;
    while (pAux->direita != pCelula)
    {
        pAux = pAux->direita;
    }

    pCelulaAinserir->direita = pCelula;
    pAux->direita = pCelulaAinserir;
}

void inserirListaColuna(TCelula *pCelula, TCelula *pCelulaAinserir)
{
    TCelula *pAux;
    pAux = pCelula;
    while (pAux->abaixo != pCelula)
    {
        pAux = pAux->abaixo;
    }
    pCelulaAinserir->abaixo = pCelula;
    pAux->abaixo = pCelulaAinserir;
}

void InsereMatriz(TMatriz *pMatriz, int i, int j, TItem valor)
{
    TCelula *CeCabecaL, *CeCabecaC, *pAUX;
    CeCabecaC = PercorreColuna(pMatriz->coluna, j);
    CeCabecaL = PercorreLinha(pMatriz->linha, i);
    pAUX = (TCelula *)malloc(sizeof(TCelula));
    inserirListaColuna(pMatriz->coluna, CeCabecaC);
    inserirListaLinha(pMatriz->linha, CeCabecaL);
}

void leArquivo()
{
    FILE *arq;
    int tamLinha, tamColuna;
    int lin, col;
    double val;
    arq = fopen("teste.txt", "r");
    //le a primeira linha com o tamanho da matriz
    fscanf(arq, "%d, %d\n", &tamLinha, &tamColuna);
    printf("tamlinha e tamcoluna: %d %d", tamLinha, tamColuna);

    while (fscanf(arq, "%d, %d, %lf", &lin, &col, &val) != NULL)
    {
        printf("linha: %d %d %lf", lin, col, val);
    }
}

void ImprimeMatriz (TMatriz *pMatriz){
    TCelula *pAUX, *Cabeca;

    double matriz[pMatriz->i][pMatriz->j];
    int i, j;

    Cabeca = pMatriz->linha->pPrimeiro->abaixo;   

    for(i=0;i<pMatriz->linha->pPrimeiro->linha;i++){
        for(j=0;j<pMatriz->coluna->pPrimeiro->coluna;j++){
            matriz[i][j] = 0;
        }        
    }
    
    while (Cabeca->abaixo != pMatriz->linha->pPrimeiro){
        pAUX = Cabeca->direita;
        while(pAUX != Cabeca){
            matriz[pAUX->linha][pAUX->coluna] = pAUX->Item.Chave;
            pAUX = pAUX->direita;
        }
        Cabeca = Cabeca->abaixo;
    }

    for(i=0;i<pMatriz->linha->pPrimeiro->linha;i++){
        for(j=0;j<pMatriz->coluna->pPrimeiro->coluna;j++){
            printf("%lf ",matriz[i][j]);
        }
        printf("\n");        
    }

}
