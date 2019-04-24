#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

class Point {
	int x , y ;
	public:
	Point ( int xx =0 , int yy =0) { x = xx ; y = yy ;}
	int getX () const { return x ;}
	int getY () const { return y ;}
	void setX ( const int xx ) { x = xx ;}
	void setY ( const int yy ) { y = yy ;}};

class PointArray{
	private:
		int size;
		Point* points;
	public:
		PointArray();
		PointArray(const Point[],const int);
		PointArray(const PointArray&);
		~PointArray();
		void resize ( int );
		void clear ();
		void push_back ( const Point & );
		void insert ( const int , const Point & p );
		void remove ( const int );
		Point * get ( const int );
		const Point * get ( const int ) const;
		int getSize();
};

PointArray :: PointArray () {
	size = 0;
	points = new Point [0]; // Allows deleting later
}
PointArray :: PointArray ( const Point ptsToCopy [] , const int toCopySize) {
	size = toCopySize ;
	points = new Point [ toCopySize ];
	for ( int i = 0; i < toCopySize ; ++ i ) {
		points [ i ] = ptsToCopy [ i ];}}

PointArray :: PointArray ( const PointArray &other) {
	// Any code in the PointArray class has access to
	// private variables like size and points
	size = other.size ;
	points = new Point [ size ];
	for ( int i = 0; i < size ; i ++) {
		points [ i ] = other . points [ i ];}}

PointArray ::~ PointArray () {
	delete [] points ; }

void PointArray :: resize ( int newSize ) {
	Point * pts = new Point [ newSize ];
	int minSize = ( newSize > size ? size : newSize ) ;
	for ( int i = 0; i < minSize ; i ++)
		pts [ i ] = points [ i ];
	delete [] points ;
	size = newSize ;
	points = pts ;}

int PointArray::getSize(){
	return size;
}

void PointArray :: clear () {
	resize (0) ;
}

void PointArray :: push_back ( const Point & p ) {
	resize ( size + 1) ;
	points [ size - 1] = p ;
// Could also just use insert ( size , p ) ;
}
void PointArray :: insert ( const int pos , const Point & p ) {
	resize ( size + 1) ;
	for ( int i = size - 1; i > pos ; i--) {
		points [ i ] = points [i -1];
	}
	points [ pos ] = p ;}

void PointArray :: remove ( const int pos ) {
	if ( pos >= 0 && pos < size ) { // pos < size implies size > 0
	// Shift everything over to the left
	for ( int i = pos ; i < size - 2; i ++) {
		points [ i ] = points [ i + 1]; }
	resize ( size - 1) ;}}

Point * PointArray :: get ( const int pos ) {
	return pos >= 0 && pos < size ? points + pos : NULL ;
}

const Point * PointArray :: get ( const int pos ) const {
	return pos >= 0 && pos < size ? points + pos : NULL ;
}

class Polygon {
	protected :
		static int numPolygons ;
		PointArray points ;
		static int n;
	public :
		Polygon ( const PointArray & pa ) ;
		Polygon ( const Point points [] , const int numPoints ) ;
		virtual double area () const = 0;
		static int getNumPolygons () { return numPolygons ;}
		int getNumSides () const { return points.getSize() ;}
		const PointArray * getPoints () const { return & points ;}
		~ Polygon () { --numPolygons ;}
};


class Rectangle : public Polygon {
public:
	Rectangle ( const Point &a , const Point & b ) ;
	Rectangle ( const int a , const int b , const int c , const int d ) ;
	virtual double area () const ;};

class Triangle : public Polygon {
public :
	Triangle ( const Point &a , const Point &b , const Point & c ) ;
	virtual double area () const ; };
