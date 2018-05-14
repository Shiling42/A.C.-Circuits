#include<iostream>
#include<math.h>
#include<string>
#include<complex>
#include <vector>
#include "components.h"
#include "circuit.h"
//#include "circuit.h"
using namespace std;

#ifndef functions_h
#define functions_h



void help(string);
void construct_circuit(vector<component*> components_container, vector<circuit*> circuits_container);
void instruction_of_circuit_construction();
void get_information_components(vector<circuit*> components_container);
void get_information_circuits(vector<circuit*> circuits_container);
void get_information(vector<component*> components_container, vector<circuit*> circuits_container);
void creat_component(vector<component*>& components_container);
#endif
