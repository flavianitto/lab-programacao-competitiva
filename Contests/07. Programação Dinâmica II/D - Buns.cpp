#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,cInit,dInit,a,b,c,d;
    scanf("%d %d %d %d", &n,&m,&cInit,&dInit);
    int ans[n+1]={0};
    for(int i = cInit; i <= n;i++) ans[i] = (i /cInit)*dInit;
    while(m--) {
        scanf("%d %d %d %d", &a,&b,&c,&d);
        for(int j=0; j<a/b;j++)
            for(int l=n;l>=c;l--) ans[l]=max(ans[l-c]+d,ans[l]);
    }
    printf("%d\n",ans[n]);
    return 0;
}