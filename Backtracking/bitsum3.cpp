#include <iostream>
#include <vector>
using namespace std;

// for &s accepting para we will have to manually do s.pop_back() after returning from function call
// for string s accepting para we will not have to do s.pop_back() after returning from function call
void solve(int n, int sum, int bitn, string s, vector<string> &ans)
{
    if (bitn == n)
    {
        if (sum >= 4)
        {
            ans.push_back(s);
            return;
        }
        else
        {
            return;
        }
    }

    // 0 bit choice
    solve(n, sum, bitn + 1, s + '0', ans);

    // 1 bit choice
    solve(n, ++sum, bitn + 1, s + '1', ans);
}

int main()
{
    int n = 4;
    int sum = 0;
    int bitn = 0;
    string s = "";
    vector<string> ans;
    solve(n, sum, bitn, s, ans);
    // print ans
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}