/*
 * entidad.h
 *
 *  Created on: Apr 26, 2021
 *      Author: Stefano
 */

#ifndef ENTIDAD_H_
#define ENTIDAD_H_


typedef struct
{
		char nombre[30];
		char descripcion[50];
		float precio;
		int isEmpty;
		int id;

}Producto;

int imprimirArray(Producto* array,int limite);
int inicializoArray(Producto* array,int limite);
void mostrarValores(Producto valor);
void mostrarValoresPorReferencia(Producto* valor);
int cargarProducto(Producto* array, int limite, int indice);
int ordenarPorNombreYPrecio(Producto* array,int limite);
int ordenarPorNombre(Producto* array,int limite);
int getEmptyIndex(Producto* array,int limite);
int buscarId(Producto* array,int limite,int valorBuscado);
int bajaArray(Producto* array,int limite,int indice);
int modificarArray(Producto* array,int limite,int indice);
int altaArray(Producto* array,int limite,int indice,int* id);
#endif /* ENTIDAD_H_ */
