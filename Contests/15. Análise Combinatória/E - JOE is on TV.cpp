#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, numero, testes;
    long long i, t=1;
    scanf("%lld", &numero);
    double answer=0.0;
    for(i=1; i<=numero; i++)
    {
        answer+=(double)1/i;
    }
    printf("%.12lf\n", answer);
}