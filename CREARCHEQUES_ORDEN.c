#include <stdio.h>	//librerias
#include <conio.h>
#include <string.h>


int cantidad[300], folio[50],i,k;
int auxcantidad, auxfolio;
char nombre[50][50],cantidade[30][30],fecha[100][100],ap[50][50],am[50][50]; 
char auxnom[50],auxap[50],auxam[50], auxfecha[50];
 main(){

	leer();
	ordenar();
	cheque();
	getch();
}
leer(){
	FILE*fp;
    	if((fp=fopen("Final.txt","r"))==NULL){
    		printf("No fue posible abrirlo...");
    										 }
    		else{
				i=0;
        	while(!feof(fp)){
        fscanf(fp,"%s %s %s %s %d %d",fecha[i],nombre[i],ap[i],am[i],&cantidad[i],&folio[i]);
          		i++;
        					}
          	printf("\nEl archivo se ha leido con exito......\n\n");
        }
	fclose(fp);
}
ordenar(){
		for(k=0;k<50;k++){
			for(i=0;i<49;i++){
				if(nombre[i][0]>nombre[i+1][0]){
				
				auxcantidad=cantidad[i];
				cantidad[i]=cantidad[i+1];
				cantidad[i+1]=auxcantidad;
				
				auxfolio=folio[i];
				folio[i]=folio[i+1];
				folio[i+1]=auxfolio;
				
				strcpy(auxnom,nombre[i]);
				strcpy(nombre[i],nombre[i+1]);
				strcpy(nombre[i+1],auxnom);
				
				strcpy(auxap,ap[i]);
				strcpy(ap[i],ap[i+1]);
				strcpy(ap[i+1],auxap);
				
				strcpy(auxam,am[i]);
				strcpy(am[i],am[i+1]);
				strcpy(am[i+1],auxam);
				
				strcpy(auxfecha,fecha[i]);
				strcpy(fecha[i],fecha[i+1]);
				strcpy(fecha[i+1],auxfecha);
				
			}
		}
	}
			}
convertir(){
    int unidad=0;
    int decena=0;
    char Auxiliar[200][200];

	for(i=0;i<1;i++){
		unidad = cantidad[i] % 10 ;
		decena = cantidad[i] / 10 ;
		
		switch(decena){
			case 1:strcpy(cantidade[i],"diez");
			break;
			case 2:strcpy(cantidade[i],"veinte");
			break;
			case 3:strcpy(cantidade[i],"treinta");
			break;
			case 4:strcpy(cantidade[i],"cuarenta");
			break;
			case 5:strcpy(cantidade[i],"cincuenta");
			break;
			case 6:strcpy(cantidade[i],"sesenta");
			break;	
			case 7:strcpy(cantidade[i],"setenta");
			break;	
			case 8:strcpy(cantidade[i],"ochenta");
			break;		
			case 9:strcpy(cantidade[i],"noventa");
			break;	
			case 10:strcpy(cantidade[i],"Cien");
			break;	
						}
		if (decena==0 || decena==2){
			switch(unidad){ 
				case 0:strcpy(cantidade[i],"cero");
					break;
				case 1:strcpy(cantidade[i],"uno");
					break;
				case 2:strcpy(cantidade[i],"dos");
					break;
				case 3:strcpy(cantidade[i],"tres");
					break;
				case 4:strcpy(cantidade[i],"cuatro");
					break;				
				case 5:strcpy(cantidade[i],"cinco");
					break;			
				case 6:strcpy(cantidade[i],"seis");
					break;			
				case 7:strcpy(cantidad[i],"siete");
					break;
				case 8:strcpy(cantidade[i],"ocho");
					break;		
				case 9:strcpy(cantidade[i],"nueve");
			}
		}
		if (decena==1) 	{
			switch(unidad)	{			 
				case 0:strcpy(cantidade[i],"diez");
					break;
				case 1:strcpy(cantidade[i],"once");
					break;
				case 2:strcpy(cantidade[i],"doce");
					break;
				case 3:strcpy(cantidade[i],"trece");
					break;
				case 4:strcpy(cantidade[i],"catorce");
					break;
				case 5:strcpy(cantidade[i],"quince");
					break;
				case 6:strcpy(cantidade[i],"dieciseis");
					break;
				case 7:strcpy(cantidade[i],"diecisiete");
					break;
				case 8:strcpy(cantidade[i],"dieciocho");
					break;
				case 9:strcpy(cantidade[i],"diecinueve");
			}
		}	     
		if(decena==2){
	  		if (unidad==0){
	  			strcpy(cantidade[i],"veinte");
	  		}	
	  		else{
			    strcpy(Auxiliar[i],"veinti");
			    strcat(Auxiliar[i],cantidade[i]);
			    strcpy(cantidade[i],Auxiliar[i]);
	  		}
		}
		if(decena>2 && decena<10 && unidad!=0) {
			strcat(cantidade[i]," y ");
			switch(unidad)	{ 
				case 1:strcat(cantidade[i],"uno");
				break;
								//ELABORADO POR TRINIDAD RAMIREZ SERGIO NAHIN
				case 2:strcat(cantidade[i],"dos");
				break;
		
				case 3:strcat(cantidade[i],"tres");
				break;
		
				case 4:strcat(cantidade[i],"cuatro");
				break;
		
				case 5:strcat(cantidade[i],"cinco");
				break;
		
				case 6:strcat(cantidade[i],"seis");
				break;
		
				case 7:strcat(cantidade[i],"siete");
				break;
		
				case 8:strcat(cantidade[i],"ocho");
				break;
		
				case 9:strcat(cantidade[i],"nueve");
				break;
			}
		}
	}
}
cheque(){
	convertir();
		for(i=0;i<50;i++){
			printf("|-----------------------------------------------------------|\n");
				printf("\t BANCO AZTECA \t Folio: %d\n", folio[i]);
								printf("\t\t\t\tFecha: %s\n",fecha[i]);
				printf("Pagar a nombre de: %s %s %s\n", nombre[i],ap[i], am[i]);
				printf("la cantidad de $%d(%s pesos)\n", cantidad[i],cantidade[i]);
										printf("\t\t\t Autoriza: RECURSOS HUMANOS\n\n");
	}	
}
