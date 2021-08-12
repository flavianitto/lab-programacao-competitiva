#include<bits/stdc++.h>
using namespace std;

void busca(vector<vector<int> > & adj, vector<int> & visitado, int v) 
{
    int i;
    visitado[v] = 1;
    for(i=0; i<adj[v].size(); i++) 
    {
        int u;
        u = adj[v][i];
        if(!visitado[u]) 
        {
            busca(adj, visitado, u);
        }
    }
}

long buscando(vector<vector<int> > & adj) 
{
    vector<int>visitado(adj.size(), 0);
    long conectado=0;
    int i;
    for(i=0; i<adj.size(); i++) 
    {
        if(!visitado[i]) 
        {
            conectado++;
            busca(adj, visitado, i);
        }
    }
    return conectado;
}

int main()
{
    long v, e;
    int i;
    cin >> v >> e;
    vector<vector<int> > adj(v);
    for(i=0; i<e; i++) 
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long conectado;
    conectado = buscando(adj);
    cout << conectado-1 << endl;
}