#include "functions.h"

/*
help(string choice){
  cout << "1 how to construct parameter" <<endl;
  cout << "2 how to delete circuit" << endl;
  cout<< "input the number of help you needed:"<<endl;
}*/
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
void construct_circuit(vector<component*>& components_container, vector<circuit*>& circuits_container){
  cout << "To read the instruction on how to creat a circuit, input (y/n)"<<endl;
  char read = 'n';
  cin >> read;
  if (read=='y'){
    instruction_of_circuit_construction();
  }
  bool repeat(true);
  do{
    cout << "You are going to construct a circuit"<<endl;
    char input;
    do{//creat circuits
      if(circuits_container.size()==0){
        cout << "There is not any circuit created, at least one \"component\" circuit is needed "<<endl;
        cout << "Do you want to creat a new component or choose one from components container(y/n): "<<endl;
        int first_circuit;
        do{
          cout<<"Input the type of first component circuit (1: resistor; 2: capacitor; 3: inductor):" <<endl;
          cin >> first_circuit;
        }while((first_circuit!=1 && first_circuit !=2)&& first_circuit!=3);
        circuits_container.push_back(new circuit(first_circuit));
        cout << "A component-circuit is created and stored at circuits_container["<<circuits_container.size()<<"]"<<endl;
      }else{
        int type_of_circuit;
        do{
          cout << "What type of circuit you want to construct?"<<endl;
          cout << "1: parallel; 2: series; 3: component; 4:Single; 5: Empty" << endl;
          cin >> type_of_circuit;
        }while(type_of_circuit!=1 && type_of_circuit!=2 &&type_of_circuit!=3 &&type_of_circuit!=4 &&type_of_circuit!=5);
        switch(type_of_circuit){
          case(1):{
            cout << "choose two existing circuit from circuits_container to connect them in parallel"<<endl;
            get_information_circuits(circuits_container);
            cout << "Choose two circuits as subcircuits connected in parallel:"<<endl;
            int subc1,subc2;
            do{
              cout << "1st one (0~"<<circuits_container.size()-1 <<"): ";
              cin >> subc1;
            }while(subc1>=circuits_container.size());
            do{
              cout << "2st one (0~"<<circuits_container.size()-1 <<"): ";
              cin >> subc2;
            }while(subc2>=circuits_container.size());
            cout << "2nd one (0~"<<circuits_container.size()-1 <<"): ";
            circuits_container.push_back(new circuit(circuits_container[subc1],circuits_container[subc2],"parallel"));
            cout << "A parallel-circuit is created and stored at" << "circuits_container[" <<circuits_container.size()-1<<"]"<<endl;
            break;
          };
          case(2):{
            cout << "choose two existing circuit from circuits_container to connect them in series"<<endl;
            get_information_circuits(circuits_container);
            cout << "Choose two circuits as subcircuits connected in sereis:"<<endl;
            int subc1,subc2;
            do{
              cout << "1st one (0~"<<circuits_container.size()-1 <<"): ";
              cin >> subc1;
            }while(subc1>=circuits_container.size());
            do{
              cout << "2st one (0~"<<circuits_container.size()-1 <<"): ";
              cin >> subc2;
            }while(subc2>=circuits_container.size());
            cout << "2nd one (0~"<<circuits_container.size()-1 <<"): ";
            circuits_container.push_back(new circuit(circuits_container[subc1],circuits_container[subc2],"series"));
            cout << "A series-circuit is created and stored at" << "circuits_container[" <<circuits_container.size()-1<<"]"<<endl;
            break;
          };
          case(3):{
            int component_circuit;
            do{
              cout<<"Input the type of first component circuit (1: resistor; 2: capacitor; 3: inductor):" <<endl;
              cin >> component_circuit;
            }while((component_circuit!=1 && component_circuit !=2)&& component_circuit!=3);
            circuits_container.push_back(new circuit(component_circuit));
            cout << "A component-circuit is created and stored at circuits_container["<<circuits_container.size()<<"]"<<endl;
            break;
          };
          case(4):{
            cout << "You are going to creat a single circuit: " <<endl;
            get_information_circuits(circuits_container);
            int subc1;
            do{
              cout << "Choose an existing circuit as the only subcircuit(0~"<<circuits_container.size()-1 <<"): ";
              cin >> subc1;
            }while(subc1>=circuits_container.size());
            circuits_container.push_back(new circuit(circuits_container[subc1]));
            cout << "A single-circuit is created and stored at circuits_container["<<circuits_container.size()<<"]"<<endl;
            break;
          };
          case(5):{
            circuits_container.push_back(new circuit());
            cout << "A empty-circuit is created and stored at circuits_container["<<circuits_container.size()<<"]"<<endl;
          };
          default:{};
        }
      }
      cout <<"Do you want to continue consturcting circuit? y/n"<<endl;
      cin >> input;
    }while(input != 'y' && input!='n');
    circuits_container[circuits_container.size()-1]->setlabel(circuits_container.size()-1);
    repeat = (input=='y');
  }while(repeat);
}

void get_information_circuits(vector<circuit*> circuits_container){
  if(circuits_container.size()==0){
    cout<<"There are no circuits"<<endl;
  }else{
    cout << "There are "<< circuits_container.size() << " circuits"<<endl;\
    char input = 'y';
    do{
      cout << "Do you want to get the information for any one of them? (y/n):";
      cin>>input;
    }while(input!='y' && input!='n');
      if(input == 'y'){
        cout << "Which one's information do you want to get? input 0~"<< circuits_container.size()-1<<endl;
        int circuit_label=0;
        do{
          cin >> circuit_label;
          if(circuit_label==-1)break;
          if( circuit_label < circuits_container.size() && circuit_label>=0){
              circuits_container[circuit_label]->info();
          }else{cout<<"No such a circuit."<<endl;}
          cout<<"Input -1 to exist, input 0~"<< circuits_container.size()-1<<" to show another ones' infomation"<< endl;
        }while(true);
    }
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
