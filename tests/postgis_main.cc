#include <iostream>

#include "../src/postgis/PostgisFunctions.h"
#include "../src/geographic/GeoPolygon.h"
#include "../src/geographic/GeoPoint.h"

int main(int argc, char **argv){
   //Area cercana a la CDMX
   GeoPoint p1(16.45,-93.04);
   GeoPoint p2(16.11,-92.60);
   
   
   std::cout << std::endl << "******************************" << std::endl;
   GeoPolygon bounds = PostgisFunctions::getBounds(p1, p2);
   
   /*
   *  GETBOUNDS
   */
   std::cout << "PostgisFunctions::getBounds(p1, p2) = "<< bounds.getText() << std::endl << std::endl;
   
   
   /*
   *  GETPOLYGONSCONTAINED
   */
   std::cout << "PostgisFunctions::getPolygonsContained(bounds) = " << std::endl;
   
   std::vector<GeoPolygon> results = PostgisFunctions::getPolygonsContained(bounds);
   
   GeoPolygon polygon;
   while( !results.empty() ){
      polygon = results.back();
      std::cout << polygon.getText() << std::endl;
      
      
      results.pop_back();
   }
   
   return 0;
}