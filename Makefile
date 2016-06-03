complete: barley-brick test clean

barley-brick: main.o project.o initialization.o movebrick.o wincase.o
	gcc -o barley-brick main.o project.o initialization.o movebrick.o wincase.o 

test: enter_test.o main_test.o 
	gcc -o test enter_test.o main_test.o project.o initialization.o movebrick.o -I ./thirdparty -I ./tests -I ./split-project

main.o: ./split-project/main.c
	gcc -c ./split-project/main.c

project.o: ./split-project/project.c
	gcc -c ./split-project/project.c

initialization.o: ./split-project/initialization.c
	gcc -c ./split-project/initialization.c

movebrick.o: ./split-project/movebrick.c
	gcc -c ./split-project/movebrick.c

wincase.o: ./split-project/wincase.c
	gcc -c ./split-project/wincase.c

enter_test.o: ./tests/enter_test.c 
	gcc -c ./tests/enter_test.c -I ./thirdparty -I ./split-project	

main_test.o: ./tests/main_test.c	
	gcc -c ./tests/main_test.c -I ./thirdparty -I ./split-project
clean:	
	rm *.o
