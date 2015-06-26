SRC=src/main.c src/memoria/memoria.c  \
  src/registros/registros.c src/errores/errores.c
MAIN=main.c
BIN=myvm
CFLAGS=-g
SUBDIRECTORIES= src/compiler src/vm


compile: 
	gcc  -o ${BIN} ${SRC} 

clean:
	rm -rf *~ *.o ${BIN}

