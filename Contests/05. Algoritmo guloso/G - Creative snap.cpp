/* G - Creative Snap */
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long int power(long long int&A, long long int&B, vector<int> &b, long long int begin, long long int end) {
    size_t l = end - begin;
    
    int N = upper_bound(b.begin(), b.end(), end) - lower_bound(b.begin(), b.end(), begin + 1);

    long long int ret = N == 0 ? A : B * N * l;

    if (N == 0 || l < 2) {
        return ret;
    }

    long long int p1 = power(A, B, b, begin, begin + l / 2);
    long long int p2 = power(A, B, b, begin + l / 2, end);

    return min(ret, p1 + p2);
}

int main() {
    long long int N = 0;
    long long int K = 0;
    long long int A = 0;
    long long int B = 0;
    cin >> N >> K >> A >> B;

    vector<int> b = vector<int>(K);
    for (long long int k = 0; k < K; k++) {
        cin >> b[k];
    }

    sort(b.begin(), b.end());

    cout << power(A, B, b, 0, 1LL << N);

    return 0;
}