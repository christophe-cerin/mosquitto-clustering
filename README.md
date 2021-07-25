# Mosquitto-clustering

Implementations of data-stream clustering on low-cost machines. An MQTT mosquitto infrastructure publishes data. A client program subscribes to the server and does a clustering according to an "on-the-fly" algorithm. The implementations are mandatory for the associated research, which is described as follows.

## Paper Abstract

Nowadays, the operations performed by the Internet of Things (IoT) systems are no more trivial
since they rely on more sophisticated devices than in the past. The IoT system is physically
composed of connected computing, digital, mechanical devices such as sensors or actuators.
Most of the time, each of them incorporates an arithmetic logical unit that can pre-compute or
compute on the device. To extract value from the data produced at the edge, processing power
offered by cloud computing is still utilized. However, streaming data to the cloud exposes some
limitations related to the increased communication and data transfer, which introduces delays
and consumes network bandwidth. Clustering data is one example of a treatment that can be
executed in the cloud. In this paper, we propose a methodology for solving the data stream
clustering problem at the edge. Data Stream clustering is deffned as the clustering of data
that arrive continuously, such as telephone records, multimedia data, sensors data, financial
transactions, etc. Since we use low-cost and low-capacity devices, the objective is, given a
sequence of points, to construct a good clustering of the stream using a small amount of memory
and time. We propose a ’windowing’ scheme, coupled with a sampling scheme to respect the
objective. Under the experimental conditions, experiments show that the clustering solutions
can be controlled, either for time-stamped data or for random data. The main difference in our
schema is that we are clustering data "on the fyy” with no knowledge or assumption regarding
the available data. We do not assume that all the data are known before a treatment batch by
batch. Our schema also has the potential to be adapted to other classes of machine learning
algorithm.

## Hints for the compilation with Makefile

* We use std::stod() hence the flag -std=c++11. The version of gcc for a Raspian distribution (8.3) is not adequate. So on Raspberry we suggest to install Gcc release 10.x or higher ; Our initial implementation for Raspberry used get_float() (see sources) to convert string to double.
* Some functions used Open-MP. The corresponding flags are not set in the Makefile. So, by default there is no parallelization.
* Directories with prefixes RESULTS* contain datasets and results. Check .csv files.
* Python files are for generating the reports of results.
* Bash scripts are maily devoted to publish data to the MQTT server

## Prerequisites

You need to install the Mosquitto MQTT server (and client-side). Regarding Python, you need to install qrcode and image libraries as well as Scikit Learn. We assume that Iertools, Numpy, and Pandas are already installed on your system.

# Inspired by

Since our project reuses codes from others, we are grateful to:
* https://github.com/ieyjzhou/KmeansPlusPlus
* https://github.com/cameron314/concurrentqueue
