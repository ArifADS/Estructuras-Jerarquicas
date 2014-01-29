//
//  NodoArbolBin.h
//  Estructuras Jerarquicas
//
//  Created by Arif De Sousa on 1/27/14.
//  Copyright (c) 2014 ADS Studios. All rights reserved.
//

#ifndef __Estructuras_Jerarquicas__NodoArbolBin__
#define __Estructuras_Jerarquicas__NodoArbolBin__


#include <iostream>
template <class T>
class NodoArbolBin{
private:
    T elem;
    NodoArbolBin<T> *hijoIzq, *hijoDer;
    
public:
    NodoArbolBin()
    {
        //this->elem = NULL;
        this->hijoIzq = NULL;
        this->hijoDer = NULL;
    }
    
    
    NodoArbolBin(T elem, NodoArbolBin<T>* izq, NodoArbolBin<T>* der)
    {
        this->elem = elem;
        this->hijoIzq = izq;
        this->hijoDer = der;
    }
    
    T getElemento(){
        return this->elem;
    }
    
    
    NodoArbolBin<T>* getHijoIzquierdo(){
        return this?this->hijoIzq:NULL;
    }
    
    NodoArbolBin<T>* getHijoDerecho(){
        return this?this->hijoDer:NULL;
    }
    void setElemento(T elem){
        this->elem = elem;
    }
    
    void setHijoIzquierdo(NodoArbolBin<T>* izq){
        this->hijoIzq = izq;
    }
    void setHijoDerecho(NodoArbolBin<T>* der){
        this->hijoDer = der;
    }
};


#endif /* defined(__Estructuras_Jerarquicas__NodoArbolBin__) */
