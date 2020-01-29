INCFLAGS = -I /mit/6.837/public/include/vecmath
INCFLAGS += -I /mit/glut/include
LINKFLAGS = -L /mit/6.837/public/lib -l vecmath
LINKFLAGS += -L /mit/glut/lib -lGL -lGLU -lglut -lX11 -lXi
LINKFLAGS += -lfltk -lfltk_gl 
CFLAGS    = -g 
CC        = g++
SRCS      = bitmap.cpp camera.cpp MatrixStack.cpp modelerapp.cpp modelerui.cpp modelerview.cpp sample.cpp
OBJS      = $(SRCS:.cpp=.o)
PROG      = a2

all: $(SRCS) $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LINKFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -c -o $@ $(INCFLAGS)

depend:
	makedepend $(INCFLAGS) -Y $(SRCS)

clean:
	rm $(OBJS) $(PROG)

bitmap.o: bitmap.h
camera.o: camera.h
MatrixStack.o: MatrixStack.h
modelerapp.o: modelerapp.h modelerview.h modelerui.h bitmap.h camera.h
modelerui.o: modelerui.h modelerview.h bitmap.h camera.h modelerapp.h
modelerview.o: modelerview.h camera.h
sample.o: MatrixStack.h modelerview.h modelerapp.h
