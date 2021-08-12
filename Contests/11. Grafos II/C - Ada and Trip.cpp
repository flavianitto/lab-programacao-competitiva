#include<bits/stdc++.h>
using namespace std;

struct city
{
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return a.second > b.second;
    }
};

int main()
{
    int n, m, q, i;
    cin >> n >> m >> q;
    vector<vector<pair<int,int> > > ed(n);
    while(m--)
    {
        int s, d, valor;
        cin >> s >> d >> valor;
        ed[s].push_back(pair<int,int>(d,valor));
        ed[d].push_back(pair<int,int>(s,valor));
    }
    while(q--)
    {
        int s1;
        cin >> s1;
        vector<bool> visit(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int> >, city> fila;
        fila.push(pair<int,int>(s1,0));
        int answer1, answer2;
        answer1=-1;
        answer2=-1;
        while(!fila.empty())
        {
            int s, dist;
            s = fila.top().first;
            dist = fila.top().second;
            fila.pop();
            if(!visit[s])
            {
                visit[s]=true;
                bool end;
                end = true;
                for(i=0; i<ed[s].size(); i++)
                {
                    int d, dis;
                    d = ed[s][i].first;
                    dis = ed[s][i].second;
                    if(visit[d]==false)
                    {
                        fila.push(pair<int,int>(d, dist+dis));
                    }
                }
                if(end)
                {
                    if(dist==answer1)
                    {
                        answer2++;
                    }
                    else if(dist>answer1)
                    {
                        answer1=dist;
                        answer2=1;
                    }
                }
            }
        }
        cout << answer1 << " " << answer2;
        if(q!=0)
        {
            cout << "\n";
        }
    }
    return 0;
}