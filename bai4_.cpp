#include<bits/stdc++.h>

using namespace std;
#define a() a;

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

    friend istream& operator >> (istream& , SinhVien&);
    friend ostream& operator << (ostream& , const SinhVien);
};

istream& operator >> (istream& in, SinhVien &a){
    a.ma = "B23DCCN831";
    getline(in, a.name);
    in >> a.lop >> a.ngaySinh >> a.gpa;
    if(a.ngaySinh[1] == '/') a.ngaySinh.insert(0, "0");
    if(a.ngaySinh[4] == '/') a.ngaySinh.insert(3, "0");
    return in;
}

ostream& operator << (ostream& out, SinhVien a){
    out << a.ma << " " << a.name << " " << a.lop << " " << a.ngaySinh << " " << setprecision(2) << fixed << a.gpa; 
    return out;
}


int main(){
    SinhVien a();
    cin >> a;
    cout << a;
    return 0;
}