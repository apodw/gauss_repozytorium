all:
	gcc -Wall -lm --pedantic src/*.c -o bin/gauss.exe
test: all
	bin/gauss.exe dane/A dane/b
	bin/gauss.exe dane/A2 dane/b2
	bin/gauss.exe dane/A3 dane/b3
