//
//  NodoArbol.h
//  Estructuras Jerarquicas
//
//  Created by Arif De Sousa on 1/20/14.
//  Copyright (c) 2014 ADS Studios. All rights reserved.
//

#ifndef __Estructuras_Jerarquicas__NodoArbol__
#define __Estructuras_Jerarquicas__NodoArbol__

#include <iostream>
template <class T>
class NodoArbol{
private:
    T elem;
    NodoArbol<T> *hijoIzq, *hermanoDer;
    
public:
    NodoArbol()
    {
        this->elem = NULL;
        this->hijoIzq = NULL;
        this->hermanoDer = NULL;
    }
    
    NodoArbol(T elem, NodoArbol<T>* izq, NodoArbol<T>* der)
    {
        this->elem = elem;
        this->hijoIzq = izq;
        this->hermanoDer = der;
    }
    
    T getElemento(){
        return this->elem;
    }
    
    
    NodoArbol<T>* getHijoIzquierdo(){
        return this->hijoIzq;
    }
    
    NodoArbol<T>* getHermanoDerecho(){
        return this->hermanoDer;
    }
    void setElemento(T elem){
        this->elem = elem;
    }
    
    void setHijoIzquierdo(NodoArbol<T>* izq){
        this->hijoIzq = izq;
    }
    void setHermanoDerecho(NodoArbol<T>* der){
        this->hermanoDer = der;
    }
};

#endif /* defined(__Estructuras_Jerarquicas__NodoArbol__) */
