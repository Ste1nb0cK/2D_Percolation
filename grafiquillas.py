import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

#empezamos por traer los archivos
df256 = pd.read_csv("datos256.txt", sep="\t", usecols=[1,2,3,4,5],names=["L","p","seed","percolation_value", "cluster_size",
                     "time"])


df256[0:11]

#lista con todas las probabilidades usadas
Probabilidad = [0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.56, 0.57,
                0.58, 0.59, 0.6, 0.61, 0.62, 0.63, 0.64, 0.65, 0.7, 0.75, 0.78, 0.79]

#Para un valor fijo de probabilidad, extraemos el promedio y desviación estandar del valor de percolación
percolation_value_avg_list = []
cluster_size_avg_list = []
percolation_value_std_list = []
cluster_size_std_list = []
for p in Probabilidad:
    #aquí cálculamos el promedio para todos los elementos que tienen el p dado y sacamos el promedio
    percolation_value_avg = df256[df256['p']== p]["percolation_value"].mean()
    cluster_size_avg = df256[df256['p']== p]["cluster_size"].mean()
    percolation_value_avg_list.append( percolation_value_avg)
    cluster_size_avg_list.append( cluster_size_avg)

    #aquí hacemos esencialmente lo mismo pero cálculamos la desviación estandar
    percolation_value_std = df256[df256['p']== p]["percolation_value"].std()
    cluster_size_std = df256[df256['p']== p]["cluster_size"].std()
    percolation_value_std_list.append( percolation_value_std)
    cluster_size_std_list.append( cluster_size_std )


percolation_value_std

plt.plot(Probabilidad, percolation_value_avg_list)
plt.errorbar(Probabilidad, percolation_value_avg_list, yerr=percolation_value_std_list)
plt.savefig("plot.pdf")
