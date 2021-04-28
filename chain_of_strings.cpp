#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool is_prefix(std::string &str1, std::string &str2) {
    for (int i = 0; i < str1.size(); ++i) {
        if (str1[i] != str2[i]) return false;
    }
    return true;
}

int main() {
    int m;
    std::cin >> m;
    std::vector<std::string> a(m + 1);
    std::vector<int> dp(m + 1,1);
    for (int i = 1; i < m + 1; ++i) {
        std::cin >> a[i];
    }
    dp[0] = 0;
    a[0] = "";

    std::sort(a.begin() + 1, a.end());

    for (int i = 1; i <= m; ++i) {
        for (int j = i + 1; j <= m; ++j) {
            if (is_prefix(a[i], a[j])) {
                dp[j] = std::max(dp[i] + 1, dp[j]);
            }
        }
    }
    int max_ = -1;
    for (int i = 1; i <= m; ++i) {
        max_ = std::max(dp[i], max_);
    }
    std::cout << max_;
    return 0;
}

