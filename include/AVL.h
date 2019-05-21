//
// Created by darkwaycode on 20/05/19.
//

#ifndef PR7_AVL_H
#define PR7_AVL_H
#include <iostream>
#include "ABB.h"
#include "NodoAVL.h"
#include "NodoBB.h"
template <class T>
class AVL : public  ABB<T>{

 public:
  AVL():ABB<T>(){

  }

  explicit AVL(NodoBB<T>* raiz):ABB<T>(raiz){

  }
  bool Insertar(T x){
    NodoBB<T> *A = new NodoAVL<T>(x,0);
    ABB<T>::Insertar(A);
    if(actualizarcarga()){
     rebalancear();
    }
  }
  bool Eliminar(T x){
    ABB<T>::Eliminar(x);
    if(actualizarcarga()){
      rebalancear();
    }
  }
 private:
  bool actualizarcarga(){
    return actualizarcarga(ABB<T>::getRaiz());
  }
  bool actualizarcarga(NodoBB<T>* raiz){
    if( raiz == nullptr){
      return  false;
    }
    bool carga_inferior=actualizarcarga(raiz->getDercop());
    bool carga_inferior2=actualizarcarga(raiz->getIzqcop());
    carga_inferior=carga_inferior||carga_inferior2;
    int carga = (ABB<T>::Altura(raiz->getIzqcop()))-(ABB<T>::Altura(raiz->getDercop()));
    static_cast<NodoAVL<T>*>(raiz)->setCarga(carga);
    switch (carga){
      case -1:
      case 0:
      case 1:
        return carga_inferior;
      default:
        return true;
    }
  }
  void rebalancear(){
    do{
      NodoAVL<T>** aux = (NodoAVL<T>**)ABB<T>::getpRaiz();
      aux =buscardesb(aux);
      if((*aux)->getCarga()==2){
        NodoAVL<T> *aux1 = dynamic_cast<NodoAVL<T>*>((*aux)->getIzqcop());
        if(aux1->getCarga()==1){
          rotacion_II(aux);
        }else{
          rotacion_ID(aux);
        }
      }else{
        if((*aux)->getCarga()==-2) {
          NodoAVL<T> *aux1 = dynamic_cast<NodoAVL<T> *>((*aux)->getDercop());
          if (aux1->getCarga() == -1) {
            rotacion_DD(aux);
          } else {
            rotacion_DI(aux);
          }
        }
      }

    }while(actualizarcarga());
  }
  NodoAVL<T> **buscardesb(NodoAVL<T> **raiz) {
    if(raiz!=nullptr) {
      if ((*raiz)->getCarga() == 0) {
        return nullptr;
      } else {
        if ((*raiz)->getCarga() == 2 || (*raiz)->getCarga() == -2) {
          return raiz;
        } else {
          NodoAVL<T> *miaux = dynamic_cast<NodoAVL<T> *>((*raiz)->getIzqcop());
          NodoAVL<T> **aux = buscardesb(&miaux);
          if ((*aux) != nullptr) {
            return aux;
          } else {
            NodoAVL<T> *A = dynamic_cast<NodoAVL<T> *>((*raiz)->getDercop());
            return buscardesb(&A);
          }
        }
      }
    }else{
      return nullptr;
    }
  }
  void rotacion_II(NodoAVL<T>** &raiz){
    NodoAVL<T>* aux= dynamic_cast<NodoAVL<T>*>((*raiz)->getIzqcop());
    (*raiz)->setIzq(aux->getDercop());
    aux->setDer((*raiz));
    (*raiz)=aux;
  }
  void rotacion_DD(NodoAVL<T>** &raiz){
    NodoAVL<T>* aux=dynamic_cast<NodoAVL<T>*>((*raiz)->getDercop());
    (*raiz)->setDer(aux->getIzqcop());
    aux->setIzq((*raiz));
    (*raiz)=aux;
  }
  void rotacion_ID(NodoAVL<T>** &raiz){
    NodoAVL<T>* izq= dynamic_cast<NodoAVL<T>*>((*raiz)->getIzqcop());
    NodoAVL<T>* der= dynamic_cast<NodoAVL<T>*>((*raiz)->getDercop());
    (*raiz)->setIzq(der->getDercop());
    der->setDer((*raiz));
    izq->setDer(der->getIzqcop());
    der->setIzq(izq);
    (*raiz)=der;
  }
  void rotacion_DI(NodoAVL<T>** &raiz){
    NodoAVL<T>* izq= dynamic_cast<NodoAVL<T>*>((*raiz)->getIzqcop());
    NodoAVL<T>* der= dynamic_cast<NodoAVL<T>*>((*raiz)->getDercop());
    (*raiz)->setDer(izq->getIzqcop());
    izq->setIzq((*raiz));
    der->setIzq(izq->getDercop());
    izq->setDer(der);
    (*raiz)=izq;
  }

};


#endif //PR7_AVL_H
