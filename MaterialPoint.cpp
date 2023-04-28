#include "MaterialPoint.h"
#define k 8.987E9
#define G 6.67E-11

MaterialPoint::MaterialPoint(double mass, double charge, const Position& p) : Particle(mass, charge) , Position(p.GetX(),p.GetY(),p.GetZ()) {}
MaterialPoint::MaterialPoint(const Particle& p , const Position& q) : Particle(p.GetMass(),p.GetCharge()) , Position(q.GetX(),q.GetY(),q.GetZ()) {}
MaterialPoint::MaterialPoint(double mass, double charge, double x, double y, double z) : Particle (mass, charge) , Position(x,y,z) {}
MaterialPoint::~MaterialPoint () {}

VectorField MaterialPoint::ElectricField(const Position &p) const {
    double Fx = k* GetCharge()*(GetX() - p.GetX()) / pow (p.Distance(GetX(),GetY(),GetZ()),3) ;
    double Fy = k* GetCharge()*(GetY() - p.GetY()) / pow (p.Distance(GetX(),GetY(),GetZ()),3) ;
    double Fz = k* GetCharge()*(GetZ() - p.GetZ()) / pow (p.Distance(GetX(),GetY(),GetZ()),3) ;
    VectorField E = VectorField (p,Fx,Fy,Fz);
    return E;
}

VectorField MaterialPoint::GravitationalField(const Position &p) const {
   long double Fx = G* GetMass()*(GetX() - p.GetX()) / pow (p.Distance(GetX(),GetY(),GetZ()),3) ;
   long double Fy = G* GetMass()*(GetY() - p.GetY()) / pow (p.Distance(GetX(),GetY(),GetZ()),3) ;
   long double Fz = G* GetMass()*(GetZ() - p.GetZ()) / pow (p.Distance(GetX(),GetY(),GetZ()),3) ;
    VectorField g = VectorField (p,Fx,Fy,Fz);
    return g;
}

