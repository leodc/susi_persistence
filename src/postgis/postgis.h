
#ifndef _POSTGIS_POSTGIS_H_
    #define _POSTGIS_POSTGIS_H_
    
    
    /*
    * 
    * Configuración para el acceso a postgis
    * 
    */
    #define HOST "127.0.0.1"
    #define PORT "5432"
    #define DATABASE "municipios"
    #define USER "postgres"
    #define PASSWORD "root"
    
    
    /*
    *
    * Query para la conexión a la base de datos
    * 
    */
    #define QUERY_CONNECTION_POSTGIS "dbname=" DATABASE " user=" USER " password=" PASSWORD " hostaddr=" HOST " port=" PORT
    
#endif
