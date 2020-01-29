INCFLAGS  = -I /mit/glut/include
INCFLAGS += -I /mit/6.837/public/include/vecmath

LINKFLAGS  = -L /mit/glut/lib -lglut -lGL -lGLU
LINKFLAGS += -L /mit/6.837/public/lib -lvecmath

CFLAGS    = -O2
CC        = g++
SRCS      = main.cpp
OBJS      = $(SRCS:.cpp=.o)
PROG      = a0

all: $(SRCS) $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCFLAGS) $(LINKFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -c -o $@ $(INCFLAGS)

depend:
	makedepend $(INCFLAGS) -Y $(SRCS)

clean:
	rm $(OBJS) $(PROG)

