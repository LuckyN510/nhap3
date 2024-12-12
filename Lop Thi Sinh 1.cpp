#include<bits/stdc++.h>

using namespace std;

class ThiSinh{
private:
	string hoTen, ngaySinh;
	double d1, d2, d3;
public:
	ThiSinh(){
	}
	
	ThiSinh(string hoTen, string ngaySinh, double d1, double d2, double d3){
		this->hoTen = hoTen;
		this->ngaySinh = ngaySinh;
		this->d1 = d1;
		this->d2 = d2;
		this->d3 = d3;
	}
	
	friend istream& operator >> (istream &in, ThiSinh &A){
		getline(in, A.hoTen);
		in >> A.ngaySinh;
		in >> A.d1 >> A.d2 >> A.d3;
		return in;
	}
	
	friend ostream& operator << (ostream &out, ThiSinh &A){
		return out << A.hoTen << " " << A.ngaySinh << " " 
		<< fixed << setprecision(1) << A.d1 + A.d2 + A.d3;
	}
};

int main(){
	ThiSinh A;
	cin >> A;
	cout << A;
}