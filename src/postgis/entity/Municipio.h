#include <string>

#include "../../geographic/GeoPolygon.h"

#ifndef _POSTGIS_ENTITY_MUNICIPIO_H_
    
    #define _POSTGIS_ENTITY_MUNICIPIO_H_
    
    class Municipio{
        
        GeoPolygon geometry;
        
        std::string id;
        long date; //epoch time
        
        /**
         * properties
         * */
        float porcentajeContaminacion;
        float porcentajeVegetacion;
        float calidad;
        float nubosidad;
        
        std::string entidad;
        std::string municipio;
        std::string localidad;
        
        public:
            void setId(std::string id){
                this->id = id;
            }
            void setDate(long date){
                this->date = date;
            }
            void setPorcentajeContaminacion(float porcentajeContaminacion){
                this->porcentajeContaminacion = porcentajeContaminacion;
            }
            void setporcentajeVegetacion(float porcentajeVegetacion){
                this->porcentajeVegetacion = porcentajeVegetacion;
            }
            void setCalidad(float calidad){
                this->calidad = calidad;
            }
            void setNubosidad(float nubosidad){
                this->nubosidad = nubosidad;
            }
            void setGeometry(GeoPolygon geometry){
                this->geometry = geometry;
            }
            void setEntidad(std::string entidad){
                this->entidad = entidad;
            }
            void setMunicipio(std::string municipio){
                this->municipio = municipio;
            }
            void setLocalidad(std::string localidad){
                this->localidad = localidad;
            }
            
            float getPorcentajeContaminacion(){
                return porcentajeContaminacion;
            }
            float getPorcentajeVegetacion(){
                return porcentajeVegetacion;
            }
            float getCalidad(){
                return calidad;
            }
            float getNubosidad(){
                return nubosidad;
            }
            GeoPolygon getGeometry(){
                return geometry;
            }
            std::string getEntidad(){
                return entidad;
            }
            std::string getMunicipio(){
                return municipio;
            }
            std::string getLocalidad(){
                return localidad;
            }
            std::string getId(){
                return id;
            }
            long getDate(){
                return date;
            }
    };
    
#endif