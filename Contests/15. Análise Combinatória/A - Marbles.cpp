#include <bits/stdc++.h>
using namespace std;

long long nume(int n, int m){
    if(m>n-m) m=n-m;
    
    long long resp=1;
    
    for(int i=0;i<m;i++) resp=resp*(n-i)/(i+1);
    
    return resp;
}

int main(){
    int T,n,k;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&n,&k);
        printf("%lld\n",nume(n-1,k-1));
    }
    
    return 0;
}