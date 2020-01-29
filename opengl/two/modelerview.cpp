#include "modelerview.h"
#include "camera.h"

#include <FL/Fl.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/gl.h>
#include <GL/glu.h>
#include <cstdio>

ModelerView::ModelerView(int x, int y, int w, int h,
			 const char *label):Fl_Gl_Window(x, y, w, h, label)
{
    m_camera = new Camera();	

    m_camera->SetDimensions( w, h );
    m_camera->SetDistance( 10 );
    m_camera->SetCenter( Vector3f( 0, 0, 0 ) );
}

ModelerView::~ModelerView()
{
    delete m_camera;
}

int ModelerView::handle( int event )
{
    unsigned eventCoordX = Fl::event_x();
    unsigned eventCoordY = Fl::event_y();
    unsigned eventButton = Fl::event_button();
    unsigned eventState  = Fl::event_state();	

    switch( event )
    {
		case FL_PUSH:
		{
			switch (eventButton)
			{
				case FL_LEFT_MOUSE:
					m_camera->MouseClick( Camera::LEFT, eventCoordX, eventCoordY );
					break;

				case FL_MIDDLE_MOUSE:
					m_camera->MouseClick( Camera::MIDDLE, eventCoordX, eventCoordY );
					break;

				case FL_RIGHT_MOUSE:
					m_camera->MouseClick( Camera::RIGHT, eventCoordX, eventCoordY );
					break;
			}
		}
		break;

		case FL_DRAG:
		{
			m_camera->MouseDrag(eventCoordX, eventCoordY);
		}
		break;

    case FL_RELEASE:
		{
            m_camera->MouseRelease(eventCoordX, eventCoordY);
		}
		break;	

    default:
		return 0;
    }

    redraw();

    return 1;
}

void ModelerView::update()
{

}

void ModelerView::draw()
{
    // Window is !valid() upon resize
    // FLTK convention has you initializing rendering here.
    if( !valid() )
    {
        // Setup opengl
        glShadeModel( GL_SMOOTH );
        glEnable( GL_DEPTH_TEST );
        glEnable( GL_LIGHTING );
        glEnable( GL_LIGHT0 );
        glEnable( GL_NORMALIZE );
        
        m_camera->SetDimensions(w(),h());
        m_camera->SetViewport(0,0,w(),h());
        m_camera->ApplyViewport();
        
        glMatrixMode( GL_PROJECTION );
        glLoadIdentity();
        m_camera->SetPerspective( 50.0f );
        glLoadMatrixf( m_camera->projectionMatrix() );
    }
        
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Note that the lighting is applied *before* applying the camera
    // transform.  This is so the light appeared fixed on the camera.    
    GLfloat Lt0diff[] = {1.0,1.0,1.0,1.0};
    GLfloat Lt0pos[] = {3.0,3.0,5.0,1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, Lt0diff);
    glLightfv(GL_LIGHT0, GL_POSITION, Lt0pos);

	m_matrixStack.clear();
	m_matrixStack.push( m_camera->viewMatrix() );
	glLoadMatrixf( m_matrixStack.top() );

    // These are just some default material colors
    GLfloat diffColor[] = {0.4f, 0.4f, 0.4f, 1.f};
    GLfloat specColor[] = {0.6f, 0.6f, 0.6f, 1.f};
    GLfloat shininess[] = {50.0f};
    
    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, diffColor );
    glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, specColor );
    glMaterialfv( GL_FRONT_AND_BACK, GL_SHININESS, shininess );
}
