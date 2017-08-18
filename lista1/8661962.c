/*
NOME: Guilherme Marthe RA: 8661962
*/

// graphM = matriz, graphLL = listas linkadas, na implementação 
// do Paulo Feofiloff apresentada em aula.SS
#include <graphM.h>  
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define vertex int

// Gera uma observação de uma variável poisson com média lbda
int rpois(float lbda)
{
    float L, p, u;
    int k;

    L = exp(-lbda);
    k = 0;
    p = 1;

    while (p > L)
    {
        //printf("L: %f| p: %f| u: %f|\n",L, p, u);
        k++;
        u = rand() / (RAND_MAX + 1.0);
        p = p * u;
    }
    return k - 1;
}

Graph GRAPHmyConstructor(int A, float lbda, float offset)
{
    Graph G;
    int V;
    vertex i, *a1, *a2, maxa1 = -1, maxa2 = -1;

    a1 = malloc(A * sizeof(int));
    a2 = malloc(A * sizeof(int));

    for (i = 0; i < A; i++)
    {
        a1[i] = rpois(lbda);
        a2[i] = a1[i];
        while (a1[i] == a2[i])
            a2[i] = rpois(lbda + offset);

        if (a1[i] > maxa1)
            maxa1 = a1[i];
        if (a2[i] > maxa2)
            maxa2 = a2[i];
    }

    if (maxa1 > maxa2)
        V = maxa1;
    else
        V = maxa2;

    G = GRAPHinit(V);

    for (i = 0; i < A; i++)
        //printf("a1[%d] = %d| a2[%d] = %d\n", i, a1[i],i , a2[i]);
        GRAPHinsertArc(G, a1[i], a2[i]);
    //printf("V = %d", V);
    return G;
}

int main()
{
    Graph G;
    int A;
    float lbda, offset;
    printf("Digite A, lambda e offset: ");
    scanf("%d %f %f", &A, &lbda, &offset);

    G = GRAPHmyConstructor(A, lbda, offset);
    GRAPHshow(G);
    printf("total de arcos = %d\n", G->A);
}