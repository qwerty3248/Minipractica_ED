/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

#include <iostream>
#include <cmath>
#include <image.h>
#include <cassert>
#include <cstdlib>


Image Crop(int nrow, int ncol, int height, int width) const{

	// Declarar la imagen
    	Image Original(*this);

   	// Verificar si las coordenadas especificadas están dentro de los límites de la imagen original, no sé me lo ha hecho el chatgpt, 
   	//muchas condiciones xd
    	if (height < 0 || width < 0 || height + nrow > Original.get_rows() || width + ncol > Original.get_cols()) {
        		cerr << "Error: Coordenadas de la imagen de destino fuera de los límites de la imagen original." << endl;
        		exit(2);


	}
	
	//subminagen
	Image sub (height, width, 0);
	
	for(int i = nrow; i < height; i++){
		for(int k = ncol; k < width; k++){
			sub.set_pixel(i,j,Original.get_pixel(i,j));
		
		}
	
	
	}
	
	return sub;
	
		
	
}	


// Genera una imagen aumentada 2x.
Image Zoom2X() const{
    
	Image Original (*this);    
    
    	Image zoomx1 (Original.get_rows(),2*Original.get_cols()-1,0);
    	
    	Image zoomx2 (2*Original.get_rows()-1,2*Original.get_cols()-1,0);
    	
    	int var = 1;
    	int var2 = 1; 
    	
    	//interpolamos por las columas primero
    	for (int i = 0; i < Original.get_rows(); i++){
    		for(int k = 0; k < Original.get_cols() ; k++){
    			if(k % 2 == 0){
    				zoomx1.set_pixel(i,var-1,Original.get_pixel(i,k));
    			
    			}else{
    				byte aux = Original.get_pixel(i,k-1) + Original.get_pixel(i,k);
    				aux = aux / 2;
    				byte aux1 = Original.get_pixel(i,k) + Original.get_pixel(i,k+1);
    				aux1 = aux1 / 2;
    				
    				zoomx1.set_pixel(i,var,aux);
    				zoomx1.set_pixel(i,var+1,Original.get_pixel(i,k));
    				zoomx1.set_pixel(i,var+2,aux1);
    				
    				var = var+4;
    			}
    		
    		
    		}
    	
    	
    	}
    	
    	//interpolamos las filas 
    	for (int i = 0; i < zoomx1.get_rows(); i++){
    		for(int k = 0; k < zoomx1.get_cols() ; k++){
    			if(i % 2 == 0){
    				zoomx2.set_pixel(var2-1,k,zoomx1.get_pixel(i,k));
    			
    			}else{
    				byte aux = zoomx1.get_pixel(i-1,k) + zoomx1.get_pixel(i,k);
    				aux = aux / 2;
    				byte aux1 = zoomx1.get_pixel(i,k) + zoomx1.get_pixel(i+1,k);
    				aux1 = aux1 / 2;
    				
    				zoomx2.set_pixel(var2,k,aux);
    				zoomx2.set_pixel(var2+1,k,zoomx1.get_pixel(i,k));
    				zoomx2.set_pixel(var2+2,k,aux1);
    				
    				var2 = va2+4;
    			}
    		
    		
    		}
    	
    	
    	}
    
    
    
    
}

// Genera un icono como reducción de una imagen.
Image Subsample(int factor) const{
	
	//la matriz sera factor x factor
	Image chiquito (factor, factor);
	//Image copia (*this);
	int media = factor*factor;
	byte suma = 0; 
	int contador = 0, contador1 = 0, chico1 = 0, chico2 = 0;
	for (int i = 0; i < media; i++){
		for (int k = 0+contador; k < factor; k++){
			for (int j = 0+contador1; j < factor; j++){
				
				suma += get_pixel(k,j);	
				
				
			
			
			}
			
		}
		suma = suma / media;
		chiquito.set_pixel(chico1,chico2,suma);
		chico2++;
		if(chico2 >= factor){
			chico2 = 0;
			chico1++;
		}
		suma = 0;
		contador += factor;
		if (contador >= get_cols()){
			contador = 0;
			contador1 += factor;
			
		}
		
		
	
	
	}
	
	
	

}

// Modifica el contraste de una Imagen .
void AdjustContrast (byte in1, byte in2, byte out1, byte out2){

	
	for (int i = 0; i < get_rows(); i++){
		for(int k = 0; k < get_cols(); k++){
			byte aux = get_pixel(i,k);
			if(aux >= 0 && aux <= in1){
				
				byte aux2 = 0+((out1 -0 / (in1 - 0)) * (aux-0));
				
			
			}else if(aux >= in1 && aux <= in2){
			
				byte aux2 = in1+((out2 -out1 / (in2 - in1)) * (aux-in1));
			
			}else if (aux >= in2 && aux <= 255){
			
				byte aux2 = in2+((255 -ou2 / (255 - in2)) * (aux-in2));
			
			}
			
			set_pixel(i,k,aux2);
		
		}
	
	}












}


// Calcula la media de los píxeles de una imagen entera o de un fragmento de ésta.
double Mean (int i, int j, int height, int width) const{

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
	

