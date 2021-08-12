#include<bits/stdc++.h>
using namespace std;

#define M 100010
vector<pair<int, int> > road[M];
int d[M], e[M];

void soluciona(int n, int m) 
{
    int i, j;
    int x, y;
    int a, b;
    int tam;

    for(i=0; i<=n; i++) 
    {
        road[i].clear();
        d[i] = 1000000000;
        e[i] = 0;
    }
    while(m--) 
    {
        cin >> x >> y;
        road[x].push_back(pair<int,int>(1,y));
        road[y].push_back(pair<int, int>(1,x));
    }
    d[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > fila;
    fila.push(pair<int, int>(0,1));
    while(!fila.empty()) 
    {
        x = fila.top().second;
        b = fila.top().first;
        fila.pop();
        tam = road[x].size();
        for(i=0; i<tam; i++) 
        {
            y = road[x][i].second;
            a = road[x][i].first;
            if(e[y] == 0 && b+a<=d[y]) 
            {
                d[y] = b+a;
                fila.push(pair<int, int>(d[y], y));
            }
        }
        e[x] = 1;
        if(x == n) 
        {
            break;
        }
    }
    cout << d[n] << endl;
}

int main() 
{
    int t;
    cin >> t;
    while(t--) 
    {
        int n, m;
        cin >> n >> m;
        soluciona(n, m);
    }
    return 0;
}