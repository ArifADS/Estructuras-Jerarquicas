//
//  ArbolBin.h
//  Estructuras Jerarquicas
//
//  Created by Arif De Sousa on 1/27/14.
//  Copyright (c) 2014 ADS Studios. All rights reserved.
//

#ifndef __Estructuras_Jerarquicas__ArbolBin__
#define __Estructuras_Jerarquicas__ArbolBin__

#include <iostream>
#include "NodoArbolBin.h"
#include "List.h"

#define self (*this)

template <class T>
class ArbolBin{
private:
    NodoArbolBin<T>* nodoRaiz;
    
    
public:
    
    ArbolBin(){
        nodoRaiz = new NodoArbolBin<T>;
    }
    
    ArbolBin(T elem){
        nodoRaiz = new NodoArbolBin<T>(elem,NULL,NULL);
    }
    
    ArbolBin(NodoArbolBin<T>* nodoR)
    {
        self.nodoRaiz = nodoR;
    }
    
    //~ArbolN();
    ArbolBin<T>& operator=(ArbolBin<T>& arbolCopia)
    {
        self.nodoRaiz = copiarNodos(arbolCopia.nodoRaiz);
        return self;
    }
    
    bool isNull()
    {
        return nodoRaiz == NULL;
    }
    
    T raiz()
    {
        return nodoRaiz->getElemento();
    }
    
    List<ArbolBin> hijos();/*
    {
        List<ArbolBin>* listaHijos = new List<ArbolBin>;
        NodoArbolBin<T>* nodoAux;
        
        nodoAux = nodoRaiz->getHijoIzquierdo();
        
        while (nodoAux != NULL) {
            listaHijos->addInfoAtPos(*(new ArbolBin<T>(nodoAux)),listaHijos->getLenght());
            
            nodoAux = nodoAux->getHijoDerecho();
        }
        
        return *listaHijos;
        
    }*/
    
    void insertarSubArbol2(ArbolBin sArbol)
    {
        NodoArbolBin<T>* aux;
        
        if (nodoRaiz->getHijoIzquierdo() == NULL) {
            nodoRaiz->setHijoIzquierdo(sArbol.nodoRaiz);
        }
        else{
            aux = nodoRaiz->getHijoIzquierdo();
            while (aux->getHijoDerecho() != NULL) {
                aux = aux->getHijoDerecho();
            }
            aux->setHijoDerecho(sArbol.nodoRaiz);
        }
        sArbol.nodoRaiz = NULL;
    }
    
    void insertarSubArbol(ArbolBin sArbol)
    {
        NodoArbolBin<T>* next, *prev;
        
        T elem = sArbol.raiz();
        
        next = self.nodoRaiz;
        
        while (next)
        {
            prev = next;
            
            if (next->getElemento() > elem) next = next->getHijoIzquierdo();
            else                            next = next->getHijoDerecho();
        }
        
        if (prev->getElemento() > elem )     prev->setHijoIzquierdo(sArbol.nodoRaiz);
        else                                prev->setHijoDerecho(sArbol.nodoRaiz);
        
    }
    
    
    void eliminarSubArbol(int pos)
    {
        NodoArbolBin<T>* aux, *aux2;
        
        aux = nodoRaiz->getHijoIzquierdo();
        
        if (pos == 0) {
            nodoRaiz->setHijoIzquierdo(aux->getHijoDerecho());
            
            
        }
        else{
            for (int i = 0; i<pos && aux; i++)
            {
                aux2 = aux;
                aux = aux->getHijoDerecho();
            }
            
            if (aux != NULL) {
                aux2->getHijoDerecho(aux->getHijoDerecho());
            }
            
            
        }
        
        delete aux;
    }
    
    
    //RECORRIDOS
    
    void preorden()
    {
        recorridosDeOrden(self.nodoRaiz,0);
    }
    
    void posorden()
    {
        recorridosDeOrden(nodoRaiz,1);
    }
    
    void inorden()
    {
        recorridosDeOrden(nodoRaiz,2);
    }
    
private:
    static NodoArbolBin<T>* copiarNodos(NodoArbolBin<T>* p)
    {
        NodoArbolBin<T>* nuevoNodo;
        
        if ( p==NULL){
            return NULL;
        }
        else
        {
            
            nuevoNodo = new NodoArbolBin<T>(p->getElemento(),copiarNodos(p->getHijoIzquierdo()),copiarNodos(p->getHijoDerecho()));
            
            return nuevoNodo;
        }
    }
    
    static void recorridoPreorden(NodoArbolBin<T>* ptrRaiz)
    {
        NodoArbolBin<T>* aux;
        
        if (ptrRaiz != NULL) {
            cout<< ptrRaiz->getElemento() << " ";
            aux = ptrRaiz->getHijoIzquierdo();
            while (aux != NULL) {
                recorridoPreorden(aux);
                aux = aux->getHijoDerecho();
            }
        }
    }
    
    static void recorridosDeOrden(NodoArbolBin<T>* ptrRaiz,int j)
    {
        if (ptrRaiz != NULL)
        {
            if (j == 0) cout<< ptrRaiz->getElemento() << " "; // preorden
            
            recorridosDeOrden(ptrRaiz->getHijoIzquierdo(),j);
            
            if (j == 1) cout<< ptrRaiz->getElemento() << " "; // PostOrden
            
            recorridosDeOrden(ptrRaiz->getHijoDerecho(),j);
            
            if (j == 2) cout<< ptrRaiz->getElemento() << " "; // WTF IS THIS?
        }
        
        
    }
    
    
    
};



#endif /* defined(__Estructuras_Jerarquicas__ArbolBin__) */
