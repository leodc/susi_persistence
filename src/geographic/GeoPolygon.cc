#include "GeoPolygon.h"


GeoPolygon::GeoPolygon(){
    srid = 0;
}

GeoPolygon::GeoPolygon(int count_vertices, int srid){
    this->count_vertices = count_vertices;
    this->srid = srid;
    
    coords = new Coords[count_vertices];
}


GeoPolygon::GeoPolygon(std::string text, int srid){
    this->text = text;
    this->srid = srid;
}
