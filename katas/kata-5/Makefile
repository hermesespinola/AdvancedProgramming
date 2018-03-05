all:
	 gcc -c hash.c
	 gcc -c main.c
	 gcc -o hash.exe hash.o main.o

clean:
	 rm *.out *.o *.exe || exit 0

hash: clean
	 gcc -c hash.c
	 gcc -c main.c
	 gcc -o hash.exe hash.o main.o

run: hash
	 ./hash.exe text.txt
