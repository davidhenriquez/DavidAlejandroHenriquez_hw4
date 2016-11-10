
all: cuerda.gif

cuerda.gif: solucion.dat
        python grafica.py

solucion.dat: cuerda.o
        ./cuerda.o

cuerda.o: cuerda.c
        gcc -o cuerda.o cuerda.c

clean:
        rm -f *.dat


