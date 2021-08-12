#include<bits/stdc++.h>
using namespace std;
int a[1010], b[1010];
int n, x;

int verifica(int i)
{
    int j;
    for(j=i+1; j<n; j++)
    {
        if(a[j]-a[i]<=x)
        {
            i=j;
        }
        else
        {
            return i;
        }
    }
    return n;
}
int main()
{
    int i;
    int maximo=0, cont=0;
    cin >> n >> x;
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    int answer=1;
    for(i=1; i<=n; i++)
    {
        answer=max(answer, verifica(i)-i+1);
    }
    printf("%d\n", answer);
    return 0;
}