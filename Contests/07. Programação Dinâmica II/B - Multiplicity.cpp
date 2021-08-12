#include <bits/stdc++.h>
using namespace std;

const long long modulo = 1000000007;

int main()
{
    long long n, answer=0;
    vector<int> vet[1000015];
    int a[1000015], i, j;

    while(cin >> n)
    {
        memset(a, 0, sizeof(a));
        for(i=1; i<=n; i++)
        {
            int x;
            cin >> x;
            vet[i].clear();
            for(j=1; j<=sqrt(x); j++)
            {
                if(x%j == 0)
                {
                    vet[i].push_back(j);
                    if(x != j*j)
                    {
                        vet[i].push_back(x/j);
                    }
                }
            }
            sort(vet[i].begin(), vet[i].end());
        }
        a[0] = 1;
        for(i=1; i<=n; i++)
        {
            for(j=vet[i].size()-1; j>=0; j--)
            {
                a[vet[i][j]] = (a[vet[i][j]] + a[vet[i][j]-1]) % modulo;
                answer = (answer + a[vet[i][j]-1]) % modulo;
            }
        }
        cout << answer << endl;
        return 0;
    }
}