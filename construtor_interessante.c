/*
A regra que pensei é bem simples. Dado um número limite X e um divisor k, cria-se um grafo
entre os vértices x-y tal que y = ficonnaci(x), onde x é o x-ésimo número da sequencia de fibonnacci.
O divisor k entra na brincadeira da seguinte forma: toda vez que k é divisor de x, reinicia-se
a sequência de fibonnaci naquele elemento x. 

Então, minha expectativa é que se formem "clusters" centrados nos primeiros vértices se k for 
um divisor comum em [0,..., X]. Se k > X temos a função entre y = fib(x).
O algorítmo passa para a desconsidera os casos em que x = y; 

*/

#include <graphLL.h>
#include <utils.h>
#include <graphGenerics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define vertex int

int fib(int n)
{
    if (n == 0)
        return n;
    else if (n == 1)
    {
        return 1;
    }
    return (fib(n - 1) + fib(n - 2));
}

Graph GRAPHmyConstructor(int X, int k)
{
    Graph G;
    int i, base;
    vertex v, w;

    G = GRAPHinit(X);


    for (i = 0, base = 0; i < X; i++, base++) {
        v = i;
        if (i % k == 0) 
            base = 0;
        w = fib(base)%(X);
        printf("v = %2d -> w = fib(base) = %2d | base = %2d | i = %2d\n", v,w,base,i);
        if (v != w)
            GRAPHinsertArc(G, v, w);
    }



    return G;

}

int main()
{
    Graph G;
    int X, k;
    vertex v, w;
    printf("Digite X e k: ");
    scanf("%d %d", &X, &k);
    
    G = GRAPHmyConstructor(X, k);

    GRAPHinspect(G);
        
}