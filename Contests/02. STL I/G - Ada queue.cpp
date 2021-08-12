#include<bits/stdc++.h>
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);    
    
    long long q;
    string operacao;
    bool inverte=false;
    deque<int>fila;
    scanf("%lld", &q);
    while(q--)
    {
        cin >> operacao;
        if(operacao == "back")
        {
            if(!inverte)
            {
                if(fila.empty())
                {
                    printf("No job for Ada?\n");
                }
                else
                {
                    printf("%d\n", fila.back()); 
                    fila.pop_back(); 
                }
            }
            else
            {
                if(fila.empty())
                {
                    printf("No job for Ada?\n");
                }
                else
                {
                    printf("%d\n", fila.front()); 
                    fila.pop_front(); 
                }
            }            
        }
        else if(operacao == "front")
        {
            if(!inverte)
            {
                if(fila.empty())
                {
                    printf("No job for Ada?\n");
                }
                else
                {
                    printf("%d\n", fila.front()); 
                    fila.pop_front(); 
                }
            }
            else
            {
                if(fila.empty())
                {
                    printf("No job for Ada?\n");
                }
                else
                {
                    printf("%d\n", fila.back()); 
                    fila.pop_back(); 
                }
            }
        }
        else if(operacao == "reverse")
        {
            inverte = !inverte;            
        }
        else if(operacao == "push_back")
        {
            int n;
            scanf("%d", &n);
            if(inverte)
            {    
                fila.push_front(n);
            }
            else
            {
                fila.push_back(n);
            }
        }
        else if(operacao == "toFront")
        {
            int n;
            scanf("%d", &n);
            if(!inverte)
            {    
                fila.push_front(n);
            }
            else
            {
                fila.push_back(n);
            }
        }        
    }
    return 0;
}