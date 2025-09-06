#include <iostream>
#include <cmath>
 int main() {
    int t;
    std::cin >> t;
    while (t-- > 0) {
        long long n, k;
        std::cin >> n >> k;
        long long x = (1 + static_cast<int>(std::sqrt(8 * k - 7))) / 2;
        long long y = ((x * (x - 1)) / 2) + 1;
        for (int i = 1; i <= (n - x - 1); i++)
            std::cout << "a";
        std::cout << "b";
        for (int i = 1; i <= (x - k + y - 1); i++)
            std::cout << "a";
        std::cout << "b";
        for (int i = 1; i <= (k - y); i++)
            std::cout << "a";
        std::cout << std::endl;
    }
    return 0;
}
 