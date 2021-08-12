#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, m, i;
    long long int max=0, h=0;
    long long int inicio, fim, meio, cut;
    scanf("%lld%lld", &n, &m);
    int vetor[n];
    for(i=0; i<n; i++)
    {
        scanf("%d", vetor+1);
        if(vetor[i] > max)
            max = vetor[i];
    }
    inicio=0;
    fim=max;
    while(inicio<=fim)
    {
        meio = (inicio+fim)/2;
        cut=0;
        for(i=0; i<n; i++)
        {
            if(vetor[i]-meio > 0)
                cut += vetor[i]-meio;
        }
        if(cut > m)
        {
            inicio = meio+1;
            if(meio>h)
                h = meio;
        }
        else if(cut < m)
        {
            fim = meio-1;
        }
        else
        {
            h = meio;
            break;
        }
    }
    printf("%lld\n", h);
}
