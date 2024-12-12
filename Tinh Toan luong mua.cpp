#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

class Rain {
private:
    string ma, ten, st, ed;
    int luongMua;
public:
    Rain() {}

    Rain(string ten, string st, string ed, int luongMua) {
        this->ten = ten;
        this->st = st;
        this->ed = ed;
        this->luongMua = luongMua;
    }

    friend istream& operator>>(istream &in, Rain &A) {
        ++cnt;
        in.ignore();
        getline(in, A.ten);
        in >> A.st >> A.ed >> A.luongMua;
        if (cnt < 10) A.ma = "T0" + to_string(cnt);
        else A.ma = "T" + to_string(cnt);
        return in;
    }

    string getTen() {
        return ten;
    }

    double getTime() {
        int startMinutes = stoi(st.substr(0, 2)) * 60 + stoi(st.substr(3));
        int endMinutes = stoi(ed.substr(0, 2)) * 60 + stoi(ed.substr(3));
        return endMinutes - startMinutes;
    }

    double getLuongMua() {
        return luongMua;
    }
};

int main() {
    int n;
    cin >> n;
    Rain A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    unordered_map<string, pair<double, double>> mp; 
    vector<string> order; 
    for (int i = 0; i < n; i++) {
        string ten = A[i].getTen();
        double luongMua = A[i].getLuongMua();
        double thoiGian = A[i].getTime();
        if (mp.find(ten) == mp.end()) {
            order.push_back(ten); 
        }
        mp[ten].first += luongMua;    
        mp[ten].second += thoiGian; 
    }
    for (string ten : order) {
        double tongLuongMua = mp[ten].first;
        double tongThoiGian = mp[ten].second;
        double luongMuaTB = tongLuongMua * 60 / tongThoiGian;
        cout << ten << " " << fixed << setprecision(2) << luongMuaTB << endl;
    }

    return 0;
}
