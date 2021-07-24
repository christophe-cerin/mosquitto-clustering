#!/bin/bash

#name=`date +%d%m%Y%H%M%N.csv`

if [ $# -lt 1 ]; then
    echo "Need a file name as argument!"
    exit 1
fi

n=37248
for i in {1..37248}; do
    sleep 0.05s
    read line
    if [ $(($i % 2048)) -eq 0 ]; then 
	echo "I read $i data over $n"
    fi
    /usr/bin/mosquitto_pub -h localhost -t date/celsius -m "$line"
done  < $1

# publish the signal to terminate
/usr/bin/mosquitto_pub -h  localhost -t date/celsius -m "0.0,0.0"
#publish the file name of generate data
filename=$(basename -- "$1")
/usr/bin/mosquitto_pub -h localhost -t final/final -m "${filename},${filename}"
