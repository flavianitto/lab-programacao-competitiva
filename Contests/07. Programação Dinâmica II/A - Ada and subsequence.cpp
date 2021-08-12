#include<bits/stdc++.h>
using namespace std;

int main()
{
    const int MAX = 2025;
    int n, m, i, j;
    int price[MAX], matriz[MAX][MAX];
    string a, b;    

    cin >> n >> m;
    for(i='a'; i<='z'; i++)
    {
        cin >> price[i];
    }
    cin >> a >> b;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(a[i-1] == b[j-1])
            {
                matriz[i][j] = matriz[i-1][j-1] + price[a[i-1]];
            }
            else
            {
                matriz[i][j] = max(matriz[i][j-1], matriz[i-1][j]);
            }
        }
    }
    cout << matriz[n][m] << endl;
    return 0;
}