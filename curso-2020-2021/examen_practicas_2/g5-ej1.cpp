/*
Una emisora de radio almacena un registro por cada canción que emite en antena. Cada emisión de una canción está identificada por un título, el nombre de quien la interpreta y la fecha en que se emitió. Una misma canción se puede emitir varias veces a lo largo de un día. Implementar una función a la que se le pase como parámetros un vector con los datos de las canciones emitidas y una fecha; la función debe devolver los siguientes datos de la canción que más veces se haya emitido en antena antes de la fecha que se pasa por parámetro: el nombre de la canción, el del intérprete y la cantidad de veces que se emitió.
*/

#include <iostream>
#include <string>
using namespace std;

struct Emision {
    string titulo;
    string interprete;
    int dia;
};

int num_emisiones( const Emision emis[],
    const int num_emis,
    const string titulo,
    const int dia ) {
    int toRet=0;
    for( int i=0; i<num_emis; ++i ) {
        if( titulo==emis[i].titulo && emis[i].dia<dia ) {
            ++toRet;
        }
    }
    return toRet;
}

void mas_emitida( const Emision emis[],
    const int num_emis,
    const int dia,
    string &titulo,
    string &interprete,
    int &cantidad ) {
    cantidad=0;
    titulo="";
    interprete="";
    for( int i=0; i<num_emis; ++i ) {
        int tmp_cantidad=num_emisiones( emis, num_emis, emis[i].titulo, dia );
        if( tmp_cantidad>cantidad ) {
            cantidad=tmp_cantidad;
            titulo=emis[i].titulo;
            interprete=emis[i].interprete;
        }
    }
}

int main() {
    Emision emisiones[]= {
        {"Cancion 1", "Interprete 1", 1},
        {"Cancion 1", "Interprete 1", 3},
        {"Cancion 1", "Interprete 1", 2},
        {"Cancion 2", "Interprete 2", 1},
        {"Cancion 2", "Interprete 2", 1},
        {"Cancion 3", "Interprete 3", 1},
        {"Cancion 3", "Interprete 3", 2},
        {"Cancion 4", "Interprete 4", 1},
        {"Cancion 5", "Interprete 5", 2}
    };
    int num_emisiones=9;
    string titulo, interprete;
    int cantidad=0;
    mas_emitida( emisiones, num_emisiones, 2 , titulo, interprete, cantidad );
    cout << "La canción más emitida antes del día 2 fue " << titulo
         << " interpretada por " << interprete
         <<". Se emitió " << cantidad << " veces." << endl;
    return 0;
}
