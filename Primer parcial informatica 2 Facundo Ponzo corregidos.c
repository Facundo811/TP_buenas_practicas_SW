#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//hola mundo

typedef struct {
	float tension;
	float corriente;
	char nombreMaquina[51];
}Maquina;

void cargarMaquina(Maquina *m);
void mostrarMaquinas(Maquina *m, int cantidad);
void buscarPorMaximos(Maquina *m, int cantidad);
void buscarPorLetra(Maquina *m, int cantidad);
void mostrarMenu();


int main() {
	Maquina *maquinas = NULL;
	int cantidad = 0;
	int opcion;
	
	do{
		mostrarMenu();
		
		scanf("%d", &opcion);
		
		switch (opcion) {
		case 1:
			maquinas = (Maquina*) realloc(maquinas, (cantidad + 1) * sizeof(Maquina));//maquinas = realloc(maquinas, (cantidad + 1) * sizeof(Maquina));
			
			if(maquinas == NULL){
				printf("Error de ingreso\n");
				return 1;
			}
			
			cargarMaquina(&maquinas[cantidad]);
			cantidad++;
			
			break;
			
		case 2:
			mostrarMaquinas(maquinas, cantidad);
			break;
			
		case 3:
			buscarPorMaximos(maquinas, cantidad);
			break;
			
		case 4:
			buscarPorLetra(maquinas, cantidad);
			break;
			
		case 0:
			printf("Proframa terminado");
			break;
			
		default:
			printf("Opcion invalida");
		}
	} while(opcion != 0);
	free(maquinas);
	
	return 0;
}

void mostrarMenu(){
	printf("1. Agregar Maquina\n");//agregar \n a todos
	printf("2. Mostrar datos ingresados\n");
	printf("3. Buscar por nombre\n");
	printf("4. Buscar por tension\n");
	printf("5. Buscar por corriente\n");
	printf("0. Salir\n");
	return;
}
	
	void cargarMaquina(Maquina *m){
		printf("Nombre de la maquina ");
		scanf(" %[^\n]", m->nombreMaquina);//scanf(" %[^\n]", m->nombremaquina);
		
		printf("tension: ");
		scanf("%f",&m->tension);
		
		printf("corriente: ");
		scanf("%f",&m->corriente);
	}
		
		void mostrarMaquinas(Maquina *m, int cantidad) {
			
			if(cantidad == 0){
				printf("\n no hay maquibnas cargadas\n");
				return;
			}
			
			printf("   MAQUINAS   ");
			
			for(int i = 0; i<cantidad; i++) {
				
				printf("\nMaquina %d\n", i + 1);
				printf("Nombre: %s\n", m[i].nombreMaquina);	//printf("Nombre: %d\n", m[i].nombreMaquina);
				printf("Tension: %.2f\n", m[i].tension);//printf("Tension: %d\n", m[i].tension);
				printf("Corriente: %.2f\n", m[i].corriente);//printf("Corriente: %d\n", m[i].corriente);
			}
		}
		
		void buscarPorMaximos(Maquina *m, int cantidad) {
			
			if(cantidad < 2) {
				printf("\n Se requieren al menos 2 maquinas \n");
				return;
			}
			int opcion;
			printf("\n 1.Tension \n");
			printf("\n 2.Corriente \n");
			printf("\n Seleccionar variable \n");
			scanf("%d", &opcion);
			
			int max1 = 0;//faltaba punto y coma
			int max2 = 0;//faltaba punto y coma
			
			float valor1, valor2;//faltaba punto y coma
			
			if(opcion ==1) {
				valor1 = m[max1].tension;
				valor2 = m[max2].tension;
			} else {
				valor1 = m[max1].corriente;
				valor2 = m[max2].corriente;
			}
			if(valor2 > valor1) {
				int aux = max1;
				max1 = max2;
				max2 = aux;
			}
			for(int i =2; i<cantidad; i++){
				float valorActual;
				
				if(opcion == 1) {
					valorActual = m[i].tension;
				} else {
					valorActual = m[i].corriente;
				}
				
				float maximo1, maximo2;
				
				if(opcion == 1) {
					maximo1 = m[max1].tension;
					maximo2 = m[max2].tension;
				} else {
					maximo1 = m[max1].corriente;
					maximo2 = m[max2].corriente;
				}
				
				if(valorActual > maximo1) {
					max2 = max1;
					max1 = i;
				}
				else if(valorActual > maximo2) {
					max2 = i;
				}
			}
			
			printf("\n Valores maximos \n");
			
			if(opcion == 1) {
				
				printf("\n n�1 mayor tension \n");
				printf("maquina: %s\n");
				printf("valor: %.2f \n");
				
				printf("\n n�2 mayor tension \n");
				printf("Maquina: %s \n");
				printf("Valor: %.2f \n");
				
			} else {
				
				printf("\n n�1 mayor corriente \n");
				printf("maquina: %s\n");
				printf("valor: %.2f \n");
				
				printf("\n n�2 mayor corriente \n");
				printf("Maquina: %s \n");
				printf("Valor: %.2f \n");
			}
		}
		
		
		void buscarPorLetra(Maquina *m, int cantidad){
			
			char letra;
			
			printf("Ingrese letra a buscar: ");
			scanf(" %c",&letra);
			
			printf("\n Maquinas que contienenen la letra '%c' :\n", letra);
			
			for(int i = 0; i < cantidad; i++) {
				
				if(strchr(m[i].nombreMaquina, letra) != NULL) {
					printf("%s\n", m[i].nombreMaquina);
				}
			}
			
		}
			
