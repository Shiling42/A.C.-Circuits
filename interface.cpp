#include "interface.h"

void interface(){
  cin.clear();
  circuit* usercircuit;
  vector<circuit*> circuits_container;
  vector<component*> components_container;
  bool running=true;
  do{
  int choice=0;
  cout << "==============Menu================"<<endl;
  cout << "What do you want to do now:\n";
  cout << "1: Creat components\n";
  cout << "2: Creat circuits\n";
  cout << "3: List all stored components\n";
  cout << "4: Get information of existing circuits\n";
  cout << "5: Modify stored circuits\n";
  cout << "6: Modify stored componetns\n";
  cout << "7: Clear all data (circuits and components)\n";
  cout << "8: Help\n";
  cout << "9: Quit\n";
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
      circuit_modify(components_container, circuits_container);
      break;
    }
    case 6:{
      components_modify(components_container);
      break;
    }
    case 7:{
      if(yes_or_no("Do you want to clear all data?")){
        circuits_container.clear();
        components_container.clear();
      }else{
        cout << "Don't panic. Data ata are safe. " << endl;
      }
      break;
    }
    case 8:{

      break;}
    case 9:{
      if(yes_or_no("Do you want to quit?"))running = false;
      break;}
    default: cout<<"*Wrong input."<<endl;
    }
  } while(running);}
void components_modify(vector<component*>& components_container){
    get_information_components(components_container);
    cout << "Choose one to modify";
    int index;
    index=get_number(0,components_container.size()-1);
    components_container[index]->info();
    cout<<"Give a new value:"<<endl;
    double newvalue=cinvalue();
    components_container[index]->setvalue(newvalue);
    components_container[index]->info();
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
        value=cinvalue();
        components_container.push_back(new resistor(value));
        cout << "You just created an resistor,";
        cout << " stored in component_container["<< components_container.size()-1<<"] component" <<endl;
        break;
      }
      case 2:{
        cout << "input the capacity:";
        value=cinvalue();
        components_container.push_back(new capacitor(value));
        cout << "You just created an capacitor, ";
        cout << "stored in component_container["<< components_container.size()-1<<"] component" <<endl;
        break;
      }
      case 3:{
        cout << "input the inductance:";
        value=cinvalue();
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
  cout << "Press Enter to Continue";
  cin.ignore();
  cout<<"\n";
};
void construct_circuit(vector<component*>& components_container, vector<circuit*>& circuits_container){
  //cout << "To read the instruction on how to creat a circuit, input (y/n)"<<endl;
  //char read = 'n';
  //cin >> read;
  //if (read=='y'){
  //  instruction_of_circuit_construction();
  //}
  bool repeat(true);
  do{
    cout << "You are going to construct a circuit"<<endl;
    char input;
    do{//creat circuits
      if(circuits_container.size()==0){
        cout << "There is not any circuit constructed, at least one \"component\" circuit is required. "<<endl;
        component_circuit_construct(components_container,  circuits_container);
        break;
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
              cout << "2nt one (0~"<<circuits_container.size()-1 <<"): ";
              cin >> subc2;
            }while(subc2>=circuits_container.size());
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
            component_circuit_construct(components_container,  circuits_container);
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
void component_circuit_construct(vector<component*>& components_container, vector<circuit*>& circuits_container){
  int choice;
  do{
    cout << "1: choose one from components container; 2: create a new component "<<endl;
    cin>>choice;
  }while(choice!=1 && choice!=2);
  switch(choice){
    case(1):{
      if(components_container.size()==0){
        cout<<"**No components in component container, you need to creat a new one."<<endl;
      }else{
       get_information_components(components_container);
       cout << "Choose one:";
       circuits_container.push_back(new circuit(components_container[get_number(0, components_container.size()-1)]));
       break;}
    }
    case(2):{
      int first_circuit;
      do{
        cout<<"Input the type of first component circuit (1: resistor; 2: capacitor; 3: inductor):" <<endl;
        cin >> first_circuit;
      }while((first_circuit!=1 && first_circuit !=2)&& first_circuit!=3);
      circuits_container.push_back(new circuit(first_circuit));
      break;
    };
    default:{}
  }
  cout << "A component-circuit is created and stored at circuits_container["<<circuits_container.size()<<"]"<<endl;
}
void circuit_modify(vector<component*>& components_container, vector<circuit*>& circuits_container){
  if(circuits_container.size()==0){
    cout<<"There are no circuits."<<endl;
  }else{
    cout << "You are going to modify existing circuits. Check existing circuits first:"<<endl;
    get_information_circuits(circuits_container);
    cout << "Choose which circuits to modify: " ;
    int number = get_number(0, circuits_container.size()-1);
    string circuit_type = circuits_container[number] -> getconntype();
    circuits_container[number] ->info();
    if(circuit_type == "component"){
      component* comp = circuits_container[number] -> getcomponent();
      cout<< "It is a component circuit:\n ";
      comp->info();
      bool changeornot = yes_or_no("Do you want to change it's value?");
      if(changeornot){
        cout << "Give a new value:"<<endl;
        double valuein;
        cin >> valuein;
        comp->setvalue(valuein);
        comp->info();
      }
    }else{
      cout<<"You can modify the circuit by deleting part of it."<<endl;
      circuits_container[number] -> delsubcircuit();
    }
  }
}
void get_information_circuits(vector<circuit*> circuits_container){
  if(circuits_container.size()==0){
    cout<<"There are no circuits"<<endl;
  }else{
    cout << "There are "<< circuits_container.size() << " circuits"<<endl;\
    bool input = yes_or_no("Do you want to get the information for any one of the stored circuits?");
      if(input){
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
int get_number(int lowerbound, int upperbound){
  int innumber;
  cout<<" "<<lowerbound<<"~"<<upperbound<<":"<< endl;
  do{
    cin >> innumber;
  }while(innumber>lowerbound && innumber<lowerbound);
  return innumber;
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
    get_information_components(components_container);
    }else{
    get_information_circuits(circuits_container);
    }
    repeat = yes_or_no("Do you want to continue?");
  }while(repeat);
}
bool yes_or_no(string sentence){
  char userinput;
  do{
    cout << sentence << " (y/n):";
    cin>>userinput;
  }while(userinput!='y' && userinput!='n');
  return userinput == 'y';
}
double cinvalue(){
  double value=1;
  do{
    if(value<=0){
      cout << "You must give a postive value:";
    }
    cin>>value;
  }while(value<=0);
  return value;
}
