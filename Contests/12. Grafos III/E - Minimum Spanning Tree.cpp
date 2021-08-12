//Minimum Spanning Tree
#include<bits/stdc++.h>
using namespace std;

struct arestas
{
    long long x;
    long long y;
    long long peso;
}grafo[200000];

struct subset
{
    long long pai;
    long long nivel;
}subsets[20000];

long long find(long long i)
{
    if(subsets[i].pai != i)
    {
        subsets[i].pai = find(subsets[i].pai);
    }
    return subsets[i].pai;
}

void unindo(long long x, long long y)
{
    long long raizX;
    long long raizY;
    raizX = find(x);
    raizY = find(y);
    if(subsets[raizX].nivel > subsets[raizY].nivel)
    {
        subsets[raizY].pai = raizX;
    }
    else if(subsets[raizX].nivel < subsets[raizY].nivel)
    {
        subsets[raizX].pai = raizY;
    }
    else
    {
        subsets[raizY].pai = raizX;
        subsets[raizX].nivel++;
    }
}

bool comparar(struct arestas a, struct arestas b)
{
    if(a.peso < b.peso)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

long long kruskal(int N, int M)
{
    int i;
    long long answer;
    sort(grafo, grafo+N, comparar);
    for(i=0; i<M; i++)
    {
        subsets[i]={i,0};
    }
    answer=0;
    for(i=0; i<N; i++)
    {
        if(find(grafo[i].x) != find(grafo[i].y))
        {
            unindo(grafo[i].x, grafo[i].y);
            answer += grafo[i].peso;
        }
    }
    return answer;
}

int main()
{
    int N, M, i;
    cin >> M;
    cin >> N;
    for(i=0; i<N; i++)
    {
        long long x, y;
        cin >> x >> y >> grafo[i].peso;
        grafo[i].x = x-1;
        grafo[i].y = y-1;
    }
    cout << kruskal(N, M);
}