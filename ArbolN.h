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

#define self (*this)

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
        self.nodoRaiz = nodoR;
    }
    
    //~ArbolN();
    ArbolN<T> operator=(ArbolN<T>& arbolCopia)
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
    
    List<ArbolN> hijos()
    {
        List<ArbolN>* listaHijos = new List<ArbolN>;
        NodoArbol<T>* nodoAux;
        
        nodoAux = nodoRaiz->getHijoIzquierdo();
        
        while (nodoAux != NULL) {
            listaHijos->addInfoAtPos(*(new ArbolN<T>(nodoAux)),listaHijos->getLenght());
            
            nodoAux = nodoAux->getHermanoDerecho();
        }
        
        return *listaHijos;
        
    }
    
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
    
    
    void eliminarSubArbol(int pos)
    {
        NodoArbol<T>* aux, *aux2;
        
        aux = nodoRaiz->getHijoIzquierdo();
        
        if (pos == 0) {
            nodoRaiz->setHijoIzquierdo(aux->getHermanoDerecho());
            
            
        }
        else{
            for (int i = 0; i<pos && aux; i++)
            {
                aux2 = aux;
                aux = aux->getHermanoDerecho();
            }
            
            if (aux != NULL) {
                aux2->setHermanoDerecho(aux->getHermanoDerecho());
            }
            

        }
        
        delete aux;
    }
    
    
    //RECORRIDOS
    
    void preorden()
    {
        cout <<"Preorden:\t";
        recorridosDeOrden(self.nodoRaiz,0);
        cout<<endl;
    }
    
    void posorden()
    {
        cout <<"Posorden:\t";
        recorridosDeOrden(nodoRaiz,1);
        cout<<endl;
    }
    
    void inorden()
    {
        cout <<"Inorden:\t";
        recorridoInorden(nodoRaiz);
        cout<<endl;
    }
    
private:
    static NodoArbol<T>* copiarNodos(NodoArbol<T>* p)
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
    
    static void recorridosDeOrden(NodoArbol<T>* ptrRaiz,int j)
    {
        if (!ptrRaiz) return;
        if (j == 0) cout<< ptrRaiz->getElemento() << " "; // preorden
        
        recorridosDeOrden(ptrRaiz->getHijoIzquierdo(),j);
        
        if (j == 1) cout<< ptrRaiz->getElemento() << " "; // PostOrden
        
        recorridosDeOrden(ptrRaiz->getHermanoDerecho(),j);
        
    }
    
    static void recorridoInorden(NodoArbol<T>* ptrRaiz)
    {
        
        NodoArbol<T>* aux;
        if (ptrRaiz == NULL) return;
        
        recorridoInorden(ptrRaiz->getHijoIzquierdo());
        
        cout<< ptrRaiz->getElemento() << " ";
        
        aux = ptrRaiz->getHijoIzquierdo();
        
        while (aux!=NULL)
        {
            aux = aux->getHermanoDerecho();
            recorridoInorden(aux);

        }
        
        
    }
    
    
    
    
};


#endif /* defined(__Estructuras_Jerarquicas__ArbolN__) */
