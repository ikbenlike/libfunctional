CC = gcc

ODIR = ./obj

src = $(wildcard src/*.c)
obj = $(src:.c=.o)

objs = $(patsubst src/%,obj/%,$(obj))

obj/%.o: src/%.c
	$(CC) -o $@ -c $<

libfunc.a: $(objs)
	ar rcs $@ $(objs)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o libfunc.a
