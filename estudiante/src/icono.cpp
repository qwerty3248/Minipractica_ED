#include <iostream>
#include <fstream>
#include <string>
#include "image.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Uso: " << argv[0] << " <archivo_entrada> <archivo_salida> <factor_de_reduccion>" << endl;
        return 1;
    }

    string archivoEntrada = argv[1];
    string archivoSalida = argv[2];
    int factor = atoi(argv[3]);

    // Cargar la imagen desde el archivo de entrada
    Image imagen;
    if (!imagen.Load(archivoEntrada.c_str())) {
        cerr << "Error al cargar la imagen desde " << archivoEntrada << endl;
        return 1;
    }

    // Reducir la imagen utilizando la función Subsample
    Image imagenReducida = imagen.Subsample(factor);

    // Guardar la imagen reducida en el archivo de salida
    if (!imagenReducida.Save(archivoSalida.c_str())) {
        cerr << "Error al guardar la imagen reducida en " << archivoSalida << endl;
        return 1;
    }

    cout << "Imagen reducida y guardada con éxito en " << archivoSalida << endl;

    return 0;
}

