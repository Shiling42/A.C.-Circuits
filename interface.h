#include<iostream>
#include<math.h>
#include<string>
#include<complex>
#include <vector>
#include "components.h"
#include "circuit.h"
//#include "circuit.h"
using namespace std;

#ifndef interface_h
#define interface_h



//void help(string);
double cinvalue();//get postive double value
void construct_circuit(vector<component*>& components_container, vector<circuit*>& circuits_container);//construct circuit
void instruction_of_circuit_construction();
void components_modify(vector<component*>& components_container);//
void get_information_components(vector<component*> components_container);
void get_information_circuits(vector<circuit*> circuits_container);
void get_information(vector<component*> components_container, vector<circuit*> circuits_container);
void creat_component(vector<component*>& components_container);
void component_circuit_construct(vector<component*>& components_container, vector<circuit*>& circuits_container);
int get_number(int , int );
bool yes_or_no(string);
void circuit_modify(vector<component*>& components_container, vector<circuit*>& circuits_container);
void interface();
#endif
