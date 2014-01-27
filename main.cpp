//
//  main.cpp
//  Estructuras Jerarquicas
//
//  Created by Arif De Sousa on 1/20/14.
//  Copyright (c) 2014 ADS Studios. All rights reserved.
//

#include <iostream>
#include "ArbolN.h"
#include "ArbolBin.h"

int main(){
    
    ArbolBin<string> a("Pedro"),b("Ramon"),c("Casique"),d("Arif"),e("Aaron"),f("Zapata"),g("Cuca"),copia;
    
    a.insertarSubArbol(e);
    a.insertarSubArbol(f);
    
    a.insertarSubArbol(g);
    
    a.insertarSubArbol(b);
    a.insertarSubArbol(c);
    a.insertarSubArbol(d);

    
    copia = a;
    a.preorden();
    
    
    return 0;
}

int main2(int argc, const char * argv[])
{
    cout << "begin\n";
    ArbolN<string> a("Pedro");
    ArbolN<string> b("Ramon");
    ArbolN<string> c("Casique");
    ArbolN<string> d("Arif");
    ArbolN<string> e("Aaron");
    ArbolN<string> f("Zapata");
    ArbolN<string> g("Cuca");
    
    
    ArbolN<char> copia;
    
    

    
    b.insertarSubArbol(e);
    b.insertarSubArbol(f);
    
    d.insertarSubArbol(g);
    
    a.insertarSubArbol(b);
    a.insertarSubArbol(c);
    a.insertarSubArbol(d);
    
    
    //copia = a;
    
    //a.preorden();
    
    copia.preorden();
    
    //copia.eliminarSubArbol(0);
    
    cout << endl;
    
    copia.preorden();
    
    cout << "\nEl primer hijo del primer hijo de la raiz es: " << copia.hijos()[0].hijos()[0].raiz()<< endl;
    
    cout << "\nFinish\n";
    
    
    return 0;
}

