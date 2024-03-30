Tum: derleme calistirma

derleme:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/DugumBaglanti.o -c ./src/DugumBaglanti.cpp
	g++ -I ./include/ -o ./lib/main.o -c ./src/main.cpp
	g++ -I ./include/ -o ./bin/Program ./lib/Dugum.o ./lib/DugumBaglanti.o ./lib/main.o

calistirma:
	./bin/Program ./doc/Sayilar.txt