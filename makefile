driver: listdriver.o
	g++ -o driver -g listdriver.o
	
listdriver.o: listdriver.cpp List.h List.cpp
	g++ -c -g listdriver.cpp
	

