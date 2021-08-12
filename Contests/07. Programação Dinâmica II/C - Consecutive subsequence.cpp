#include <bits/stdc++.h>
using namespace std;

map<int,int> memo;
vector <int> res;


void print(){
    sort(res.begin(),res.end());
    for(int v: res) printf("%d ",v+1);
    printf("\n");
    return;
}

void answer(int n, int vec[],int numMax){ 
    for(int i=n-1;i>=0;i--){
        if(vec[i]==numMax){
            res.push_back(i);
            numMax--;
        }
    }

    print();
    return;
}

int main (){
    int n,max=0,numMax=0;
    scanf("%d",&n);
    int vec[n];
    for(int i=0;i<n;i++){
        scanf("%d",&vec[i]);
    }
    for(int i=0;i<n;i++){
        memo[vec[i]] = memo[vec[i]-1]+1;
        if(memo[vec[i]]> max){
            max= memo[vec[i]];
            numMax = vec[i];
        }
    }
    printf("%d\n",max);
    answer(n,vec,numMax);
    return 0;
}