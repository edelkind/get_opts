DEFAULT: all
include ./Makefile.sets
include ./Makefile.ready
include ./Makefile.bin

SRC             = get_opts.c \
                  gather_opt.c \
                  try_opt.c \
                  opt_free.c \
                  opt_strcmp.c \
                  opt_vars.c \
                  new_list.c \
                  get_opts_errormatic.c \

OBJ             = $(SRC:.c=.o)
LIB             = get_opts.a

CFLAGS         += $(D_CFLAGS)

.c.o:
	./compile.sh $<
	
all: lib

ready-local: READYBANNER compile.sh makelib.sh

lib: ready-local $(LIB) lib$(LIB)

$(LIB): BINBANNER $(OBJ)
	./makelib.sh $@ $(OBJ)
#	$(AR) $@ $(OBJ)
#	$(RANLIB) $@

lib$(LIB): $(LIB)
	rm -f $@
	ln -s $(LIB) $@

relib: lean libclean lib

rebin: binclean bin

remake: clean all

lean:
	rm -f core $(OBJ)

libclean:
	rm -f BINBANNER $(LIB) lib$(LIB)

clean: lean libclean readyclean

distclean: clean
	@echo ""
	@echo "note: distclean is the same as clean"

install:
	@echo "minilib: install me not."

