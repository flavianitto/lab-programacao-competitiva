#include <bits/stdc++.h>
using namespace std;

int main (){
    long long int cases,res;
    long long int values[100001];
    while(scanf("%lld",&cases)){
        res=0;
        if(cases==0)
            break;
        for(int i=0;i<cases;i++){
            scanf("%lld",&values[i]);
            if(i>0){
                values[i]+= values[i-1];
                res+=abs(values[i]);
            }
            else{
                res+=abs(values[i]);
            }
        }
        cout << res << "\n";
    }
}