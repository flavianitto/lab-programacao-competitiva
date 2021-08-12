#include <iostream>

using namespace std;

int main()
{
    int q;
    cin >> q;

    while (q--)
    {
        long long n;
        int a, b;
        cin >> n >> a >> b;
        b = min(b, 2 * a);
        cout << (n / 2) * b + (n % 2) * a << '\n';
    }

    return EXIT_SUCCESS;
}