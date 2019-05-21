#include <iostream>
#include "../include/AVL.h"
#include "../include/DNI.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <climits>
int main() {
  char clr[]="clear";
  system(clr);
  srand(time(NULL));
  std::cout << "Programa Modo Estadistica" << std::endl;
  std::cout<<"Introduce el Tamaño del Arbol: ";
  int size,nPruebas;
  std::cin>>size;
  std::cout<<"Introduce el Numero de Pruebas: ";
  std::cin>>nPruebas;
  system(clr);
  std::vector<DNI> banco_pb;
  for (int i = 0; i <2*size ; ++i) {
    DNI aux(rand()%100000000);
    banco_pb.push_back(aux);
  }

  AVL<DNI> Arbol;
  for (int j = 0; j <size ; ++j) {
    Arbol.Insertar(banco_pb[j]);
  }
  DNI a;
  int minBus(INT_MAX), maxBus(INT_MIN), acumuladorBus(0);
  for (int j = 0; j <nPruebas ; ++j) {
    a.setContador();
    Arbol.Buscar(banco_pb[rand()%size]);
    int temp =a.getContador();
    acumuladorBus+=temp;
    if(temp<minBus){
      minBus=temp;
    }
    if(temp>maxBus){
      maxBus=temp;
    }
  }
  int minIns(INT_MAX), maxIns(INT_MIN), acumuladorIns(0);
  for (int j = 0; j <nPruebas ; ++j) {
    a.setContador();
    Arbol.Buscar(banco_pb[size+(rand()%size)]);
    int temp =a.getContador();
    acumuladorIns+=temp;
    if(temp<minIns){
      minIns=temp;
    }
    if(temp>maxIns){
      maxIns=temp;
    }
  }
std::cout<<"############  Numero de Comparaciones ############\n"
           "\t\t\tN\t\tPruebas\t\tMinimo\t\tMedio\t\t\tMaximo\t\tProfundidad\n"
           "Busqueda\t"<<size<<"\t\t"<<nPruebas<<"\t\t\t"<<minBus<<"\t\t\t"<<acumuladorBus/nPruebas<<"\t\t\t"<<maxBus<<"\t\t\t"<<Arbol.Profundidad()<<"\n"
           "Insercion\t"<<size<<"\t\t"<<nPruebas<<"\t\t\t"<<minIns<<"\t\t\t"<<acumuladorIns/nPruebas<<"\t\t\t"<<maxIns<<"\t\t\t"<<Arbol.Profundidad()<<"\n"
                                                                                         "";
  return 0;
}

