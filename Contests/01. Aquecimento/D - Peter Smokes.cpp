#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, aux, res;
    while(cin >> n >> k)
    {
        res = n + n/k;
        //cout << res << endl;
        aux = n/k + n%k;
        //cout << aux << " " << n%k << endl;

        while(aux>=k)
        {
            res = res+aux/k;
            //cout << aux/k << endl;
            aux = aux/k + aux%k;
            //cout << aux << endl;            
        }
        cout << res << endl;
    }
}

#include<stdio.h>
int main()
{
    int n,k,s,b,tb,r;
    while(cin >> n >> k)
    {
        s=n;
        tb=0;
        while(s>=k)
        {
            b=s/k;
            r=s%k;
            s=b+r;
            tb=tb+b;
        }
    printf("%d\n",n+tb);
    }
    return 0;
}