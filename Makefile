Main.out: Main.o Carros.o Motor.o Chasis.o Pintura.o
	g++ Main.o Carros.o Motor.o Chasis.o Pintura.o -o Main.out

Main.o: Main.cpp Carros.h Motor.h Chasis.h Pintura.h
	g++ -c Main.cpp

Carros.o: Carros.cpp Carros.h Motor.h Chasis.h Pintura.h
	g++ -c Carros.cpp

Motor.o: Motor.cpp Motor.h
	g++ -c Motor.cpp

Chasis.o: Chasis.cpp Chasis.h
	g++ -c Chasis.cpp

Pintura.o: Pintura.cpp Pintura.h
	g++ -c Pintura.cpp
