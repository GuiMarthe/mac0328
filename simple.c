#include <graphM.h>


int main(){
    /* inicializando um gráfico simples */

    int nvertices, narcos, i;
    vertex v, w;
    Graph G;
    printf("Digite o número de vertices: ");
    scanf("%d", &nvertices);
    G = GRAPHinit(nvertices);
    printf("\nDigite o número de arcos: ");
    scanf("%d", &narcos);
    
    printf("\nDigite os pares arcos: ");    
    while (i < narcos){
        scanf("%d %d", &v, &w);
        GRAPHinsertArc(G, v, w);
        i++;
    }

    /* demonstração de alguns métodos */

    GRAPHshow(G);

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
        if( IsSink[v] == 1)  
            printf("%d\n", v);


    //TODO: how do I free memory of somthing I have alredy used?

    // Sources

    int *IsSource; 
    IsSource = malloc(G->V * sizeof(int));

    GRAPHsourcesBool(G, IsSource);
    
    printf("Sources\n");
    for (v = 0; v < G->V; v++)
        if( IsSource[v] == 1)  
            printf("%d\n", v);


    
}