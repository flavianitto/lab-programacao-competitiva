#include<bits/stdc++.h>
using namespace std;

#define M 300005

typedef struct 
{
    int par;
    int alt;
    int cont;
}node;
vector<pair<int, pair<int, int> > > E;
vector<pair<int, pair<int, int> > > Q;

node busca[100005];
int ans[300005];

int achar(int v)
{
    if(busca[v].par==-1)
    {
        return v;
    }
    return achar(busca[v].par);
}
void juntar(int x, int y)
{
    int rx, ry;
    rx = achar(x);
    ry = achar(y);

    if(rx==ry)
    {
        return;
    }
    if(busca[rx].alt > busca[ry].alt)
    {
        busca[ry].par=rx;
        busca[rx].cont += busca[ry].cont;
    }
    else if(busca[ry].alt > busca[rx].alt)
    {
        busca[rx].par = ry;
        busca[ry].cont += busca[rx].cont;
    }
    else
    {
        busca[ry].par = rx;
        busca[rx].cont += busca[ry].cont;
        busca[rx].alt++;
    }
}
int main()
{
    int i, j;
    int n, m, q, x, y, z;
    for(i=0; i<100005; i++)
    {
        ans[i]=0;
        busca[i].par=-1;
        busca[i].cont=1;
        busca[i].alt=0;
    }
    cin >> n >> m >> q;
    while(m--)
    {
        cin >> x >> y >> z;
        E.push_back(make_pair(z, make_pair(x, y)));
    }

    sort(E.begin(), E.end(), greater<pair<int, pair<int, int> > >() );

    for(i=0; i<q; i++)
    {
        cin >> y >> z;
        Q.push_back(make_pair(z, make_pair(y, i)));
    }

    sort(Q.begin(), Q.end(), greater<pair<int, pair<int, int> > >() );
    
    j=0;
    for(i=0; i<q; i++)
    {
        z = Q[i].first;
        while(E[j].first >= z)
        {
            juntar(E[j].second.first, E[j].second.second);
            j++;
        }
        ans[Q[i].second.second] = busca[achar(Q[i].second.first)].cont;
    }
    for(i=0; i<q; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}