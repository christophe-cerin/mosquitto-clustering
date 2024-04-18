# Mosquitto-clustering

Implementations of data-stream clustering on low-cost machines such as Raspberry pi. An [MQTT Mosquitto](https://mosquitto.org/) infrastructure publishes data. A client program subscribes to the server and clusters data with an "online" algorithm. The implementations are now mandatory for the associated research.

## Paper Abstract

Nowadays, the operations performed by the Internet of Things (IoT) systems are no longer trivial
since they rely on more sophisticated devices than in the past. The IoT system is physically
composed of connected computing, digital, and mechanical devices such as sensors or actuators.
Most of the time, each device incorporates an arithmetic logical unit that can pre-compute or
compute on the device. To extract value from the data produced at the edge, the processing power
offered by cloud computing is still utilized. However, streaming data to the cloud exposes some
limitations related to the increased communication and data transfer, which introduces delays
and consumes network bandwidth. Clustering data is one example of a treatment that can be
executed in the cloud. We propose a methodology for solving the data stream
clustering problem at the edge. Data Stream clustering is defined as the clustering of data
that arrive continuously, such as telephone records, multimedia data, sensor data, financial
transactions, etc. Since we use low-cost and low-capacity devices, the objective is given a
sequence of points, to construct a "good" clustering of the stream using a small amount of memory
and time. We propose a ’windowing’ scheme coupled with a sampling scheme to respect the
objective, we mean the diversity in data. Under the experimental conditions, the experiments show that the clustering solutions
can be controlled either with time-stamped or random data. The main difference in our
schema is that we are clustering data "on the fly” with no knowledge or assumption regarding
the available data. We do not assume all the data are known before a treatment batch by
batch. Our schema also has the potential to be adapted to other classes of machine learning
algorithms.

## Hints for the compilation with Makefile

* We use std::stod() hence the flag -std=c++11. The GCC version for a Raspian distribution (8.3) is not adequate. So on Raspberry, we suggest installing Gcc release 10.x or higher; Our initial implementation for Raspberry used get_float() (see sources) to convert string to double.
* Some functions used Open-MP. The corresponding flags are not set in the Makefile. So, by default, there is no parallelization.
* Directories with prefixes RESULTS* contain datasets and results. Check .csv files.
* Python files are for generating the reports of results.
* Bash scripts are mainly devoted to publishing data to the MQTT server

## Prerequisites

You need to install a [Mosquitto MQTT](https://mosquitto.org/) server and the client. 

# Inspired by

Since our project reuses programs from others, we are grateful to:
* https://github.com/ieyjzhou/KmeansPlusPlus
* https://github.com/cameron314/concurrentqueue

# Bibliography

```
@article{DBLP:journals/jpdc/CerinKS22,
  author       = {Christophe C{\'{e}}rin and
                  Keiji Kimura and
                  Mamadou Sow},
  title        = {Data stream clustering for low-cost machines},
  journal      = {J. Parallel Distributed Comput.},
  volume       = {166},
  pages        = {57--70},
  year         = {2022},
  url          = {https://doi.org/10.1016/j.jpdc.2022.04.009},
  doi          = {10.1016/J.JPDC.2022.04.009},
  timestamp    = {Mon, 28 Aug 2023 21:32:03 +0200},
  biburl       = {https://dblp.org/rec/journals/jpdc/CerinKS22.bib},
  bibsource    = {dblp computer science bibliography, https://dblp.org}
}
```
