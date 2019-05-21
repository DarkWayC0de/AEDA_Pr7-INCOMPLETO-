//
// Created by darkwaycode on 20/05/19.
//

#ifndef PR7_NODOAVL_H
#define PR7_NODOAVL_H
#include "NodoBB.h"


template <class T>
class NodoAVL : public NodoBB<T>{

 private:

    int carga_;

 public:


  NodoAVL():NodoBB<T>(), carga_(0){

  }

  NodoAVL(T dato,int carga):NodoBB<T>(dato),carga_(carga){

  }


  virtual  ~NodoAVL()= default;

  int getCarga() const {
    return carga_;
  }

  void setCarga(int carga) {
    carga_ = carga;
  }
  
};

#endif //PR7_NODOAVL_H
