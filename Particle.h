#ifndef __Particle_h__
#define __Particle_h__

#include <iostream>

using namespace std;

class Particle {
    public: 
        Particle() ;
        Particle (double mass, double charge);
        ~Particle();

        double GetMass() const {return m_mass;}
        double GetCharge() const {return m_charge;}
        void Print() const;

    protected:
        double m_mass;
        double m_charge;
};

#endif