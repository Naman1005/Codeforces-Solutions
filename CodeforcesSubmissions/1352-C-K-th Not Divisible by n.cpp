#include <iostream>
 long long kth_non_divisible(long long n, long long k)
{
    // Calculate the result using a formula
    return k + (k - 1) / (n - 1);
}
 int main()
{
    // Example usage
    long long n, k, t;
    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> k;
        std::cout << kth_non_divisible(n, k) << "\n";
    }
    return 0;
}