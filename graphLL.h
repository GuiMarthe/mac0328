#include <stdlib.h>
#include <stdio.h>

#define vertex int

struct graph {
   int V; 
   int A; 
   link *adj; 
};

typedef struct graph *Graph;

typedef struct node *link;

struct node { 
   vertex w; 
   link next; 
};

static link NEWnode( vertex w, link next) { 
   link a = malloc( sizeof (struct node));
   a->w = w; 
   a->next = next;     
   return a;                         
}

Graph GRAPHinit(int V)
{
    vertex v;
    Graph G;
    G = malloc(sizeof (*G));
    G->V = V;
    G->A = A;
    G->adj = malloc(V * sizeof(link));

    for (v = 0; v < V; v++)
        G->adj[v] = NULL;
    return G;
}


void GRAPHinsertArc(Graph G, vertex v, vertex w)
{
    link p;

    if (v != w) {
        for (p = G->adj[v]; p != NULL; p = p->next)

    }
        
}









