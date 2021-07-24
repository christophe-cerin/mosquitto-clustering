#
# /usr/local/opt/python@3.9/bin/python3.9 test2.py
#

import numpy as np
import pandas as pd
from sklearn.cluster import KMeans
import math
import matplotlib.pyplot as plt
from sklearn.decomposition import PCA

df = [[1.75848145e+11, 4.87975400e+06],
      [1.75900557e+11, 6.03623100e+06],
      [1.75908569e+11, 2.42252700e+06],
      [1.75924167e+11, 1.71726000e+06],
      [1.75926477e+11, 4.48367500e+06]]


input_file = "RESULTS_WITHOUT_RECALCULATION_CENTERS/140620211758900921776.csv"
df1 = np.loadtxt(input_file, delimiter=',')

#reduced_data = PCA(n_components=2).fit_transform(df1)
mykmeans = KMeans(n_clusters=5, random_state=0).fit(df1)

print("------------CENTROIDS--------------")
print("With our data-stream algorithm:")
print(df)
print("With k-means:")
print(mykmeans.cluster_centers_)

#plt.figure(figsize=(12, 12))
#plt.subplot(221)
plt.scatter(df1[:, 0], df1[:, 1], c=mykmeans.labels_)
# plot data stream centroids
plt.scatter(*zip(*df),color='#76c2b4')
# plot kmeans centroids
plt.scatter(*zip(*mykmeans.cluster_centers_),color='#ff0000')
#
plt.xlabel("Time")
plt.ylabel("Some values")
plt.title("Incorrect centroids initializations")
plt.show()

