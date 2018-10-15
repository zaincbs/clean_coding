
SHELL=/bin/sh
# --------------------------------------------------------------------------- #
# --------------------------------------------------------------------------- #
# --------------------------------------------------------------------------- #
OBJDIR  = ../obj/
LIBSDIR  = ../lib/
RUNDIR  = ../run/
SRC= ../src
INC= ../include
BIN=link_list


INCLUDE_PATHS =  \
             -I./$(INC)

CFLAGS+= -g -c -Wall $(INCLUDE_PATHS) 

SRC_INC=$(SRC)/

%.o : $(SRC_INC)%.c
	$(CC) $(CFLAGS) $< -o $(OBJDIR)$(@F)

all: pre $(BIN)

OBJS1 :=    link_list.o                              

$(BIN): $(OBJS1) 
	$(CC) -g -Wall -o $(RUNDIR)$@ -Wl,-rpath -Wl, $(INCLUDE_PATHS) $(addprefix $(OBJDIR),$^) 

pre :   
	test -e $(OBJDIR)   || mkdir -p $(OBJDIR)    

clean:
	-rm -rf $(OBJDIR)

