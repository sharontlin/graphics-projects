INCFLAGS = -I/mit/6.837/public/include/vecmath
LINKFLAGS = -L/mit/6.837/public/lib -lvecmath -lm
CC = g++
SRCS = main.cpp Image.cpp SceneParser.cpp
OBJS = $(SRCS:.cpp=.o)
PROG = a4

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LINKFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -c -o $@ $(INCFLAGS)

clean:
	rm -f *.bak *.o core.* $(PROG) 
