#include "sample.h"

#include <FL/Fl.H>

using namespace std;

// This is annoying that we have to have this function.  Don't ask.
ModelerView* createSampleModel( int argc, char* argv[],
							   int x, int y, int w, int h, char* label )
{
	return new SampleModel( argc, argv, x, y, w, h, label );
}

// Implementation of SampleModel constructor.  This function
// calls the constructor of the parent ModelerView.  If you
// want to load files, etc, do that here.
SampleModel::SampleModel( int argc, char* argv[],
						 int x, int y, int w, int h, char* label ) :

	m_drawAxes( true ),
	m_drawJoints( true ),
	m_drawSkeleton( true ),
	m_drawMesh( true ),
	
	ModelerView( x, y, w, h, label )
{
    glutInit( &argc, argv );

	string prefix = argv[ 1 ];
	string skeletonFile = prefix + ".skel";
	string meshFile = prefix + ".obj";
	string attachmentfile = prefix + ".attach";

	loadSkeleton( skeletonFile.c_str() );

	computeBindWorldToBoneTransforms();
	updateCurrentBoneToWorldTransforms();

	loadMesh( meshFile.c_str() );
	loadAttachments( attachmentfile.c_str() );	
}

// virtual
int SampleModel::handle( int event )
{
	ModelerView::handle( event );

	unsigned key = Fl::event_key();
	if( event == FL_KEYUP )
	{
		if( key == 'a' )
		{
			m_drawAxes = !m_drawAxes;
			cout << "drawAxes is now: " << m_drawAxes << endl;
		}
		if( key == 'j' )
		{
			m_drawJoints = !m_drawJoints;
			cout << "drawJoints is now: " << m_drawJoints << endl;
		}
		else if( key == 'm' )
		{
			m_drawMesh = !m_drawMesh;
			cout << "drawMesh is now: " << m_drawMesh << endl;
		}
		else if( key == 's' )
		{
			m_drawSkeleton = !m_drawSkeleton;
			cout << "drawSkeleton is now: " << m_drawSkeleton << endl;
		}
	}

	redraw();
	return 1;
}

// virtual
void SampleModel::update()
{
	// update the skeleton from sliders
	updateSkeleton();

	// update the mesh given the new skeleton
	updateMesh();
}

void SampleModel::draw()
{
	// Call the draw function of the parent.  This sets up the
	// viewport, projection, and camera position, as well as some
	// default lighting parameters.  If you want to change the default
	// lighting, I suggest you copy the code out of
	// ModelerView::draw(), paste it here in place of the following
	// line, and then make changes.
	ModelerView::draw();	

	// draw the axes
	if( m_drawAxes )
	{
		drawAxes();
	}
	
	if( m_drawJoints )
	{
		drawJoints( m_rootJoint );
	}

	if( m_drawSkeleton )
	{
		drawSkeleton( m_rootJoint );
	}	

	if( m_drawMesh )
	{
		drawMesh();
	}
}

void SampleModel::loadSkeleton( const char* filename )
{
	// Load the skeleton from file here.
	// You should probably delete the following line
	// and set m_nJoints to however many are in the file.
	m_nJoints = 1;


	m_nBones = m_nJoints - 1;
	m_bindWorldToBoneTransforms.resize( m_nBones );
	m_currentBoneToWorldTransforms.resize( m_nBones );
}

void SampleModel::drawJoints( SceneGraphNode* node )
{
	// Draw a sphere at each joint.
	// We recommend using glutSolidSphere( 0.05f, 36, 36 )
	// to draw a sphere of reasonable size.
	//
	// You are *not* permitted to use the OpenGL matrix stack commands
	// (glPushMatrix, glPopMatrix, glMultMatrix).
	// You should use your MatrixStack class
	// and use glLoadMatrix() before your drawing call.

}

