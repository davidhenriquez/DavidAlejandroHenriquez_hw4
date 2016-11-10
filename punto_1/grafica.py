import numpy as np
import matplotlib.pyplot as plt
import os

infile = open("potencial.dat",'r')
text = infile.readlines()
U = np.ones((251,251))
for i in range(251):
    for j in range(251):
        U[i,j] = text[i*251 +j]

fig = plt.figure()
ax = plt.axes()
ax.set_xlabel("X")
ax.set_ylabel("Y")
ax.set_title("Potencial")

plt.imshow(U)
plt.grid(True)
plt.colorbar()

plt.savefig("potencial.pdf",format = 'pdf')
plt.close()

infile1 = open("E_x.dat",'r')
text = infile1.readlines()
U1 = np.ones((251,251))
for i in range(251):
    for j in range(251):
        U1[i,j] = text[i*251 +j]

infile2 = open("E_y.dat",'r')
text = infile2.readlines()
U2 = np.ones((251,251))
for i in range(251):
    for j in range(251):
        U2[i,j] = text[i*251 +j]

X = np.linspace(0,5,251)
Y = np.linspace(0,5,251)

fig = plt.figure()
ax = plt.axes()
ax.set_xlabel("X")
ax.set_ylabel("Y")
ax.set_title("Campo Electrico")

plt.streamplot(X,Y,U1,U2)

plt.savefig("Campo_Electrico.pdf",format = 'pdf')
plt.close()

