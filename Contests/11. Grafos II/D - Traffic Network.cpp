#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f

int n, m, k, s, t, u, v, T, d, answer;
vector<int> ds, dt;
pair<int,int> aux;
vector<vector<pair<int,int> > > adj, adj_rev;

void dijkstra(int start, vector<int> &dist, vector<vector<pair<int,int> > > &adj)
{
    int i;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > visitado;
    visitado.push(make_pair(0, start));
    dist[start]=0;
    while(!visitado.empty())
    {
        aux = visitado.top();
        visitado.pop();
        d = aux.first;
        u = aux.second;
        if(dist[u] < d)
        {
            continue;
        }
        for(i=0; i<adj[u].size(); i++)
        {
            aux = adj[u][i];
            d = aux.second;
            v = aux.first;
            if(dist[u]+d < dist[v])
            {
                dist[v] = dist[u]+d;
                visitado.push(make_pair(dist[v], v));
            }
        }
    }
}

int main()
{
    int i;
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> k >> s >> t;
        adj.clear();
        adj.resize(n+1);
        adj_rev.clear();
        adj_rev.resize(n+1);
        ds.assign(n+1, inf);
        dt.assign(n+1, inf);
        for(i=0; i<m; i++)
        {
            cin >> u >> v >> d;
            adj[u].push_back(make_pair(v,d));
            adj_rev[v].push_back(make_pair(u,d));
        }
        dijkstra(s, ds, adj);
        dijkstra(t, dt, adj_rev);
        answer = inf;
        for(i=0; i<k; i++)
        {
            cin >> u >> v >> d;
            answer = min(ds[t], min(answer, d+min(ds[u]+dt[v], ds[v]+dt[u])));
        }
        if(answer == inf)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << answer << endl;
        }
    }
}