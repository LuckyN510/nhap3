#include <bits/stdc++.h>
using namespace std;

void chuanHoa(string &s) {
    s[0] = toupper(s[0]);
    for (int i = 1; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
}

class SinhVien {
private:
    string ma, ten, ngaySinh, lop;
    double gpa;

public:
    friend istream& operator>>(istream &in, SinhVien &A) {
        in.ignore();
        getline(in, A.ma);
        getline(in, A.ten);
        stringstream ss(A.ten);
        string word;
        string tmp = "";
        while (ss >> word) {
            chuanHoa(word);
            tmp += word + " ";
        }
        tmp.pop_back(); // Remove the trailing space
        A.ten = tmp;
        getline(in, A.ngaySinh);
        if (A.ngaySinh[1] == '/') A.ngaySinh.insert(0, "0");
        if (A.ngaySinh[4] == '/') A.ngaySinh.insert(3, "0");
        getline(in, A.lop);
        in >> A.gpa;
        return in;
    }

    friend ostream& operator<<(ostream &out, const SinhVien &A) {
        return out << A.ma << " " << A.ten << " " << A.ngaySinh << " " << A.lop << " "
                   << fixed << setprecision(2) << A.gpa << endl;
    }

    string getLop() const {
        return lop;
    }

    string getTen() {
        stringstream ss(ten);
        string lastWord;
        while (ss >> lastWord); 
        return lastWord;
    }
};

bool cmp(SinhVien &A, SinhVien &B) {
    if (A.getLop() == B.getLop()) {
        return A.getTen() < B.getTen();
    }
    return A.getLop() < B.getLop();
}

int main() {
    int n;
    cin >> n;
    vector<SinhVien> ds(n);
    for (int i = 0; i < n; i++) {
        cin >> ds[i];
    }
    sort(ds.begin(), ds.end(), cmp);
    for (const auto &sv : ds) {
        cout << sv;
    }
    return 0;
}
