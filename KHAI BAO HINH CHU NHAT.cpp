#include<bits/stdc++.h>

using namespace std;

class Rectangle{
private:
	double width, height;
	string color;
public:
	Rectangle(){
		width = 1;
		height = 1;
	}
	Rectangle(double width, double height, string color){
		this->width = width;
		this->height = height;
		this->color = color;
	}
	double getWidth(){
		return width;
	}
	
	double getHeight(){
		return height;
	}
	
	string getColor(){
		return color;
	}
	void setColor(string color){
		this->color = color;
	}
	
	double findArea(){
		return this->width * this->height;
	}
	
	double findPerimeter(){
		return (this->width + this->height) * 2;
	}
	 friend istream& operator >> (istream &in, Rectangle &A){
        return in >> A.width >> A.height >> A.color;
    }
	
};



int main(){
	// double x, y;
	// string z;
	// cin >> x >> y >> z;
	// z[0] = toupper(z[0]);
    // for (int i = 1; i < z.length(); i++) {
    //     z[i] = tolower(z[i]);
    // }
	// Rectangle A(x, y, z);
	Rectangle A;
	cin >> A;
	string z = A.getColor();
	z[0] = toupper(z[0]);
    for (int i = 1; i < z.length(); i++) {
        z[i] = tolower(z[i]);
    }
	A.setColor(z);
	if(A.getWidth() > 0 && A.getHeight() > 0){
		cout << A.findArea() << " " << A.findPerimeter() << " " << A.getColor();
	}
	else{
		cout << "INVALID\n";
	}
}