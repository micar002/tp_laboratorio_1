/*
 ============================================================================
 Name        : utn_getNum.c
 Author      : Micaela Ramirez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Calculos.h"
#define INCREMENTO 25
#define DESCUENTO 10
#define BITCOIN 4,612,786.59


int calcularCostos(int costoCalculado, int Latam, int Aerolinea);
int main(void) {
	int kilometros;
	float costoVueloAerolinea;
	int respuesta;
	float costoVueloLatam;
	int opcion;
	int respuesta;
	float calcularCostos;
	float precioAerolineas;
	float debitoAerolineas;
	float creditoAerolineas;
	float bitcoinAerolineas;
	float precioUnitarioAerolineas;
	float precioLatam;
	float debitoLatam;
	float creditoLatam;
	float bitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaPrecios;



	do(respuesta!=6)
	{
		printf("Ingrese opcion 1 para kilometros \n 2 ingrese precio \n 3 diferencia de precio");
		scanf("%d",&opcion);
		printf("Ingrese el precio del vuelo");
		scanf("%g",&costoVueloAerolinea);


		switch(opcion)
			{
				case 1:
					if(kilometros<0){
						printf("Ingrese kilometros validos");
						scanf("%d",&kilometros);
					}
					break;
				case 2:
						if(costoVueloAerolinea<0)
						{
							printf("Ingresa precio valido");
							scanf("%g",&costoVueloAerolinea);
						}
					break;
				case 3:
					if(calcularCostos(precioAerolineas, kilometros, &debitoAerolineas, &creditoAerolineas, &bitcoinAerolineas, &precioUnitarioAerolineas, INCREMENTO, DESCUENTO, BITCOIN) &&
										calcularCostos(precioLatam, kilometros, &debitoLatam, &creditoLatam, &bitcoinLatam, &precioUnitarioLatam, INCREMENTO, DESCUENTO, BITCOIN) &&
										calcularDiferenciaPrecios(precioAerolineas, precioLatam, &diferenciaPrecios))
												{
													printf("*Costos calculados correctamente.*\n");

												}
												else
													{
														printf("\nPrimero debe ingresar los kilometros y los precios.\n");
													}
					break;
			}
	}

	return 0;
}

int calcularPrecioDebito(float precio, int descuento, float* precioTotal){


	int retorno=0;

	if(precio>0 && descuento>0 && precioTotal!=NULL)
	{
		*precioTotal = precio - ((precio * descuento)/100);
		retorno=1;
	}

	return retorno;
}
int calcularPrecioCredito(float precio, int incremento, float*precioTotal){


	int retorno=0;

	if(precio>0 && incremento>0 && precioTotal != NULL)
	{
		*precioTotal = precio + ((precio * incremento)/100);
		retorno=1;
	}

	return retorno;
}
int calcularPrecioBitcoin(float precioPesos, float precioBitcoin, float* precioTotal){
	int retorno=0;

		if(precioPesos>0 && precioBitcoin>0 && precioTotal != NULL)
		{
			*precioTotal= precioPesos/precioBitcoin;
			retorno=1;
		}

		return retorno;
}
int calcularPrecioUnitario(float precio, float kilometros, float* precioTotal){
	int retorno=0;

		if(precio>0 && kilometros>0 && precioTotal != NULL)
		{
			*precioTotal = precio/kilometros;
			retorno=1;
		}

		return retorno;
}
int calcularDiferenciaPrecio(float precioUno, float precioDos, float* precioTotal){
	int retorno = 0;

		if (precioUno > 0 && precioDos > 0 && precioTotal != NULL)
		{
			*precioTotal = precioDos - precioUno;
			retorno = 1;
		}

		return retorno;
}
int calcularCostos(float precio, float kilometros, float* precioDebito, float* precioCredito, float* precioConBitcoin, float* precioUnitario, int incremento, int descuento, float bitcoin){
	int retorno=0;
		if(calcularPrecioDebito(precio, descuento, precioDebito) &&
			calcularPrecioCredito(precio, incremento, precioCredito) &&
			calcularPrecioBitcoin(precio, bitcoin, precioConBitcoin) &&
			calcularPrecioUnitario(precio, kilometros,precioUnitario))
		{
			retorno=1;
		}
		return retorno;
}

