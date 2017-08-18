#include <graphLL.h>
#include <graphGenerics.h>
#include <stdio.h>
#include <math.h>

#define vertex int
#define UGraph Graph

UGraph UGRAPHrand2(int V, int A)
{
    double prob = (double)(A / 2) / V / (V - 1);
    UGraph G = GRAPHinit(V);
    for (vertex v = 0; v < V; ++v)
        for (vertex w = 0; w < V; ++w)
            if (v != w)
                if (rand() < prob * (RAND_MAX + 1.0))
                {
                    GRAPHinsertArc(G, v, w);
                    GRAPHinsertArc(G, w, v);
                }
    return G;
}

long double probabilidade_de_encontro(UGraph G)
{
    vertex v, w;
    double prob1, prob2;
    int n_encontros, total;
    prob1 = (double)1 / G->V;
    prob2 = (double)1 / ((G->V) - 1);
    total = 0;
    for (v = 0; v < G->V; v++)
    {
        n_encontros = 0;
        for (w = 0; w < G->V; w++)
            if (GRAPHreach(G, v, w) == 1)
                n_encontros++;
        total += (n_encontros);
    }
    return (prob1 * prob2 * total);
}

double probabilidade_de_encontro_naive(UGraph G)
{
    vertex v, w;
    int n_encontros;
    double rv;
    for (v = 0; v < G->V; v++)
    {
        for (w = 0; w < G->V; w++)
            if (GRAPHreach(G, v, w) == 1)
                n_encontros++;
    }
    return (double)n_encontros / ((G->V) * ((G->V) - 1));
}

// int simple_testing()
// {

//     Graph G1, G2;

//     G1 = UGRAPHrand2(30, 20);
//     G2 = UGRAPHrand2(100, 150);

//     printf("Numero de arcos G1: %d", G1->A);
//     GRAPHshow(G1);
//     printf("É UGRAPH?: %d", GRAPHcheckUGraph(G1));
//     printf("\n ******* \n");
//     printf("Numero de arcos G2: %d", G2->A);
//     printf("É UGRAPH?: %d", GRAPHcheckUGraph(G2));
//     GRAPHshow(G2);
//     printf("\n ****Soma de probs**** \n");

//     printf("Prob de encontro G1: %f\n", probabilidade_de_encontro(G1));
//     printf("Prob de encontro G2: %f\n", probabilidade_de_encontro(G2));

//     return 0;
// }

int main()
{

    int V, A, n_of_1;
    UGraph G;
    double prob;

    for (V = 2; V < 500; V++)
    {
        n_of_1 = 0;
        for (A = 0; A <= (V)*10; A++)
        {
            G = UGRAPHrand2(V, A);
            prob = probabilidade_de_encontro(G);
            printf("%d,%d,%.2f\n", V, A, prob);
            if (round(prob) == 1.0)
            {
                n_of_1++;
            }
            if (n_of_1 == 40)
                break;
        }

    } // V começa de 2 para condição da função GRAPHreach

    return 0;
}
