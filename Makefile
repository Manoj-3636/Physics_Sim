CC     = gcc
CFLAGS = -Wall -Iinclude
LIBS   = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC = src/main.c src/physics.c src/render.c
OUT = build/sim

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LIBS) -o $(OUT)

clean:
	rm -f build/sim