DEFAULT: all
include ../Makefile.sets
include ../Makefile.ready
include ../Makefile.bin

SRC             = opt_example.c \
                  opt_example_em.c \

OBJ             = $(SRC:.c=.o)
BIN             = $(SRC:.c=)

CFLAGS         += -I.. $(D_CFLAGS)
LDFLAGS        += -L.. -lget_opts $(D_LDFLAGS)

.c.o:
	./compile.sh $<
	
all: ready bin

rebin: binclean bin

remake: clean all

bin: $(BIN)

$(BIN): BINBANNER $(OBJ)
	./load.sh $@ $@.o

lean:
	rm -f core $(OBJ)

binclean:
	rm -f BINBANNER $(BIN)

clean: lean binclean readyclean

distclean: clean
	@echo ""
	@echo "note: $@ is the same as clean"

install: all installbin

installbin:
	cp $(BIN) $(HOME)/bin/


