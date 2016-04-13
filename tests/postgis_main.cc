#include <iostream>
#include <stdlib.h>

#include "../src/postgis/PostgisFunctions.h"
#include "../src/geographic/GeoPolygon.h"
#include "../src/geographic/GeoPoint.h"
#include "../src/postgis/entity/Municipio.h"

int main(int argc, char **argv){
   //Area cercana a la CDMX
   GeoPoint p1(16.45,-93.04);
   GeoPoint p2(16.11,-92.60);
   
   
   std::cout << std::endl << "******************************" << std::endl;
   GeoPolygon bounds = PostgisFunctions::getBounds(p1, p2);
   
   // getBounds test
   std::cout << "PostgisFunctions::getBounds(p1, p2) = "<< bounds.getText() << std::endl << std::endl;
   
   
   std::vector<Municipio> results = PostgisFunctions::getMunicipiosContained(bounds);
   Municipio municipio;
   while( !results.empty() ){
      municipio = results.back();
      
      std::cout << "Localidad: " << municipio.getLocalidad() << endl;
      
      municipio.setId("id_landsat_scene");
      municipio.setDateAcquired("2015-05-10");
      municipio.setSceneCenterTime("16:59:04.4259340Z");
      municipio.setPorcentajeContaminacion(0.73213213);
      municipio.setporcentajeVegetacion(0.13123123);
      municipio.setCalidad(0.13123123);
      municipio.setNubosidad(0.13123123);
      
      PostgisFunctions::insertMunicipio(municipio);
      
      results.pop_back();
   }

   system("node scripts/mongoTransition.js");
   return 0;
}
