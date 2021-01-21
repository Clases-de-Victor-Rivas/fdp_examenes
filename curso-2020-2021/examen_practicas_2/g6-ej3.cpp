/*
Realizar una función que reciba como parámetros de entrada un vector de números reales y su tamaño, 
y devuelva un puntero en el que se almacene la dirección de memoria de algún elemento del vector que 
sea exactamente igual a la suma de todos los datos dividos por 50. En caso de no haber ningún elemento igual 
a dicho valor o de no haber elementos en el vector, debe devolver puntero a nulo.
Además, escribir una función main que muestre que la función puede ser usada con un vector de números reales 
en memoria estática y, a continuación, con un vector de números reales en memoria dinámica.

*/
#include <iostream>
using namespace std;
double* elemento_igual_a_la_suma_dividido_50( double vector[], const int tama ) {
    double *toRet=0;

    // Podríamos aceptar: if (tama==0) return 0   // o return toRet;

    // Calculo la suma dividida por 50
    double valor=0;
    for( int i=0; i<tama; ++i ) {
        valor+=vector[i];
    }
    valor/=50;
    cout << "El valor buscado es: "<< valor<<endl; // Comprobación interna para ver que funciona
    for( int i=0; i<tama && !toRet; ++i ) {
        if( valor==vector[i] ) {
            toRet=&vector[i]; // o toRet=vector+i;
        }
    }
    return toRet;
}

int main() {

    // Comprobación con vector estático
    double v_estatico[]={45,1,3,1};
    int cont_v_estatico=4;

    double *direccion_mitad=elemento_igual_a_la_suma_dividido_50( v_estatico, cont_v_estatico );
    cout << "En el vector estático: ";
    if( direccion_mitad ) {
        cout << "El dato que es igual a la suma dividida por 50 es " << *direccion_mitad << endl;
    } else {
        cout << "No hay dato que sea igual a la suma dividida por 50 " << endl;
    }
    cout << endl;

    // Comprobación con vector dinámico
    int cont_v_dinamico=10;
    double *v_dinamico=new double[cont_v_dinamico];
    for( int i=0; i<cont_v_dinamico; ++i ) {
        v_dinamico[i]=i;
    }

    direccion_mitad=elemento_igual_a_la_suma_dividido_50( v_dinamico, cont_v_dinamico );
    cout << "En el vector dinámico: ";
    if( direccion_mitad ) {
        cout << "El dato que es igual a la suma dividida por 50 es " << *direccion_mitad<< endl;
    } else {
        cout << "No hay dato que sea igual a la suma dividida por 50 " << endl;
    }    
    cout << endl;
    
    delete [] v_dinamico;

    return 0;
}
