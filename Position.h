#ifndef __Position_h__
#define __Position_h__

#include <cmath>
#include <iostream>

using namespace std;

class Position {
    public:
      Position();
      Position(double x, double y, double z);
      ~Position();

      double GetX() const {return m_x;} 
      double GetY() const {return m_y;}
      double GetZ() const {return m_z;}
      double GetPhi() const;
      double GetR() const;
      double GetTheta() const;
      double GetRho() const;
      double Distance(const Position&);
      double Distance(double x, double y, double z) const;
    
    private:
      double m_x, m_y, m_z;
};

#endif