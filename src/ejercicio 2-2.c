/*
 ============================================================================
 Name        : ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Ejercicio 2-2: Ingresar números enteros, hasta que el usuario pida.
 Mostrar:
a) El promedio de los positivos y su mínimo.
b) El promedio de los negativos y su máximo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	int numero;
	char respuesta;
	char simbolo;

	float promedioPositivos;
	int   contadorPositivos;
	int   acumuladorPositivos;
	contadorPositivos=0;
	acumuladorPositivos=0;

	float promedioNegativos;
	int   contadorNegativos;
	int   acumuladorNegativos;
	contadorNegativos=0;
	acumuladorNegativos=0;

	int flagMinimoPositivo;
	int flagMaximoNegativo;
	int minimoPos;
	int maximoNeg;

	flagMinimoPositivo=0;
	flagMaximoNegativo=0;

	do
	{
		printf("ingrese simbolo positivo o negativo");
		fflush(stdin);
		scanf("%c",&simbolo);

		while(simbolo != 'p' && simbolo != 'n')
		{
			printf("error reingrese simbolo");
			fflush(stdin);
			scanf("%c",&simbolo);
		}

		switch(simbolo)
		{
		case 'p':
					printf("ingrese numero positivo");
					scanf("%d",&numero);
					while(numero<0)
					{
						printf("error reingrese numero positivo");
						scanf("%d",&numero);
					}

					contadorPositivos++;
					acumuladorPositivos+=numero;

					if(numero<minimoPos || flagMinimoPositivo ==0)
					{
						minimoPos=numero;
						flagMinimoPositivo=1;
					}

			break;

		case 'n':
					printf("ingrese numero negativo");
					scanf("%d",&numero);
					while(numero>=0)
					{
						printf("error reingrese numero negativo");
						scanf("%d",&numero);
					}

					contadorNegativos++;
					acumuladorNegativos+=numero;

					if(numero>maximoNeg || flagMaximoNegativo ==0)
					{
						maximoNeg=numero;
						flagMaximoNegativo=1;
					}
			break;
		}

		printf("desea agregrar otro numero? coloque  s\n");
		fflush(stdin);
		scanf("%c",&respuesta);

	}while(respuesta=='s');

	printf("el minimo de los positivos es %d\n",minimoPos);
	printf("el maximo negativo es %d\n",maximoNeg);

	if(contadorPositivos != 0)
	{
		promedioPositivos= (float)acumuladorPositivos/contadorPositivos;
		printf("el promedio de los positivos es %.2f\n",promedioPositivos);
	}
	else
	{
		printf("no se pudo calcular el promedio de los positivos\n");
	}

	if(contadorNegativos != 0)
	{
		promedioNegativos= (float)acumuladorNegativos/contadorNegativos;
		printf("el promedio de los negativos es %.2f\n",promedioNegativos);
	}
	else
	{
		printf("el promedio de los negativos no se pudo calcular\n");
	}

	return 0;
}
