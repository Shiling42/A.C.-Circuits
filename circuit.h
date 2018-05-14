#include<iostream>
#include<math.h>
#include<string>
#include<complex>
#include <vector>
#include "components.h"
//#include "circuit.h"
using namespace std;
#ifndef circuit_h
#define circuit_h


/* a circuit element is a two-end point circut element,
it can be either a elementary circuit or a linear-parallel composition of several circuit,
however it can still be characterized by impedance with extral internal topology structure*/
//enum circuit-type{parallel,series,single,empty};

class circuit: public component{
  protected:
    string conntype;
    vector<circuit*> sub_circuit;
    component* base_component;
  public:
    circuit();
    circuit(circuit* sub_circuit_1,circuit* sub_circuit_2, string ctype);
    circuit(circuit* sub_circuit_1);
    circuit(component* newcomponent);
    string getconntype();
    //vector<circuit*> getsubcircuits(int i);
    void delsubcircuit();
    void setimpedance();
    void setf(double);
    void info();
    void setvalue(double);
    double getvalue();
    void branchtype(vector<bool>&,int&, bool);
    void wire(vector<bool>&, int& );
    void plot(vector<bool>&,int& level);


    ~circuit(){}; //virtual Destructor
};




#endif
