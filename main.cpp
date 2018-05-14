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
    cin.clear();
    circuit* usercircuit;
    vector<circuit*> circuits_container;
    vector<component*> components_container;
    bool running=true;
    do{
    cout << "Creat your own circuit" <<endl;
    int choice=0;
    cout << "==============Menu================"<<endl;
    cout << "What do you want to do now:\n";
    cout << "1: Creat components\n";
    cout << "2: Creat circuits\n";
    cout << "3: List all stored components\n";
    cout << "4: Get information of existing circuits\n";
    cout << "5: Modify existing circuits\n";
    cout << "6: Clear all data (circuits and components)\n";
    cout << "7: Help\n";
    cout << "8: Quit\n";
    cout << "==================================="<<endl;
    cout << "input the number to choose:";
    cin>>choice;
    switch(choice){
      case 1: {
          creat_component(components_container);
          break;
      }
      case 2: {
        construct_circuit(components_container, circuits_container);
        break;
      }
      case 3: {
        get_information_components( components_container);
        break;
      }
      case 4: {
        get_information_circuits( circuits_container);
        break;
      }
      case 5:{
        break;
      }
      case 6:{
        char input = 'y';
        do{
          cout << "Do you want to get the information for any one of them? (y/n):";
          cin>>input;
        }while(input!='y' && input!='n');
        if(input == 'y'){
          circuits_container.clear();
          components_container.clear();
        }else{
          cout << "Don't panic. Data ata are safe. " << endl;
        }
        break;
      }
      case 9:{break;}
      case 8:{
        char input = 'y';
        do{
          cout << "Do you want to quit? (y/n):";
          cin>>input;
        }while(input!='y' && input!='n');
        if(input == 'y')running = false;
        break;}
      default: cout<<"*Wrong input."<<endl;
      }
    } while(running);

    return 0;
}
