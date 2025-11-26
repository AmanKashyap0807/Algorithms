#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> dpCreat(int N, int W, vector<int> &wt, vector<long long> &val)
{
    vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (wt[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else if (wt[i] == j)
            {
                dp[i][j] = max(val[i], dp[i - 1][j]);
            }
            else if (wt[i] < j)
            {
                dp[i][j] = max(dp[i - 1][j], val[i] + dp[i - 1][j - wt[i]]);
            }
        }
    }
    return dp;
}

long long ans(vector<vector<long long>> &dp, int N, int W)
{
    return dp[N][W];
}

int main()
{
    int N;
    cin >> N;
    int W;
    cin >> W;
    vector<int> wt;
    vector<long long> val;
    wt.push_back(0);
    val.push_back(0);
    for (int i = 0; i < N; i++)
    {
        int w;
        cin >> w;
        wt.push_back(w);
        long long v;
        cin >> v;
        val.push_back(v);
    }
    vector<vector<long long>> dp = dpCreat(N, W, wt, val);
    cout << ans(dp, N, W);
    return 0;
}