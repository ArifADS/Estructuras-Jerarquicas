//
//  ArbolN.h
//  Estructuras Jerarquicas
//
//  Created by Arif De Sousa on 1/20/14.
//  Copyright (c) 2014 ADS Studios. All rights reserved.
//

#ifndef __Estructuras_Jerarquicas__ArbolN__
#define __Estructuras_Jerarquicas__ArbolN__

#include <iostream>
#include "NodoArbol.h"
#include "List.h"

template <class T>
class ArbolN{
private:
    NodoArbol<T>* nodoRaiz;
    
public:
    
    ArbolN(){
        nodoRaiz = new NodoArbol<T>;
    }
    
    ArbolN(T elem){
        nodoRaiz = new NodoArbol<T>(elem,NULL,NULL);
    }
    
    ArbolN(NodoArbol<T>* nodoR)
    {
        this->nodoRaiz = nodoR;
    }
    
    //~ArbolN();
    ArbolN<T> operator=(ArbolN<T>& arbolCopia)
    {
        copiarNodos(arbolCopia.getRaiz());
    }
    
    bool isNull()
    {
        return nodoRaiz == NULL;
    }
    
    T raiz()
    {
        return nodoRaiz->getElemento();
    }
    
    /*List<ArbolN> hijos()
    {
        List<ArbolN>* listaHijos = new List<ArbolN>;
        Node<NodoArbol*> auxNodo;
        
        auxNodo.setInfo(nodoRaiz.getHijoIzquierdo());
        while (auxNodo != NULL)
        {
            listaHijos.addInfoAtPos(auxNodo);
            
        }
        
    }*/
    
    void insertarSubArbol(ArbolN sArbol)
    {
        NodoArbol<T>* aux;
        
        if (nodoRaiz->getHijoIzquierdo() == NULL) {
            nodoRaiz->setHijoIzquierdo(sArbol.nodoRaiz);
        }
        else{
            aux = nodoRaiz->getHijoIzquierdo();
            while (aux->getHermanoDerecho() != NULL) {
                aux = aux->getHermanoDerecho();
            }
            aux->setHermanoDerecho(sArbol.nodoRaiz);
        }
        sArbol.nodoRaiz = NULL;
    }
    
    
    void eliminarSubArbol(int pos);
    
    
    //RECORRIDOS
    
    void preorden()
    {
        recorridoPreorden2(nodoRaiz);
    }
    
private:
    static ArbolN<T>* copiarNodos(ArbolN<T>* p)
    {
        NodoArbol<T>* nuevoNodo;
        
        if ( p==NULL){
            return NULL;
        }
        else
        {
            nuevoNodo = new NodoArbol<T>(p->getElemento(),copiarNodos(p->getHijoIzquierdo()),copiarNodos(p->getHermanoDerecho()));
            return nuevoNodo;
        }
    }
    
    static void recorridoPreorden(NodoArbol<T>* ptrRaiz)
    {
        NodoArbol<T>* aux;
        
        if (ptrRaiz != NULL) {
            cout<< ptrRaiz->getElemento() << " ";
            aux = ptrRaiz->getHijoIzquierdo();
            while (aux != NULL) {
                recorridoPreorden(aux);
                aux = aux->getHermanoDerecho();
            }
        }
    }
    
    static void recorridoPreorden2(NodoArbol<T>* ptrRaiz)
    {
        if (ptrRaiz != NULL)
        {
            //cout<< ptrRaiz->getElemento() << " "; // preorden
            
            recorridoPreorden2(ptrRaiz->getHijoIzquierdo());
            
            //cout<< ptrRaiz->getElemento() << " "; // PostOrden
            
            recorridoPreorden2(ptrRaiz->getHermanoDerecho());
            
            cout<< ptrRaiz->getElemento() << " ";
        }
        
        
    }
    
    
    
};

#endif /* defined(__Estructuras_Jerarquicas__ArbolN__) */
