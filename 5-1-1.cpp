#include<iostream>
#include<string.h>
#include "5-1-1.h"

using namespace std;

int Polygon :: n = 0;

Polygon :: Polygon ( const PointArray & pa ) : points ( pa ) {
++ numPolygons ;}

Polygon :: Polygon ( const Point pointArr [] , const int numPoints ) :
	points ( pointArr , numPoints ) { ++ numPolygons ;}

int main(){

	return 0;
}
