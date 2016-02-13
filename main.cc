#include "geographic/Coords.h"
#include "geographic/BoundingBox.h"

int main(int argc, char** argv){
    Coords left_top(0,1);
    Coords right_bottom(1,-1);
    
    BoundingBox bounds(left_top,right_bottom);
    bounds.buildBox();
    bounds.print();
}