# Arduino_Planificador
## Description
A real time scheduler for Arduino. It's a limited and simple code that allows to create a concurrency layer in the Arduino architecture.
## Usage

The usage is as simple as the code itself:
First include the library with
```c
#include "Planificador.h"
```
Then, outside of any function create a variable such as:
```c
Planificador p;
```
And create a class extending Tarea overriding "ejecutar", for example:
```c
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
```
Then, in "setup()" instantiate the task, set its period and add it to the scheduler.
```c
void setup() {
  task1 t1;
  t1.setPeriodo(1000);
  pinMode(13,OUTPUT);
  p.addTask(&t1);
}
```
Also, keep in mind that you have to execute "p.bucle()" every iteration:
```c
void loop() {
  p.bucle();
}
```
