#
# /usr/local/opt/python@3.9/bin/python3.9 test2.py
#

import numpy as np
import pandas as pd
from sklearn.cluster import KMeans
import math
import matplotlib.pyplot as plt
from sklearn.decomposition import PCA

df = [[2164202.6211907,  7781578.68085373],
      [7775478.56926763, 2211497.60872298],
      [7808071.06668359, 7782651.94992386],
      [2210953.41548584, 2235258.35235316],
      [5060219.27305952, 5098423.4255134 ]]

input_file = "RESULTS_KEAMSPLUSPLUS_DATA_WITHOUT_TIME/220620212021939092347.csv"
df1 = np.loadtxt(input_file, delimiter=',')

#reduced_data = PCA(n_components=2).fit_transform(df1)
mykmeans = KMeans(init="k-means++",n_clusters=5, random_state=0).fit(df1)

print("------------CENTROIDS--------------")
print("With our data-stream algorithm:")
print(df)
print("With k-means:")
print(mykmeans.cluster_centers_)

#plt.figure(figsize=(12, 12))
#plt.subplot(221)
plt.scatter(df1[:, 0], df1[:, 1], c=mykmeans.labels_)
# plot data stream centroids
plt.scatter(*zip(*df),s=120.0,marker='x',color='#ff0000')
# plot kmeans++ centroids
plt.scatter(*zip(*mykmeans.cluster_centers_),color='#ff0000')
#
plt.xlabel("Random values")
plt.ylabel("Random values")
plt.title("Cross = datastream ; Dot = kmeans++")
plt.show()

