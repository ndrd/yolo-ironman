#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include <stdio.h>
#include <string.h>
#include "../memoria/memoria.h"
#include "../registros/registros.h"
#include "../alu/alu.h"

#define LIMITE_MEMORIA_INSTRUCCIONES 1024

int pc;

#define ADD 		0h0	
#define SUB 		0h1
#define MUL 		0h2		
#define DIV 		0h3		
#define FADD 		0h4		
#define FSUB 		0h5		
#define FMUL 		0h6	
#define FDIV 		0h7		
#define ANDR 		0h8		
#define OR 			0h9		
#define XOR 		0hA
#define NOT 		0hB
#define LB 			0hC
#define LW 			0hD
#define SB 			0hE
#define SW 			0hF
#define LI 			0h10	
#define B 			0h11		
#define BEQZ 		0h12
#define BLTZ 		0h13
#define SYSCALL 	0h14



struct instruccion
{
	int cod[4];
	char*c;
} ;

typedef struct 
{
	struct instruccion rows[LIMITE_MEMORIA_INSTRUCCIONES];
} memoria_instrucciones;

struct etiqueta {
	char nombre[20];
	int n_instruccion;	
} ;

struct 
{
	int limite;
	struct etiqueta indice[100];

} tabla_etiquetas;

int num_label;


int* encode(char*input,int*coded, memoria_ram *ram,int num);	 
void decode(int*encoded_inst, memoria_ram *ram);	

void load_instruccion_mem(struct memoria_instrucciones*im,int posiscion_mem,int*instruccion);  
void execute(struct memoria_instrucciones*im,int fin, memoria_ram *ram);

int posicion_label(char*name);			

#endif 