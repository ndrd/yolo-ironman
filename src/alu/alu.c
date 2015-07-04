#include "alu.h"
#include <stdio.h>

void add(int dest, int reg1, int reg2)
{	
		
	int a = registros[reg1].data;
	int b = registros[reg2].data;
	registros[dest].data=a+b;
	pc++;

	return;
}

 
void sub(int dest,int reg1,int reg2)
{	

	int a=registros[reg1].data;
	int b=registros[reg2].data;
	
	registros[dest].data=a-b;
	pc++;

	return;
}

void mul (int dest,int reg1,int reg2)
{	
		
	int a=registros[reg1].data;
	int b=registros[reg2].data;
	
	registros[dest].data=a*b;
	pc++;

	return;
}	
void divi (int dest,int reg1,int reg2)
{	
		
	int a=registros[reg1].data;
	int b=registros[reg2].data;
	printf("no, es\n");

	if(b <= 0)
		tirar_error(DIVISION_CERO) ;

	registros[dest].data=a/b;
	pc++;

	return;
}


void fadd(int dest,int reg1,int reg2)
{	
		
	int a=registros[reg1].data;
	int b=registros[reg2].data;
	registros[dest].data=a+b;
	pc++;

	return;
}

 
void fsub(int dest,int reg1,int reg2)
{	
		
	int a=registros[reg1].data;
	int b=registros[reg2].data;
	
	registros[dest].data=a-b;
	pc++;

	return;
}
void fmul (int dest,int reg1,int reg2)
{	
		
	int a=registros[reg1].data;
	int b=registros[reg2].data;

	registros[dest].data=a*b;
	pc++;

	return;
}	
void fdiv (int dest,int reg1,int reg2)
{	
		
	int a=registros[reg1].data;
	int b=registros[reg2].data;
	printf("es aqui\n");
	if(b <= 0)
		tirar_error(DIVISION_CERO) ;
	registros[dest].data= a / b;
	pc++;

	return;
}


void and(int dest,int reg1,int reg2)
{	

	int a=registros[reg1].data;
	int b=registros[reg2].data;
	
	registros[dest].data = a & b;
	pc++;
	return;
}
 


void or(int dest,int reg1,int reg2)
{
		
			
	int a=registros[reg1].data;
	int b=registros[reg2].data;
	
	registros[dest].data = a | b;
	pc++;
	
	
	return;
}
 
void not(int reg1)
{
				
	int a=registros[reg1].data;
	
	a = -a;
	pc++;
	
	return;
}
 
 void xor(int dest,int reg1,int reg2)
{
		
	int a=registros[reg1].data;
	int b=registros[reg2].data;
	
	registros[dest].data= ((a + b) * ((-a) + (-b))) ;
	pc++;
	
	
	return;
}
 
 

void li(int dest, int val)
{
	printf("%d\n",dest);
	registros[dest].data = val;
	pc++;	
		
	return;
}


void lw(int dest,int addr, memoria_ram *ram)
{
	registros[dest].data=(ram->rows[addr].data);
	pc++;
	return;
}

void sw(int dest, int addr, memoria_ram *ram)
{
	ram->rows[addr].data = registros[dest].data;
	pc++;
	return;	
}

void lb(int dest,int addr,memoria_ram *ram)
{
	registros[dest].data=(ram->rows[addr].data);
	pc++;
	return;
}

void sb(int dest,int addr,memoria_ram *ram)
{
	ram->rows[addr].data=registros[dest].data;
	pc++;
	return;	
}

void b(int pc_dest)
{	
	pc = tabla_etiquetas.indice[pc_dest].n_instruccion;
	return;
}

void beqz(int pc_dest)
{	
	if (pc_dest == 0)
		pc = tabla_etiquetas.indice[pc_dest].n_instruccion;
	else
		return;

}
void bltz(int pc_dest)
{	
	if(pc_dest < 0)
		pc=tabla_etiquetas.indice[pc_dest].n_instruccion;
	else
		return;

}


void syscalli()
{
	if(registros[8].data==0)
	{ 
		scanf("%d",&registros[8].data);
		registros[10].data = registros[8].data;
		prinftf("%d",registros[10].data);
	}
	if(registros[8].data==1)
	{ 
		scanf("%d",&registros[8].data);
		registros[10].data = registros[8].data;
		prinftf("caracter leido:%d",registros[10].data);
	}
	if(registros[8].data==2)
	{ 
		scanf("%d",&registros[8].data);
		registros[10].data = registros[8].data;
		prinftf("numero leido:%d",registros[10].data);
	}
	if(registros[8].data==3)
	{ 
		scanf("%d",&registros[8].data);
		registros[10].data = registros[8].data;
		prinftf("numero de caracteres leido:%d",registros[10].data);
	}

	if(registros[9].data==4)
	{ 
		scanf("%d",&registros[9].data);
		registros[9].data = registros[9].data;
		prinftf("%d\n",registros[9].data);
	}
	if(registros[9].data==5)
	{ 
		scanf("%d",&registros[9].data);
		registros[9].data = registros[9].data;
		prinftf("%d\n",registros[9].data);
	}
	if(registros[9].data==6)
	{ 
		scanf("%d",&registros[9].data);
		registros[9].data = registros[9].data;
		prinftf("%d\n",registros[9].data);
	}
	if(registros[9].data==7)
	{ 
		scanf("%d",&registros[9].data);
		registros[9].data = registros[9].data;
		prinftf("%d\n",registros[9].data);
	}
	if(registros[10].data==8)
	{ 
		exit(0);
	}
	if(registros[2].data==1)
	{
		printf("%d\n",registros[4].data);		
	}
	else if(registros[2].data==5)
	{
		scanf("%d",&registros[2].data);

	}
	else if(registros[2].data==10)
	{

		exit(0);
	}	
	
	pc++;
	return;	
}