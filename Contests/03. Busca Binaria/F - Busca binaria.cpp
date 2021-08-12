#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, x;
    int i, answer;
    cin >> n >> q;
    int array[q];
    for(i=0; i<n; i++)
    {
        cin >> array[i];
    }
    while(q--)
    {
        cin >> x;
        answer = binary_search(array, array+n, x);
        if(answer == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

/* SOLUÇÃO DO MATHEUS
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    unordered_set<int> s;
    s.reserve(n);

    while (n--)
    {
        int i;
        cin >> i;
        s.insert(i);
    }

    while (q--)
    {
        int x;
        cin >> x;
        if (s.find(x) != s.end())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return EXIT_SUCCESS;
}
*/
