CFLAGS = -O3 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm

INC = sdl2-light.h
SRC = main.c Modules/sdl2-light.c Modules/graphics.c Modules/monde.c Modules/vaisseau.c
OBJ = $(SRC:%.c=%.o)

INC_TEST = Modules/param.h  Modules/monde.h Modules/vaisseau.h
SRC_TEST = Tests/tests.c  Modules/monde.c Modules/vaisseau.c
OBJ_TEST = $(SRC_TEST:%.c=%.o)

PROG = spacecorridor

PROG_TEST = test

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<

spacecorridor: $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

test: $(OBJ_TEST)
	gcc $(CFLAGS) $(OBJ_TEST) $(LDFLAGS) -o $@



doc: $(PROG)
	doxygen ./$(PROG)
	make -C latex

clean:
	rm -f *~ *.o $(PROG)
	rm -rf latex html


