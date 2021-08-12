#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    int maior=0, menor=0;
    int a[1005];

    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    if(n%2 == 1)
    {
        cout << a[n/2] << endl;
    }
    else
    {
        cout << a[(n-1)/2] << endl;
    }
}