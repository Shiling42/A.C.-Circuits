#include<iostream>
#include<math.h>
#include<string>
#include<complex>
#include <vector>
using namespace std;
#include "components.h"
#include "circuit.h"
#include "circuitconstruction.h"
/* The circuit is represented by a tree structure */


int main(){
/*
    component *shape_array[7];
    shape_array[0] = new capacitor(1.2);
    shape_array[1] = new capacitor(2);
    cout << shape_array[0]->getname()<<endl;
    shape_array[2] = new inductor(3);
    circuit *circuit_array[6];
    cout.precision(1);
    circuit_array[2] = new circuit(shape_array[0]);
    circuit_array[1] = new circuit(shape_array[2]);
    circuit_array[2] -> setf(4);
    circuit_array[3] = new circuit(circuit_array[1],circuit_array[2],"parallel");
    cout<< shape_array[1] -> getimpedance() <<endl;
    circuit_array[3] -> setf(2);
    circuit_array[4] = new circuit(circuit_array[3],circuit_array[3],"series");
    circuit_array[5] = new circuit(circuit_array[3]);
    circuit_array[6] = new circuit(circuit_array[5],circuit_array[3],"parallel");
    circuit_array[5]->info();
    circuit_array[4]->info();
    circuit_array[6]->info();
    //circuit_array[3] -> delsubcircuit();
    //int label[4] = (0,0,0,0);
    //shape_array[4] = shape_array[3]->getsubcircuit(0);
    //int d = 0;
    //plot(shape_array[3], d);
    for(int i=0;i<1;i++){
        shape_array[i] -> setf(5);
        shape_array[i] -> setvalue(10);
        shape_array[i] -> info();
        double frequency=shape_array[i]->getf();
        cout << shape_array[i]->getf() <<endl;
        shape_array[i]->setimpedance();
        cout << shape_array[i]->getimpedance()<<endl;
        cout << shape_array[i]->getphase()<<endl;
        cout << shape_array[i]->getmagnitude()<<endl;
    }*/
    do{
      cout << "Now you are going to creat you own cirucit" << endl;
      cin.clear();
      circuit* usercircuit;
      vector<circuit*> circuits_container;
      vector<component*> components_container;
      do{
      cout << "Creat your own circuit" <<endl;
      int choice=0;
      cout<< "===============0================"<<endl;
      cout << "What do you want to do now:\n";
      cout<< "1: Creat components to use later\n";
      cout<< "2: Creat a circuit\n";
      cout<< "3: Check stored components/circuits\n";
      cout<< "4: Show circuit information\n";
      cout<< "5: Set circuit parameter\n";
      cout<< "6: show all components created\n";
      cout<< "================================"<<endl;
      cout<< "input the number to choose:";
      cin>>choice;
      switch(choice){
        case 1: {
          bool repeat(true);
          do{
            int component_choice=0;
            double value;
            cout<< "===============0-1================="<<endl;
            cout << "Input the type of components you wanat to add:\n";
            cout << "1: resistor\n";
            cout << "2: capacitor\n";
            cout << "3: inductor\n";
            cout<< "================================"<<endl;
            cout << "Your choice(input the number):";
            cin >> component_choice;
            switch(component_choice){
              case 1:{
                cout << "input the resistance in Omega:";
                cin >> value;
                components_container.push_back(new resistor(value));
                cout << "You just created an resistor,";
                cout << " stored in component_container["<< components_container.size()-1<<"] component" <<endl;
                break;
              }
              case 2:{
                cout << "input the capacity:";
                cin>>value;
                components_container.push_back(new capacitor(value));
                cout << "You just created an capacitor, ";
                cout << "stored in component_container["<< components_container.size()-1<<"] component" <<endl;
                break;
              }
              case 3:{
                cout << "input the inductance:";
                cin >> value;
                components_container.push_back(new inductor(value));
                cout << "You just created an inductor, ";
                cout << "stored in component_container["<< components_container.size()-1<<"] component" <<endl;
                break;
              }
              default:{cout << "Wrong input" << endl;};
            }
            char input;
            do{
              cout <<"Do you want to continue creating components? y/n"<<endl;
              cin >> input;
            }while(input != 'y' && input!='n');
            repeat = (input=='y');
          }while(repeat);
            break;
        }
        case 2: {}
        case 3: {
          bool repeat(true);
          do{
            int circuit_or_component;
            do{
              cout <<"Visit stored ciruits or components? 1:components ;2:circuits"<<endl;
              cin >> circuit_or_component;
            }while(circuit_or_component != 1 && circuit_or_component!= 2);
            if(circuit_or_component == 1){
              cout << "Here are "<< components_container.size() << " compinents stored"<<endl;
              cout << "Which one do you want to check? input 1~"<<components_container.size()<<endl;
              int component_label=0;
              cin >> component_label;
              if( component_label>components_container.size()){
                components_container[component_label-1]->info();
              }else{cout<<"No such a component."<<endl;}
            }else{
              cout << "Here are "<< circuits_container.size() << "circuits stored"<<endl;
              cout << "Which one do you want to check? input 1~"<< circuits_container.size()<<endl;
              int circuit_label=0;
              cin >> circuit_label;
              if( circuit_label>circuits_container.size()){
                circuits_container[circuit_label-1]->info();
              }else{cout<<"No such a circuit."<<endl;}
            }
            char input;
            do{
              cout <<"Do you want to continue checking? y/n"<<endl;
              cin >> input;
            }while(input != 'y' && input!='n');
            repeat = (input=='y');
          }while(repeat);
          break;
        }
        default: cout<<"*Wrong input."<<endl;
        }
      } while(true);
    } while(true);
    return 0;
}
