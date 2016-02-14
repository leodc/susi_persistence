#include <iostream>
#include <string>
#include <sstream>
#include "Coords.h"


#ifndef _GEOGRAPHIC_GEO_POINT_H_
    #define _GEOGRAPHIC_GEO_POINT_H_
    
    std::string doubleToString(double);

    class GeoPoint{
        Coords coords;
        int srid;
        
        public:
            GeoPoint(Coords, int srid=4326);
            GeoPoint(double, double, int srid=4326);
            std::string asText();
            
            void setCoords(Coords coords){
                this->coords=coords;
            }
            
            Coords getCoords(){
                return coords;
            }
    };

#endif