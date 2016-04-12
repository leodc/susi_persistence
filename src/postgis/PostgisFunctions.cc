#include "PostgisFunctions.h"


/**
 * @bounds -> esquinas de la escena satelital
 * 
 * @return
 *  Objeto Vector con todos los objetos Municipios contenidos en la escena satelital.
 * */
std::vector<Municipio> PostgisFunctions::getMunicipiosContained(GeoPolygon bounds){
    std::vector<Municipio> results;
    
    try{
        
        /* Creamos la conexión  */
        connection C( POSTGIS_QUERY_CONNECTION );
        
        if (C.is_open()) {
            
            /*    Creamos consulta  */
            std::string sql = "SELECT ST_Envelope(ST_Intersection(";
            
            //bounds
            sql.append("ST_GeomFromText('");
            sql.append(bounds.getText());
            sql.append("',");
            sql.append(to_string(bounds.getSrid()));
            sql.append(")");
            
            //cierre
            sql.append(",geom)),cve_ent,cve_mun,nom_loc FROM municipios ");
            
            //condicion
            sql.append("WHERE NOT ST_isEmpty(ST_Intersection(");
            
            sql.append("ST_GeomFromText('");
            sql.append(bounds.getText());
            sql.append("',");
            sql.append(to_string(bounds.getSrid()));
            sql.append(")");
            
            sql.append(", geom))");
            
            /*    Creamos un objeto non-transactional    */
            nontransaction N(C);
            
            /*    Ejecutamos el query     */
            result R( N.exec(sql) );
            
            
            /*    Manejo de resultado    */
            /*    El valor del registro dentro del for esta en el array c */
            for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
                GeoPolygon polygon(c[0].as<string>(), bounds.getSrid());
                
                Municipio municipio;
                municipio.setGeometry(polygon);
                municipio.setEntidad(c[1].as<string>());
                municipio.setMunicipio(c[2].as<string>());
                municipio.setLocalidad(c[3].as<string>());
                
                results.push_back(municipio);
            }
            
            /*      Reducimos el tamaño del vector      */
            //results.shrink_to_fit();
            
            //Cerramos la conexión
            C.disconnect();
        } else {
            //No se creo la conexión
            cout << "Error en la conexión" << endl;
        }
        
    }catch (const std::exception &e){
        cerr << e.what() << std::endl;
    }
    
    return results;
}



/**
 * @table_name -> nombre de la tabla.
 * @geometry_column -> nombre de la columna geografica.
 * 
 * @return
 *  Regresa el srid de la tabla especificada
 * */
std::string PostgisFunctions::getTableSrid(std::string table_name, std::string geometry_column){
    std::string srid;
    try{
        
        /* Creamos la conexión  */
        connection C( POSTGIS_QUERY_CONNECTION );
        
        if (C.is_open()) {
            
            /*    Creamos consulta  */
            std::string sql = "SELECT Find_SRID('public',";
            
            sql.append("'");
            sql.append(table_name);
            sql.append("'");
            
            sql.append(",");
            
            sql.append("'");
            sql.append(geometry_column);
            sql.append("'");
            
            
            //cierre de la consulta
            sql.append(")");
            
            /*    Creamos un objeto non-transactional    */
            nontransaction N(C);
            
            /*    Ejecutamos el query     */
            result R( N.exec(sql) );
            
            
            /*    Manejo de resultado    */
            /*    El valor del registro dentro del for esta en el array c */
            
            if( R.size() > 0 ){
                srid = R[0][0].as<string>();
            }
            
        
            //Cerramos la conexión
            C.disconnect();
        } else {
            //No se creo la conexión
            cout << "Error en la conexión" << endl;
        }
        
    }catch (const std::exception &e){
        cerr << e.what() << std::endl;
    }
    
    return srid;
}



/*
* @p1 -> esquina superior izquierda
* @p2 -> esquina inferior derecha
* 
* @return
*   Regresa un GeoPolygon que contiene a los dos puntos.
*   Si el SRID del objeto es -1 significa que hubo un error.
*/
GeoPolygon PostgisFunctions::getBounds(GeoPoint p1, GeoPoint p2){
    GeoPolygon g_polygon;
    
    try{
        
        /* Creamos la conexión  */
        connection C( POSTGIS_QUERY_CONNECTION );
        
        if (C.is_open()) {
            
            /*    Creamos consulta  */
            std::string sql = "SELECT ST_AsText( ST_Envelope( ST_Collect(";
            
            //p1
            sql.append("ST_GeomFromText('");
            sql.append(p1.asText());
            sql.append("')");
            
            sql.append(",");
            
            //p2
            sql.append("ST_GeomFromText('");
            sql.append(p2.asText());
            sql.append("')");
            
            //cierre
            sql.append(")))");
            
            /*    Creamos un objeto non-transactional    */
            nontransaction N(C);
            
            /*    Ejecutamos el query     */
            result R( N.exec(sql) );
            
            
            /*    Manejo de resultado    */
            /*    El valor del registro dentro del for esta en el array c */
            if( R.size() > 0 ){
                g_polygon.setText(R[0][0].as<string>());
                g_polygon.setSrid(p1.getSrid());
            }
        
            //Cerramos la conexión
            C.disconnect();
        } else {
            //No se creo la conexión
            cout << "Error en la conexión" << endl;
        }
        
    }catch (const std::exception &e){
        cerr << e.what() << std::endl;
    }
    
    return g_polygon;
}


/**
 * Persistencia de la información del municipio
 * */
bool PostgisFunctions::insertMunicipio(Municipio municipio){
    
    try{
        /* Creamos la conexión  */
        connection C( POSTGIS_QUERY_CONNECTION );
        
        if( !C.is_open() ){
            return false;
        }
        
        std::string sql = "INSERT INTO transition(data,the_geom) VALUES ('";
        sql.append("{");
        
        sql.append( propertyToString("entidad", municipio.getEntidad()));
        sql.append( propertyToString("municipio", municipio.getMunicipio()));
        sql.append( propertyToString("localidad", municipio.getLocalidad()));
        
        sql.append( propertyToString("calidad", municipio.getCalidad()));
        sql.append( propertyToString("nubosidad", municipio.getNubosidad()));
        sql.append( propertyToString("vegetacion", municipio.getPorcentajeVegetacion()));
        sql.append( propertyToString("contaminacion", municipio.getPorcentajeContaminacion()));
        
        sql.append( propertyToString("scene_id", municipio.getId()));
        sql.append( propertyToString("scene_time", municipio.getDate(), true));
        
        sql.append("}");
        sql.append("','");
        sql.append(municipio.getGeometry().getText());
        sql.append("')");
        
        /* Create a transactional object. */
        work W(C);
        
        /* Execute SQL query */
        W.exec( sql );
        W.commit();
        C.disconnect ();
        
        return true;
    }catch (const std::exception &e){
        cerr << e.what() << std::endl;
        return false;
    }
}


std::string propertyToString(std::string key, std::string value, bool last){
    std::string aux = "\"";
    aux.append(key);
    aux.append("\": ");
    aux.append("\"");
    aux.append(value);
    aux.append("\"");
    
    if(!last){
        aux.append(",");
    }
    
    return aux;
}


std::string propertyToString(std::string key, float value, bool last){
    std::string value_aux = to_string(value);
    
    std::string aux = "\"";
    aux.append(key);
    aux.append("\": ");
    aux.append(value_aux);
    
    if(!last){
        aux.append(",");
    }
    
    return aux;
}
