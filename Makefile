#CFLAGS=-Wall -ggdb -I../../lib -I../../lib/cpp
#LDFLAGS=-L../../lib ../../lib/cpp/libmosquittopp.so.1 ../../lib/libmosquitto.so.1
CFLAGS=-Wall -std=c++11
LDFLAGS=-L/usr/lib/arm-linux-gnueabihf/libmosquittopp.so.1 /usr/lib/arm-linux-gnueabihf/libmosquitto.so.1 -lmosquittopp -lmosquitto -lpthread

.PHONY: all clean 

all : mqtt_date_amplitude 

mqtt_date_amplitude : main.o date_amplitude.o kmeans.beautifier.o kmeansPlusPlus.beautifier.o sort.beautifier.o
	${CXX} ${CFLAGS} $^ -o $@ ${LDFLAGS} 

main.o : main.cpp
	${CXX} ${CFLAGS} -c $^ -o $@

date_amplitide.o : date_amplitude.cpp
	${CXX} ${CFLAGS} -c $^ -o $@

kmeans.beautifier.o : kmeans.beautifier.cpp
	${CXX} ${CFLAGS} -c $^ -o $@

kmeansPlusPlus.beautifier.o : kmeansPlusPlus.beautifier.cpp
	${CXX} ${CFLAGS} -c $^ -o $@

sort.beautifier.o : sort.beautifier.cpp
	${CXX} ${CFLAGS} -c $^ -o $@

clean : 
	-rm -f *.o mqtt_date_amplitude
