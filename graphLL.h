#include <stdlib.h>
#include <stdio.h>

#define vertex int

static int visit[1000];

typedef struct node *link;
struct node
{
    vertex w;
    link next;
};

static link NEWnode(vertex w, link next)
{
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    return a;
}

typedef struct graph *Graph;
struct graph
{
    int V;
    int A;
    link *adj;
};

Graph GRAPHinit(int V)
{
    vertex v;
    Graph G;
    G = malloc(sizeof(*G));
    G->V = V;
    G->A = 0;
    G->adj = malloc(V * sizeof(link));

    for (v = 0; v < V; v++)
        G->adj[v] = NULL;
    return G;
}

void GRAPHinsertArc(Graph G, vertex v, vertex w)
{
    link p;

    if (v != w)
    {
        for (p = G->adj[v]; p != NULL; p = p->next)
        {
            //printf("\np->w: %d", p->w);
            if (p->w == w)
                return;
        }
        G->adj[v] = NEWnode(w, G->adj[v]);
        G->A++;
    }
}

void GRAPHshow(Graph G)
{
    printf("\n\n --- Representação --- \n\n");
    vertex v;
    link p;
    for (v = 0; v < G->V; v++)
    {
        printf("%2d:", v);
        for (p = G->adj[v]; p != NULL; p = p->next)
            if (p->w != 0)
                printf(" %2d|", p->w);
        printf("\n");
    }
    printf("\n");
}

int GRAPHvOutDegree(Graph G, vertex v)
{
    link p;
    int od;
    od = 0;
    for (p = G->adj[v]; p != NULL; p = p->next)
        od++;
    return od;
}

int GRAPHvInDegree(Graph G, vertex v)
{
    link p;
    int id;
    vertex u;
    id = 0;
    for (u = 0; u < G->V; u++)
        if (u != v)
        {
            for (p = G->adj[u]; p != NULL; p = p->next)
            {
                if (p->w == v)
                    id++;
            }
        }
    return id;
}

int GRAPHcheckUGraph(Graph G)
{
    vertex v, w;
    link p, q;
    int w_to_v;
    w_to_v = 0;
    for (v = 0; v < G->V; v++)
        for (p = G->adj[v]; p != NULL; p = p->next)
        {
            // como tem v-w, vou checar se tem w-v
            for (q = G->adj[p->w]; q != NULL; q = q->next)
            {
                if (q->w == v)
                {
                    w_to_v = 1;
                    break;
                }
            }
            if (w_to_v == 0)
                return 0;
            else
                continue;
        }
    return 1;
}

static int GRAPHcheckIsParallel(Graph G, vertex v, vertex w)
{
    link p;
    int p_to_w, w_to_p;
    p_to_w = w_to_p = 0;
    for (p = G->adj[v]; p != NULL; p = p->next)
        if (p->w == w)
            p_to_w = 1;
    for (p = G->adj[w]; p != NULL; p = p->next)
        if (p->w == v)
            w_to_p = 1;
    if (p_to_w == 1 && w_to_p == 1)
        return 1;
    else
        return 0;
}

static void reachR( Graph G, vertex v) 
{ 
   visit[v] = 1;
   for (link a = G->adj[v]; a != NULL; a = a->next)
      if (visit[a->w] == 0)
         reachR( G, a->w);
}

int GRAPHreach( Graph G, vertex s, vertex t) 
{ 
   for (vertex v = 0; v < G->V; ++v)
      visit[v] = 0;
   reachR( G, s);
   if (visit[t] == 0) return 0;
   else return 1;
}