#include "functions.h"

help(){
  cout << "1 how to construct parameter" <<endl;
  cout << "2 how to delete circuit" << endl;
  cout<< "input the number of help you needed:"<<endl;
}
void creat_component(vector<component*>& components_container){
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


void get_information_circuits(vector<circuit*> circuits_container){
  if(circuits_container.size()==0){
    cout<<"There are no circuits"<<endl;
  }else{
    cout << "Here are "<< circuits_container.size() << "circuits stored"<<endl;
    cout << "Which one do you want to check? input 0~"<< circuits_container.size()-1<<endl;
    int circuit_label=0;
    cin >> circuit_label;
    if( circuit_label < circuits_container.size() && circuit_label>=0){
        circuits_container[circuit_label]->info();
    }else{cout<<"No such a circuit."<<endl;}
  }
}

void get_information_components(vector<component*> components_container){
  if(components_container.size()==0){
    cout<<"There are no components"<<endl;
  }else{
  cout << "Here are "<< components_container.size() << " components: type(value)"<<endl;
  for(int i=0;i<components_container.size();i++){
    cout<< i <<": " << components_container[i] ->getname()<<"("<<components_container[i] ->getvalue()<<"); ";
  }
  }
}
void get_information(vector<component*> components_container, vector<circuit*> circuits_container){
  bool repeat(true);
  do{
    int circuit_or_component;
    do{
      cout <<"Stored ciruits or components? 1:components ;2:circuits"<<endl;
      cin >> circuit_or_component;
    }while(circuit_or_component != 1 && circuit_or_component!= 2);
    if(circuit_or_component == 1){
    get_information_components(components_container);
    }else{
    get_information_circuits(circuits_container);
    }
    char input;
    do{
      cout <<"Do you want to continue checking? y/n"<<endl;
      cin >> input;
    }while(input != 'y' && input!='n');
    repeat = (input=='y');
  }while(repeat);
}