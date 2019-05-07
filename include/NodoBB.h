//
// Created by darkwaycode on 30/04/19.
//

#ifndef PR6_NODOBB_H
#define PR6_NODOBB_H

template <class T>
class NodoBB {

 private:

  NodoBB<T> *izq_;
  NodoBB<T> *der_;
  T Dato_;

 public:

  NodoBB() : izq_(nullptr), der_(nullptr) {
  }

  explicit NodoBB(T dato) : izq_(nullptr), der_(nullptr), Dato_(dato) {
  }

  virtual ~NodoBB()= default;


  NodoBB<T> **getIzq()  {
    return &izq_;
  }
  NodoBB<T> *getIzqcop()  {
    return izq_;
  }

  void setIzq(NodoBB<T> *izq) {
    izq_ = izq;
  }

  NodoBB<T> **getDer() {
    return &der_;
  }
  NodoBB<T> *getDercop() {
    return der_;
  }

  void setDer(NodoBB<T> *der) {
    der_ = der;
  }

  T getDato() const {
    return Dato_;
  }

  void setDato(T dato) {
    Dato_ = dato;
  }

};

#endif //PR6_NODOBB_H
