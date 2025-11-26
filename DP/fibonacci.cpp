#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return dp[n];
}

int main()
{
    vector<int> dp(100, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < 100; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int n;
    cin >> n;
    cout << fibonacci(n, dp) << endl;
    return 0;
}