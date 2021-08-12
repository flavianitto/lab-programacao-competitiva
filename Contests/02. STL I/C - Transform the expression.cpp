#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, tam;
    string exp1, exp2, pilha;
    cin >> t;
    while(t--)
    {
        cin >> exp1;
        tam = exp1.size();
        exp2 = "";
        pilha = "";
        for(i=0; i<tam; i++)
        {
            if(exp1[i]=='+' || exp1[i]=='-' || exp1[i]=='*' || exp1[i]=='/' || exp1[i]=='(' || exp1[i]=='^')
            {
                pilha = exp1[i] + pilha;
            }
            else if(exp1[i]==')')
            {
                while(pilha.size()!=0 && pilha[0]!='(')
                {
                    exp2 += pilha[0];
                    pilha = pilha.substr(1);
                }
                pilha = pilha.substr(1);
            }
            else
            {
                exp2 += exp1[i];
            }
        }
        cout << exp2 << endl;
    }
    return 0;
}