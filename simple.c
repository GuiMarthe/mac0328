#include <graphLL.h>
#include <utils.h>


int main()
{
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
    while (i < narcos)
    {
        scanf("%d %d", &v, &w);
        GRAPHinsertArc(G, v, w);
        i++;
    }

    GRAPHinspect(G);
}