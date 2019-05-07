#include <iostream>
#include "../include/ABB.h"
#include "../include/DNI.h"
int main() {
  std::cout << "Programa Modo Demostracion" << std::endl;
  ABB<DNI> Arbol;
  int opcion(0), Clave(0);
  DNI dni;
  do {
    std::cout << "[0] Salir\n"
                 "[1] Insertar Clave\n"
                 "[2] Eliminar Clave\n"
                 "Introduce una de las opciones anteriores:";
    std::cin >> opcion;
    switch (opcion) {
      case 0:
        break;
      case 1:
          std::cout<<"Introduzca una Clave:";
          std::cin>>Clave;
        std::cout<<"Insertar :"<<Clave<<"\n";
          dni.setDni(Clave);
          Arbol.Insertar(dni);
          std::cout<<Arbol<<"\n";
        break;
      case 2:
        std::cout<<"Introduzca una Clave:";
        std::cin>>Clave;
        std::cout<<"Eliminar :"<<Clave<<"\n";
        dni.setDni(Clave);
        Arbol.Eliminar(dni);
        std::cout<<Arbol<<"\n";
        break;
      default:
        std::cout << "Opcion no permitida\n";
    }
  }while(opcion!=0);



  return 0;
}