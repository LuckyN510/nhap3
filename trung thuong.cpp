#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.first > b.first;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        vector<pair<int, int>> v;
        for (auto& x : freq) {
            v.push_back({x.first, x.second});
        }
        sort(v.begin(), v.end(), cmp);
        cout << v[0].first << endl;
    }
    return 0;
}
