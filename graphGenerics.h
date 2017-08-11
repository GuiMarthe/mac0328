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