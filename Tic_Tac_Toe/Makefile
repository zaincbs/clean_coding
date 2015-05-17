CC=gcc
CFLAGS=-c -g -Wall
EXEC= run_me

OBJECTS= tic_tac_toe.o game_menu.o

all: $(OBJECTS) $(EXEC) finish 

$(EXEC): 
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< 

finish:
	mkdir OBJS
	mv *.o OBJS 

run:
	./$(EXEC)	

clean:
	rm OBJS/*.o $(EXEC)
	rm -rf OBJS
# -c  Compile or assemble the source files, but do not link.  The linking \
      stage simply is not done. The ultimate output is in the form of an \
      object file for each source file.


