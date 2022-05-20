import math
import matplotlib.pyplot as plt
import pandas as pd

#lista con todas las probabilidades usadas
Probabilidad = [0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.555, 0.56, 0.565, 0.57, 0.575, 0.58, 0.585, 0.59, 0.595, 0.6, 0.605, 0.61, 0.615, 0.62, 0.625, 0.63,
0.635, 0.64, 0.645 ,0.65, 0.7, 0.75, 0.78, 0.8, 0.85, 0.9, 0.95, 1]

#empezamos por traer los archivos
df32 = pd.read_csv("datos32.txt", sep="\t", usecols=[1,2,3,4,5],names=["L","p","seed","percolation_value", "cluster_size",
                     "time"])
df64 = pd.read_csv("datos64.txt", sep="\t", usecols=[1,2,3,4,5],names=["L","p","seed","percolation_value", "cluster_size",
                     "time"])
df128 = pd.read_csv("datos128.txt", sep="\t", usecols=[1,2,3,4,5],names=["L","p","seed","percolation_value", "cluster_size",
                     "time"])
df256 = pd.read_csv("datos256.txt", sep="\t", usecols=[1,2,3,4,5],names=["L","p","seed","percolation_value", "cluster_size",
                     "time"])
df512 = pd.read_csv("datos512.txt", sep="\t", usecols=[1,2,3,4,5],names=["L","p","seed","percolation_value", "cluster_size",
                     "time"])
#Para un valor fijo de probabilidad, extraemos el promedio y desviación estandar del valor de percolación
percolation_value_avg_list32 = []
percolation_value_std_list32 = []

percolation_value_avg_list64 = []
percolation_value_std_list64 = []

percolation_value_avg_list128 = []
percolation_value_std_list128 = []

percolation_value_avg_list256 = []
percolation_value_std_list256 = []

percolation_value_avg_list512 = []
percolation_value_std_list512 = []

for p in Probabilidad:
    #aquí cálculamos el promedio para todos los elementos que tienen el p dado y sacamos el promedio
    percolation_value_avg32 = df32[df32['p']== p]["percolation_value"].mean()
    percolation_value_avg_list32.append( percolation_value_avg32)

    percolation_value_avg64 = df64[df64['p']== p]["percolation_value"].mean()
    percolation_value_avg_list64.append( percolation_value_avg64)

    percolation_value_avg128 = df128[df128['p']== p]["percolation_value"].mean()
    percolation_value_avg_list128.append( percolation_value_avg128)

    percolation_value_avg256 = df256[df256['p']== p]["percolation_value"].mean()
    percolation_value_avg_list256.append( percolation_value_avg256)

    percolation_value_avg512 = df512[df512['p']== p]["percolation_value"].mean()
    percolation_value_avg_list512.append( percolation_value_avg512)

    #aquí hacemos esencialmente lo mismo pero cálculamos la desviación estandar
    percolation_value_std32 = df32[df32['p']== p]["percolation_value"].std()
    percolation_value_std_list32.append( percolation_value_std32)

    percolation_value_std64 = df64[df64['p']== p]["percolation_value"].std()
    percolation_value_std_list64.append( percolation_value_std64)

    percolation_value_std128 = df128[df128['p']== p]["percolation_value"].std()
    percolation_value_std_list128.append( percolation_value_std128)

    percolation_value_std256 = df256[df256['p']== p]["percolation_value"].std()
    percolation_value_std_list256.append( percolation_value_std256)

    percolation_value_std512 = df512[df512['p']== p]["percolation_value"].std()
    percolation_value_std_list512.append( percolation_value_std512)

#aquí hacemos las graficas
plt.figure(figsize=(13,10))
plt.errorbar(Probabilidad, percolation_value_avg_list32, yerr = percolation_value_std_list32, marker = 'o', label = 'L=32')
plt.errorbar(Probabilidad, percolation_value_avg_list64, yerr = percolation_value_std_list64, marker = 'o', label = 'L=64')
plt.errorbar(Probabilidad, percolation_value_avg_list128, yerr = percolation_value_std_list128, marker = 'o', label = 'L=128')
plt.errorbar(Probabilidad, percolation_value_avg_list256, yerr = percolation_value_std_list256, marker = 'o', label = 'L=256')
plt.errorbar(Probabilidad, percolation_value_avg_list512, yerr = percolation_value_std_list512, marker = 'o', label = 'L=512')
plt.title('Probabilidad para la aparación de cluster percolante')
plt.xlabel(r'Probabilidad de llenado $p$')
plt.ylabel(r'Probabilidad $P(p,L)$')
plt.legend()
plt.grid()
plt.savefig("Probabilidad.png")
