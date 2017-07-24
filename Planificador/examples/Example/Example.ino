#include "Planificador.h"

class task1: public Tarea {
    public:
      void ejecutar() override {
        if (flag){
         digitalWrite(13,1);
         flag=false; 
        }else{
          digitalWrite(13,0);
           flag=true;
         }
      }
    private:
      bool flag;
    };
class task2: public Tarea {
    public:
      void ejecutar() override {
        if (flag){
         digitalWrite(10,1);
         flag=false; 
        }else{
          digitalWrite(10,0);
           flag=true;
         }
      }
    private:
      bool flag;
    };
Planificador p;
void setup() {
  task1 t1;
  task2 t2;
  t1.setPeriodo(1000);
  t2.setPeriodo(500);
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(11,0);
  p=Planificador(3);
  //task1 t1(60);
  p.addTask(&t1);
  p.addTask(&t2);
}

void loop() {
  p.bucle();
}

