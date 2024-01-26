CC = gcc
OBJ_LOOP = basicClassification.o advancedClassificationLoop.o
OBJ_REC = basicClassification.o advancedClassificationRecursion.o
MAIN_FILE = main.c


all: mains maindloop mainrec

### build static libraries ###
loop: libclassloops.a
libclassloops.a: $(OBJ_LOOP)
	ar rc libclassloops.a $(OBJ_LOOP)

recursive: libclassrec.a
libclassrec.a: $(OBJ_REC)
	ar rc libclassrec.a $(OBJ_REC)
### end build static libraries ###

### build dynamic libraries ###
recursived: libclassrec.so
libclassrec.so: $(OBJ_REC)
	$(CC) -shared $(OBJ_REC) -o libclassrec.so
	export LD_LIBRARY_PATH=.

looped: libclassloops.so
libclassloops.so: $(OBJ_LOOP)
	$(CC) -shared $(OBJ_LOOP) -o libclassloops.so
	export LD_LIBRARY_PATH=.
### end build dynamic libraries ###


### build main ###
mains: main.o libclassrec.a
	$(CC) -o mains main.o libclassrec.a

maindloop: main.o libclassloops.so
	$(CC) main.o -L . -lclassloops -o maindloop

mainrec: main.o libclassrec.so
	$(CC) main.o -L . -lclassrec -o mainrec


### end build main ###

### build files ###
main.o: main.c NumClass.h
	$(CC) -Wall -c main.c

basicClassification.o: basicClassification.c NumClass.h
	$(CC) -Wall -fPIC -c basicClassification.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) -Wall -fPIC -c advancedClassificationRecursion.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) -Wall -fPIC -c advancedClassificationLoop.c
### end build files ###

clean:
	rm -f *.o^
	rm -f *.a^
	rm -f *.so^

#make loop, make recursive, make recursived, make looped, make mains, make maindloop, make mainrec, make all, make clean