/*
 ============================================================================
 Name        : PROYECTO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "validaciones.h"
#include "entidad.h"

#define CANT_PRODUCTOS 10

int main(void) {
	setbuf(stdout,NULL);
	Producto producto[CANT_PRODUCTOS];
	int idProductos=0;
	int opcion;
	int auxIndice=0;
	int auxId=0;
	fflush(stdin);

	//nicializoArrayAlumnos(arrayPersonas,CANT_ALUMNOS);
	/*
	 * TOMAR EL PROGRAMA Y AGREGAR:
	 * UNA VEZ QUE INGRESA DATOS, SI DESEA APLICAR O NO UN DESCUENTO DEL 25%.
	 * SI ACEPTA MOSTRAR EL NUEVO PRECIO
	 * 2)HACER UNA FUNCION Q RECIBA LA VARIABLE PRODUCTO DEFINIDA Y QUE IMPRIMA SUS VALORES
	 */
	if(inicializoArray(producto, CANT_PRODUCTOS)==0)
	{
		printf("Array inicializado correctamente\n");
	}

	do{

	if(get_int(&opcion,3,"Ingrese una opcion\n"
		"0)CARGAR PRODUCTO\n"
		"1)MODIFICAR PRODUCTO\n"
		"2)ELIMINAR UN PRODUCTO\n"
		"3)ORDENAR LISTA DE PRODUCTOS\n"
		"4)IMPRIMIR LISTA DE PRODUCTOS\n"
		"5)SALIR\n","Opcion incorrecta.",0,5,2,0)==1)
		{
			switch(opcion)
			{
			case 0:
				auxIndice=getEmptyIndex(producto,CANT_PRODUCTOS);
				if(auxIndice>=0)
				{
					if(altaArray(producto, CANT_PRODUCTOS, auxIndice,&idProductos)==0)
					{
						printf("Carga realizada con exito\n");
					}
				}
				else
				{
					printf("No hay mas lugar\n");
				}
				break;
			case 1:
				imprimirArray(producto, CANT_PRODUCTOS);
				if(get_int(&auxId,2,"Indique el id del cliente a modificar:\n","ID invalido.",0,100,2,0)==1)
				{
					auxIndice=buscarId(producto, CANT_PRODUCTOS,auxId);
					if(auxIndice >=0 &&
						modificarArray(producto, CANT_PRODUCTOS, auxIndice)==0)
					{
						printf("Modificacion realizada con exito\n");
					}
				}
				break;
			case 2:
				imprimirArray(producto, CANT_PRODUCTOS);
				if(get_int(&auxId,2,"Indique el id del cliente a dar de baja:\n","ID invalido",0,100,2,0)==1)
				{
					auxIndice = buscarId(producto,CANT_PRODUCTOS,auxId);
					if(auxIndice >= 0 &&
					bajaArray(producto, CANT_PRODUCTOS,auxIndice)==0)
					{
						printf("Baja realizada con exito.");
					}
				}
				break;
			case 3:
				ordenarPorNombre(producto, CANT_PRODUCTOS);
				break;
			case 4:
					imprimirArray(producto, CANT_PRODUCTOS);
				break;
			}
		}
	}while(opcion != 5);
	imprimirArray(producto, CANT_PRODUCTOS);

	return EXIT_SUCCESS;
}


