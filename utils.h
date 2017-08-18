#include <stdlib.h>
#include <stdio.h>
#include <graphGenerics.h>
#define vertex int

/* a few functions to make my life easier when inspacting and testing graphs */

void GRAPHinspect(Graph G)
{
    vertex v;

    GRAPHshow(G);
    printf("\n***********************\n");

    // outDegree

    for (v = 0; v < G->V; v++)
        printf("outDegree of %d is: %d\n", v, GRAPHvOutDegree(G, v));

    // inDegree

    for (v = 0; v < G->V; v++)
        printf("inDegree of %d is: %d\n", v, GRAPHvInDegree(G, v));
    // Sinks

    int *IsSink;
    IsSink = malloc(G->V * sizeof(int));

    GRAPHsinksBool(G, IsSink);

    printf("Sinks\n");
    for (v = 0; v < G->V; v++)
        if (IsSink[v] == 1)
            printf("%d\n", v);

    //TODO: how do I free memory of somthing I have alredy used?

    // Sources

    int *IsSource;
    IsSource = malloc(G->V * sizeof(int));

    GRAPHsourcesBool(G, IsSource);

    printf("Sources\n");
    for (v = 0; v < G->V; v++)
        if (IsSource[v] == 1)
            printf("%d\n", v);

    printf("\n****Vértices isolados****\n");
    for (v = 0; v < G->V; v++)
        if (GRAPHvInDegree(G, v) == 0 && GRAPHvOutDegree(G, v) == 0)
            printf("|%2d|", v);
    printf("\nFIM\n");
}