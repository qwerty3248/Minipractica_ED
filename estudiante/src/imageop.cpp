/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

#include <iostream>
#include <cmath>
#include <image.h>
#include <cassert>
#include <cstdlib>


using namespace std;

Image Image::Crop(int nrow, int ncol, int height, int width)const{

	// Declarar la imagen
    	Image Original(*this);

    	if (height < 0 || width < 0 || height + nrow > Original.get_rows() || width + ncol > Original.get_cols()) {
        		cerr << "Error: Coordenadas de la imagen de destino fuera de los límites de la imagen original." << endl;
        		exit(2);


	}
	
	//subminagen
	Image sub (height, width, 0);
	
	for(int i = 0/*nrow*/; i < height; i++){
		for(int k = 0/*ncol*/; k < width; k++){
			sub.set_pixel(i,k,Original.get_pixel(i+nrow,k+ncol));
		
		}
	
	
	}
	
	return sub;
	
		
	
}	


// Genera una imagen aumentada 2x.
/*Image Image::Zoom2X() const {
    // Creamos una copia de la imagen original.
    Image Original(*this);

    // Creamos dos imágenes para la interpolación en columnas (zoomx1) y filas (zoomx2).
    Image zoomx1(Original.get_rows(), 2 * Original.get_cols() - 1, 0);
    Image zoomx2(2 * Original.get_rows() - 1, 2 * Original.get_cols() - 1, 0);

    int var = 1;
    int var2 = 1;

    // Interpolamos por las columnas primero.
    for (int i = 0; i < Original.get_rows(); i++) {
        for (int k = 0; k < Original.get_cols(); k++) {
            if (k % 2 == 0) {
                // Si la columna es par, copiamos el píxel original a zoomx1.
                zoomx1.set_pixel(i, var - 1, Original.get_pixel(i, k));
            } else {
                // Si la columna es impar, calculamos la interpolación.
                byte aux = (Original.get_pixel(i, k - 1) + Original.get_pixel(i, k)) / 2;
                byte aux1 = (Original.get_pixel(i, k) + Original.get_pixel(i, k + 1)) / 2;
                
                // Asignamos los valores interpolados a zoomx1.
                zoomx1.set_pixel(i, var, aux);
                zoomx1.set_pixel(i, var + 1, Original.get_pixel(i, k));
                zoomx1.set_pixel(i, var + 2, aux1);

                var = var + 4;
            }
        }
    }

    // Luego, interpolamos las filas en zoomx1 para obtener zoomx2.
    for (int i = 0; i < zoomx1.get_rows(); i++) {
        for (int k = 0; k < zoomx1.get_cols(); k++) {
            if (i % 2 == 0) {
                // Si la fila es par, copiamos el píxel de zoomx1 a zoomx2.
                zoomx2.set_pixel(var2 - 1, k, zoomx1.get_pixel(i, k));
            } else {
                // Si la fila es impar, calculamos la interpolación.
                byte aux = (zoomx1.get_pixel(i - 1, k) + zoomx1.get_pixel(i, k)) / 2;
                byte aux1 = (zoomx1.get_pixel(i, k) + zoomx1.get_pixel(i + 1, k)) / 2;

                // Asignamos los valores interpolados a zoomx2.
                zoomx2.set_pixel(var2, k, aux);
                zoomx2.set_pixel(var2 + 1, k, zoomx1.get_pixel(i, k));
                zoomx2.set_pixel(var2 + 2, k, aux1);

                var2 = var2 + 4;
            }
        }
    }

    // Devolvemos la imagen resultante del zoom (zoomx2).
    return zoomx2;
}
*/

// Genera una imagen aumentada 2x.
Image Image::Zoom2X() const {
    Image zoomx2(2 * get_rows() - 1, 2 * get_cols() - 1);

    for (int i = 0; i < get_rows(); i++) {
        for (int j = 0; j < get_cols(); j++) {
            //valor original en ubicacion que le corresponde
            zoomx2.set_pixel(2 * i, 2 * j, get_pixel(i, j));

	    //si el pixel no esta en la ultima columna de la imagen original
            if (j < get_rows() - 1) {
                byte valor_fila = (get_pixel(i, j) + get_pixel(i, j + 1)) / 2;
                zoomx2.set_pixel(2 * i, 2 * j + 1, valor_fila);
            }//se calcula el valor interpolado y se coloca en la siguiente col

	    //Si el pixel no esta en la ultima fila de la img original 
            if (i < get_rows() - 1) {
                byte valor_col = (get_pixel(i, j) + get_pixel(i + 1, j)) / 2;
                zoomx2.set_pixel(2 * i + 1, 2 * j, valor_col);
	    //calculamos su valor en vertical y lo ponemos en la sig fila
		//Si no esta ni en fil ni en col orignal
                if (j < get_cols() - 1) {
                    byte valor_colsyfil = (get_pixel(i, j) + get_pixel(i, j + 1) +  
                    get_pixel(i + 1, j) + get_pixel(i + 1, j + 1)) / 4;
                    zoomx2.set_pixel(2 * i + 1, 2 * j + 1, valor_colsyfil);
                }//calculamos su interpolacion con  los 4 de alrededor
                 //lo ponemos en la siguiente fila y en la siguiente columna
            }
        }
    }
    //devolvemos la imagen con el zoom
    return zoomx2;
}



// Genera un icono como reducción de una imagen.
Image Image::Subsample(int factor) const {
    Image Original(*this);
    
    int chiquito_rows = Original.get_rows() / factor;
    int chiquito_cols = Original.get_cols() / factor;
    
    Image chiquito(chiquito_rows, chiquito_cols);

    for (int i = 0; i < chiquito_rows; i++) {
        for (int j = 0; j < chiquito_cols; j++) {
            int suma = 0;
            for (int k = 0; k < factor; k++) {
                for (int l = 0; l < factor; l++) {
                    suma += Original.get_pixel(i * factor + k, j * factor + l);
                }
            }
            chiquito.set_pixel(i, j, suma / (factor * factor));
        }
    }

    return chiquito;
}


// Modifica el contraste de una Imagen .
void Image::AdjustContrast(byte in1, byte in2, byte out1, byte out2) {
    for (int i = 0; i < get_rows(); i++) {
        for (int k = 0; k < get_cols(); k++) {
            byte aux = get_pixel(i, k);
            double aux2; //usamos un double para las operaciones y redondeamos
                         //para evitar errores de coma flotante.

            if (aux >= 0 && aux <= in1) {
                aux2 = round((out1 / in1) * aux);
            } else if (aux > in1 && aux <= in2) {
                aux2 = round((out2 - out1) / (in2 - in1) * (aux - in1) + out1);
            } else if (aux > in2 && aux <= 255) {
                aux2 = round((255 - out2) / (255 - in2) * (aux - in2) + out2);
            }

            // Convierte el valor aux2 a byte, hacemos un casteo ya que hemos
            //redondeado
            set_pixel(i, k, (byte)(aux2));
        }
    }
}





// Calcula la media de los píxeles de una imagen entera o de un fragmento de ésta.
double Image::Mean (int i, int j, int height, int width)const{

	Image recuadro;
	recuadro = Crop(i,j,height,width);
	double suma = 0.0;
	for (int i = 0; i < recuadro.get_rows(); i++){
		for(int j = 0; j < recuadro.get_cols(); j++){
			
			suma += recuadro.get_pixel(i,j);
			
		}
	
	}
	
	return suma/recuadro.size();



}
	

