import matplotlib.pyplot as plt

plt.figure(0)

with open('time_data01.txt') as f:
    lines = f.readlines()
    M = [float(line.split()[0]) for line in lines]
    t = [float(line.split()[1]) for line in lines]
    t_err = [float(line.split()[2]) for line in lines]

plt.plot(M ,t,label='-O0')
plt.errorbar(M,t,yerr = t_err,fmt ='o')

with open('time_data11.txt') as f:
    lines = f.readlines()
    M = [float(line.split()[0]) for line in lines]
    t = [float(line.split()[1]) for line in lines]
    t_err = [float(line.split()[2]) for line in lines]

plt.plot(M ,t,label='-O1')
plt.errorbar(M,t,yerr = t_err,fmt ='o')

with open('time_data31.txt') as f:
    lines = f.readlines()
    M = [float(line.split()[0]) for line in lines]
    t = [float(line.split()[1]) for line in lines]
    t_err = [float(line.split()[2]) for line in lines]

plt.plot(M ,t,label='-O3')
plt.errorbar(M,t,yerr = t_err,fmt ='o')

plt.title("Tiempo de ejecución. p=0.3")
plt.xlabel("Tamaño de la matriz")
plt.ylabel("Tiempo (s)")
plt.legend()
plt.grid()
plt.savefig('Execution_time_p03.png')

#---------------------------------------------------------------------

plt.figure(1)

with open('time_data02.txt') as f:
    lines = f.readlines()
    M = [float(line.split()[0]) for line in lines]
    t = [float(line.split()[1]) for line in lines]
    t_err = [float(line.split()[2]) for line in lines]

plt.plot(M ,t,label='-O0')
plt.errorbar(M,t,yerr = t_err,fmt ='o')

with open('time_data12.txt') as f:
    lines = f.readlines()
    M = [float(line.split()[0]) for line in lines]
    t = [float(line.split()[1]) for line in lines]
    t_err = [float(line.split()[2]) for line in lines]

plt.plot(M ,t,label='-O1')
plt.errorbar(M,t,yerr = t_err,fmt ='o')

with open('time_data32.txt') as f:
    lines = f.readlines()
    M = [float(line.split()[0]) for line in lines]
    t = [float(line.split()[1]) for line in lines]
    t_err = [float(line.split()[2]) for line in lines]

plt.plot(M ,t,label='-O3')
plt.errorbar(M,t,yerr = t_err,fmt ='o')

plt.title("Tiempo de ejecución. p=0.6")
plt.xlabel("Tamaño de la matriz")
plt.ylabel("Tiempo (s)")
plt.legend()
plt.grid()
plt.savefig('Execution_time_p06.png')

#---------------------------------------------------------------------

plt.figure(3)

with open('time_data03.txt') as f:
    lines = f.readlines()
    M = [float(line.split()[0]) for line in lines]
    t = [float(line.split()[1]) for line in lines]
    t_err = [float(line.split()[2]) for line in lines]

plt.plot(M ,t,label='-O0')
plt.errorbar(M,t,yerr = t_err,fmt ='o')

with open('time_data13.txt') as f:
    lines = f.readlines()
    M = [float(line.split()[0]) for line in lines]
    t = [float(line.split()[1]) for line in lines]
    t_err = [float(line.split()[2]) for line in lines]

plt.plot(M ,t,label='-O1')
plt.errorbar(M,t,yerr = t_err,fmt ='o')

with open('time_data33.txt') as f:
    lines = f.readlines()
    M = [float(line.split()[0]) for line in lines]
    t = [float(line.split()[1]) for line in lines]
    t_err = [float(line.split()[2]) for line in lines]

plt.plot(M ,t,label='-O3')
plt.errorbar(M,t,yerr = t_err,fmt ='o')

plt.title("Tiempo de ejecución. p=0.8")
plt.xlabel("Tamaño de la matriz")
plt.ylabel("Tiempo (s)")
plt.legend()
plt.grid()
plt.savefig('Execution_time_p08.png')
