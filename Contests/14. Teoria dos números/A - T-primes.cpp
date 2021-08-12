#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
long long first[MAX];

int square(long long n){
    double sqrt_n = sqrt(n);
    if(sqrt_n == int(sqrt_n)){
        return 1;
    }
    else{
        return 0;
    }
}
void calculflag(){
  long long i, j;
    first[0] = first[1] = 1;
    for(i=2;i<MAX;i++){
        if (first[i]==0){
            for(j=i*i;j<MAX;j+=i){
                first[j] = 1;
            }
        }
    }
}
int main(){
    calculflag();
    long long i, j;
    long long N, n;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>n;
        if (n==4){
            cout<<"YES"<<endl;
        }
        else if (n%2==0){
            cout<<"NO"<<endl;
        }
        else if(square(n)==1 && first[int(sqrt(n))]==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}