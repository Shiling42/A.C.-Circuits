#include "circuit.h"
using namespace std;

void circuit::setimpedance(){
    if(conntype=="series") {
      sub_circuit[0]->setf(frequency);
      sub_circuit[1]->setf(frequency);
      impedance = sub_circuit[0]->getimpedance()+sub_circuit[1]->getimpedance();
    }
    else if(conntype=="parallel"){
      sub_circuit[0]->setf(frequency);
      sub_circuit[1]->setf(frequency);
      impedance = complex<double>(1.0,0.0)/(complex<double>(1.0,0.0)/(sub_circuit[0]->getimpedance()+complex<double>(e,e))+complex<double>(1.0,0.0)/(sub_circuit[1]->getimpedance()+complex<double>(e,e))+complex<double>(e,e));
      if (abs(impedance.real()) <THRESHOLD) impedance.real(0.0);
      if (abs(impedance.imag()) < THRESHOLD) impedance.imag(0.0);
      //if (std::abs(number) < THRESHOLD) number = 0;
    }else if(conntype=="empty"){
      impedance = complex<double>(0.0,0.0);
    }else if(conntype=="single"){
      sub_circuit[0]->setf(frequency);
      impedance = sub_circuit[0]->getimpedance();
    }else{
      cout << "wrong connection type" <<endl;}
};
//set the frequency of the circuit and update the impedance accordingly
void circuit::setf(double f){
  frequency=f;
  setimpedance();
};
void circuit::info(){cout << "impedance = " << impedance << ", frequency ="<< frequency <<endl; };
void circuit::setvalue(double value){};
double circuit::getvalue(){};
// default constructor
circuit::circuit(){
  conntype = "empty";
  setimpedance();
};
// default constructor

circuit::circuit(component* sub_circuit_1,component* sub_circuit_2, string ctype){
  sub_circuit.push_back(sub_circuit_1);
  sub_circuit.push_back(sub_circuit_2);
  conntype = ctype;
  setimpedance();
};

circuit::circuit(component* sub_circuit_1){
  sub_circuit.push_back(sub_circuit_1);
  conntype = "single";
  setimpedance();
};
