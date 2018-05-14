#include<iostream>
#include<math.h>
#include<string>
#include<complex>
#include <vector>
using namespace std;
#include "components.h"
#include "circuit.h"
/* The circuit is represented by a tree structure */


int main(){
    component *shape_array[7];
    shape_array[0] = new capacitor(1.2);
    shape_array[1] = new capacitor(2);
    cout << shape_array[0]->getname()<<endl;
    shape_array[2] = new inductor(3);
    circuit *circuit_array[5];
    cout.precision(1);
    circuit_array[2] = new circuit(shape_array[0]);
    circuit_array[2] -> setf(4);
    circuit_array[3] = new circuit(circuit_array[2],circuit_array[2],"parallel");
    cout<< shape_array[1] -> getimpedance() <<endl;
    circuit_array[3] -> setf(2);
    circuit_array[4] = new circuit(circuit_array[3],circuit_array[3],"series");
    circuit_array[2]->info();
    //circuit_array[3] -> delsubcircuit();
    int a=0;
    circuit_array[4]->plot(a);
    //shape_array[4] = shape_array[3]->getsubcircuit(0);
    //int d = 0;
    //plot(shape_array[3], d);
    /*
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
    }

    bool Usercreat=1;
    do{
    cout<< "Now you can creat your own AC cicuit" <<endl;
    cout << "First Assign the frequency" <<end;


    }    while(Usercreat==1);
    */
    return 0;
}
