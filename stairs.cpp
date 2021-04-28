#include <iostream>
#include <vector>

int main () {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::vector<int> dp(n + 1);
    std::vector<int> way(n + 1);
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        if (dp[i - 1] > dp[i - 2]) {
            dp[i] = dp[i - 1] + a[i];
            way[i] = i - 1;
        } else {
            dp[i] = dp[i - 2] + a[i];
            way[i] = i - 2;
        }
    }
    std::cout << dp[n] << std::endl;
    int j = n;
    int l = 0;
    std::vector<int> b;
    while (j) {
        b.push_back(j);
        ++l;
        j = way[j];
    }
    for (int i = l -1; i >= 0; --i) {
        std::cout << b[i] << " ";
    }
    return 0;
}
