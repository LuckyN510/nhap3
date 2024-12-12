#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int a[1001][1001], b[1001][1001];
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void loang(int i, int j, int &sum)
{
    int cnt = 0;
    a[i][j] = 0;
    for (int k = 0; k < 4; ++k)
    {
        int i1 = i + dx[k], j1 = j + dy[k];
        if (i1 >= 0 && j1 >= 0 && j1 < m && i1 < n && b[i1][j1] == 1)
        {
            ++cnt;
        }
        // cout << cnt << endl;
    }
    sum += 4 - cnt;
    for (int k = 0; k < 4; ++k)
    {
        int i1 = i + dx[k], j1 = j + dy[k];
        if (i1 >= 0 && j1 >= 0 && j1 < m && i1 < n && a[i1][j1] == 1)
        {
            loang(i1, j1, sum);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }
    int max_ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j])
            {
                int sum = 0;
                loang(i, j, sum);
                max_ans = max(max_ans, sum);
            }
        }
    }
    cout << max_ans;
    return 0;
}
