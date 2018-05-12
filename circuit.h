#include<iostream>
#include<math.h>
#include<string>
#include<complex>
#include <vector>
//#include "component.h"
using namespace std;
#ifndef circuit_h
#define circuit_h


/* a circuit element is a two-end point circut element,
it can be either a elementary component or a linear-parallel composition of several component,
however it can still be characterized by impedance with extral internal topology structure*/

class circuit: public component{
  protected:
    vector<*circuit> sub_circut[2];
    type conntype
  public:
    void setimpedance();
    void setf(double);
    void info();
    void setvalue(double);
    double getvalue();
    ~component(){}; //virtual Destructor
};



#endif
