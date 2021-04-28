/*
 * entidad.c
 *
 *  Created on: Apr 26, 2021
 *      Author: Stefano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "validaciones.h"
#include "entidad.h"
/*
 * brief IMPRIMO EL ARRAY DE PERSONAS
 * param array Puntero al array de alumnos
 * param limite define el tamaño del array
 * return retorna 0(EXITO) y -1(ERROR)
 *
 */
#define LEN_NOMBRE 20
int imprimir(Producto* pElemento)
{
	int retorno=-1;
		if(pElemento != NULL && pElemento->isEmpty == 0)
		{
			retorno=0;
			printf("ID:%d\n"
					"NOMBRE:%s\n"
					"DESCRIPCION:%s\n"
					"PRECIO:%.2f\n",pElemento->id,pElemento->nombre,pElemento->descripcion,pElemento->precio);
		}
	return retorno;
}
int imprimirArray(Producto* array,int limite)
{
	int i;
	int retorno=-1;
	if(array != NULL && limite > 0 )
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			imprimir(&array[i]);
		}
	}
	return retorno;
}


/*
 * brief INICIALIZO EL ARRAY DE PERSONAS
 * param array Puntero al array de alumnos
 * param limite define el tamaño del array
 * return retorna 0(EXITO) y -1(ERROR)
 *
 */
int inicializoArray(Producto* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return retorno;
}
int altaArray(Producto* array,int limite,int indice,int* id)
{
	int retorno=-1;
	Producto auxiliar;
	if(array != NULL && id != NULL && limite > 0 && indice < limite && indice >= 0)
	{
		if(get_name(auxiliar.nombre,50,"Ingrese su nombre:\n","NO!\n",2)==1 &&
			get_text(auxiliar.descripcion,50,"Ingrese descripcion:\n","CUECK\n",2)==1 &&
			get_float(&auxiliar.precio,10,"Ingrese el precio:\n","Error\n",0,20000,2,0)==1)
			{
					auxiliar.id=*id;
					array[indice]=auxiliar;
					auxiliar.isEmpty=0;
					(*id)++;
					retorno=0;
			}
	}

	return retorno;
}

int modificarArray(Producto* array,int limite,int indice)
{
	int retorno=-1;
	Producto auxiliar;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty==0)
	{
		if(get_name(auxiliar.nombre,50,"Ingrese su nombre:\n","NO!\n",2)==1 &&
				get_text(auxiliar.descripcion,50,"Ingrese descripcion:\n","CUECK\n",2)==1 &&
				get_float(&auxiliar.precio,10,"Ingrese el precio:\n","Error\n",0,20000,2,0)==1)
				{
						retorno=0;
						auxiliar.id=array[indice].id;
						auxiliar.isEmpty=0;
						array[indice]=auxiliar;
				}
	}
	return retorno;
}
int bajaArray(Producto* array,int limite,int indice)
{
	int retorno=-1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty==0)
	{
		array[indice].isEmpty=1;
		retorno=0;
	}
	return retorno;
}
int buscarId(Producto* array,int limite,int valorBuscado)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			if(array[i].id==valorBuscado)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int getEmptyIndex(Producto* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty==1)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
int ordenarPorNombre(Producto* array,int limite)
{
	int retorno=-1;
	int i;
	int flagSwap;
	int auxCmp;
	Producto buffer;
	if(array != NULL && limite > 0)
	{
		retorno=0;
		do{
			flagSwap=0;
			for(i=0;i<limite;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				auxCmp=strncmp(array[i].nombre,array[i+1].nombre,LEN_NOMBRE);
				//if(array[i].precio < array[i+1].precio) PARA ORDENAR NUMEROS
				if(auxCmp> 0) //PARA ORDENAR STRING LOS COMPARO CON
				{															//STRNCMP
					flagSwap=1;
					buffer=array[i];
					array[i]=array[i+1];
					array[i+1]=buffer;
				}
			}
		limite--;
		}while(flagSwap);
	}
	return retorno;
}
int ordenarPorNombreYPrecio(Producto* array,int limite)
{
	int retorno=-1;
	int i;
	int flagSwap;
	int auxCmp;
	Producto buffer;
	if(array != NULL && limite > 0)
	{
		retorno=0;
		do{
			flagSwap=0;
			for(i=0;i<limite;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				auxCmp=strncmp(array[i].nombre,array[i+1].nombre,LEN_NOMBRE);
				if( auxCmp> 0 ||
					(auxCmp== 0 && array[i].precio < array[i+1].precio))
				{
					flagSwap=1;
					buffer=array[i];
					array[i]=array[i+1];
					array[i+1]=buffer;
				}
			}
		limite--;
		}while(flagSwap);
	}
	return retorno;
}


void mostrarValores(Producto valor)
{
	printf("NOMBRE:%s\nDESCRIPCION:%s\nPRECIO%.3f\n",valor.nombre,valor.descripcion,valor.precio);
}
void mostrarValoresPorReferencia(Producto* valor)
{
	printf("NOMBRE:%s\nDESCRIPCION:%s\nPRECIO%.3f\n",valor->nombre,valor->descripcion,valor->precio);
}
int cargarProducto(Producto* array, int limite, int indice)
{
	int retorno=-1;
	if(array != NULL && limite >= 0 && indice < limite)
	{
			if(get_name(array[indice].nombre,50,"Ingrese su nombre:\n","NO!\n",2)==1 &&
				get_text(array[indice].descripcion,50,"Ingrese descripcion:\n","CUECK\n",2)==1 &&
				get_float(&array[indice].precio,10,"Ingrese el precio:\n","Error\n",0,20000,2,0)==1)
			{
				array[indice].isEmpty=0;
				retorno=0;
			}
	}
	return retorno;
}
