#include "Position.h"
#include <cmath>

Position::Position() {
    m_x = 0;
    m_y = 0;
    m_z = 0;
}

Position::Position(double x, double y, double z){
    m_x = x;
    m_y = y;
    m_z = z;
}

Position::~Position(){

}

double Position::GetPhi() const {
    return acos(m_x / sqrt(m_x*m_x + m_y*m_y));
}

double Position::GetTheta() const {
    return acos(m_z / GetR());
}

double Position::GetR() const {
    return sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
}

double Position::Distance(const Position& P) {
    return sqrt( pow(m_x-P.GetX(),2) + pow(m_y-P.GetY(),2) + pow(m_z-P.GetZ(),2) );
}

double Position::Distance(double x, double y, double z) const{
return sqrt( pow(GetX() - x,2) + pow(GetY() - y,2) + pow(GetZ() - z,2) ) ;
}

double Position::GetRho() const{
    return sqrt(m_x*m_x + m_y*m_y );
}