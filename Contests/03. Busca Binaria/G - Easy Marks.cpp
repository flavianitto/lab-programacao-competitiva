#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, res;
    int i, j; 
    cin >> t;
    for(i=0; i<t; i++)
    {
        cin >> n >> k;
        int a[n];
        int soma=0;
        for(j=0; j<n; j++)
        {
            cin >> a[j];
            soma += a[j];
        }
        res = k*(n+1) - soma;
        cout << "Case " << i+1 << ": " << res << endl;
    }
    return 0;
}
