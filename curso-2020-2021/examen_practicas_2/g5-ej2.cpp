/*
Escribir una función que reciba entre sus parámetros una matriz NxN de caracteres (N debe ser como máximo 10). La función debe devolver el número de caracteres que son dígitos que aparecen por encima de la diagonal principal en filas impares de la matriz y el número de caracteres que son dígitos que aparecen por debajo de la diagonal principal en filas pares de la matriz.
*/

#include <iostream>
#include <string>
using namespace std;
const int MAX_N=10;
void procesar_matriz( const char matriz[MAX_N][MAX_N]
    , const int n
    , int &encima_impar
    , int &debajo_par
    , string &encima
    , string &debajo ) {
    encima_impar=0;
    debajo_par=0;
    encima=debajo="";
    //  Encima impar
    for( int f=1; f<n; f+=2 ) {
        for( int c=0; c<n; ++c ) {
            if( c>f && matriz[f][c]>='0' && matriz[f][c]<='9' ) {
              ++encima_impar;
              encima+=matriz[f][c];
            }
        }
    }
    //  Debajo par
    for( int f=0; f<n; f+=2 ) {
        for( int c=0; c<n; ++c ) {
            if( f>c && matriz[f][c]>='0' && matriz[f][c]<='9' ) {
                ++debajo_par;
                debajo+=matriz[f][c];
            }
        }
    }
}


int main() {
    int N=5;
    char matriz[MAX_N][MAX_N]= {
        {'d', '1', 'k', '5', '1'},
        {'z', 'y', '4', 'a', '2'},
        {'6', '9', 'u', 'b', '4'},
        {'7', 'a', '1', 'o', '8'},
        {'3', 'f', '0', 'd', 'e'}
    };

    int encima_impar, debajo_par;
    string encima, debajo;
    procesar_matriz( matriz, N, encima_impar, debajo_par, encima, debajo );
    cout << "El número de dígitos que están por encima de la diagonal principal en filas impares es " << encima_impar
        << " y el número de dígitos que están por debajo de la diagonal principal en filas pares es " << debajo_par
        << endl;
    cout << "Los digitos son " << encima << " y " << debajo << endl;

}
