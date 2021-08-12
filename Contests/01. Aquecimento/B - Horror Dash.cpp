#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, v, max;
    int i, j;
    cin >> t;
    for(i=0; i<t; i++)
    {
        cin >> n;
        max = 0;
        for(j=0; j<n; j++)
        {
            cin >> v;
            if(v > max) //encontrando o maior valor
            {
                max = v;
            }
        }
        cout << "Case " << i+1 << ": " << max << endl;
    }
}