
# Start broker
#mqtt_date_amplitude &

#sleep 2s

# Execute the experiments, sequentially
for k in {1..1}; do

    echo "Iteration $k starts"
    
    name=`date +%d%m%Y%H%M%N.csv`

    for i in {1..12256}; do
    #for i in {1..286}; do
	sleep 0.25s
	#foo=`gdate +%H%M%S%N`;
	#foo=`date +%H%M%S%N`;
	#i=`expr $foo / 1000`;
	i=`shuf -i 1-10000000 -n 1`;
	#j=`gshuf -i 1-10000000 -n 1`;
	j=`shuf -i 1-10000000 -n 1`;
	#echo "$i,$j"
	/usr/local/bin/mosquitto_pub -h localhost -t date/celsius -m "$i,$j"
	#/usr/local/bin/mosquitto_pub -h localhost -t date/celsius -m "$i,$j"
	echo "$i,$j" >> ${name}
    done
    # publish the signal to terminate
    /usr/local/bin/mosquitto_pub -h  localhost -t date/celsius -m "0.0,0.0"
    #publish the file name of generate data
    /usr/local/bin/mosquitto_pub -h localhost -t final/final -m "${name},${name}"
    #sleep 1s
    #killall ./mqtt_date_amplitude
    #pkill -s KILL mqtt_date_amplitude
    #sleep 1s
done
