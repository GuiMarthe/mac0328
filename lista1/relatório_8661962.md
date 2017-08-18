## lista 1: Questão 10 - Relatório 

**Nome:** Guilherme Marthe
**RA:** 8661962 

A função para gerar um grafo aleatório que pensei surgiu de um comentário em aula, que dizia que, como
o algorítmo geraria `GRAPHrand2`: 

> "Cada um dos V*(V-1) possíveis arcos é criado com probabilidade prob, sendo prob calculado de modo que 
> o número esperado de arcos seja A."

Que é basicamente uma distribuição binomial.

Pensando nisso, desenvolvi uma função que gera arcos a partir de uma distribuição poisson. O algorítmo para gerar observações de uma variável de poisson foi feito por D. Knuth e está descrito [aqui](https://en.wikipedia.org/wiki/Poisson_distribution#Generating_Poisson-distributed_random_variables).
E reproduzo-o a seguir:

```
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
        u = rand( ) / (RAND_MAX + 1.0);
        p = p * u;
    }
    return k - 1;
}
```
Assim para gerar os arcos aleatóriamente, gero um vetor de vértices `a1` a partir de uma poisson lambda e outro vetor `a2` a partir de uma variável lambda + offset, que assumo ser positivo. Faço isso para diminuir as chances de arcos iguais serem escolhidos e diminuir a chance de que dois arcos sejam escolhidos mais de uma vez.

Após gerar duas sequências de A vértices, checando apenas para que os pares não sejam iguais, chego nos arcos que serão inseridos no grafo. Para saber o total de vértices e assim inicializar o gráfico, apenas preciso saber qual é o máximo gerado nas sequências, que computo enquanto gero os vértices para evitar uma passada em cada vetor de vértices (ponta de arcos).

Essa algorítimo é um pouco ruim por duas razões:

- não consigo grantir o total de arcos que será gerado, devido a chance de gerar arcos iguais;
- não consigo saber quantos vértices terá o grafo, pois inicializo o grafo com base nas informações das sequências de vértices geradas por `rpois`;

Todavia, consigo saber que a região de vértices ao redor de [lambda, lambda + offset] será com populada com arcos entre-si;

Algumas melhorias para esse algorítmo são:

- saber a proporção de arcos efetivamente populados com relação ao total de arcos gerados;
- normalizar o grafo após a geração dos arcos, ou seja:
    + retirar vértices isolados;
    + normalizar a numeração dos vértices;

Reproduzo a seguir o construtor de grafos com base na exposição anterior:

```
Graph GRAPHmyConstructor(int A, float lbda, float offset)
{
    Graph G;
    int V;
    vertex i, *a1, *a2, maxa1 = -1, maxa2 = -1;

    a1 = malloc(A * sizeof( int ));
    a2 = malloc(A * sizeof( int ));

    for (i = 0; i < A; i++)
    {
        a1[i] = rpois(lbda);
        a2[i] = a1[i];
        while(a1[i] == a2[i]) 
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
        GRAPHinsertArc(G, a1[i], a2[i]);
    return G;

}

```
