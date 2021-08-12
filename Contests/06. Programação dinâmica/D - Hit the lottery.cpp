#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, resp=0;
    int a[] = {100, 20, 10, 5, 1};
    cin >> n;
    for(int i=0; i<5; i++)
    {
        resp += n/a[i];
        n = n%a[i];
    }
    cout << resp << endl;
}