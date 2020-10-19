COMPILEFLAGS=
CCOMP=gcc

main: main.o fileHandler.o push.o pop.o readTop.o nfaInit.o transitionInit.o addNfa.o addTrans.o print.o addTransEnd.o opAnd.o opOr.o opStar.o
	$(CCOMP) $(COMPILEFLAGS) -o main main.o fileHandler.o push.o pop.o readTop.o nfaInit.o transitionInit.o addNfa.o addTrans.o print.o addTransEnd.o opAnd.o opOr.o opStar.o
main.o: main.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c main.c
fileHandler.o: fileHandler.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c fileHandler.c
push.o: push.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c push.c
pop.o: pop.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c pop.c
readTop.o: readTop.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c readTop.c
nfaInit.o: nfaInit.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c nfaInit.c
transitionInit.o: transitionInit.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c transitionInit.c
addNfa.o: addNfa.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c addNfa.c
addTrans.o: addTrans.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c addTrans.c
print.o: print.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c print.c
addTransEnd.o: addTransEnd.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c addTransEnd.c
opAnd.o: opAnd.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c opAnd.c
opOr.o: opOr.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c opOr.c
opStar.o: opStar.c header.h
	$(CCOMP) $(COMPILEFLAGS) -c opStar.c
clean:
	rm main.o fileHandler.o push.o pop.o readTop.o nfaInit.o transitionInit.o addNfa.o addTrans.o print.o addTransEnd.o opAnd.o opOr.o opStar.o main
