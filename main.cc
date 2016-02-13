#include <iostream>
#include <pqxx/pqxx> 

using namespace std;
using namespace pqxx;

int main(int argc, char* argv[])
{
   try{
      connection C("dbname=municipios user=postgres password=root \
      hostaddr=127.0.0.1 port=5432");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }
      C.disconnect ();
   }catch (const std::exception &e){
      cerr << e.what() << std::endl;
      return 1;
   }
}

/*#include "geographic/Coords.h"
#include "geographic/BoundingBox.h"

int main(int argc, char** argv){
    Coords left_top(0,1);
    Coords right_bottom(1,-1);
    
    BoundingBox bounds(left_top,right_bottom);
    bounds.buildBox();
    bounds.print();
}
*/