#include<bits/stdc++.h>

using namespace std;
#define a() a;

void chuanHoa(string &s){
    s[0] = toupper(s[0]);
    for(int i = 1; i < s.length(); i++){
        s[i] = tolower(s[i]);
    }
}


class SinhVien{
private:
    string name, ma, ngaySinh, lop;
    double gpa;
public:
    SinhVien(){
        this->name = this->lop = this->ngaySinh = "";
        this->gpa = 0;
    }

    SinhVien(string name, string lop, string ngaySinh, double gpa){
        this->name = name;
        this->lop = lop;
        this->ngaySinh = ngaySinh;
        this->gpa = gpa;
    }
    bool cmp(SinhVien a, SinhVien b){
        return a.gpa > b.gpa;
    }

    friend istream& operator >> (istream& , SinhVien&);
    friend ostream& operator << (ostream& , const SinhVien);

    double getGpa(){
        return gpa;
    }

    void setGpa(double gpa){
       this->gpa = gpa;
    }

};

int cnt = 0;

istream& operator >> (istream& in, SinhVien &a){
    ++cnt;
    if(cnt < 10) a.ma = "B23DCCN00" + to_string(cnt);
    else a.ma = "B23DCCN0" + to_string(cnt);
    scanf("\n");
    getline(in, a.name);
    in >> a.lop >> a.ngaySinh >> a.gpa;
    if(a.ngaySinh[1] == '/') a.ngaySinh.insert(0, "0");
    if(a.ngaySinh[4] == '/') a.ngaySinh.insert(3, "0");
    stringstream ss(a.name);
    string word;
    string s = "";
    while(ss >> word){
        chuanHoa(word);
        s += word + " ";
    }
    a.name = s;
    return in;
}

ostream& operator << (ostream& out, SinhVien a){
    out << a.ma << " " << a.name << " " << a.lop << " " << a.ngaySinh << " " << setprecision(2) << fixed << a.gpa << endl; 
    return out;
}

bool cmp(SinhVien a, SinhVien b){
    return a.getGpa() > b.getGpa();
}

int main(){
    int n; cin >> n;
    SinhVien a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    a[0].setGpa(4.5);
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
}