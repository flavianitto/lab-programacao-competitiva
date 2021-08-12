#include<bits/stdc++.h>
using namespace std;

void calcula(string s, string l, char *answer)
{
    int tam1 = s.length();
    int tam2 = l.length();
    int i, j;
    int aux=0, indice=-1, maximo=-1;
    for(i=tam1-1; i>=0; i--)
    {
        indice = tam1-i-2;
        for(j=tam2-1; j>=0; j--)
        {
            int valor = aux+(s[i]-'0')*(l[j]-'0');
            answer[++indice] += valor%10;
            aux = valor/10;
            if(answer[indice]>'9')
            {
                answer[indice] = answer[indice]-'9'-1+'0';
                aux++;
            }
        }
        while(aux)
        {
            answer[++indice] += aux%10;
            aux = aux/10;
        }
        if(indice>maximo)
        {
            maximo=indice;
        }
    }
    answer[++maximo]='\0';
}

int main()
{
    int tam, i;
    string n;
    while(cin >> n)
    {
        if(n=="1" || n=="0")
        {
            if(n=="1")
            {
                cout << 1;
            }
            else
            {
                cout << 0;
            }
            printf("\n");
            continue;
        }
        string s="2";
        char answer[500];
        for(i=0; i<500; i++)
        {
            answer[i]='0';
        }
        calcula(n, s, answer);
        tam = strlen(answer);
        i=0;
        int aux=0;
        answer[0]=answer[0]-2;
        while(i<tam && answer[i]-aux<'0')
        {
            {
                answer[i]=answer[i]+10-aux;
                aux=1;
            }
            i++;
        }
        answer[i]=answer[i]-aux;
        i=tam-1;
        while(i>=0 && answer[i]=='0')
        {
            i--;
        }
        while(i>=0)
        {
            cout << answer[i--];
        }
        printf("\n");
    }
    return 0;
}