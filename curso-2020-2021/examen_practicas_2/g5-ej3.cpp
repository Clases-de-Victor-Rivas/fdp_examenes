/*
Realizar una función que reciba como parámetros de entrada un vector de números reales y su tamaño, y devuelva un puntero en el que se almacene la dirección de memoria de algún elemento del vector que sea exactamente igual a la media de todos los datos. En caso de no haber ningún elemento igual a la media o de no haber elementos en el vector, debe devolver puntero a nulo.
Como en los ejercicios anteriores, se debe escribir también una función main. Para este ejercicio, la función debe mostrar que la función creada puede trabajar correctamente con un vector de números reales en memoria estática y, a continuación, con un vector de números reales en memoria dinámica.
*/
#include <iostream>
using namespace std;
double* elemento_igual_a_la_media( double vector[], const int tama ) {
    double *toRet=0;

    // Podríamos aceptar: if (tama==0) return 0   // o return toRet;

    // Calculo la media
    double media=0;
    for( int i=0; i<tama; ++i ) {
        media+=vector[i];
    }
    if ( tama>0 ) {
        media/=tama;
        // cout << "La media vale: "<< media<<endl; // Comprobación interna para ver que funciona
        for( int i=0; i<tama && !toRet; ++i ) {
            if( media==vector[i] ) {
                toRet=&vector[i]; // o toRet=vector+i;
            }
        }
    }
    return toRet;
}

int main() {

    // Comprobación con vector estático
    double v_estatico[]={1,2,3,4,5,6,7,8,9};
    int cont_v_estatico=9;

    double *direccion_media=elemento_igual_a_la_media( v_estatico, cont_v_estatico );
    cout << "En el vector estático: ";
    if( direccion_media ) {
        cout << "El dato que es igual a la media es " << *direccion_media << endl;
    } else {
        cout << "No hay dato que sea igual a la media " << endl;
    }

    // Comprobación con vector dinámico
    int cont_v_dinamico=10;
    double *v_dinamico=new double[cont_v_dinamico];
    for( int i=0; i<cont_v_dinamico; ++i ) {
        v_dinamico[i]=i;
    }

    direccion_media=elemento_igual_a_la_media( v_dinamico, cont_v_dinamico );
    cout << "En el vector dinámico: ";
    if( direccion_media ) {
        cout << "El dato que es igual a la media es " << *direccion_media << endl;
    } else {
        cout << "No hay dato que sea igual a la media " << endl;
    }

    delete [] v_dinamico;
    cout << endl;

    return 0;
}
