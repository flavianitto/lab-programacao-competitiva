#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i, op, n;
    stack<int>pilha;
    cin >> t;
    for(i=0; i<t; i++)
    {
        cin >> op;
        //push n positions to the top of the stack
        switch(op)
        {
            case 1:
            {
                cin >> n;
                pilha.push(n);
            }break;
            //pop an element from the top
            case 2:
            {
                if(!pilha.empty())
                {
                    pilha.pop();
                }
            }break;
            //printf the top element
            case 3:
            {
                if(pilha.empty())
                {
                    cout << "Empty!\n";
                }
                else
                {
                    cout << pilha.top() << "\n";
                }
            }break;
        }
    }
    return 0;
}