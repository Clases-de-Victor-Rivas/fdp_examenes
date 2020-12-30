/*
Un canal de Youtube almacena un registro por cada vídeo que es visualizado a lo largo de los 365 días del año. Cada visualización de un vídeo está identificada por la URL del vídeo, el usuario que lo visualizó y el día del año en que se emitió (un número entre 1 y 365). Un mismo vídeo puede ser visualizado varias veces a lo largo de un mismo día.


Implementar una función a la que se le pase entre sus parámetros un vector con los datos de los vídeos visualizados en un año; y también se le pase un día (entre 1 y 365); la función debe devolver los siguientes datos del vídeo que más veces se haya visualizado desde el día que se pasa por parámetro: la URL del vídeo, el último usuario que lo visualizó y la cantidad total de veces que se visualizó. (Puede implementar otras funciones auxiliares si lo considera necesario).
*/

#include <iostream>
#include <string>
using namespace std;

struct Video {
    string url;
    string usuario;
    int dia;
};

int num_visualizaciones( const Video videos[],
    const int num_vis,
    const string url,
    const int dia ) {
    int toRet=0;
    for( int i=0; i<num_vis; ++i ) {
        if( url==videos[i].url && videos[i].dia>dia ) {
            ++toRet;
        }
    }
    return toRet;
}

void mas_visualizado( const Video videos[],
    const int num_videos,
    const int dia,
    string &url,
    string &usuario,
    int &cantidad ) {
    cantidad=0;
    url="";
    usuario="";
    for( int i=0; i<num_videos; ++i ) {
        int tmp_cantidad=num_visualizaciones( videos, num_videos, videos[i].url, dia );
        if( tmp_cantidad>=cantidad ) {
            cantidad=tmp_cantidad;
            url=videos[i].url;
            usuario=videos[i].usuario;
        }
    }
}

int main() {
    Video visualizaciones[]= {
        {"URL 1", "Usuario 1", 10},
        {"URL 1", "Usuario 2", 20},
        {"URL 1", "Usuario 3", 20},
        {"URL 2", "Usuario 2", 1},
        {"URL 2", "Usuario 2", 1},
        {"URL 3", "Usuario 3", 3},
        {"URL 3", "Usuario 3", 4},
        {"URL 4", "Usuario 4", 1},
        {"URL 5", "Usuario 5", 2}
    };
    int num_vis=9;
    string url, usuario;
    int cantidad=0;
    mas_visualizado( visualizaciones, num_vis, 2 , url, usuario, cantidad );
    cout << "El vídeo más visualizado después del día 2 fue " << url
         << " visualizado por última vez por " << usuario << "."
         << " Se visualizó " << cantidad << " veces." << endl;
    return 0;
}
