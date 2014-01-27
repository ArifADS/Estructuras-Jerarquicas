//
//  main.cpp
//  Estructuras Jerarquicas
//
//  Created by Arif De Sousa on 1/20/14.
//  Copyright (c) 2014 ADS Studios. All rights reserved.
//

#include <iostream>
#include "ArbolN.h"

int main(int argc, const char * argv[])
{
    cout << "begin\n";
    ArbolN<char> a('a');
    ArbolN<char> b('b');
    ArbolN<char> c('c');
    ArbolN<char> d('d');
    ArbolN<char> e('e');
    ArbolN<char> f('f');
    ArbolN<char> g('g');
    
    
    ArbolN<char> copia;
    
    

    
    b.insertarSubArbol(e);
    b.insertarSubArbol(f);
    
    d.insertarSubArbol(g);
    
    a.insertarSubArbol(b);
    a.insertarSubArbol(c);
    a.insertarSubArbol(d);
    
    
    copia = a;
    
    //a.preorden();
    
    copia.preorden();
    
    //copia.eliminarSubArbol(0);
    
    cout << endl;
    
    copia.preorden();
    
    cout << "\nEl primer hijo del primer hijo de la raiz es: " << copia.hijos()[0].hijos()[0].raiz()<< endl;
    
    cout << "\nFinish\n";
    
    
    return 0;
}

