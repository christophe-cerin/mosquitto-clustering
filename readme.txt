This is a simple example of the C++ library mosquittopp.

%---------------------------------------------
Client side:

It is a client that subscribes to the topic date/amplitude. It reads a
data tuple (date,amplitude) representing a date and a value associated
to the date. It converts the tuble into a Point().

%---------------------------------------------
Server side:

Assume that a MQTT serveur is running on the raspberry.

We publish a random tuple (date, amplitude) on channel date/amplitude like this:

pi@raspberrypi:~ $ mosquitto_pub -h localhost -t date/amplitude -m `echo -n ${EPOCHREALTIME}${j}; shuf -i 1-100000 -n 1`

To publish 64 tuples composed of a timestamp and a random number:

pi@raspberrypi:~ $ for i in `seq 64`; do DATE=`date -d 'Apr 30 2021' +%s%3N`; DATE1=`date +%s%3N`; j=`expr $DATE1 - $DATE`;j=${j},`shuf -i 1-10000000 -n 1`; mosquitto_pub -h localhost -t date/celsius -m `echo -n $j`; sleep 0.5; done

Note: the timestamps form an increasing sequence of ellapsed ms from 'Apr 30 2021' and the current date

To publish 64 tuples composed of two random numbers:

pi@raspberrypi:~ $ for i in `seq 64`; do DATE=`j=`shuf -i 1-10000000 -n 1`,`shuf -i 1-10000000 -n 1`; mosquitto_pub -h localhost -t date/celsius -m `echo -n $j`; sleep 0.5; done

The client can read the tuples:

agathe@ordinateur-agathe:~/Bureau/mosquitto$ ./mqtt_date_amplitude 
Connected with code 0.
Subscription succeeded.
date/celcius: 6088479
date/celcius: 4034491
6088479.00 == 4034491.00
0 Point (0) : (6088479.00, 4034491.00)
date/celcius: 2355463
date/celcius: 3734764
2355463.00 == 3734764.00
1 Point (0) : (2355463.00, 3734764.00)
date/celcius: 554211
date/celcius: 5641570
554211.00 == 5641570.00
2 Point (0) : (554211.00, 5641570.00)
date/celcius: 2863824
date/celcius: 8935249
2863824.00 == 8935249.00
3 Point (0) : (2863824.00, 8935249.00)
date/celcius: 9691330
date/celcius: 3698900
9691330.00 == 3698900.00
4 Point (0) : (9691330.00, 3698900.00)
date/celcius: 3655193
date/celcius: 5679755
3655193.00 == 5679755.00
5 Point (0) : (3655193.00, 5679755.00)
date/celcius: 2965093
date/celcius: 4630259
2965093.00 == 4630259.00
6 Point (0) : (2965093.00, 4630259.00)
date/celcius: 8152955
date/celcius: 5609266
8152955.00 == 5609266.00
7 Point (0) : (8152955.00, 5609266.00)
date/celcius: 8236387
date/celcius: 5708816
8236387.00 == 5708816.00
8 Point (0) : (8236387.00, 5708816.00)
date/celcius: 6595587
date/celcius: 6836770
6595587.00 == 6836770.00
9 Point (0) : (6595587.00, 6836770.00)
date/celcius: 8349881
date/celcius: 7001872
8349881.00 == 7001872.00
10 Point (0) : (8349881.00, 7001872.00)
date/celcius: 6544549
date/celcius: 5673930
6544549.00 == 5673930.00
11 Point (0) : (6544549.00, 5673930.00)
date/celcius: 459051
date/celcius: 1467117
459051.00 == 1467117.00
12 Point (0) : (459051.00, 1467117.00)
date/celcius: 3910396
date/celcius: 3650846
3910396.00 == 3650846.00
13 Point (0) : (3910396.00, 3650846.00)
date/celcius: 4927746
date/celcius: 4637366
4927746.00 == 4637366.00
14 Point (0) : (4927746.00, 4637366.00)
date/celcius: 3902536
date/celcius: 1668500
3902536.00 == 1668500.00
15 Point (0) : (3902536.00, 1668500.00)
date/celcius: 8262824
date/celcius: 1539370
8262824.00 == 1539370.00
16 Point (0) : (8262824.00, 1539370.00)
date/celcius: 1811697
date/celcius: 3130297
1811697.00 == 3130297.00
17 Point (0) : (1811697.00, 3130297.00)
date/celcius: 2092841
date/celcius: 7791434
2092841.00 == 7791434.00
18 Point (0) : (2092841.00, 7791434.00)
date/celcius: 1247110
date/celcius: 776750
1247110.00 == 776750.00
19 Point (0) : (1247110.00, 776750.00)
date/celcius: 7306212
date/celcius: 8427687
7306212.00 == 8427687.00
20 Point (0) : (7306212.00, 8427687.00)
date/celcius: 8315695
date/celcius: 7347559
8315695.00 == 7347559.00
21 Point (0) : (8315695.00, 7347559.00)
date/celcius: 6871383
date/celcius: 2523416
6871383.00 == 2523416.00
22 Point (0) : (6871383.00, 2523416.00)
date/celcius: 4081852
date/celcius: 8561765
4081852.00 == 8561765.00
23 Point (0) : (4081852.00, 8561765.00)
date/celcius: 9155931
date/celcius: 6659312
9155931.00 == 6659312.00
24 Point (0) : (9155931.00, 6659312.00)
date/celcius: 4727837
date/celcius: 7784230
4727837.00 == 7784230.00
25 Point (0) : (4727837.00, 7784230.00)
date/celcius: 5912300
date/celcius: 1156154
5912300.00 == 1156154.00
26 Point (0) : (5912300.00, 1156154.00)
date/celcius: 284938
date/celcius: 411638
284938.00 == 411638.00
27 Point (0) : (284938.00, 411638.00)
date/celcius: 9148784
date/celcius: 4089989
9148784.00 == 4089989.00
28 Point (0) : (9148784.00, 4089989.00)
date/celcius: 6153138
date/celcius: 6537700
6153138.00 == 6537700.00
29 Point (0) : (6153138.00, 6537700.00)
date/celcius: 334217
date/celcius: 230409
334217.00 == 230409.00
30 Point (0) : (334217.00, 230409.00)
date/celcius: 7582944
date/celcius: 9843212
7582944.00 == 9843212.00
31 Point (0) : (7582944.00, 9843212.00)
date/celcius: 448176
date/celcius: 6623012
448176.00 == 6623012.00
32 Point (0) : (448176.00, 6623012.00)
date/celcius: 5208427
date/celcius: 7340444
5208427.00 == 7340444.00
33 Point (0) : (5208427.00, 7340444.00)
date/celcius: 3252673
date/celcius: 2425188
3252673.00 == 2425188.00
34 Point (0) : (3252673.00, 2425188.00)
date/celcius: 3556347
date/celcius: 6220437
3556347.00 == 6220437.00
35 Point (0) : (3556347.00, 6220437.00)
date/celcius: 8742620
date/celcius: 2991455
8742620.00 == 2991455.00
36 Point (0) : (8742620.00, 2991455.00)
date/celcius: 4028026
date/celcius: 8477106
4028026.00 == 8477106.00
37 Point (0) : (4028026.00, 8477106.00)
date/celcius: 9440699
date/celcius: 1625111
9440699.00 == 1625111.00
38 Point (0) : (9440699.00, 1625111.00)
date/celcius: 5796498
date/celcius: 4386341
5796498.00 == 4386341.00
39 Point (0) : (5796498.00, 4386341.00)
date/celcius: 7559117
date/celcius: 3366225
7559117.00 == 3366225.00
40 Point (0) : (7559117.00, 3366225.00)
date/celcius: 1648270
date/celcius: 2390227
1648270.00 == 2390227.00
41 Point (0) : (1648270.00, 2390227.00)
date/celcius: 2734262
date/celcius: 43420
2734262.00 == 43420.00
42 Point (0) : (2734262.00, 43420.00)
date/celcius: 8615998
date/celcius: 3568069
8615998.00 == 3568069.00
43 Point (0) : (8615998.00, 3568069.00)
date/celcius: 3069057
date/celcius: 7939451
3069057.00 == 7939451.00
44 Point (0) : (3069057.00, 7939451.00)
date/celcius: 6591080
date/celcius: 1122570
6591080.00 == 1122570.00
45 Point (0) : (6591080.00, 1122570.00)
date/celcius: 7435157
date/celcius: 8478487
7435157.00 == 8478487.00
46 Point (0) : (7435157.00, 8478487.00)
date/celcius: 415977
date/celcius: 1280960
415977.00 == 1280960.00
47 Point (0) : (415977.00, 1280960.00)
date/celcius: 872698
date/celcius: 1595956
872698.00 == 1595956.00
48 Point (0) : (872698.00, 1595956.00)
date/celcius: 119622
date/celcius: 910460
119622.00 == 910460.00
49 Point (0) : (119622.00, 910460.00)
date/celcius: 4697571
date/celcius: 4883630
4697571.00 == 4883630.00
50 Point (0) : (4697571.00, 4883630.00)
date/celcius: 1797017
date/celcius: 3008497
1797017.00 == 3008497.00
51 Point (0) : (1797017.00, 3008497.00)
date/celcius: 6535881
date/celcius: 886072
6535881.00 == 886072.00
52 Point (0) : (6535881.00, 886072.00)
date/celcius: 4252731
date/celcius: 5916540
4252731.00 == 5916540.00
53 Point (0) : (4252731.00, 5916540.00)
date/celcius: 75954
date/celcius: 6117383
75954.00 == 6117383.00
54 Point (0) : (75954.00, 6117383.00)
date/celcius: 6661274
date/celcius: 9206370
6661274.00 == 9206370.00
55 Point (0) : (6661274.00, 9206370.00)
date/celcius: 7134303
date/celcius: 2655017
7134303.00 == 2655017.00
56 Point (0) : (7134303.00, 2655017.00)
date/celcius: 1336577
date/celcius: 5482062
1336577.00 == 5482062.00
57 Point (0) : (1336577.00, 5482062.00)
date/celcius: 4368069
date/celcius: 4874909
4368069.00 == 4874909.00
58 Point (0) : (4368069.00, 4874909.00)
date/celcius: 4542162
date/celcius: 6359191
4542162.00 == 6359191.00
59 Point (0) : (4542162.00, 6359191.00)
date/celcius: 1709122
date/celcius: 9596275
1709122.00 == 9596275.00
60 Point (0) : (1709122.00, 9596275.00)
date/celcius: 7062355
date/celcius: 1487550
7062355.00 == 1487550.00
61 Point (0) : (7062355.00, 1487550.00)
date/celcius: 3187791
date/celcius: 8089483
3187791.00 == 8089483.00
62 Point (0) : (3187791.00, 8089483.00)
date/celcius: 5396674
date/celcius: 9189502
5396674.00 == 9189502.00
63 Point (0) : (5396674.00, 9189502.00)
6088479.00	4034491.00
2355463.00	3734764.00
554211.00	5641570.00
2863824.00	8935249.00
9691330.00	3698900.00
3655193.00	5679755.00
2965093.00	4630259.00
8152955.00	5609266.00
8236387.00	5708816.00
6595587.00	6836770.00
8349881.00	7001872.00
6544549.00	5673930.00
459051.00	1467117.00
3910396.00	3650846.00
4927746.00	4637366.00
3902536.00	1668500.00
8262824.00	1539370.00
1811697.00	3130297.00
2092841.00	7791434.00
1247110.00	776750.00
7306212.00	8427687.00
8315695.00	7347559.00
6871383.00	2523416.00
4081852.00	8561765.00
9155931.00	6659312.00
4727837.00	7784230.00
5912300.00	1156154.00
284938.00	411638.00
9148784.00	4089989.00
6153138.00	6537700.00
334217.00	230409.00
7582944.00	9843212.00
448176.00	6623012.00
5208427.00	7340444.00
3252673.00	2425188.00
3556347.00	6220437.00
8742620.00	2991455.00
4028026.00	8477106.00
9440699.00	1625111.00
5796498.00	4386341.00
7559117.00	3366225.00
1648270.00	2390227.00
2734262.00	43420.00
8615998.00	3568069.00
3069057.00	7939451.00
6591080.00	1122570.00
7435157.00	8478487.00
415977.00	1280960.00
872698.00	1595956.00
119622.00	910460.00
4697571.00	4883630.00
1797017.00	3008497.00
6535881.00	886072.00
4252731.00	5916540.00
75954.00	6117383.00
6661274.00	9206370.00
7134303.00	2655017.00
1336577.00	5482062.00
4368069.00	4874909.00
4542162.00	6359191.00
1709122.00	9596275.00
7062355.00	1487550.00
3187791.00	8089483.00
5396674.00	9189502.00
calculate time 114.58



%---------------------------------------------

To install the C/C++ headers:

git clone https://github.com/eclipse/mosquitto.git
cd mosquitto
sudo apt-get install libssl-dev
sudo apt install libcjson-dev
sudo apt install xsltproc
make
sudo make install
make clean

%---------------------------------------------

To install the MQTT server:

sudo apt-get install mosquitto mosquitto-clients python-mosquitto
or
sudo apt-get install mosquitto mosquitto-clients
if python-mosquitto is not available for your processor architecture

Check if mosquitto is running:
sudo systemctl status mosquitto

To start the service:
sudo systemctl enable mosquitto.service

%---------------------------------------------

To install the concurrent queue library:a
https://github.com/cameron314/concurrentqueue
Download the .h files only.
The files are auto-sufficient

wget https://raw.githubusercontent.com/cameron314/concurrentqueue/master/concurrentqueue.h
wget https://raw.githubusercontent.com/cameron314/concurrentqueue/master/blockingconcurrentqueue.h
wget https://raw.githubusercontent.com/cameron314/concurrentqueue/master/lightweightsemaphore.h

%---------------------------------------------

Generating data

The test.sh script file allows to publish random data to the MQTT server.

Let w the window size (in data size unit).
Let p=floor(sqrt(w))-1.
The iteration number (on line: for i in {1..12256}; do of the script) should verify
w + k*p, here 12256=256+800*15
since p = sqrt(256) - 1

You should set W in date_amplitude.cpp file too! And then you need to recompile
the project according to numbers in test.sh

Example :
$ python3
Python 3.8.6 (default, May 27 2021, 13:28:02) 
[GCC 10.2.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> import math
>>> pow(2,19)
524288
>>> math.sqrt(pow(2,19))
724.0773439350247
>>> math.floor(math.sqrt(pow(2,19)))
724 ==> hence p = 724 - 1 = 723, whereas w = 2^19 = 524288
>>> 

%---------------------------------------------

On a Raspberry pi zero w:

a) in window 1)

do not forget to install headers files of mosquitto:
pi@raspberrypi:~/mosquitto $ sudo apt-get install libmosquittopp-dev

Then

pi@raspberrypi:~/mosquitto $ make
g++    -c -o date_amplitude.o date_amplitude.cpp
g++ -Wall -std=c++11 main.o date_amplitude.o kmeans.beautifier.o kmeansPlusPlus.beautifier.o sort.beautifier.o -o mqtt_date_amplitude -L/usr/lib/arm-linux-gnueabihf/libmosquittopp.so.1 /usr/lib/arm-linux-gnueabihf/libmosquitto.so.1 -lmosquittopp -lmosquitto -lpthread 
pi@raspberrypi:~/mosquitto $ ./mqtt_date_amplitude 
Connected with code 0.
Subscription succeeded.
calculate time (1) 0.00886
calculate time (2) 0.00861
calculate time (3) 0.009885
calculate time (4) 0.011748
calculate time (5) 0.006578
calculate time (6) 0.009001
calculate time (7) 0.015146
calculate time (8) 0.009145
calculate time (9) 0.007836
calculate time (10) 0.008609
calculate time (11) 0.006611
calculate time (12) 0.007243
calculate time (13) 0.0065
calculate time (14) 0.005915
calculate time (15) 0.009214
calculate time (16) 0.005833
calculate time (17) 0.005286
calculate time (18) 0.005
calculate time (19) 0.00712
calculate time (20) 0.004673
calculate time (21) 0.008068
calculate time (22) 0.008541
calculate time (23) 0.00646
calculate time (24) 0.005933
calculate time (25) 0.009978
calculate time (26) 0.005922
calculate time (27) 0.00587
calculate time (28) 0.007218
calculate time (29) 0.004386
calculate time (30) 0.004529
calculate time (31) 0.009086
calculate time (32) 0.008499
calculate time (33) 0.011083
calculate time (34) 0.004391
calculate time (35) 0.007826
calculate time (36) 0.009802
calculate time (37) 0.006014
calculate time (38) 0.005865
calculate time (39) 0.004525
calculate time (40) 0.005243
calculate time (41) 0.010523
calculate time (42) 0.010367
calculate time (43) 0.012456
calculate time (44) 0.006772
calculate time (45) 0.005379
calculate time (46) 0.008383
calculate time (47) 0.00799
calculate time (48) 0.007758
calculate time (49) 0.004575
calculate time (50) 0.010269
calculate time (51) 0.009103
calculate time (52) 0.005167
calculate time (53) 0.005954
calculate time (54) 0.004672
calculate time (55) 0.005999
calculate time (56) 0.005665
calculate time (57) 0.007296
calculate time (58) 0.007685
calculate time (59) 0.012345
calculate time (60) 0.007107
calculate time (61) 0.005144
calculate time (62) 0.008702
calculate time (63) 0.010575
calculate time (64) 0.010057
calculate time (65) 0.008444
calculate time (66) 0.006633
calculate time (67) 0.007098
calculate time (68) 0.008978
calculate time (69) 0.005299
calculate time (70) 0.009856
calculate time (71) 0.01385
calculate time (72) 0.005916
calculate time (73) 0.014536
calculate time (74) 0.018311
calculate time (75) 0.011192
calculate time (76) 0.012562
calculate time (77) 0.00546
calculate time (78) 0.009775
calculate time (79) 0.01173
calculate time (80) 0.005806
calculate time (81) 0.007806
calculate time (82) 0.005201
calculate time (83) 0.007591
calculate time (84) 0.011708
calculate time (85) 0.013925
calculate time (86) 0.017181
calculate time (87) 0.021009
calculate time (88) 0.021681
calculate time (89) 0.01309
calculate time (90) 0.014505
calculate time (91) 0.007097
calculate time (92) 0.003254
calculate time (93) 0.004566
calculate time (94) 0.007729
calculate time (95) 0.007899
calculate time (96) 0.004557
calculate time (97) 0.015752
calculate time (98) 0.006533
calculate time (99) 0.013283
calculate time (100) 0.0124
calculate time (101) 0.013085
calculate time (102) 0.005783
calculate time (103) 0.007144
calculate time (104) 0.006945
calculate time (105) 0.007257
calculate time (106) 0.00735
calculate time (107) 0.005095
calculate time (108) 0.00903
calculate time (109) 0.011934
calculate time (110) 0.004354
calculate time (111) 0.005175
calculate time (112) 0.009156
calculate time (113) 0.006472
calculate time (114) 0.005238
calculate time (115) 0.00515
calculate time (116) 0.007733
calculate time (117) 0.010429
calculate time (118) 0.011049
calculate time (119) 0.010494
calculate time (120) 0.009121
calculate time (121) 0.007191
calculate time (122) 0.010361
calculate time (123) 0.005834
calculate time (124) 0.017208
calculate time (125) 0.005307
calculate time (126) 0.005815
calculate time (127) 0.007799
calculate time (128) 0.004486
calculate time (129) 0.005844
calculate time (130) 0.006528
calculate time (131) 0.008978
calculate time (132) 0.008393
calculate time (133) 0.008948
calculate time (134) 0.006502
calculate time (135) 0.003886
calculate time (136) 0.00781
calculate time (137) 0.003877
calculate time (138) 0.005217
calculate time (139) 0.007794
calculate time (140) 0.004526
calculate time (141) 0.006478
calculate time (142) 0.011893
calculate time (143) 0.006491
calculate time (144) 0.005245
calculate time (145) 0.006428
calculate time (146) 0.004493
calculate time (147) 0.016238
calculate time (148) 0.014297
calculate time (149) 0.006431
calculate time (150) 0.018453
calculate time (151) 0.00741
calculate time (152) 0.009705
calculate time (153) 0.012351
calculate time (154) 0.012879
calculate time (155) 0.006933
calculate time (156) 0.014489
calculate time (157) 0.012429
calculate time (158) 0.013262
calculate time (159) 0.013027
calculate time (160) 0.014287
calculate time (161) 0.009778
calculate time (162) 0.012518
calculate time (163) 0.015875
calculate time (164) 0.012371
calculate time (165) 0.012431
calculate time (166) 0.014331
calculate time (167) 0.006939
calculate time (168) 0.014969
calculate time (169) 0.01235
calculate time (170) 0.006536
calculate time (171) 0.004586
calculate time (172) 0.013012
calculate time (173) 0.011881
calculate time (174) 0.011242
calculate time (175) 0.007857
calculate time (176) 0.015632
calculate time (177) 0.013559
calculate time (178) 0.007906
calculate time (179) 0.010981
calculate time (180) 0.01317
calculate time (181) 0.009712
calculate time (182) 0.010392
calculate time (183) 0.010456
calculate time (184) 0.013786
calculate time (185) 0.012345
calculate time (186) 0.012381
calculate time (187) 0.013723
calculate time (188) 0.014394
calculate time (189) 0.00788
calculate time (190) 0.005135
calculate time (191) 0.014214
calculate time (192) 0.009912
calculate time (193) 0.014373
calculate time (194) 0.004531
calculate time (195) 0.013014
calculate time (196) 0.011148
calculate time (197) 0.009701
calculate time (198) 0.015027
calculate time (199) 0.005767
calculate time (200) 0.013872
calculate time (201) 0.015754
calculate time (202) 0.011019
calculate time (203) 0.011724
calculate time (204) 0.010489
calculate time (205) 0.011794
calculate time (206) 0.008515
calculate time (207) 0.01034
calculate time (208) 0.009928
calculate time (209) 0.006524
calculate time (210) 0.013862
calculate time (211) 0.015069
calculate time (212) 0.009309
calculate time (213) 0.005173
calculate time (214) 0.012583
calculate time (215) 0.005845
calculate time (216) 0.013792
calculate time (217) 0.007767
calculate time (218) 0.014283
calculate time (219) 0.007158
calculate time (220) 0.013067
calculate time (221) 0.014543
calculate time (222) 0.011119
calculate time (223) 0.010299
calculate time (224) 0.009079
calculate time (225) 0.015017
calculate time (226) 0.007897
calculate time (227) 0.007706
calculate time (228) 0.003726
calculate time (229) 0.006569
calculate time (230) 0.011613
calculate time (231) 0.015119
calculate time (232) 0.006564
calculate time (233) 0.012408
calculate time (234) 0.010373
calculate time (235) 0.009642
calculate time (236) 0.012937
calculate time (237) 0.012496
calculate time (238) 0.009671
calculate time (239) 0.013602
calculate time (240) 0.007793
calculate time (241) 0.012411
calculate time (242) 0.007027
calculate time (243) 0.011058
calculate time (244) 0.010385
calculate time (245) 0.010363
calculate time (246) 0.011103
calculate time (247) 0.009138
calculate time (248) 0.013826
calculate time (249) 0.004597
calculate time (250) 0.009182
calculate time (251) 0.01313
calculate time (252) 0.013914
calculate time (253) 0.011147
calculate time (254) 0.011166
calculate time (255) 0.013089
calculate time (256) 0.009955
calculate time (257) 0.007815
calculate time (258) 0.009709
calculate time (259) 0.014919
calculate time (260) 0.007133
calculate time (261) 0.013186
calculate time (262) 0.014958
calculate time (263) 0.006016
calculate time (264) 0.012405
calculate time (265) 0.010312
calculate time (266) 0.003745
calculate time (267) 0.006473
calculate time (268) 0.013834
calculate time (269) 0.013003
calculate time (270) 0.01381
calculate time (271) 0.004501
calculate time (272) 0.005007
calculate time (273) 0.015804
calculate time (274) 0.014363
calculate time (275) 0.011249
calculate time (276) 0.011735
calculate time (277) 0.003726
calculate time (278) 0.007151
calculate time (279) 0.014574
calculate time (280) 0.014531
calculate time (281) 0.004476
calculate time (282) 0.012557
calculate time (283) 0.014313
calculate time (284) 0.010737
calculate time (285) 0.009891
calculate time (286) 0.012352
calculate time (287) 0.010061
calculate time (288) 0.014374
calculate time (289) 0.012371
calculate time (290) 0.010449
calculate time (291) 0.01359
calculate time (292) 0.013914
calculate time (293) 0.004659
calculate time (294) 0.007101
calculate time (295) 0.011787
calculate time (296) 0.011222
calculate time (297) 0.012457
calculate time (298) 0.01317
calculate time (299) 0.008442
calculate time (300) 0.008382
calculate time (301) 0.009018
calculate time (302) 0.013104
calculate time (303) 0.013832
calculate time (304) 0.011072
calculate time (305) 0.012971
calculate time (306) 0.010612
calculate time (307) 0.00522
calculate time (308) 0.007113
calculate time (309) 0.008999
calculate time (310) 0.015049
calculate time (311) 0.009245
calculate time (312) 0.006562
calculate time (313) 0.006498
calculate time (314) 0.014363
calculate time (315) 0.012389
calculate time (316) 0.012353
calculate time (317) 0.01422
calculate time (318) 0.009728
calculate time (319) 0.00847
calculate time (320) 0.010459
calculate time (321) 0.015896
calculate time (322) 0.0131
calculate time (323) 0.013167
calculate time (324) 0.014959
calculate time (325) 0.009945
calculate time (326) 0.012369
calculate time (327) 0.015729
calculate time (328) 0.010594
calculate time (329) 0.013084
calculate time (330) 0.013185
calculate time (331) 0.009127
calculate time (332) 0.011778
calculate time (333) 0.011651
calculate time (334) 0.012954
calculate time (335) 0.011598
calculate time (336) 0.012002
calculate time (337) 0.010546
calculate time (338) 0.0044
calculate time (339) 0.008532
calculate time (340) 0.014987
calculate time (341) 0.009798
calculate time (342) 0.00736
calculate time (343) 0.012405
calculate time (344) 0.005906
calculate time (345) 0.008301
calculate time (346) 0.01239
calculate time (347) 0.015671
calculate time (348) 0.010396
calculate time (349) 0.011126
calculate time (350) 0.011108
calculate time (351) 0.008463
calculate time (352) 0.008472
calculate time (353) 0.012424
calculate time (354) 0.005919
calculate time (355) 0.016287
calculate time (356) 0.011027
calculate time (357) 0.013381
calculate time (358) 0.011768
calculate time (359) 0.00844
calculate time (360) 0.013799
calculate time (361) 0.013846
calculate time (362) 0.015811
calculate time (363) 0.005257
calculate time (364) 0.015028
calculate time (365) 0.015499
calculate time (366) 0.009854
calculate time (367) 0.010393
calculate time (368) 0.013016
calculate time (369) 0.011013
calculate time (370) 0.013056
calculate time (371) 0.012552
calculate time (372) 0.003876
calculate time (373) 0.007867
calculate time (374) 0.011665
calculate time (375) 0.003888
calculate time (376) 0.011346
calculate time (377) 0.011753
calculate time (378) 0.012504
calculate time (379) 0.015398
calculate time (380) 0.013784
calculate time (381) 0.008571
calculate time (382) 0.013857
calculate time (383) 0.012362
calculate time (384) 0.013202
calculate time (385) 0.013843
calculate time (386) 0.007049
calculate time (387) 0.011033
calculate time (388) 0.010427
calculate time (389) 0.011044
calculate time (390) 0.009126
calculate time (391) 0.008619
calculate time (392) 0.008527
calculate time (393) 0.008782
calculate time (394) 0.0136
calculate time (395) 0.014315
calculate time (396) 0.01293
calculate time (397) 0.01362
calculate time (398) 0.011028
calculate time (399) 0.008972
calculate time (400) 0.008569
calculate time (401) 0.00976
calculate time (402) 0.009838
calculate time (403) 0.009705
calculate time (404) 0.011886
calculate time (405) 0.011788
calculate time (406) 0.014297
calculate time (407) 0.011308
calculate time (408) 0.011809
calculate time (409) 0.015203
calculate time (410) 0.011711
calculate time (411) 0.010448
calculate time (412) 0.013058
calculate time (413) 0.013308
calculate time (414) 0.01394
calculate time (415) 0.004365
calculate time (416) 0.007225
calculate time (417) 0.004371
calculate time (418) 0.012349
calculate time (419) 0.012315
calculate time (420) 0.013177
calculate time (421) 0.009251
calculate time (422) 0.010651
calculate time (423) 0.0105
calculate time (424) 0.007916
calculate time (425) 0.003954
calculate time (426) 0.003726
calculate time (427) 0.012447
calculate time (428) 0.014358
calculate time (429) 0.012512
calculate time (430) 0.014435
calculate time (431) 0.009091
calculate time (432) 0.00794
calculate time (433) 0.006563
calculate time (434) 0.015236
calculate time (435) 0.012426
calculate time (436) 0.012388
calculate time (437) 0.007254
calculate time (438) 0.010076
calculate time (439) 0.01243
calculate time (440) 0.010485
calculate time (441) 0.009107
calculate time (442) 0.008382
calculate time (443) 0.010494
calculate time (444) 0.014476
calculate time (445) 0.005977
calculate time (446) 0.014534
calculate time (447) 0.013648
calculate time (448) 0.00852
calculate time (449) 0.009781
calculate time (450) 0.011763
calculate time (451) 0.008512
calculate time (452) 0.00929
calculate time (453) 0.015782
calculate time (454) 0.010445
calculate time (455) 0.012405
calculate time (456) 0.012944
calculate time (457) 0.014988
calculate time (458) 0.005188
calculate time (459) 0.009606
calculate time (460) 0.012396
calculate time (461) 0.010399
calculate time (462) 0.007914
calculate time (463) 0.01121
calculate time (464) 0.007848
calculate time (465) 0.013771
calculate time (466) 0.013084
calculate time (467) 0.003926
calculate time (468) 0.007058
calculate time (469) 0.013102
calculate time (470) 0.015119
calculate time (471) 0.014446
calculate time (472) 0.010331
calculate time (473) 0.007108
calculate time (474) 0.004356
calculate time (475) 0.007858
calculate time (476) 0.007937
calculate time (477) 0.013018
calculate time (478) 0.00659
calculate time (479) 0.01252
calculate time (480) 0.013758
calculate time (481) 0.017148
calculate time (482) 0.008531
calculate time (483) 0.011057
calculate time (484) 0.013194
calculate time (485) 0.010526
calculate time (486) 0.015028
calculate time (487) 0.004584
calculate time (488) 0.015721
calculate time (489) 0.01044
calculate time (490) 0.005271
calculate time (491) 0.011015
calculate time (492) 0.004572
calculate time (493) 0.010362
calculate time (494) 0.007719
calculate time (495) 0.009246
calculate time (496) 0.013315
calculate time (497) 0.011793
calculate time (498) 0.013124
calculate time (499) 0.016945
calculate time (500) 0.01395
calculate time (501) 0.006654
calculate time (502) 0.004366
calculate time (503) 0.009673
calculate time (504) 0.014325
calculate time (505) 0.007927
calculate time (506) 0.009777
calculate time (507) 0.007153
calculate time (508) 0.0143
calculate time (509) 0.004367
calculate time (510) 0.009712
calculate time (511) 0.013117
calculate time (512) 0.014945
calculate time (513) 0.013887
calculate time (514) 0.013832
calculate time (515) 0.01647
calculate time (516) 0.009711
calculate time (517) 0.006453
calculate time (518) 0.014966
calculate time (519) 0.015658
calculate time (520) 0.012373
calculate time (521) 0.010766
calculate time (522) 0.016255
calculate time (523) 0.013155
calculate time (524) 0.014006
calculate time (525) 0.009166
calculate time (526) 0.007816
calculate time (527) 0.010498
calculate time (528) 0.013981
calculate time (529) 0.014304
calculate time (530) 0.012455
calculate time (531) 0.012479
calculate time (532) 0.013102
calculate time (533) 0.006532
calculate time (534) 0.009081
calculate time (535) 0.010494
calculate time (536) 0.013877
calculate time (537) 0.008347
calculate time (538) 0.005368
calculate time (539) 0.015116
calculate time (540) 0.009189
calculate time (541) 0.011877
calculate time (542) 0.014929
calculate time (543) 0.01141
calculate time (544) 0.013823
calculate time (545) 0.014959
calculate time (546) 0.013895
calculate time (547) 0.013024
calculate time (548) 0.006496
calculate time (549) 0.014314
calculate time (550) 0.015537
calculate time (551) 0.015084
calculate time (552) 0.010489
calculate time (553) 0.00466
calculate time (554) 0.011783
calculate time (555) 0.012968
calculate time (556) 0.011125
calculate time (557) 0.013731
calculate time (558) 0.01297
calculate time (559) 0.003079
calculate time (560) 0.013898
calculate time (561) 0.011052
calculate time (562) 0.009776
calculate time (563) 0.012962
calculate time (564) 0.007711
calculate time (565) 0.009117
calculate time (566) 0.006519
calculate time (567) 0.008342
calculate time (568) 0.014568
calculate time (569) 0.006479
calculate time (570) 0.013839
calculate time (571) 0.012485
calculate time (572) 0.010503
calculate time (573) 0.011109
calculate time (574) 0.012398
calculate time (575) 0.007725
calculate time (576) 0.00933
calculate time (577) 0.010569
calculate time (578) 0.013811
calculate time (579) 0.004666
calculate time (580) 0.013821
calculate time (581) 0.018529
calculate time (582) 0.011744
calculate time (583) 0.012585
calculate time (584) 0.009738
calculate time (585) 0.009275
calculate time (586) 0.010642
calculate time (587) 0.007801
calculate time (588) 0.012307
calculate time (589) 0.013113
calculate time (590) 0.005309
calculate time (591) 0.016719
calculate time (592) 0.011721
calculate time (593) 0.013111
calculate time (594) 0.011148
calculate time (595) 0.005263
calculate time (596) 0.007111
calculate time (597) 0.005641
calculate time (598) 0.006936
calculate time (599) 0.013379
calculate time (600) 0.005661
calculate time (601) 0.015712
calculate time (602) 0.00992
calculate time (603) 0.011668
calculate time (604) 0.010462
calculate time (605) 0.007126
calculate time (606) 0.013702
calculate time (607) 0.012363
calculate time (608) 0.006538
calculate time (609) 0.015014
calculate time (610) 0.011815
calculate time (611) 0.005005
calculate time (612) 0.004428
calculate time (613) 0.012546
calculate time (614) 0.006391
calculate time (615) 0.0103
calculate time (616) 0.013585
calculate time (617) 0.010321
calculate time (618) 0.010423
calculate time (619) 0.004375
calculate time (620) 0.01255
calculate time (621) 0.005794
calculate time (622) 0.017589
calculate time (623) 0.009788
calculate time (624) 0.012916
calculate time (625) 0.009657
calculate time (626) 0.009094
calculate time (627) 0.011195
calculate time (628) 0.00856
calculate time (629) 0.011725
calculate time (630) 0.013196
calculate time (631) 0.013028
calculate time (632) 0.004513
calculate time (633) 0.009274
calculate time (634) 0.006618
calculate time (635) 0.012516
calculate time (636) 0.013057
calculate time (637) 0.011018
calculate time (638) 0.010422
calculate time (639) 0.012942
calculate time (640) 0.009165
calculate time (641) 0.012456
calculate time (642) 0.013816
calculate time (643) 0.00649
calculate time (644) 0.003727
calculate time (645) 0.006569
calculate time (646) 0.015576
calculate time (647) 0.013191
calculate time (648) 0.00989
calculate time (649) 0.013727
calculate time (650) 0.014403
calculate time (651) 0.012726
calculate time (652) 0.013399
calculate time (653) 0.010357
calculate time (654) 0.005308
calculate time (655) 0.011098
calculate time (656) 0.007695
calculate time (657) 0.004544
calculate time (658) 0.014494
calculate time (659) 0.010413
calculate time (660) 0.013822
calculate time (661) 0.010337
calculate time (662) 0.013129
calculate time (663) 0.017149
calculate time (664) 0.012046
calculate time (665) 0.010414
calculate time (666) 0.004621
calculate time (667) 0.015245
calculate time (668) 0.007689
calculate time (669) 0.009289
calculate time (670) 0.007881
calculate time (671) 0.007873
calculate time (672) 0.011933
calculate time (673) 0.006525
calculate time (674) 0.013209
calculate time (675) 0.010357
calculate time (676) 0.004519
calculate time (677) 0.011787
calculate time (678) 0.009768
calculate time (679) 0.012475
calculate time (680) 0.009697
calculate time (681) 0.007355
calculate time (682) 0.005934
calculate time (683) 0.015231
calculate time (684) 0.011748
calculate time (685) 0.005824
calculate time (686) 0.012952
calculate time (687) 0.011052
calculate time (688) 0.01096
calculate time (689) 0.006428
calculate time (690) 0.014249
calculate time (691) 0.0142
calculate time (692) 0.006463
calculate time (693) 0.007774
calculate time (694) 0.004477
calculate time (695) 0.009816
calculate time (696) 0.009862
calculate time (697) 0.007928
calculate time (698) 0.013816
calculate time (699) 0.004456
calculate time (700) 0.014937
calculate time (701) 0.013671
calculate time (702) 0.012617
calculate time (703) 0.012376
calculate time (704) 0.006412
calculate time (705) 0.012586
calculate time (706) 0.012368
calculate time (707) 0.008968
calculate time (708) 0.013072
calculate time (709) 0.00781
calculate time (710) 0.014541
calculate time (711) 0.014412
calculate time (712) 0.011061
calculate time (713) 0.014345
calculate time (714) 0.016463
calculate time (715) 0.007064
calculate time (716) 0.0107
calculate time (717) 0.014328
calculate time (718) 0.011174
calculate time (719) 0.005816
calculate time (720) 0.008035
calculate time (721) 0.007219
calculate time (722) 0.010988
calculate time (723) 0.007948
calculate time (724) 0.009741
calculate time (725) 0.006558
calculate time (726) 0.007174
calculate time (727) 0.005122
calculate time (728) 0.005214
calculate time (729) 0.005874
calculate time (730) 0.008531
calculate time (731) 0.00587
calculate time (732) 0.003725
calculate time (733) 0.003985
calculate time (734) 0.007699
calculate time (735) 0.015616
calculate time (736) 0.006366
calculate time (737) 0.004601
calculate time (738) 0.005152
calculate time (739) 0.005177
calculate time (740) 0.014884
calculate time (741) 0.007844
calculate time (742) 0.00581
calculate time (743) 0.007161
calculate time (744) 0.006487
calculate time (745) 0.007148
calculate time (746) 0.00589
calculate time (747) 0.004364
calculate time (748) 0.005043
calculate time (749) 0.005288
calculate time (750) 0.005032
calculate time (751) 0.006528
calculate time (752) 0.007266
calculate time (753) 0.006513
calculate time (754) 0.007038
calculate time (755) 0.005146
calculate time (756) 0.011747
calculate time (757) 0.013036
calculate time (758) 0.016378
calculate time (759) 0.023544
calculate time (760) 0.026174
calculate time (761) 0.012436
calculate time (762) 0.011693
calculate time (763) 0.015643
calculate time (764) 0.014465
calculate time (765) 0.01572
calculate time (766) 0.017557
calculate time (767) 0.018215
calculate time (768) 0.018382
calculate time (769) 0.019146
calculate time (770) 0.027406
calculate time (771) 0.024915
calculate time (772) 0.009781
calculate time (773) 0.011715
calculate time (774) 0.010338
calculate time (775) 0.012396
calculate time (776) 0.009842
calculate time (777) 0.016258
calculate time (778) 0.010456
calculate time (779) 0.010423
calculate time (780) 0.024174
calculate time (781) 0.021047
calculate time (782) 0.023806
calculate time (783) 0.009763
calculate time (784) 0.010514
calculate time (785) 0.012934
calculate time (786) 0.013732
calculate time (787) 0.016932
calculate time (788) 0.019213
calculate time (789) 0.021117
calculate time (790) 0.026
calculate time (791) 0.019007
calculate time (792) 0.012469
calculate time (793) 0.012362
calculate time (794) 0.011777
calculate time (795) 0.009682
calculate time (796) 0.014556
calculate time (797) 0.014527
calculate time (798) 0.019026
calculate time (799) 0.020162
calculate time (800) 0.022352
calculate time (801) 0.024387
File name of input data: 150620211050982790139.csv
Final centroids:
0	105023315968.000000	6305816.000000
1	115954335744.000000	5486339.000000
2	120476803072.000000	5527223.500000
3	120655437824.000000	4906716.500000
4	120775303168.000000	5035626.500000
File name for centriods AFTER kmeans: Centroids_After_150620211050982790139.csv
File name for centriods BEFORE kmeans: Centroids_Before_150620211050982790139.csv
^C

b) in window 2) start the script file to publish data:

pi@raspberrypi:~/mosquitto $ /bin/bash test.sh
pi@raspberrypi:~/mosquitto $
pi@raspberrypi:~/mosquitto $ cat test.sh
name=`date +%d%m%Y%H%M%N.csv`
for i in {1..12256}; do
#for i in {1..286}; do
    sleep 0.05s
    #foo=`gdate +%H%M%S%N`;
    foo=`date +%H%M%S%N`;
    i=`expr $foo / 1000`;
    #j=`gshuf -i 1-10000000 -n 1`;
    j=`shuf -i 1-10000000 -n 1`;
    #echo "$i,$j"
    /usr/bin/mosquitto_pub -h localhost -t date/celsius -m "$i,$j"
    #/usr/bin/mosquitto_pub -h localhost -t date/celsius -m "$i,$j"
    echo "$i,$j" >> ${name}
done
# publish the signal to terminate
/usr/bin/mosquitto_pub -h  localhost -t date/celsius -m "0.0,0.0"
#publish the file name of generated data
/usr/bin/mosquitto_pub -h localhost -t final/final -m "${name},${name}"
