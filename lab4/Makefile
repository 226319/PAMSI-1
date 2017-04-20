#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic

program: obj obj/main.o obj/List.o obj/Stack.o obj/Queue.o obj/Clock.o \
           
	g++ -Wall -pedantic -o program obj/main.o obj/List.o\
                        obj/Stack.o obj/Queue.o obj/Clock.o 

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/List.hh inc/Stack.hh inc/Queue.hh inc/Clock.hh 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp


obj/List.o: src/List.cpp inc/List.hh 
	g++ -c ${CXXFLAGS} -o obj/List.o src/List.cpp

obj/Queue.o: src/Queue.cpp inc/Queue.hh
	g++ -c ${CXXFLAGS} -o obj/Queue.o src/Queue.cpp

obj/Stack.o: src/Stack.cpp inc/Stack.hh 
	g++ -c ${CXXFLAGS} -o obj/Stack.o src/Stack.cpp

obj/Clock.o: src/Clock.cpp inc/Clock.hh
	g++ -c ${CXXFLAGS} -o obj/Clock.o src/Clock.cpp


clean:
	rm -f obj/*.o program

