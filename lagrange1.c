        //setlocale para deixar tudo em portugu?s.
        setlocale(LC_ALL, "Portuguese");

        cabec();//Abertura do Programa
        do {
            printf("\nPor favor d?gite o n?mero de pontos da tabela de x e f(x):\n");
            scanf("%d", &pontos);
        } while (pontos <= 0);//N?o permite que o usuario digite o numero de pontos igual ou menor que 0

        system("cls");

        //Aloca??o dinamica de Memoria para x e f(x)
        fx = (double *) malloc(sizeof(double) * pontos);
        x = (double *) malloc(sizeof(double) * pontos);

        for (i = 0; i < pontos; i++) {
            printf("x (%d):", i);
            scanf("%lf", &x[i]);
            printf("fx(%d):", i);
            scanf("%lf", &fx[i]);
            printf("------\n");
        }
        do {
            do {
                printf("\nPor favor dig?te o ponto a ser interpolado:\n");
                scanf("%lf", &pc);
            }while(pc<x[0] || pc>x[aux]);
            printf("\nO resultado de f(%4.2lf) ? igual a %5.4lf\n", pc, PI(pontos, pc));
            printf("\nDeseja interpolar outro ponto?\n(1)Sim (2)N?o\n\n");
            scanf("%i",&resp);
        } while(resp==1);



        do {
            printf("\n Escolha uma das op??es:\n(1)Repetir o programa (2)Fechar o programa\n");
            scanf("%i", &op);
        } while (op < 1 || op > 2);

        if (op == 1) {
            printf("REINICIANDO O PROGRAMA");
            printf("\nPresssione qualquer tecla para continuar...");
            getch();
            system("cls");
        } else {
            exit(1);
        }//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <conio.h>

//Fun??es
void cabec();
double Formula_Lagrange(int n, int k,double val);
double PI(int n, double x);//PI pois a fun??o calcula o ponto de interpola??o

//Fun??es de Aloca??o dinamica de Memoria
double* fx;
double* x;


//Main
int main() {
    //Variaveis
    int pontos, i;
    double pc;
    int op;
    char resp;
    int aux = pontos-1;

    do {
        //setlocale para deixar tudo em portugu?s.
        setlocale(LC_ALL, "Portuguese");

        cabec();//Abertura do Programa
        do {
            printf("\nPor favor d?gite o n?mero de pontos da tabela de x e f(x):\n");
            scanf("%d", &pontos);
        } while (pontos <= 0);//N?o permite que o usuario digite o numero de pontos igual ou menor que 0

        system("cls");

        //Aloca??o dinamica de Memoria para x e f(x)
        fx = (double *) malloc(sizeof(double) * pontos);
        x = (double *) malloc(sizeof(double) * pontos);

        for (i = 0; i < pontos; i++) {
            printf("x (%d):", i);
            scanf("%lf", &x[i]);
            printf("fx(%d):", i);
            scanf("%lf", &fx[i]);
            printf("------\n");
        }
        do {
            do {
                printf("\nPor favor dig?te um ponto entre os valores de x a ser interpolado:\n");
                scanf("%lf", &pc);
            }while(pc<x[0] || pc>x[aux]);
            printf("\nO resultado de f(%4.2lf) ? igual a %5.4lf\n", pc, PI(pontos, pc));
            printf("\nDeseja interpolar outro ponto?\n(1)Sim (2)N?o\n\n");
            scanf("%i",&resp);
        } while(resp==1);



        do {
            printf("\n Escolha uma das op??es:\n(1)Repetir o programa (2)Fechar o programa\n");
            scanf("%i", &op);
        } while (op < 1 || op > 2);

        if (op == 1) {
            printf("REINICIANDO O PROGRAMA");
            printf("\nPresssione qualquer tecla para continuar...");
            getch();
            system("cls");
        } else {
            exit(1);
        }
    } while (op==1);

}

void cabec() {
    printf("\n M?todos Num?rico Computacionais Lagrange");
    printf("\n   By: Jos? Guilherme and Lu?s Claudio\n");

}

double Formula_Lagrange(int n, int k, double val)
{
    int i;
    double resultado = 1;
    for (i = 0; i < n; i++)
    {
        if (i!=k)
            resultado = resultado * (double)((val - x[i]) / (x[k] - x[i]));
    }
    return resultado;
}

double PI(int n,double x)
{
    int i;
    double p = 0;
    double *L = (double*)malloc(sizeof(double)*n);
    for (i = 0; i < n; i++)
    {
        L[i] = Formula_Lagrange(n, i, x);
        p += fx[i] * L[i];
        printf("\n------\nL(%d) = %5.3lf\n", i, L[i]);
    }

    printf("\n");
    return p;
}


