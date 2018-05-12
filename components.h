#include<iostream>
#include<math.h>
#include<string>
#include<complex>
#include <vector>
using namespace std;
#ifndef components_h
#define components_h

class component{
    protected:
      complex<double> impedance;
      double frequency;
        //complex<double> impedance;
    public:
      component();
      virtual void setimpedance()=0;
      virtual void setf(double)=0;
      virtual void info()=0;
      virtual void setvalue(double)=0;
      virtual double getvalue()=0;
      virtual ~component(){}; //virtual Destructor
      double getmagnitude();//get magnitude of impedance
      double getphase();//get phase difference of impedance
      complex<double> getimpedance();//get impedance
      double getf();

        //virtual complex<double> impedance()=0;
};

class resistor: public component{
    private:
        double resistance;
    public:
        resistor(double);
        resistor(double,double);
        ~resistor(){cout << "resistor destructor called" << endl;};
        double getvalue();
        void setimpedance();
        void setvalue(double);
        void setf(double);
        void setr(double);
        void info();
};



class capacitor: public component{
    private:
      double capacity;
    public:
      capacitor(double C);
      ~capacitor(){cout << "capacitor destructor called" << endl;};
      double getvalue();
      void setimpedance();
      void setvalue(double);
      void setf(double);
      void setc(double);
      void info();
};

class inductor: public component{
    private:
        double inductance;
    public:
        inductor(double L);
        ~inductor(){cout << "Inductor destructor called" << endl;};
        double getvalue();
        void setimpedance();
        void setvalue(double);
        void setf(double);
        void setl(double);
        void info();
};


#endif
