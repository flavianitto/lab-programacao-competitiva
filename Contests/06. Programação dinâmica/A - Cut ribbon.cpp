#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b, c;
    int x, y, z, aux, p=0;
    cin >> n >> a >> b >> c;
    aux = min(a, min(b, c));
    aux = n/aux;
    for(x=aux; x>=0; x--)
    {
        for(y=0; y<=aux; y++)
        {
            z = abs((n-(a*x + b*y))/c);
            if((a*x + b*y + c*z)==n)
            {
                p = max(p, x+y+z);
            }
        }
    }
    cout << p << endl;
}