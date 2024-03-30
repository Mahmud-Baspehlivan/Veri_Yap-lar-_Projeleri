Tum: derleme calistirma

derleme:
	g++ -I ./include/ -o ./lib/Yigit.o -c ./src/Yigit.cpp
	g++ -I ./include/ -o ./lib/IkiliAramaAgaciDugum.o -c ./src/IkiliAramaAgaciDugum.cpp
	g++ -I ./include/ -o ./lib/IkiliAramaAgaci.o -c ./src/IkiliAramaAgaci.cpp
	g++ -I ./include/ -o ./lib/BagliAgacListesi.o -c ./src/BagliAgacListesi.cpp
	g++ -I ./include/ -o ./lib/main.o -c ./src/main.cpp
	g++ -I ./include/ -o ./bin/Program ./lib/Yigit.o ./lib/IkiliAramaAgaciDugum.o ./lib/IkiliAramaAgaci.o ./lib/BagliAgacListesi.o ./lib/main.o

calistirma:
	./bin/Program ./doc/Sayilar.txt