#include <iostream>
#include <vector>


int main () {
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> a(n + 1);
    std::vector<long long> b(n + 1);

    a[1] = k - 1;
    b[1] = 0;

    for (int i = 2; i <= n; ++i) {
        a[i] = (b[i - 1] + a[i - 1]) * (k - 1);
        b[i] = a[i - 1];
    }

    std::cout << a[n] + b[n];
    return 0;
}