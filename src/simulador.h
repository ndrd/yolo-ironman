#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "memoria/memoria.h"
#include "registros/registros.h"
#include "instrucciones/instrucciones.h"
#include "lector/lector.h"
#include "alu/alu.h"

void ejecuta_instruccion(int pc, instruccion *instr, memoria_ram *ram, int *total_de_ciclos);


void 
run_simulator(memoria_ram *ram, memoria_instrucciones *mar, FILE *binario) 
{
	if (binario != NULL)
		cargar_binario(binario, mar, ram);
	else
		return;

	/* verificamos que las instrucciones se hayan cargado correctamente */
	if (mar->n <= 2)
		printf("Ejecucion terminada correctamente\n");

	int pc = 0;
	int total_de_ciclos = 0;

	while(pc <= mar->n)
	{
		ejecuta_instruccion(pc, &mar->rows[pc], ram, &total_de_ciclos);
		pc++;
	}
	printf("Total de cilcos %d\n", total_de_ciclos);
}

void ejecuta_instruccion(int pc, instruccion *instr, memoria_ram *ram, int *total_de_ciclos)
{

	int dest = instr->r3;
	int reg1 = instr->r1;
	int reg2 = instr->r2;
	int num = instr->dato;
	int val = num;
	
	switch (instr->opcode)	 {
		case ADD:
			add(dest, reg1, reg2);
			*(total_de_ciclos) += C_ADD;
			printf("haciendo C_ADD %d %d %d \n", dest, reg1, reg2);
			break;
		case SUB :
			sub(dest, reg1, reg2);
			*(total_de_ciclos) += C_SUB;
			printf("haciendo C_SUB %d %d %d \n", dest, reg1, reg2);
			break;
		case MUL:
			mul(dest, reg1, reg2);
			*(total_de_ciclos) += C_MUL;
			printf("haciendo C_MUL %d %d %d \n", dest, reg1, reg2);
			break;
		case DIV :
			divi(dest, reg1, reg2);
			*(total_de_ciclos) += C_DIV;
			printf("haciendo C_DIV %d %d %d \n", dest, reg1, reg2);
			break;
		case FADD :
			fadd(dest, reg1, reg2);
			*(total_de_ciclos) += C_FADD;
			printf("haciendo C_FAD %d %d %d \n", dest, reg1, reg2);
			break;
		case FSUB :
			fsub(dest, reg1, reg2);	
			*(total_de_ciclos) += C_FSUB;
			printf("haciendo C_FSU %d %d %d \n", dest, reg1, reg2);
			break;
		case FMUL :
			fmul(dest, reg1, reg2);
			*(total_de_ciclos) += C_FMUL;
			printf("haciendo C_FMU %d %d %d \n", dest, reg1, reg2);
			break;
		case FDIV :
			fdiv(dest, reg1, reg2);
			*(total_de_ciclos) += C_FDIV;
			printf("haciendo C_FDI %d %d %d \n", dest, reg1, reg2);
			break;
		case ANDR:
			and(dest, reg1, reg2);
			*(total_de_ciclos) += C_ANDR;
			printf("haciendo C_AND %d %d %d \n", dest, reg1, reg2);
			break;
		case OR:
			or(dest, reg1, reg2);
			*(total_de_ciclos) += C_OR;
			printf("haciendo C_OR %d %d %d \n", dest, reg1, reg2);
			break;
		case XOR :
			xor(dest, reg1, reg2);
			*(total_de_ciclos) += C_XOR;
			printf("haciendo C_XOR %d %d %d \n", dest, reg1, reg2);
			break;
		case NOT :
			not(num);
			*(total_de_ciclos) += C_NOT;
			printf("haciendo C_NOT %d %d %d \n", dest, reg1, reg2);
			break;
		case LB:
			lb(dest,reg1,ram);
			*(total_de_ciclos) += C_LB;
			printf("haciendo C_LB %d %d %d \n", dest, reg1, reg2);
			break;
		case LW:
			lw(dest,reg1,ram);	
			*(total_de_ciclos) += C_LW;
			printf("haciendo C_LW %d %d %d \n", dest, reg1, reg2);
			break;
		case SB:
			sb(dest,reg1,ram);
			*(total_de_ciclos) += C_SB;
			printf("haciendo C_SB %d %d %d \n", dest, reg1, reg2);
			break;
		case SW :
			sw(dest,reg1,ram);
			*(total_de_ciclos) += C_SW;
			printf("haciendo C_SW %d %d %d \n", dest, reg1, reg2);
			break;
		case LI:
			li(dest,val);
			*(total_de_ciclos) += C_LI;
			printf("haciendo C_LI %d %d %d \n", dest, reg1, reg2);
			break;
		case B:
			b(num);
			*(total_de_ciclos) += C_B;
			printf("haciendo C_B %d %d %d \n" , dest, reg1, reg2);
			break;
		case BEQZ :
			beqz(num);
			*(total_de_ciclos) += C_BEQZ;
			printf("haciendo C_BEQ %d %d %d \n", dest, reg1, reg2);
			break;
		case BLTZ :
			bltz(num);
			*(total_de_ciclos) += C_BLTZ;
			printf("haciendo C_BLT %d %d %d \n", dest, reg1, reg2);
			break;
		case SYSCALL:
			syscalli();
			*(total_de_ciclos) += C_SYSCALL;
			printf("haciendo C_SYS %d %d %d \n", dest, reg1, reg2);
		break;
	}

}




