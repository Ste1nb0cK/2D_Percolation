import math
import matplotlib.pyplot as plt
import pandas

n = 10
p = 26

archivo = open("datos32.txt")
V1=archivo.readlines()
archivo.close


P1=[]
DV1=[]
df=pandas.DataFrame("datos32.txt",sep="\t",names=["Percolation_value","L","t"])
print(df["Percolation_value"])
for j in range(1,p+1):
  	v1 = []
  	for i in range(n*j-n,3*n*j+1,3):
		print(i)
    		v1.append(V1[i])
	print(v1)
	print(len(v1))
  	suma1 = 0.0
  	for l in range(n):
    		suma1 = suma1 + int(v1[l])
	media1 = suma1 / n
  	P1.append(media1)
	VAR1 = 0.0
	for k in range(n):
		VAR1 = (float(v1[k])-media1)**2
	VAR1 = VAR1/n
	dv1 = math.sqrt(VAR1)
	DV1.append(dv1)

print("L = 32")
print(P1)
print(DV1)

archivo = open("datos64.txt")
V2=archivo.readlines()
archivo.close

P2=[]
DV2=[]
for j in range(1,p+1):
        v2 = []
        for i in range(n*j-n,n*j,3):
                v2.append(V2[i])
        suma2 = 0.0
        for l in range(n):
                suma2 = suma2 + int(v2[l])
        media2 = suma2 / n
        P2.append(media2)
        VAR2 = 0.0
        for k in range(n):
                VAR2 = (float(v2[k])-media2)**2
        VAR2 = VAR2/n
        dv2 = math.sqrt(VAR2)
        DV2.append(dv2)

print("L = 64")
print(P2)
print(DV2)

archivo = open("datos128.txt")
V3=archivo.readlines()
archivo.close


P3=[]
DV3=[]
for j in range(1,p+1):
        v3 = []
        for i in range(n*j-n,n*j,3):
                v3.append(V3[i])
        suma3 = 0.0
        for l in range(n):
                suma3 = suma3 + int(v3[l])
        media3 = suma3 / n
        P3.append(media3)
        VAR3 = 0.0
        for k in range(n):
                VAR3 = (float(v3[k])-media3)**2
        VAR3 = VAR3/n
        dv3 = math.sqrt(VAR3)
        DV3.append(dv3)

print("L = 128")
print(P3)
print(DV3)

archivo = open("datos256.txt")
V4=archivo.readlines()
archivo.close


P4=[]
DV4=[]
for j in range(1,p+1):
        v4 = []
        for i in range(n*j-n,n*j,3):
                v4.append(V4[i])
        suma4 = 0.0
        for l in range(n):
                suma4 = suma4 + int(v4[l])
        media4 = suma4 / n
        P4.append(media4)
        VAR4 = 0.0
        for k in range(n):
                VAR4 = (float(v4[k])-media4)**2
        VAR4 = VAR4/n
        dv4 = math.sqrt(VAR4)
        DV4.append(dv4)

print("L = 256")
print(P4)
print(DV4)

archivo = open("datos512.txt")
V5=archivo.readlines()
archivo.close

'''
P5=[]
DV5=[]
for j in range(1,p+1):
        v5 = []
        for i in range(n*j-n,n*j,3):
                v5.append(V5[i])
        suma5 = 0.0
        for l in range(n):
                suma5 = suma5 + int(v5[l])
        media5 = suma5 / n
        P5.append(media5)
        VAR5 = 0.0
        for k in range(n):
                VAR5 = (float(v5[k])-media5)**2
        VAR5 = VAR5/n
        dv5 = math.sqrt(VAR5)
        DV5.append(dv5)

print("L = 512")
print(P5)
print(DV5)
'''

Probabilidad = [0, 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.56, 0.57, 0.58, 0.59, 0.6, 0.61, 0.62, 0.63, 0.64, 0.65, 0.7, 0.75, 0.78, 0.79]

plt.errorbar(Probabilidad, P1, yerr = DV1, marker = 'o', label = 'L=32')
plt.errorbar(Probabilidad, P2, yerr = DV2, marker = 'o', label = 'L=64')
plt.errorbar(Probabilidad, P3, yerr = DV3, marker = 'o', label = 'L=128')
plt.errorbar(Probabilidad, P4, yerr = DV4, marker = 'o', label = 'L=256')
#plt.errorbar(Probabilidad, P5, yerr = DV5, marker = 'o', label = 'L=512')
plt.title('P(p,L)')
plt.xlabel('Probabilidad de Llenado')
plt.ylabel('Probabilidad promedio(p,L)')
plt.legend()
plt.show()
