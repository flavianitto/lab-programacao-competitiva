#include<bits/stdc++.h>
#define L 10
#define N 400
#define M 79800
using namespace std;

char nome1[L+1], nome2[L+1];
int f[N+1], fcnt;

struct aresta
{
    int u;
    int v;
    int w;
}a[M];

void inicia(int n)
{
    int i;
    for(i=0; i<=n; i++)
    {
        f[i]=i;
        fcnt = n;
    }
}

int find(int a)
{
    return a==f[a] ? a: f[a] = find(f[a]);
}

bool uniao(int a, int b)
{
    if((a=find(a)) != (b=find(b)))
    {
        f[a]=b;
        return true;
    }
    else
    {
        return false;
    }
}

bool compara(aresta a, aresta b)
{
   return a.w < b.w;
}

int main()
{
    int n, m, i;
    int answer;
    while((cin >> n >> m) && (n || m))
    {
        map<string, int> mp;
        for(i=1; i<=n; i++)
        {
            cin >> nome1;
            mp[nome1]=i;
        }
        for(i=0; i<m; i++)
        {
            cin >> nome1;
            cin >> nome2;
            cin >> a[i].w;
            a[i].u = mp[nome1];
            a[i].v = mp[nome2];
        }
        cin >> nome1;

        inicia(n);

        //kruskal 
        answer=0;
        sort(a, a+m, compara);
        for(i=0; i<m; i++)
        {
            int u, v;
            u = find(a[i].u);
            v = find(a[i].v);
            if(u != v)
            {
                f[u] = v;
                answer += a[i].w;
                if(--fcnt == 1)
                {
                    break;
                }
            }
        }

        if(fcnt == 1)
        {
            cout << answer << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}