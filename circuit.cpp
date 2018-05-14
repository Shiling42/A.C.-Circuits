#include "circuit.h"
using namespace std;

// default constructor
circuit::circuit(){
  conntype = "empty";
  setimpedance();
  name = "circuit";
};
// two sub circuit constructor
circuit::circuit(circuit* sub_circuit_1,circuit* sub_circuit_2, string ctype){
  sub_circuit.push_back(sub_circuit_1);
  sub_circuit.push_back(sub_circuit_2);
  conntype = ctype;
  name = "circuit";
  setimpedance();
};
// one subcicuit constructor
circuit::circuit(circuit* sub_circuit_1){
  sub_circuit.push_back(sub_circuit_1);
  conntype = "single";
  name = "circuit";
  setimpedance();
};
circuit::circuit(component* newcomponent){
  conntype = "component";
  name == "circuit";
  base_component = newcomponent;
  setimpedance();
};

void circuit::setimpedance(){
    if(conntype=="series") {
      sub_circuit[0]->setf(frequency);
      sub_circuit[1]->setf(frequency);
      impedance = sub_circuit[0]->getimpedance()+sub_circuit[1]->getimpedance();
    }
    else if(conntype=="parallel"){
      sub_circuit[0]->setf(frequency);
      sub_circuit[1]->setf(frequency);
      impedance = complex<double>(1.0,0.0)/(complex<double>(1.0,0.0)/(sub_circuit[0]->getimpedance()+complex<double>(e,e))+complex<double>(1.0,0.0)/(sub_circuit[1]->getimpedance()+complex<double>(e,e))+complex<double>(e,e));
      if (abs(impedance.real()) <THRESHOLD) impedance.real(0.0);
      if (abs(impedance.imag()) < THRESHOLD) impedance.imag(0.0);
      //if (std::abs(number) < THRESHOLD) number = 0;
    }else if(conntype=="empty"){
      impedance = complex<double>(0.0,0.0);
    }else if(conntype=="single"){
      sub_circuit[0]->setf(frequency);
      impedance = sub_circuit[0]->getimpedance();
    }else if(conntype=="component"){
      impedance = complex<double>(0,0);
      //impedance = base_component-> getimpedance();
    }
};
//set the frequency of the circuit and update the impedance accordingly
void circuit::setf(double f){
  frequency=f;
  setimpedance();
};
void circuit::info(){
  cout << "\n****Information of this circuit:*****"<<endl;
  cout << "impedance = " << impedance << ", frequency ="<< frequency <<endl;
  cout << "circuit type is \" "<< conntype <<"\"" << endl;
};
void circuit::setvalue(double value){};
double circuit::getvalue(){};

void circuit::delsubcircuit(){
  cout << "the current circuit is \" " << conntype <<"\" type" <<endl;
  // type 1
  if(conntype=="series" or conntype=="parallel") {
    int todelete = 0;
    cout << "enter which subcitcuit you want delete (1 or 2), if you want to stop deleting, input 0 : " <<endl;
    cin >> todelete;
    cout << todelete <<endl;
    if (todelete == 0){
      cout << "Nothing is done." <<endl;
    }else if (todelete == 1){
      cout << "subcircuit 1 is deleted, and this circuit is now \"single\" type" << endl;
      sub_circuit[0] = move(sub_circuit[1]);
      conntype = "single";
    }else if(todelete == 2){
      cout << "subcircuit 2 is deleted" << endl;
      sub_circuit.erase(sub_circuit.begin()+1);
      conntype = "single";
      cout << "subcircuit 1 is deleted, and this circuit is now \"single\" type" << endl;
    }else{
      cout << "wrong input" <<endl;
    }
  }else if(conntype=="empty"){
    cout << "You can not delete subcircuit if it does not exist." <<endl;
  }else if(conntype=="single"){
   cout << "Delete or keep the only subcitcuit (1:deleting, 0: keeping): " << endl;
   int action = 1;
   cin >> action;
   if (action == 1){
     cout << "you deleted the only subcircuit, now the type of this circuit is empty" << endl;
     sub_circuit.erase(sub_circuit.begin());
     conntype = "empty";
   }else{
     cout << "Thank you for keeping me, said by the subcircuit." << endl;
   }
  }
};

string circuit::getconntype(){
return conntype;
};

//component* circuit::getsubcircuit(int i){return sub_circuit[i];};

void circuit::wire(int& space){
  for(int i=0;i<space+1;i++)
  cout << "| ";

  //cout<< space<<endl;
}

//void tree(component* circuit2plot)

void circuit::plot(int& space){
  //string name = circuit2plot -> getname();
  wire(space);
  if(conntype != "component"){
    //string conntype = circuit2plot -> getconntype()
      if(conntype=="series" ){
        cout<< "S\n|-";
        sub_circuit[0]->plot(space);
        cout<< "|-";
        sub_circuit[1]->plot(space);
        space = space +1;
      }else if(conntype=="parallel"){
        cout<< "P\n|-";
        sub_circuit[0]->plot(space);
        cout<< "|-";
        sub_circuit[1]->plot(space);
        space = space +1;
      }else if(conntype=="empty"){
        cout<< "E"<<endl;;
        space = space -1;
      }else if(conntype=="single"){
        cout<< "O-" ;
        sub_circuit[0]->plot(space);
        space = space +1;
      }
  }else{
     if(base_component->getname()=="resistor"){
      cout << "R"<<endl;;
      space = space -1;
    }else if(base_component->getname() == "capacitor"){
      cout << "C"<<endl;;
      space = space -1;
    }else if(base_component->getname() == "inductor"){
      cout << "L"<<endl;;
      space = space -1;
    }
  }
}
