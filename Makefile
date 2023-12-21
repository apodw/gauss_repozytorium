all:
	mkdir -p bin
	gcc -Wall -lm --pedantic src/*.c -o bin/gauss.exe
test: all
	bin/gauss.exe dane/A dane/b
	bin/gauss.exe dane/A2 dane/b2
	bin/gauss.exe dane/A3 dane/b3
	bin/gauss.exe dane/A4 dane/b4
	bin/gauss.exe dane/A5 dane/b5
	bin/gauss.exe dane/A6 dane/b6
	bin/gauss.exe dane/A7 dane/b7
