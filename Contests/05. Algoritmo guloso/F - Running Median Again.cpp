#include<bits/stdc++.h>
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    long long t, i;
    scanf("%lld", &t);
    for(i=0; i<t; i++)
    {
        priority_queue<long long> big;
        priority_queue<long long, vector<long long>, greater<long long> > small;

        long long n, aux;
        scanf("%lld", &aux);
        big.push(aux);

        scanf("%lld", &n);
        while(n)
        {
            long long tamBig = big.size();
            long long tamSmall = small.size();
            long long middle;

            if(tamBig > tamSmall)
            {
                middle = big.top();
            }
            else if(tamBig < tamSmall)
            {
                middle = small.top();
            }
            else
            {
                if(tamBig==0 and tamSmall==0)
                {
                    big.push(n);
                    scanf("%lld", &n);
                    continue;
                }
                else
                {
                    middle = min(big.top(), small.top());
                }
            }
            if(n==-1)
            {
                printf("%lld\n", middle);
                if(tamBig==0)
                {
                    small.pop();
                }
                else if(tamSmall==0)
                {
                    big.pop();
                }
                else if(big.top()==middle)
                {
                    big.pop();
                }
                else
                {    
                    small.pop();
                }
                scanf("%lld", &n);
                continue;
            }   
            if(n >= middle)
            {
                if(tamBig >= tamSmall)
                {
                    small.push(n);
                }
                else if(tamBig < tamSmall)
                {
                    big.push(small.top());
                    small.pop();
                    small.push(n);
                }
            }
            else
            {
                if(tamBig <= tamSmall)
                {
                    big.push(n);
                }
                else if(tamBig > tamSmall)
                {
                    small.push(big.top());
                    big.pop();
                    big.push(n);
                }
            }
            scanf("%lld", &n);
        }
    }
}