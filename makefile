LIBS:= `root-config --libs`
INCS:= `root-config --cflags`

main: main.o Position.o Particle.o MaterialPoint.o VectorField.o
	g++ -o main main.o Position.o Particle.o MaterialPoint.o VectorField.o ${INCS} ${LIBS}

Position.o: Position.cpp Position.h
	g++ -c Position.cpp

Particle.o: Particle.cpp Particle.h
	g++ -c Particle.cpp

MaterialPoint.o: MaterialPoint.cpp MaterialPoint.h Position.h Particle.h VectorField.h
	g++ -c MaterialPoint.cpp

VectorField.o: VectorField.cpp VectorField.h Position.h
	g++ -c VectorField.cpp

main.o: main.cpp MaterialPoint.h VectorField.h
	g++ -c main.cpp ${INCS} ${LIBS}