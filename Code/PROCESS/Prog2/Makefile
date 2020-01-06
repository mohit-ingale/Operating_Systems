CC=gcc
prog2:
	$(CC) -o prog2 prog2.c 
transfer:
	scp -r ../Prog2 debian@192.168.7.2:/home/debian/Desktop

clean:
	rm -r prog2
	
run: 
	./prog2
