#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <conio.h>

void cabec();
double Formula_Lagrange(int n, int k,double val);
double PI(int n, double x);

double* fx;
double* x;

int main() {
   
    int pontos, i;
    double pc;
    int op;
    char resp;
    int aux;

    do {
        setlocale(LC_ALL, "Portuguese");

        cabec();
        do {
            printf("\nPor favor dígite o número de pontos da tabela de x e f(x):\n");
            scanf("%d", &pontos);
        } while (pontos <= 0);

        aux = pontos-1;
        system("cls");
        
        fx = (double *) malloc(sizeof(double) * pontos);
        x = (double *) malloc(sizeof(double) * pontos);

        for (i = 0; i < pontos; i++) {
            printf("x (%d):", i);
            scanf("%lf",x+i);
            printf("fx(%d):", i);
            scanf("%lf",fx + i);
            printf("------\n");
        }
        do {
            do {
                printf("\nPor favor digíte um ponto entre os valores de x a ser interpolado:\n");
                scanf("%lf", &pc);
            }while(pc<*x && pc>*(x + aux));
            printf("\nO resultado de f(%4.2lf) é igual a %5.4lf\n", pc, PI(pontos, pc));
            printf("\nDeseja interpolar outro ponto?\n(1)Sim (2)Não\n\n");
            scanf("%i",&resp);
        } while(resp==1);



        do {
            printf("\n Escolha uma das opções:\n(1)Repetir o programa (2)Fechar o programa\n");
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
    printf("\n Métodos Numéricos Computacionais Lagrange");
    printf("\n   By: José Guilherme and Luís Cláudio\n");

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
