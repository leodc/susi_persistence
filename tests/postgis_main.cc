#include <iostream>

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
   
   
   // getMunicipiosContained test
   std::cout << "PostgisFunctions::getPolygonsContained(bounds) = " << std::endl;
   
   
   std::vector<Municipio> results = PostgisFunctions::getMunicipiosContained(bounds);
   Municipio municipio;
   while( !results.empty() ){
      municipio = results.back();
      
      std::cout << "Entidad: " << municipio.getEntidad() << "     ";
      std::cout << "Municipio: " << municipio.getMunicipio() << "    ";
      std::cout << "Localidad: " << municipio.getLocalidad() << "    ";
      std::cout << "Geometria: " << municipio.getGeometry().getText() << std::endl;
      
      municipio.setId("id_landsat_scene");
      municipio.setDate(1460434359L);
      municipio.setPorcentajeContaminacion(0.73213213);
      municipio.setporcentajeVegetacion(0.13123123);
      municipio.setCalidad(0.13123123);
      municipio.setNubosidad(0.13123123);
      
      
      if( PostgisFunctions::insertMunicipio(municipio) ){
         std::cout << "Guardado correctamente" << std::endl;
      }
      
      results.pop_back();
   }
   
   return 0;
}
