#include <iostream>
#include "image.h"

using namespace std;

int main(int argc, char *argv[]) {
    // Verificar si se proporcionan los 7 argumentos necesarios
    if (argc != 7) {
        cout << "Uso: " << argv[0] << " [fichero_entrada] [fichero_salida] [in1] [in2] [out1] [out2]" << endl;
        return 1;
    }

    // Obtener nombres de archivos y otros argumentos
    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];
    int in1 = atoi(argv[3]);
    int in2 = atoi(argv[4]);
    int out1 = atoi(argv[5]);
    int out2 = atoi(argv[6]);

    // Cargar la imagen desde el archivo de entrada
    Image imagen;
    if (!imagen.Load(inputFileName)) {
        cout << "Error al cargar la imagen desde " << inputFileName << endl;
        return 1;
    }

    // Modificar el contraste de la porción de la imagen
    imagen.AdjustContrast(in1, in2, out1, out2);

    // Guardar el resultado en el archivo de salida
    if (!imagen.Save(outputFileName)) {
        cout << "Error al guardar la imagen en " << outputFileName << endl;
        return 1;
    }

    cout << "Operación exitosa. Imagen guardada en " << outputFileName << endl;

    return 0;
}

