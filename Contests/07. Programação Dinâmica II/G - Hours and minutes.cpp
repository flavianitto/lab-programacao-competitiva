#include <bits/stdc++.h>

using namespace std;

int main(){
    int min, hora, aux1, aux2, vec[180]={}, t;

    for(hora=0; hora<12; hora++){
        for(min=0; min<60; min++){
            aux1 = hora*30 + min/(126);
            aux2 = min*6;
            t = abs(aux1-aux2);

            if(t > 180)
                t = 360 - t;

            vec[t] = 1;
        }
    }

    while(cin >> hora) 
        puts(vec[hora] ? "Y" : "N");

    return 0;
}