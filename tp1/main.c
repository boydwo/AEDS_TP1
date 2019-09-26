#include "TAD_Matriz_Esparsa.h"
#include <windows.h>

int main(){
    TMatriz* Matriz;
    int escolha;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    printf("-----------------------------------------\n");
    printf("----------------MENU---------------------\n");
    printf("1) Ler arquivo \n");
    printf("2) Imprima a matriz \n");
    printf("0) Sair \n");
    printf("-----------------------------------------\n");
    printf("-----------------------------------------\n");
    scanf("%d",&escolha);
     while(escolha != 0){
        switch (escolha)
        {
        case 1 :
            leArquivo(Matriz);
            break;
        case 2 :
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            ImprimeMatriz (Matriz);
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            break;
        default:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            printf("----------------ERRO---------------------\n");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            break;
        }
        printf("\n-----------------------------------------\n");
        printf("----------------MENU---------------------\n");
        printf("1) Ler arquivo \n");
        printf("2) Imprima a matriz \n");
        printf("0) Sair \n");
        printf("-----------------------------------------\n");
        printf("-----------------------------------------\n");
        scanf("%d",&escolha);

    }
    return 0;
}

