#include "VectorField.h"

VectorField::VectorField(const Position &p) :Position (p.GetX(),p.GetY(),p.GetZ()) {
    m_Fx=0.;
    m_Fy=0.;
    m_Fz=0.;
}

VectorField::VectorField(const Position &p, double Fx, double Fy, double Fz) :Position (p.GetX(),p.GetY(),p.GetZ()) {
    m_Fx= Fx;
    m_Fy= Fy;
    m_Fz= Fz;
}

VectorField::VectorField(double x, double y, double z, double Fx, double Fy, double Fz){
    m_Fx= Fx;
    m_Fy= Fy;
    m_Fz= Fz;
}

VectorField::VectorField(const VectorField* E) {
m_Fx= E->GetFx();
m_Fy= E->GetFy();
m_Fz= E->GetFz();
}

VectorField::~VectorField(){

}

VectorField VectorField::operator+(const VectorField &v) const {
    VectorField sum(v);
    sum.m_Fx += GetFx();
    sum.m_Fy += GetFy();
    sum.m_Fz += GetFz();
    return sum;
}

VectorField & VectorField::operator +=(const VectorField &v){
    return (*this) = (*this)+v;
}