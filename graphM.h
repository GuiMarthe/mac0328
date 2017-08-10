#include <stdlib.h>
#include <stdio.h>

#define vertex int

struct graph
{
    int V;     // número de vértices
    int A;     // número de arcos
    int **adj; // ponteiro para algo que aponta para a representação de adj
};

typedef struct graph *Graph;

/* representação por matrizes */

static int **MATRIXint(int r, int c, int val)
{
    vertex i, j;
    int **m = malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)
        m[i] = malloc(c * sizeof(int));
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            m[i][j] = val;
    return m;
}

Graph GRAPHinit(int V)
{
    Graph G = malloc(sizeof *G);
    G->A = 0;
    G->V = V;
    G->adj = MATRIXint(V, V, 0);
    return G;
}

void GRAPHinsertArc(Graph G, vertex v, vertex w)
{
    if (v != w && G->adj[v][w] == 0)
    {
        G->adj[v][w] = 1;
        G->A++;
    }
}

void GRAPHremoveArc(Graph G, vertex v, vertex w)
{
    if (v != w && G->adj[v][w] == 1)
    {
        G->adj[v][w] = 0;
        G->A--;
    }
}

void GRAPHshow(Graph G)
{
    printf("\n\n --- Representação --- \n\n");
    vertex v, w;
    for (v = 0; v < G->V; ++v)
    {
        printf("%2d:", v);
        for (w = 0; w < G->V; ++w)
            if (G->adj[v][w] == 1)
                printf(" %2d", w);
        printf("\n");
    }
}

int GRAPHvOutDegree(Graph G, vertex v)
{
    vertex w;
    int od;
    od = 0;
    for (w = 0; w < G->V; w++)
    {
        od += G->adj[v][w];
    }
    return od;
}

int GRAPHvInDegree(Graph G, vertex v)
{
    vertex w;
    int od;
    od = 0;
    for (w = 0; w < G->V; w++)
    {
        od += G->adj[w][v];
    }
    return od;
}

int GRAPHvIsSource(Graph G, vertex v)
{
    // ser fonte -> grau de entrada == 0

    if (GRAPHvInDegree(G, v) == 0)
        return 1;
    else
        return 0;
}

int GRAPHvIsSink(Graph G, vertex v)
{
    // ser fonte -> grau de entrada == 0

    if (GRAPHvOutDegree(G, v) == 0)
        return 1;
    else
        return 0;
}

void GRAPHsourcesBool(Graph G, int *isSource)
{

    vertex v;

    for (v = 0; v < G->V; v++)
        isSource[v] = GRAPHvIsSource(G, v);
}

void GRAPHsinksBool(Graph G, int *isSink)
{

    vertex v;

    for (v = 0; v < G->V; v++)
        isSink[v] = GRAPHvIsSink(G, v);
}