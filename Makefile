COMPILEFLAGS=
CCOMP=gcc

main: main.o fileHandler.o 
	$(CCOMP) $(COMPILEFLAGS) -o main main.o fileHandler.o
main.o: main.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c main.c
fileHandler.o: fileHandler.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c fileHandler.c
clean:
	rm main.o fileHandler.o main

