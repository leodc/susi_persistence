#include "PostgisFunctions.h"


/*
* 
* @p1 -> esquina superior izquierda
* @p2 -> esquina inferior derecha
* 
* @return
* Regresa un GeoPolygon que contiene a los dos puntos.
* Si el SRID del objeto es -1 significa que hubo un error.
* 
*/
GeoPolygon PostgisFunctions::getBounds(GeoPoint p1, GeoPoint p2){
   GeoPolygon g_polygon;
    try{
        
        /* Creamos la conexión  */
        connection C( QUERY_CONNECTION_POSTGIS );
        
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
            for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
                g_polygon.setText(c[0].as<string>());
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