#include "functions.h"

help(){
  cout << "1 how to construct parameter" <<endl;
  cout << "2 how to delete circuit" << endl;
  cout<< "input the number of help you needed:"<<endl;
}

void instruction_of_circuit_construction(){
cout<<"------------Instruction on how to construct a circuit------------"<<endl;
cout<<"Here are three types of circuit: parallel, seris, single empty and component."<<endl;
cout<<"\n## Types of circuits"<<endl;
cout<<"A \"parallel/series\" cirucit contains two sub-circuit connected in parallel/series. "<<endl;
cout<<"A \"single\" circuit contains a single subcircuit" <<endl;
cout<<"A \"empty\" circuit do not have sub circuit, it is equavilant to an open circuit (impedance = infinity)"<<endl;
cout<<"A \"component\" circuit contains one ideal componet (resistor, inductor or capacitor)"<<endl;
cout<<"\n## Consturcting circuits"<<endl;
cout<<"Constructing circuits stars from creating \"component\" circuits. ";
cout<<"More complex circuits can be constructed via connecting two circuits in parallel/series"<<endl;
cout<<"\n## Represention"<<endl;
cout<<"After constrcting a circuit, you can check its total impedance as well as the topology of the circuit.";
cout<<"The topology of a circuit is represented by a tree diagram";
cout<<"Each node can have at most two branches, and the character assigned to each node represents its type:";
cout<<"\"P\" for parallel, \"S\" for series, \"E\" for empty, \"O\" for single, and \"R\", \"C\",\"L\" are for three type \"component\" circuit"<<endl;
};

void get_information(vector<component*> components_container, vector<circuit*> circuits_container){
  bool repeat(true);
  do{
    int circuit_or_component;
    do{
      cout <<"Stored ciruits or components? 1:components ;2:circuits"<<endl;
      cin >> circuit_or_component;
    }while(circuit_or_component != 1 && circuit_or_component!= 2);
      if(circuit_or_component == 1){
        if(components_container.size()==0){
          cout<<"There are no components"<<endl;
        }else{
        cout << "Here are "<< components_container.size() << " compinents stored"<<endl;
        cout << "Which one do you want to check? input 0~"<<components_container.size()-1<<endl;
        int component_label=0;
        cin >> component_label;
        if(component_label>components_container.size()){
          components_container[component_label-1]->info();
        }else{cout<<"No such a component."<<endl;}
      }
    }else{
      if(circuits_container.size()==0){
        cout<<"There are no circuits"<<endl;
      }else{
        cout << "Here are "<< circuits_container.size() << "circuits stored"<<endl;
        cout << "Which one do you want to check? input 0~"<< circuits_container.size()-1<<endl;
        int circuit_label=0;
        cin >> circuit_label;
        if( circuit_label>circuits_container.size()){
            circuits_container[circuit_label-1]->info();
        }else{cout<<"No such a circuit."<<endl;}
      }
    }
    char input;
    do{
      cout <<"Do you want to continue checking? y/n"<<endl;
      cin >> input;
    }while(input != 'y' && input!='n');
    repeat = (input=='y');
  }while(repeat);
}
