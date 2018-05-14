#include<iostream>
#include<math.h>
#include<string>
#include<complex>
#include <vector>
using namespace std;
#include "components.h"
#include "circuit.h"
#include "functions.h"
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
    cout << "Now you are going to creat you own cirucit" << endl;
    do{

      cin.clear();
      circuit* usercircuit;
      vector<circuit*> circuits_container;

      vector<component*> components_container;

      do{
      cout << "Creat your own circuit" <<endl;
      int choice=0;
      cout<< "===============0================"<<endl;
      cout << "What do you want to do now:\n";
      cout<< "1: Creat components\n";
      cout<< "2: Creat circuits\n";
      cout<< "3: Show stored components/circuits\n";
      cout<< "4: Modify existing circuits\n";
      cout<< "5: Modifying existnig circuits\n";
      cout<< "================================"<<endl;
      cout<< "input the number to choose:";
      cin>>choice;
      switch(choice){
        case 1: {
            creat_component(components_container);
            break;
        }
        case 2: {
          bool repeat(true);
          do{
            cout << "You are going to construct a circuit"<<endl;
            cout << "To read the instruction on how to creat a circuit, input \"y\", ";
            cout << "any other key to skip"<<endl;
            char read = 'n';
            cin >> read;
            if (read=='y'){
              instruction_of_circuit_construction();
            }
            char input;
            do{//creat circuits
              if(circuits_container.size()==0){
                cout << "There is not any circuit created, at least one \"component\" circuit is needed "<<endl;
                int first_circuit;
                do{
                  cout<<"Input the type of first component circuit (1: resistor; 2: capacitor; 3: inductor):" <<endl;
                  cin >> first_circuit;
                }while((first_circuit!=1 && first_circuit !=2)&& first_circuit!=3);
                circuits_container.push_back(new circuit(first_circuit));
                cout << "A circuit is created and stored at circuits_container["<<circuits_container.size()<<"]"<<endl;
              }else{
                int type_of_circuit;
                do{
                  cout << "What type of circuit you want to construct?"<<endl;
                  cout << "1: parallel; 2: series; 3: component; 4:single; 5: Empty" << endl;
                  cin >> type_of_circuit;
                }while(type_of_circuit!=1 && type_of_circuit!=2 &&type_of_circuit!=3 &&type_of_circuit!=4 &&type_of_circuit!=5);
                switch(type_of_circuit){
                  case(1):{
                    cout << "choose two existing circuit from circuit_container to connect them in parallel"<<endl;
                    cout << "Do you want to have a look at ";
                  };
                  case(2):{};
                  case(3):{};
                  default:{};
                }
              }
              cout <<"Do you want to continue consturcting circuit? y/n"<<endl;
              cin >> input;
            }while(input != 'y' && input!='n');
            repeat = (input=='y');
          }while(repeat);
          break;
        }
        case 3: {
          get_information(components_container,circuits_container);
          break;
        }
        default: cout<<"*Wrong input."<<endl;
        }
      } while(true);
    } while(true);
    return 0;
}
