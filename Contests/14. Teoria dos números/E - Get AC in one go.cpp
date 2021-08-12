#include<bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    if(x==0)
    {
        return y;
    }
    return gcd(y%x, x);
}
int main()
{
    int i;
    int t;
    long long x, y;
    scanf("%d", &t);
    assert(t<=10000000);
    for(i=0; i<t; i++)
    {
        scanf("%lld %lld", &x, &y);
        assert(x<=1000000000);
        assert(y<=1000000000);
        if(gcd(x,y)==1)
        {
            printf("%lld\n", x*y-x-y+1);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}