#include "boundingBox.h"


BoundingBox::BoundingBox(Coords left_top, Coords right_bottom){
    this->left_top = left_top;
    this->right_bottom = right_bottom;
}


int BoundingBox::buildBox(){
    //Esquina superior derecha
    right_top.setLat( right_bottom.getLat() );
    right_top.setLng( left_top.getLng() );
    
    //Esquina inferior izquierda
    left_bottom.setLat( left_top.getLat() );
    left_bottom.setLng(  )
}

void BoundingBox::print(){
    left_top.print();
}