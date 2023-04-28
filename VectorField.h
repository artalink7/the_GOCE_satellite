#ifndef __VectorField_h__
#define __VectorField_h__

#include "Position.h"

class VectorField : public Position {

    public:
        VectorField(const Position&);
        VectorField(const Position&, double Fx, double Fy, double Fz);
        VectorField(double x, double y, double z, double Fx, double Fy, double Fz);
        VectorField(const VectorField* );
        ~VectorField();

        VectorField & operator +=(const VectorField &);
        VectorField operator+(const VectorField &) const;

        long double Modulus() {return sqrt(m_Fx*m_Fx + m_Fy*m_Fy + m_Fz*m_Fz);}

        double GetFx() const {return m_Fx;}
        double GetFy() const {return m_Fy;}
        double GetFz() const {return m_Fz;}

    private:
        double m_Fx, m_Fy, m_Fz;

};

#endif