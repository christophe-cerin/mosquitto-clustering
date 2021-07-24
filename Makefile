#CFLAGS=-Wall -ggdb -I../../lib -I../../lib/cpp
LDFLAGS=-L../../mosquitto/lib ../../mosquitto/lib/cpp/libmosquittopp.so.1 ../../mosquitto/lib/libmosquitto.so.1 -lpthread
CFLAGS=-Wall -O3 -std=c++11 -ggdb
#LDFLAGS=-L/usr/lib/arm-linux-gnueabihf/libmosquittopp.so.1 /usr/lib/arm-linux-gnueabihf/libmosquitto.so.1 -lmosquittopp -lmosquitto -lpthread

.PHONY: all clean 

all : mqtt_date_amplitude 

#
# date_amplitude.o ==> the original implementation for publishing/subscribing
# date_amplitude_kmeans.o => for using kmeans
# date_amplitude_kmeansplusplus.o => for using kmeans++
#

#mqtt_date_amplitude : main.o date_amplitude_kmeansplusplus.o kmeansPlusPlus.beautifier.o kmeans.beautifier.o sort.beautifier.o
#	${CXX} ${CFLAGS} $^ -o $@ ${LDFLAGS} 

mqtt_date_amplitude : main.o date_amplitude_kmeans.o kmeans.beautifier.o kmeans.beautifier.o sort.beautifier.o
	${CXX} ${CFLAGS} $^ -o $@ ${LDFLAGS} 

main.o : main.cpp
	${CXX} ${CFLAGS} -c $^ -o $@

date_amplitude_kmeansplusplus.o : date_amplitude_kmeansplusplus.cpp
	${CXX} ${CFLAGS} -c $^ -o $@

date_amplitude_kmeans.o : date_amplitude_kmeans.cpp
	${CXX} ${CFLAGS} -c $^ -o $@

kmeans.beautifier.o : kmeans.beautifier.cpp
	${CXX} ${CFLAGS} -c $^ -o $@

kmeansPlusPlus.beautifier.o : kmeansPlusPlus.beautifier.cpp
	${CXX} ${CFLAGS} -c $^ -o $@

sort.beautifier.o : sort.beautifier.cpp
	${CXX} ${CFLAGS} -c $^ -o $@

clean : 
	-rm -f *.o mqtt_date_amplitude
