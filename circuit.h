#include<iostream>
#include<math.h>
#include<string>
#include<complex>
#include <vector>
#include "components.h"
//#include "component.h"
using namespace std;
#ifndef circuit_h
#define circuit_h


/* a circuit element is a two-end point circut element,
it can be either a elementary component or a linear-parallel composition of several component,
however it can still be characterized by impedance with extral internal topology structure*/
//enum circuit-type{parallel,series,single,empty};

class circuit: public component{
  protected:
    vector<component*> sub_circuit;
    string conntype;
  public:
    circuit();
    circuit(component* sub_circuit_1,component* sub_circuit_2, string ctype);
    circuit(component* sub_circuit_1);
    void setimpedance();
    void setf(double);
    void info();
    void setvalue(double);
    double getvalue();
    ~circuit(){}; //virtual Destructor
};



#endif
