// modelerview.h

// This is the base class for all your models.  It contains
// a camera control for your use.  The draw() function will 
// set up default lighting and apply the projection, so if you 
// inherit, you will probably want to call ModelerView::draw()
// to set up the camera.
  
#ifndef MODELERVIEW_H
#define MODELERVIEW_H
  
#ifdef WIN32
#include <windows.h>
#endif

#include <FL/Fl_Gl_Window.H>
#include <GL/gl.h>

#include "MatrixStack.h"

class Camera;
class ModelerView;

// This is a typedef for a function pointer.  Nasty syntax.
// Ignore, ignore, ignore.
typedef ModelerView *(*ModelerViewCreator_f) ( int argc, char* argv[],
											  int x, int y, int w, int h,
                                              char *label );

class ModelerView : public Fl_Gl_Window 
{
public:

    ModelerView(int x, int y, int w, int h, const char *label = 0);
    
    virtual ~ModelerView ();
    
    virtual int handle(int event);
	virtual void update();
    virtual void draw();

    Camera *m_camera;
	MatrixStack m_matrixStack;
};


#endif	/*  */
