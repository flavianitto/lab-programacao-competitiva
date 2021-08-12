#include<bits/stdc++.h>
using namespace std;

struct aresta
{
    int prox;
    long long w;
};

bool comparar(aresta A, aresta B)
{
    return A.w < B.w;
}

vector<aresta> con[100001];
vector<aresta> E;
long long dist[100001];

void busca(int s)
{
    int i;
    queue<int> Q;
    bool V[100001] = {false};
    Q.push(s);
    V[s] = true;
    while(!Q.empty())
    {
        int cur;
        cur = Q.front();
        Q.pop();
        for(i=0; i<con[cur].size(); i++)
        {
            aresta &e = con[cur][i];
            if(dist[cur] + e.w < dist[e.prox])
            {
                dist[e.prox] = dist[cur] + e.w;
                if(!V[e.prox])
                {
                    Q.push(e.prox), V[e.prox] = true;
                }
            }
        }
        V[cur] = false;
    }
}

int main()
{
    int n, m, k, i;
    while(scanf("%d%d%d", &n, &m, &k) == 3)
    {
        for(i=0; i<=n; i++)
        {
            dist[i] = 1e14, con[i].clear();
        }
        E.clear();
        for(i=0; i<m; i++)
        {
            int a, b, w;
            scanf("%d%d%lld", &a, &b, &w);
            con[a].push_back(aresta{ b , w });
            con[b].push_back(aresta{ a , w });
        }
        dist[1]=0;
        busca(1);

        int answer=0;
        for(i=0; i<k; i++)
        {
            int b, w;
            cin >> b >> w;
            E.push_back(aresta{ b , w });
        }
        sort(E.begin(), E.end(), comparar);

        for(i=0; i<k; i++)
        {
            if(dist[E[i].prox] > E[i].w)
            {
                dist[E[i].prox] = E[i].w, busca(E[i].prox);
            }
            else
            {
                answer++;
            }
        }
        cout << answer << endl;
    }
    return 0;
}