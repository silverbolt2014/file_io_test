all: project.exe

# Specify the output name for the executable file
project.exe: project.o handle_data.o
	gcc -o project.exe project.o handle_data.o

 #The -c option means to compile the source code file into an object file but not to invoke the linker
project.o handle_data.o: project.c handle_data.c
	gcc -c project.c handle_data.c

clean:
	rm *.o *~ project.exe *.dat
