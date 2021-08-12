#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, n, k, p[101], m[101], min, custo, i, j, l;

    m[0] = 0;

    cin >> t;

    for(i=0; i<t; i++){
        cin >> n >> k;

        for(j=1; j<=k; j++)
            cin >> p[j];

        for(j=1; j<=k; j++){
            min = INT_MAX;

            for(l=1; l<=j; l++){
                if((p[l] != -1) && (m[j-l] != INT_MAX)){
                    custo = m[j-l] + p[l];

                    if(custo < min) 
                        min = custo;
                }
            }

            m[j] = min;
        }

        if(m[k] == INT_MAX) 
            cout << -1 << "\n";
        else 
            cout << m[k] << "\n";
    }

    return 0;
}