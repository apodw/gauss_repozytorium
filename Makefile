all:
	gcc -Wall -lm --pedantic src/*.c -o bin/gausss.exe
test: all
	bin/gauss.exe dane/A dane/b
