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

    cout << "============== Template ============== "<<endl;


    cout << " ======== User Create Circuit ======== "<<endl;
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
        get_information_components(components_container);
        break;
      }
      case 4: {
        get_information_circuits(circuits_container);
        break;
      }
      case 5:{
        cout << "You are going to modify existing circuits. Check existing circuits first:"<<endl;
        get_information_circuits(circuits_container);
        cout << "Choose which circuits to modify: " << endl;
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
      case 7:{break;}
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
