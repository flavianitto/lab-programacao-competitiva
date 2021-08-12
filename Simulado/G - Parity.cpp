#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#define M 50010
using namespace std;

struct Node
{
    int x;
    int y;
    int marcado;
};
Node node[M];
int vetor[M], pos;
int pai[M], rank[M];
int num;

void inicia()
{
    int i;
    sort(vetor, vetor+pos);
    num = unique(vetor, vetor+pos)-vetor;
    memset(rank, 0, sizeof(rank));
    for(i=0; i<=num; i++)
    {
        pai[i] = i;
    }
}

int encontra(int x)
{
    if(pai[x] != x)
    {
        int p;
        p = pai[x];
        pai[x] = encontra(pai[x]);
        rank[x] = (rank[x]+rank[p])%2;
    }
    return pai[x];
}

int busca(int x)
{
    int esquerda=0;
    int direita = num-1;
    while(esquerda<=direita)
    {
        int meio = (esquerda+direita)>>1;
        if(vetor[meio]==x)
        {
            return meio;
        }
        else if(vetor[meio]<x)
        {
            esquerda = meio+1;
        }
        else
        {
            direita = meio-1;
        }
    }
}

int resolve(int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        int x, y, fx, fy, valor;
        x = busca(node[i].x)+1;
        y = busca(node[i].y)+1;
        fx = encontra(x);
        fy = encontra(y);
        valor = node[i].marcado;
        if(fx == fy)
        {
            if((rank[y]-rank[x]+2)%2 != valor)
            {
                return i;
            }
        }
        else
        {
            pai[fx] = fy;
            rank[fx] = (valor+rank[y]-rank[x]+2)%2;
        }
    }
    return n;
}

int main()
{
    int tam, n, i;
    char string[10];
    while(cin >> tam >> n)
    {
        pos=0;
        for(i=0; i<n; i++)
        {
            cin >> node[i].x >> node[i].y >> string;
            node[i].x--;
            vetor[pos++] = node[i].x;
            vetor[pos++] = node[i].y;
            if(string[0] == 'e')
            {
                node[i].marcado=0;
            }
            else if(string[0] == 'o')
            {
                node[i].marcado=1;
            }
        }
        inicia();
        cout << resolve(n) << endl;
    }
    return 0;
}