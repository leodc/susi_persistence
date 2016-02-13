#include <iostream>
#include "Coords.h"

#ifndef _GEOGRAPHIC_BOUNDINGBOX_H_
    #define _GEOGRAPHIC_BOUNDINGBOX_H_
    
    
    class BoundingBox{
        Coords left_top, right_top, right_bottom, left_bottom;
        
        public:
            BoundingBox(Coords,Coords);
            void print();
            int buildBox();
    };
#endif