#
# /usr/local/opt/python@3.9/bin/python3.9 test4.py
#
# Requirements:
#     pip3 install qrcode
#     pip3 install image

import os
import numpy as np
import pandas as pd
from sklearn.cluster import KMeans
from pathlib import Path
from typing import List
from itertools import combinations
import math
import qrcode

def gini(x: List[tuple]) -> float:
    #print(type(x))
    y   = np.array(x,dtype=float)
    res = sum(math.sqrt( ((i[0]-j[0])**2)+((i[1]-j[1])**2) ) for i, j in combinations(y, r=2))
    return res/(len(y)**2 - len(y))

pathlist = Path('RESULTS_FIVE_CENTROIDS').glob('Centroids_After_*.csv')
for path in pathlist:
         # because path is object not string
         path_in_str = str(path)
         #print(path_in_str)

         # Results for mosquitto

         input_file = path_in_str
         
         # comma delimited is the default
         #df = pd.read_csv(input_file, header = 0)

         # for space delimited use:
         # df = pd.read_csv(input_file, header = 0, delimiter = " ")

         # for tab delimited use:
         # df = pd.read_csv(input_file, header = 0, delimiter = "\t")

         # for tab delimited use:
         #df = pd.read_csv(input_file, header = 1, delimiter = ";")
         with open(input_file) as f:
             lines = (line for line in f if not line.startswith('#'))
             df = np.loadtxt(lines, delimiter=';')
         # df = np.loadtxt(input_file, delimiter=';')

         # put the original column names in a python list
         # original_headers = list(df.columns.values)

         # remove the non-numeric columns
         #df = df._get_numeric_data()

         # put the numeric column names in a python list
         #numeric_headers = list(df.columns.values)

         # create a numpy array with the numeric values for input into scikit-learn
         #numpy_array = df.as_matrix()

         #print(df)
         #print(df[0])
         #print(df[0][0])

         # We start kmeansplusplus

         input_file = "RESULTS_FIVE_CENTROIDS/" + path_in_str.removeprefix("RESULTS_FIVE_CENTROIDS/Centroids_After_")

         df1 = np.loadtxt(input_file, delimiter=',')

         kmeans = KMeans(init="k-means++",n_clusters=5, random_state=0).fit(df1)

         print("------------CENTROIDS--------------")
         print("With our data-stream algorithm:")
         print("QRcode: "+os.path.splitext(path_in_str)[0]+".png")
         print(df)
         print("With k-means++:")
         print("QRcode: "+os.path.splitext(input_file)[0]+".png")
         print(kmeans.cluster_centers_)

         # Save data as a qrcode
         img = qrcode.make(str(df))
         #type(img)  # qrcode.image.pil.PilImage
         img.save(os.path.splitext(path_in_str)[0]+".png")
         
         # Save data as a qrcode
         img = qrcode.make(str(kmeans.cluster_centers_))
         #type(img)  # qrcode.image.pil.PilImage
         img.save(os.path.splitext(input_file)[0]+".png")
                                             
         # Print the intersection

         res=[list(x) for x in set(tuple(x) for x in df).intersection(set(tuple(x) for x in df1))]
         #print('---------INTERSECTION-------------')
         #print(res)

         #print('------------UNION-----------------')
         #print(set(tuple(x) for x in df))
         #print(set(tuple(x) for x in kmeans.cluster_centers_))
         res1=[list(x) for x in set(tuple(x) for x in df).union(set(tuple(x) for x in kmeans.cluster_centers_))]
         #print(res1)

         print('----------JACCARD INDEX-----------')
         print(len(res)/len(res1))
         #print('----------------------------------')
         print('------GINI INDEX data stream------')
         XX = list(tuple(x) for x in df)
         print(gini(XX))
         #print('----------------------------------')
         print('------GINI INDEX k-means++ --------')
         YY = list(tuple(x) for x in kmeans.cluster_centers_)
         print(gini(YY))
         print('--RATIO BETWEEN GINI INDEXES (%)--')
         print(str((100.0 * gini(XX)/gini(YY)) - 100.0) + " %")
         print('----------------------------------')
                           
