#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic

program: obj/main.o obj/Clock.o obj/Quicksort.o obj/Tablica.o obj/MergeSort.o
           
	g++ -Wall -pedantic -o program obj/main.o obj/Clock.o obj/Quicksort.o obj/Tablica.o obj/MergeSort.o


obj:
	mkdir obj

obj/main.o: src/main.cpp inc/Clock.hh inc/Tablica.hh inc/MergeSort.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Clock.o: src/Clock.cpp inc/Clock.hh 
	g++ -c ${CXXFLAGS} -o obj/Clock.o src/Clock.cpp

obj/Tablica.o: src/Tablica.cpp inc/Tablica.hh
	g++ -c ${CXXFLAGS} -o obj/Tablica.o src/Tablica.cpp

obj/Quicksort.o: src/Quicksort.cpp
	g++ -c ${CXXFLAGS} -o obj/Quicksort.o src/Quicksort.cpp

obj/MergeSort.o: src/MergeSort.cpp
	g++ -c ${CXXFLAGS} -o obj/MergeSort.o src/MergeSort.cpp


clean:
	rm -f obj/*.o program

