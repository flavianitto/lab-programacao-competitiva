#include<bits/stdc++.h>
#define tam 30010
using namespace std;

int f[tam], answer[tam];

int find(int x)
{
    if(f[x]==x)
    {
        return x;
    }
    else
    {
        return(f[x]=find(f[x]));
    }
}

int main()
{
    int N;
    cin >> N;
    while(N--)
    {
        int n, m;
        cin >> n >> m;
        for(int i=1; i<=n; i++)
        {
            f[i]=i;
        }
        memset(answer, 0, sizeof(answer));
        for(int i=1; i<=m; i++)
        {
            int x, y;
            int fx, fy;
            cin >> x >> y;
            fx = find(x);
            fy = find(y);
            if(fx != fy)
            {
                f[fx]=fy;
            }
        }   
        for(int i=1; i<=n; i++)
        {
            answer[find(i)]++;
        }
        int maior=0;
        for(int i=1; i<=n; i++)
        {
            if(answer[i]>maior)
            {
                maior = answer[i];
            }
        }
        cout << maior << endl;
    }
    return 0;
}