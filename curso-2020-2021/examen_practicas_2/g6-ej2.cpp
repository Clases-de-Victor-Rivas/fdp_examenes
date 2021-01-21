/*
Escribir una función que reciba entre sus parámetros una matriz MxM de caracteres (M debe ser como máximo 25). 
La función debe devolver el número de caracteres que son letras mayúsculas que aparecen por encima de la diagonal 
principal en filas pares de la matriz y el número de caracteres que son letras mayúsculas que aparecen por debajo 
de la diagonal principal en filas impares de la matriz.
*/

#include <iostream>
#include <string>
using namespace std;
const int MAX_M=25;
void procesar_matriz( const char matriz[MAX_M][MAX_M]
    , const int n
    , int &encima_par
    , int &debajo_impar
    , string &encima
    , string &debajo ) {
    encima_par=0;
    debajo_impar=0;
    encima="";
    debajo="";
    //  Encima par
    for( int f=0; f<n; f+=2 ) {
        for( int c=0; c<n; ++c ) {
            if( c>f && matriz[f][c]>='A' && matriz[f][c]<='Z' ) {
                encima+=matriz[f][c];
                ++encima_par;
            }
        }
    }
    //  Debajo impar
    for( int f=1; f<n; f+=2 ) {
        for( int c=0; c<n; ++c ) {
            if( f>c && matriz[f][c]>='A' && matriz[f][c]<='Z' ) {
                debajo+=matriz[f][c];
                ++debajo_impar;
            }
        }
    }
}


int main() {
    int M=4;
    char matriz[MAX_M][MAX_M]= {
        {'d', '1', 'V', '5'},
        {'I', 'y', '4', 'C'},
        {'T', '9', '2', 'O'},
        {'R', 'M', '1', 'o'}
    };

    int encima_par, debajo_impar;
    string encima, debajo;
    procesar_matriz( matriz, M, encima_par, debajo_impar, encima, debajo );
    cout << "El número de mayúsculas que están por encima de la diagonal principal en filas pares es " << encima_par
        << " y el número de mayúsculas que están por debajo de la diagonal principal en filas impares es " << debajo_impar
        << endl;
    cout << "Las letras son " << encima << " y " << debajo << endl;

}
