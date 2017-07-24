/*
	Planificador.cpp Library for creating a concurrency layer for
	Arduino. As all concurrency, you can specify a period of operation
	but you the real execution is not deterministic.
	
	
	Copyright 2017 Félix Laguna Teno

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#include "Arduino.h"
#include "Planificador.h"
Tarea::Tarea(){
  }
long Tarea::getPeriodo(){
    return periodo;
  }
void Tarea::setPeriodo(long p){
	periodo=p;
};
Planificador::Planificador(int ta){
    tam=ta;  
  }
Planificador::Planificador(){}
void Planificador::bucle(){
    for (int i=0;i<used;++i){
      long t=millis();
     if ((t-(*tareas[i]).tiempoPrevio)>=(*tareas[i]).getPeriodo()){
      (*tareas[i]).tiempoPrevio=millis();
       (*tareas[i]).ejecutar();
       
     }
    }
    
  }
void Planificador::addTask(Tarea *t){
    tareas[used]=t;
    used++;
  }