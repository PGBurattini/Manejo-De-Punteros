/*   PUNTEROS A ESTRUCTURA  */
/*   VECTOR DE PUNTEROS ESTRUCTURAS  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct ALUMNO {
	char NOM[20] ;
	char SEX ;
	int NOTA ;
};

#define NUM 12

void CARGAR ( struct ALUMNO * , int );
void MIRAR ( struct ALUMNO * , int );
struct ALUMNO * PEOR_ALUMNO ( struct ALUMNO * , int );

int main()
{  		
		struct ALUMNO VEC[NUM];
		struct ALUMNO * VP[NUM];
		int I, J;
		struct ALUMNO * VPAUX;
		
		CARGAR ( VEC , NUM );
		printf("\n\n\n\n VECTOR ORIGINAL");
		MIRAR ( VEC , NUM );
		
		/* INICIALIZACION DEL VECTOR DE PUNTEROS */
		for ( I = 0 ; I < NUM ; I++)
			//	VP[I] = &VEC[I];
				*(VP+I) = VEC+I;
		
					
		printf("\n\n\n DATOS A TRAVES DEL VECTOR DE PUNTEROS \n");
		for ( I = 0 ; I < NUM ; I++ ) 
				printf("\n\n\t\t %-15s%8c%10d" , 
				(*(VP+I)) -> NOM , (*(VP+I)) -> SEX , (*(VP+I)) -> NOTA) ;
		getchar();
		
		
		
				/*ORDENAMIENTO*/	
		for ( I = 0 ; I < NUM ; I++)
			for ( J = 0 ; J < NUM-I-1 ; J++)
				if ( (*(VP+J)) -> NOTA < (*(VP+J+1)) -> NOTA ){
					
					VPAUX = *(VP+J);
					*(VP+J) = *(VP+J+1);
					*(VP+J+1) = VPAUX;
					
				}
		printf("\n\n\n DATOS A TRAVES DEL VECTOR DE PUNTEROS \n");
		for ( I = 0 ; I < NUM ; I++ ) 
				printf("\n\n\t\t %-15s%8c%10d" , 
				(*(VP+I)) -> NOM , (*(VP+I)) -> SEX , (*(VP+I)) -> NOTA) ;
		getchar();
		
		printf("\n\n\n\n VECTOR ORDENADO");
		MIRAR ( VEC , NUM );
		printf("\n\n");	
		return 0 ;
}


void CARGAR ( struct ALUMNO * P , int N )
{
		int I ;
		
		char NOM[][20] = {"CAROLINA","PEPE","LOLA","CARLOS",
		                  "LUCRECIA","PEDRO","ANA","LAURA",
						  "FILIBERTO","PERICO","BARTOLO","LAUTARO"};
		char SEX[] = {'F','M','F','M','F','M',
		              'F','F','M','M','M','M'};
		
		/*  CARGA DE DATOS  */
		for ( I = 0 ; I < N ; I++ ) {
				strcpy ( (P+I)->NOM , NOM[I] );
				(P+I)->SEX = SEX[I] ;
				(P+I)->NOTA = 2 + rand()%9 ;
		}
}

void MIRAR ( struct ALUMNO * P , int N )
{
		int I ;
		
			
		printf("\n\n\n \n");
		for ( I = 0 ; I < N ; I++ ) 
				printf("\n\n\t\t %-15s%8c%10d" , 
				(P+I)->NOM , (P+I)->SEX , (P+I)->NOTA );
		getchar();	
}


