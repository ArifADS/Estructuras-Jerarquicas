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


//int main2();


int main()
{
   // main2();
    
    //return 0;
    ArbolBin<int> a;
    
    Cola<int> preorden, inorden;

    /* preorder = {1, 2, 4, 5, 7, 3, 6, 8}
		inorder = {4, 2, 5, 7, 1, 8, 6, 3}*/
    
    preorden.pushBack(1);
    preorden.pushBack(2);
    preorden.pushBack(4);
    preorden.pushBack(5);
    preorden.pushBack(7);
    preorden.pushBack(3);
    preorden.pushBack(6);
    preorden.pushBack(8);
    

    inorden.pushBack(4);
    inorden.pushBack(2);
    inorden.pushBack(5);
    inorden.pushBack(7);
    inorden.pushBack(1);
    inorden.pushBack(8);
    inorden.pushBack(6);
    inorden.pushBack(3);

    
    //a.bt(inorden, preorden);
    a.bt(preorden, inorden);
	
    a.preorden();
    a.inorden();
    a.posorden();
    
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

/*int main2()
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
}*/

