#include "Particle.h"

Particle::Particle() {
    m_mass = 0.;
    m_charge = 0.;
}

Particle::Particle(double mass, double charge) {
    m_mass = mass;
    m_charge = charge;
}

Particle::~Particle(){

}

void Particle::Print() const {
    cout<<" The mass of the particle is: "<<GetMass();
    cout<<" The charge of the particle is: "<<GetCharge()<<endl;
}