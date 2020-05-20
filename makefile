# Maria Maldonado 1000061100
SRC = Code6_1000061100.c
OBJ = $(SRC:.c=.o)
EXE = $(SRC:.c=.e)

LSRC = SockLib.c
LOBJ = $(LSRC:.c=.o)
LHDR = $(LSRC:.c=.h)

CFLAGS = -g

LIBOBJ = $(LOBJ)

all : $(EXE)

$(EXE): $(OBJ) $(LIBOBJ)
	gcc $(CFLAGS) $(OBJ) $(LIBOBJ) -o $(EXE)

$(OBJ) : $(SRC)
	gcc -c $(CFLAGS) $(SRC) -o $(OBJ)

$(LOBJ): $(LSRC) $(LHDR)
	gcc -c $(CFLAGS) $(LSRC) -o $(LOBJ)