void SampleModel::drawSkeleton( SceneGraphNode* node )
{
	Vector3f rnd( 0, 0, 1 );

	// We recommend using glutSolidCube() to draw the boxes
	// between joints. Unfortunately, glutSolidCube can
	// only draw a cube centered about the origin.
	// Therefore, make sure that you understand hierarchical
	// transformations, we recommend the following strategy:
	//
	// Start with a cube with side length 1.
	// Translate in z so that it goes from [-0.5, -0.5, 0] to [0.5, 0.5,1]
	// Scale it so that it goes from [-0.05, -0.05, 0] to [0.05, 0.05, length]
    //     where length is the distance to the next joint
	// Rotate the z-axis so that it is aligned with the direction to
	//     the next joint: z --> z'
	// Since the x and y axes are arbitrary, we recommend mapping:
	//     y' --> z' cross rnd,
	//     x' --> y' cross z'
	//     with the rnd given above.
	//
	// You are *not* permitted to use the OpenGL matrix stack commands
	// (glPushMatrix, glPopMatrix, glMultMatrix).
	// You should use your MatrixStack class
	// and use glLoadMatrix() before your drawing call.

}

void SampleModel::updateSkeleton()
{
	// You should use VAL() to read your various
	// slider values and update the appropriate
	// joint angles here.
	
	// YOUR CODE HERE

	// Update the bone to world transforms for SSD.
	updateCurrentBoneToWorldTransforms();
}

void SampleModel::loadMesh( const char* filename )
{
	// Load the mesh from file into m_mesh.bindVertices.


	// make a copy of the bind vertices as the current vertices
	m_mesh.currentVertices = m_mesh.bindVertices;
}

void SampleModel::drawMesh()
{
	// Use your matrix stack to draw the mesh.
	// Since these meshes don't have normals
	// be sure to generate a normal per triangle.
	// Notice that since we have per-triangle normals
	// rather than the analytical normals from
	// assignment 1, the appearance is "faceted".

}

void SampleModel::loadAttachments( const char* filename )
{
}

void SampleModel::computeBindWorldToBoneTransforms()
{
}

void SampleModel::updateCurrentBoneToWorldTransforms()
{
}

void SampleModel::updateMesh()
{
}


void SampleModel::drawAxes()
{
	glDisable( GL_LIGHTING );
	glBegin( GL_LINES );

	glColor3f( 1, 0, 0 );
	glVertex3f( 0, 0, 0 );
	glVertex3f( 1, 0, 0 );

	glColor3f( 0, 1, 0 );
	glVertex3f( 0, 0, 0 );
	glVertex3f( 0, 1, 0 );

	glColor3f( 0, 0, 1 );
	glVertex3f( 0, 0, 0 );
	glVertex3f( 0, 0, 1 );

	glEnd();
	glEnable( GL_LIGHTING );
}

int main( int argc, char* argv[] )
{
	if( argc < 2 )
	{
		cout << "Usage: " << argv[ 0 ] << " PREFIX" << endl;
		cout << "For example, if you're trying to load data/cheb.skel, data/cheb.obj, and data/cheb.attach, run with: " << argv[ 0 ] << " data/cheb" << endl;
		return -1;
	}

    // Initialize the controls.  You have to define a ModelerControl
    // for every variable name that you define in the enumeration.

    // The constructor for a ModelerControl takes the following arguments:
    // - text label in user interface
    // - minimum slider value
    // - maximum slider value
    // - step size for slider
    // - initial slider value
    //
    // You will want to modify this to accommodate your model.
    ModelerControl controls[ NUMCONTROLS ];
    controls[ FX ] = ModelerControl( "Foot Angle X", -M_PI, M_PI, 0.1f, 0 );
    controls[ FY ] = ModelerControl( "Foot Angle Y", -M_PI, M_PI, 0.1f, 0 );
    controls[ FZ ] = ModelerControl( "Foot Angle Z", -M_PI, M_PI, 0.1f, 0 );

    // Initialize the ModelerApplication with your model and the
    // appropriate array of controls.  Basically, what this does is
    // "hook in" the user interface code.
    ModelerApplication::Instance()->Init
	(
		&createSampleModel,
		argc, argv,
		controls,
		NUMCONTROLS
	);

    // Run the modeler application.
    int ret = ModelerApplication::Instance()->Run();

    // This line is reached when you close the program.
    delete ModelerApplication::Instance();
    
    return ret;
}
