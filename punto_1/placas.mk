all: potencial.pdf Campo_electrico.pdf

potencial.pdf: potencial.dat
	python grafica.py

potencial.dat: placas.o
	./placas.o

placas.o: placas.c
	gcc -o placas.o placas.c

Campo_electrico.pdf: E_x.dat E_y.dat
        python grafica.py

E_x.dat E_y.dat: placas.o
        ./placas.o

placas.o: placas.c
        gcc -o placas.o placas.c 
clean:
	rm -f *.dat