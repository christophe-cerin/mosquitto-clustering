#!/usr/bin/env python
# -*- coding: utf-8 -*-
from math import sqrt# Importation de la fonction racine carré
from random import random# Importation de la fonction aléatoire
from random import randint# Importation de la fonction aléatoire

NombreHistoires = 55000# Nombre de réalisations d'histoires
Compteur= 0# Nombre de fois que l'on se trouve dans le cercle

res = []
for i in range(NombreHistoires):
    x = random()# Composante sur x aléatoire
    y = random()# Composante sur y aléatoire
    r = sqrt(x**2+y**2)# Calcul de la distance entre le centre et le point
    if r <= 1:# Vérification que le point se trouve dans le cercle
        Compteur = Compteur + 1
        #print(Compteur)
        # choix du centroid
        cadran = randint(1,4)
        if  cadran == 2:
                    x=-x;
        elif cadran == 3:
                    x=-x;y=-y;
        elif cadran ==  4:
                    y=-y
        x=x*5000;y=y*5000;
        centroid = randint(1,5)
        if centroid == 1:
                    x=x+30000;y=y+30000;
        elif centroid == 2:
                    x=x+10000;y=y+30000;
        elif centroid == 3:
                    x=x+10000;y=y+10000;
        elif centroid == 4:
                    x=x+30000;y=y+10000;
        elif centroid == 5:
                    x=x+20000;y=y+20000;
        res = res + [[int(x),int(y)]]
#print(res)
import numpy as np
import pandas as pd
from sklearn.cluster import KMeans
import math
import matplotlib.pyplot as plt
from datetime import datetime

X = np.array(res)
mykmeans = KMeans(init='k-means++',n_clusters=5, random_state=0).fit(X)

now = datetime.now()
timestamp = str(datetime.timestamp(now))
stamp = timestamp.replace(".", "")
np.savetxt(stamp+'.csv', X, delimiter=',',fmt='%d')

#plt.figure(figsize=(12, 12))
#plt.subplot(221)
plt.scatter(X[:, 0], X[:, 1], c=mykmeans.labels_)
# plot kmeans centroids
plt.scatter(*zip(*mykmeans.cluster_centers_),color='#ff0000')
#
#plt.xlabel("Time")
#plt.ylabel("Some values")
#plt.title("Incorrect centroids initializations")

#plt.show()

