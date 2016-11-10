import numpy as np
import matplotlib.pyplot as plt
import os

infile = open("solucion.dat",'r')
text = infile.readlines()
U = np.ones((200,26))
for i in range(200):
    for j in range(26):
        U[i,j] = text[i*26 +j]


x = np.arange(26)*4
for i in range(200):
    fig = plt.figure()
    ax = plt.axes()
    plt.plot(x,U[i,::],'o-',label='Cuerda')
    plt.ylim(-np.amax(U)*1.1,np.amax(U)*1.1)
    ax.set_title("Simulacion Cuerda")
    ax.set_xlabel("posicion_x")
    ax.set_ylabel("posicion_y")
    ax.legend()
    plt.savefig(str(i)+'.png', format = 'png')
    plt.close()
os.system('convert -delay 75 -loop 0 $(ls *.png | sort -n) cuerda.gif')
os.system('rm -f *.png')

for i in range(200):
    os.system('rm -f ' + str(i)+'.gif')  

