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

int main2();


int main()
{
    main2();
    
    return 0;
    ArbolBin<int> a;
    
    List<int> preorden, inorden;
    int i = 0;
    /* preorder = {1, 2, 4, 5, 7, 3, 6, 8}
     inorder = {4, 2, 5, 7, 1, 8, 6, 3}*/
    
    preorden.addInfoAtPos(1, i++);
    preorden.addInfoAtPos(2, i++);
    preorden.addInfoAtPos(4, i++);
    preorden.addInfoAtPos(5, i++);
    preorden.addInfoAtPos(7, i++);
    preorden.addInfoAtPos(3, i++);
    preorden.addInfoAtPos(6, i++);
    preorden.addInfoAtPos(8, i++);
    
    i=0;
    
    inorden.addInfoAtPos(4, i++);
    inorden.addInfoAtPos(2, i++);
    inorden.addInfoAtPos(5, i++);
    inorden.addInfoAtPos(7, i++);
    inorden.addInfoAtPos(1, i++);
    inorden.addInfoAtPos(8, i++);
    inorden.addInfoAtPos(6, i++);
    inorden.addInfoAtPos(3, i++);
    
    a.bt(inorden, preorden);
    
    a.inorden();
    
}

int main3(){
    
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

int main2()
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
    copia.inorden();
    copia.posorden();
    
    
    //copia.eliminarSubArbol(0);
    
    
    //cout << "\nEl primer hijo del primer hijo de la raiz es: " << copia.hijos()[0].hijos()[0].raiz()<< endl;
    
    cout << "Finish\n";
    
    
    return 0;
}

