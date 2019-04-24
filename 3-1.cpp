#include<iostream>
#include<string.h>

using namespace std;

class Point {
	int x , y ;
	public :
	Point ( int xx =0 , int yy =0) { x = xx ; y = yy ;}
	int getX () const { return x ;}
	int getY () const { return y ;}
	void setX ( const int xx ) { x = xx ;}
	void setY ( const int yy ) { y = yy ;}};

int main(){
	Point puntito(4,5);
	cout<<puntito.getX()<<endl;
	return 0;
}
