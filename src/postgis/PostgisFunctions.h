#include <iostream>
#include <pqxx/pqxx>
#include <vector>
#include <string>

#include "postgis.h"
#include "../geographic/GeoPolygon.h"
#include "../geographic/GeoPoint.h"
#include "entity/Municipio.h"

using namespace std;
using namespace pqxx;

#ifndef _POSTGIS_POSTGIS_FUNCTIONS_H_
    #define _POSTGIS_POSTGIS_FUNCTIONS_H_
    
    std::string propertyToString(std::string, std::string, bool last = false);
    std::string propertyToString(std::string, float, bool last = false);
    
    class PostgisFunctions{
        public:
            static GeoPolygon getBounds(GeoPoint, GeoPoint);
            static std::vector<Municipio> getMunicipiosContained(GeoPolygon);
            static std::string getTableSrid(std::string, std::string geometry_column = "geom");
            static bool insertMunicipio(Municipio);
    };
#endif