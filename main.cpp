#include<iostream>
#include<math.h>
#include<string>
#include<complex>
#include <vector>
using namespace std;
#include "components.h"
/* The circuit is represented by a tree structure */


int main(){
    component *shape_array[7];
    shape_array[0] = new resistor(1.2);
    //shape_array[1] = new capacitor(2);
    //shape_array[2] = new inductor(3);
    for(int i=0;i<2;i++){
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
    return 0;
}
