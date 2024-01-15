IDIR=include
CC=g++
CLFAGS=-I$(IDIR)

ODIR=obj
LDIR=../lib

LIBS=-lm -lncurses

_DEPS=defs.h Vector2.h Vector3.h Vector4.h Matrix22.h Matrix33.h Matrix44.h Rasterizer.h GenMath.h Framebuffer.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o Vector2.o Vector3.o Vector4.o Matrix22.o Matrix33.o Matrix44.o Rasterizer.o GenMath.o Framebuffer.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CLFAGS)

all: $(OBJ)
	$(CC) -o $@ $^ $(CLFAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *- core $(INCDIR)/*-

run: all
	./all