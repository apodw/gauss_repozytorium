all:
<<<<<<< HEAD
	gcc -Wall --pedantic src/*.c -o bin/gauss.exe
=======
	gcc -Wall -lm --pedantic src/*.c -o bin/gauss.exe
>>>>>>> 79c5633a285a7eae1098c180556251de47ed1f05

test: all
	bin/gauss.exe dane/A dane/b
