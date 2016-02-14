#include <iostream>

#include "../src/postgis/PostgisFunctions.h"
#include "../src/geographic/GeoPolygon.h"
#include "../src/geographic/GeoPoint.h"

int main(int argc, char **argv){
   GeoPoint p1(3,4);
   GeoPoint p2(5,8);
   
   
   GeoPolygon bounds = PostgisFunctions::getBounds(p1, p2);
   std::cout << "PostgisFunctions::getBounds(p1, p2) = "<< bounds.getText() << std::endl;
   
   return 0;
}