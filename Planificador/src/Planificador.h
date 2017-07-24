/*
	Planificador.h Library for creating a concurrency layer for
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
#ifndef Planificador_h
#define Planificador_h
class Tarea{
  public:
    virtual void ejecutar(){};
    long getPeriodo();
	void setPeriodo(long p);
    long tiempoPrevio=0;
    Tarea();
  private:
    long periodo;
  };
class Planificador {
  public:
    void addTask(Tarea *t);
    void bucle();
    Planificador(int tam);
    Planificador();
  private:
    Tarea * tareas[20];
    int tam;
    int used;
    long tiempoPrevio;
  
  };
#endif