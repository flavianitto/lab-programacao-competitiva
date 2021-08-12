#include<bits/stdc++.h>
#define M 105
using namespace std;

int main()
{
    char frase1[M], frase2[M], frase3[M];
    int i;
    int soma1=0;
    int soma2=0;
    int soma3=0;
    
    gets(frase1);
    gets(frase2);
    gets(frase3);
    
    for(i=0; frase1[i]!='\0'; i++)
    {
        if(frase1[i]=='a' || frase1[i]=='e' || frase1[i]=='i' || frase1[i]=='o' || frase1[i]=='u')
        {
            soma1++;
        }
    }
    for(i=0; frase2[i]!='\0'; i++)
    {
        if(frase2[i]=='a' || frase2[i]=='e' || frase2[i]=='i' || frase2[i]=='o' || frase2[i]=='u')
        {
            soma2++;
        }
    }
    for(i=0; frase3[i]!='\0'; i++)
    {
        if(frase3[i]=='a' || frase3[i]=='e' || frase3[i]=='i' || frase3[i]=='o' || frase3[i]=='u')
        {
            soma3++;
        }
    }    
    if(soma1==5 && soma2==7 && soma3==5)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}