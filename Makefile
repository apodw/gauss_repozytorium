all:
	gcc -Wall --pedantic src/*.c -o bin/gauss.exe

test: all
	bin/gauss.exe dane/A dane/b
