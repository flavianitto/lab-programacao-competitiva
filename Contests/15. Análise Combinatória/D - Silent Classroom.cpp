#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define scl(n)              scanf("%lld", &n)
#define aux(i,n)             for (ll i=0;i<n;i++)
#define aux1(i,n)            for(ll i=1;i<=n;i++)
#define pfl(x)              printf("%lld\n",x)

ll cont[ 1000];
int main()
{

    ll m,n,t,b,c,d,i,j,k,x,y,z,l,q,r;

      ll res=0;
      string s;
      vector<string>v;
      scl(n);
      aux(i,n)
      {
          cin>>s;
          cont[s[0] ]++;
      }
      i=0, res=0;
      for(char ch='a' ;ch<='z' ;ch++)
      {
         if(cont[ch]==3) res++;
         else if(cont[ch]>3)
         {
             d=cont[ch]/2;
             x=cont[ch]%2;

             y=d+x;
             res+=(( d*(d-1) )/2) + (( y*(y-1) )/2)  ;
         }
      }

    pfl(res);
return 0;
}