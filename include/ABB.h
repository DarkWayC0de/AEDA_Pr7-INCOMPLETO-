//
// Created by darkwaycode on 5/05/19.
//

#ifndef PR6_ABB_H
#define PR6_ABB_H

#include <iostream>
#include "NodoBB.h"
#include <queue>


template <class T>
class ABB{

 private:
  NodoBB<T> *raiz_;

 public:
  friend std::ostream &operator<<(std::ostream &os, const ABB &abb) {
    std::queue<std::pair<NodoBB<T>*,int>> Cola;
    int niv_actual(0);
    std::pair<NodoBB<T>*,int>  a(abb.raiz_,0);
    Cola.push(a);
    std::cout<<"Nivel "<<niv_actual<<": ";
    while (!Cola.empty()){
      a = Cola.front();
      Cola.pop();
      if (a.second>niv_actual){
        niv_actual=a.second;
        os<<"\nNivel "<<niv_actual<<": ";
      }
      if(a.first!= nullptr){
        os<<"["<<a.first->getDato()<<"]";
        std::pair<NodoBB<T>*,int>  b(a.first->getIzqcop(),a.second+1);
        Cola.push(b);
        b.first=a.first->getDercop();
        b.second=a.second+1;
        Cola.push(b);
      }else{
        os<<"[.]";
      }

    }
    return os;
  }
  ABB():raiz_(nullptr){

  }

  explicit ABB(NodoBB<T>* raiz):raiz_(raiz){

  }

  virtual ~ABB() {
   destruir(raiz_);
  }

  NodoBB<T> *getRaiz() const {
    return raiz_;
  }
  NodoBB<T> **getpRaiz()  {
    //NodoAVL<T>* A= dynamic_cast<NodoAVL<T>*>(raiz_);
    return &raiz_;
  }

  void setRaiz(NodoBB<T> *raiz) {
    raiz_ = raiz;
  }
  NodoBB<T>** Buscar(T x){
    return Buscar(x,&raiz_);
  }

  NodoBB<T>** Buscar(T x,NodoBB<T>** raiz){
    if(*raiz == nullptr){
      return raiz;
    }else{
      if((**raiz).getDato()==x){
        return  raiz;
      }else{
        if ((**raiz).getDato() > x){
          return Buscar(x,(**raiz).getIzq());
        }else{
          return Buscar(x,(**raiz).getDer());
        }
      }
    }
  }

  virtual bool Insertar(T x){
   NodoBB<T>** aux= Buscar(x,&raiz_);
   if(*aux==nullptr){
     *aux=new NodoBB<T> (x);
     return true;
   }
    return  false;
  }
  bool Insertar(NodoBB<T> *x){
    NodoBB<T>** aux= Buscar(x->getDato(),&raiz_);
    if(*aux==nullptr){
      *aux=x;
      return true;
    }
    return  false;
  }

  virtual bool Eliminar(T x){
    NodoBB<T>** aux = Buscar(x,&raiz_);
    if(*aux!=nullptr){
      NodoBB<T>* izq =(**aux).getIzqcop();
      NodoBB<T>* der =(**aux).getDercop();
      if(izq== nullptr && der== nullptr){
        delete *aux;
        *aux= nullptr;
        return true;
      }else{
        if(izq== nullptr){
          (**aux).setDer(nullptr);
          delete *aux;
          *aux=der;
          return true;
        }
        if(der== nullptr){
          (**aux).setIzq(nullptr);
          delete *aux;
          *aux=izq;
          return true;
        }
        NodoBB<T> **temp = recorrer((**aux).getIzq());
        (**aux).setDato((**temp).getDato());
        NodoBB<T> *izqtemp= (**temp).getIzqcop();
        delete (**aux).getIzqcop();
        (**aux).setIzq(izqtemp);
      }
    }
    return  false;
  }
  int Altura(){
    return Profundidad();
  }
  int Altura(NodoBB<T>* A){
    if (A==nullptr)return 0;
    if((A->getIzqcop()== nullptr)&&(A->getDercop()== nullptr)) return 1;
    return std::max( Altura(A->getDercop()),Altura(A->getIzqcop()))+1;
  }
  int tamano(){
    tamano(raiz_);
  }
  int tamano(NodoBB<T>* raiz){
    return (raiz== nullptr)? 0:(1+tamano(raiz->getDercop())+tamano(raiz->getIzqcop()));
  }

  int Profundidad(){
    return Profundidad(raiz_);
  }

  int Profundidad(NodoBB<T>* raiz){
    std::queue<std::pair<NodoBB<T>*,int>> Cola;
    int prof(0);
    int niv_actual(0);
    std::pair<NodoBB<T>*,int>  a(raiz,0);
    Cola.push(a);

    while (!Cola.empty()) {
      a = Cola.front();
      Cola.pop();
      if (a.second > niv_actual) {
        niv_actual = a.second;
        if (niv_actual > prof) {
          prof = niv_actual;
        }
      }

      if (a.first != nullptr) {
        std::pair<NodoBB<T> *, int> b(a.first->getIzqcop(), a.second + 1);
        Cola.push(b);
        b.first = a.first->getDercop();
        b.second = a.second + 1;
        Cola.push(b);
      }
    }
    return prof;
  }

 private:
  NodoBB<T>** recorrer(NodoBB<T>** raiz,bool Izquirda = false){
    if(Izquirda){
      if ((**raiz).getIzqcop() == nullptr) {
        return raiz;
      } else {
        return recorrer((**raiz).getIzq(),true);
      }
    }else {
      if ((**raiz).getDercop() == nullptr) {
        return raiz;
      } else {
        return recorrer((**raiz).getDer());
      }
    }
  }
  void destruir(NodoBB<T>* raiz){
    if(raiz!= nullptr){
      destruir(raiz->getIzqcop());
      destruir(raiz->getDercop());
      delete raiz;
    }
  }


};


#endif //PR6_ABB_H
