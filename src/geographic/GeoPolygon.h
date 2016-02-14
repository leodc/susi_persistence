#include <iostream>
#include <string>
#include "Coords.h"


#ifndef _GEOGRAPHIC_GEO_POLYGON_H_
    #define _GEOGRAPHIC_GEO_POLYGON_H_

    class GeoPolygon{
        Coords *coords;
        
        int srid;
        int count_vertices;
        
        std::string text;
        
        public:
            GeoPolygon();
            GeoPolygon(int, int srid = 4326);
            GeoPolygon(std::string, int srid = 4326);
            
            Coords * getCoords(){
                return coords;
            }
            
            void setSrid(int srid){
                this->srid = srid;
            }
            
            int getSrid(){
                return srid;
            }
            
            void setText(std::string text){
                this->text = text;
            }
            
            std::string getText(){
                return text;
            }
    };

#endif