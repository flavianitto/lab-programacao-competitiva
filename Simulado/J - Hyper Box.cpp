#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long f[50] = {1,2};
    int t, i, j;
    int n, x, c=0;
    for(i=2; i<50; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }
    cin >> t;
    while(t--)
    {
        cin >> n;
        long long minimo=1;
        for(i=0; i<n; i++)
        {
            cin >> x;
            int cont=0;
            for(j=49; j>=0; j--)
            {
                if(x >= f[j])
                {
                    x -= f[j], cont++;
                }
            }
            minimo = minimo*cont;
        }
        cout << "Case " << ++c << ": " << minimo << endl;
    }
    return 0;
}