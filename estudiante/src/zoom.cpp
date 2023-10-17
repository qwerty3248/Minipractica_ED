// Fichero: zoom.cpp
// Hace zoom a una imagen PGM
//

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;
//using namespace ImageOp;

int main (int argc, char *argv[]){
 
  char *origen, *destino; // nombres de los ficheros
  Image image;

  // Comprobar validez de la llamada
  if (argc != 6){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: Zoom <FichImagenOriginal> <FichImagenDestino>\n";
    exit (1);
  }

  // Obtener argumentos
  origen  = argv[1];
  destino = argv[2];
  int fila = atoi(argv[3]);
  int col = atoi(argv[4]);
  int lado = atoi(argv[5]);
    
  // Mostramos argumentos
  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << destino << endl;

  // Leer la imagen del fichero de entrada
  if (!image.Load(origen)){
    cerr << "Error: No pudo leerse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  // Mostrar los parametros de la Imagen
  cout << endl;
  cout << "Dimensiones de " << origen << ":" << endl;
  cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;

 	Image imagenRecortada= image.Crop(fila, col, lado, lado);
 	cout << "Dimensiones de la imagen recortada:" << endl;
    cout << "   Imagen recortada = " << imagenRecortada.get_rows() << " filas x " << imagenRecortada.get_cols() << " columnas " << endl;
    
 	Image imagenAumentada = imagenRecortada.Zoom2X();
 	
 	cout << "Dimensiones de la imagen aumentada:" << endl;
cout << "   Imagen aumentada = " << imagenAumentada.get_rows() << " filas x " << imagenAumentada.get_cols() << " columnas " << endl;


  // Guardar la imagen resultado en el fichero
  if (imagenAumentada.Save(destino))
    cout  << "La imagen se guardo en " << destino << endl;
  else{
    cerr << "Error: No pudo guardarse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  return 0;
}
