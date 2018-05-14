#include "components.h"
using namespace std;

/* member function of the base class component */
component::component(){
  impedance=complex<double>(0,0);
  frequency=0;
};

string component::getname(){
  return name;
}

double component::getf(){
  return frequency;
};

double component::getmagnitude(){
  return abs(impedance);
};//get magnitude of impedance

double component::getphase(){
  return arg(impedance);
};//get phase difference of impedance

complex<double> component::getimpedance(){
  return impedance;
};//get impedance


/*memberfunction of resistor class*/
resistor::resistor(double r){
  resistance = r;
  name = "resistor";
  setimpedance();
};//resistor constructor
resistor::resistor(double r,double f):resistance(r){
  name = "resistor";
  setimpedance();
};//resistor constructor
//~resistor(){cout << "resistor destructor called" << endl;};
double resistor::getvalue(){
  return resistance;
};
void resistor::setimpedance(){
  impedance = complex<double>(resistance,0);
};
void resistor::setvalue(double r){
  resistance=r;
  setimpedance();
};
void resistor::setr(double r){
  resistance=r;
  setimpedance();
};
void resistor::setf(double f){
  frequency=f;
  setimpedance();
};
void resistor::info(){
  cout<< "It is a resistor. It's resistance is R=" << resistance << "Omega" << endl;
};



/* member function of inductor class*/

inductor::inductor(double L):inductance(L){
  name = "inductor";
  setimpedance();
};//inductor constructor
//~inductor(){cout<< "Inductor destructor called" << endl;};
double inductor::getvalue(){
  return inductance;
};
void inductor::setimpedance(){
  impedance = complex<double>(0.0,-inductance/frequency);
};
void inductor::setvalue(double L){
  inductance=L;
  setimpedance();
};
void inductor::setl(double L){
  inductance=L;
  setimpedance();
};
void inductor::setf(double f){
  frequency=f;
  setimpedance();
};
void inductor::info(){cout << "It is a inductor. It's  inductance is L=" <<  inductance << "unit" << endl;};

/* member functions of capacitor class*/
capacitor::capacitor(double C):capacity(C){
  name = "capacitor";
  setimpedance();
};//capacitor constructor
double capacitor::getvalue(){
  return capacity;
};
void capacitor::setimpedance(){
  impedance = complex<double>(0.0,capacity*frequency);
};
void capacitor::setvalue(double c){
  capacity=c;
  setimpedance();
};

void capacitor::setc(double c){
  capacity=c;
  setimpedance();
};

void capacitor::setf(double f){
  frequency=f;
  setimpedance();
};
//~capacitor(){cout<< "Capacitor destructor called" << endl;};
void capacitor::info(){
  cout << "It is a capacitor. It's capacity is C=" << capacity << "unit" << endl;
};
