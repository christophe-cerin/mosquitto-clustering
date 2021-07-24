#CFLAGS=-Wall -ggdb -I../../lib -I../../lib/cpp
#LDFLAGS=-L../../lib ../../lib/cpp/libmosquittopp.so.1 ../../lib/libmosquitto.so.1
CFLAGS=-Wall -O3 -fopenmp
CXXFLAGS=-Wall -O3 -fopenmp
LDFLAGS=-L/usr/local/lib/libmosquittopp.so.1 /usr/local/lib/libmosquitto.so.1 -lmosquittopp -lmosquitto -lgomp -fopenmp

.PHONY: all clean

all : mykmeans

mykmeans : main.beautifier.o kmeans.beautifier.o kmeansPlusPlus.beautifier.o sort.beautifier.o
	${CXX} $^ -o $@ ${LDFLAGS}

main.beautifier.o : main.beautifier.cpp
	${CXX} -c $^ -o $@ ${CFXXLAGS}

kmeans.beautifier.o : kmeans.beautifier.cpp
	${CXX} -c $^ -o $@ ${CXXFLAGS}

kmeansPlusPlus.beautifier.o : kmeansPlusPlus.beautifier.cpp
	${CXX} -c $^ -o $@ ${CXXFLAGS}

sort.beautifier.o : sort.beautifier.cpp
	${CXX} -c $^ -o $@ ${CXXFLAGS}

clean : 
	-rm -f *.o mykmeans
