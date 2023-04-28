#ifndef __MaterialPoint_h__
#define __MaterialPoint_h__

#include "Particle.h"
#include "Position.h"
#include "VectorField.h"
#include <cmath>

class MaterialPoint : public Particle, public Position {
    public:

        MaterialPoint(double mass, double charge, const Position &);
        MaterialPoint(const Particle &, const Position&);
        MaterialPoint(double mass, double charge, double x, double y, double z);
        ~MaterialPoint();

        VectorField ElectricField(const Position&) const;
        VectorField GravitationalField(const Position&) const;

    
};

#endif