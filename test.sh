name=`date +%d%m%Y%H%M%N.csv`
#for i in {1..12256}; do
for i in {1..37248}; do
    sleep 0.05s
    #foo=`gdate +%H%M%S%N`;
    #foo=`date +%H%M%S%N`;
    #i=`expr $foo / 1000`;
    #j=`gshuf -i 1-10000000 -n 1`;
    i=`shuf -i 1-10000000 -n 1`;
    j=`shuf -i 1-10000000 -n 1`;
    #echo "$i,$j"
    /usr/bin/mosquitto_pub -h localhost -t date/celsius -m "$i,$j"
    #/usr/bin/mosquitto_pub -h localhost -t date/celsius -m "$i,$j"
    echo "$i,$j" >> ${name}
done
# publish the signal to terminate
/usr/bin/mosquitto_pub -h  localhost -t date/celsius -m "0.0,0.0"
#publish the file name of generate data
/usr/bin/mosquitto_pub -h localhost -t final/final -m "${name},${name}"
