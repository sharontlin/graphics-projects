#ifndef SAMPLE_H
#define SAMPLE_H

#ifdef WIN32
#include <windows.h>
#endif

#ifndef M_PI
#define M_PI 3.14159265358979f
#endif

#include <cstdlib>
#include <FL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <vecmath.h>

#include "modelerview.h"
#include "modelerapp.h"
#include "tuple.h"

struct SceneGraphNode
{
	int index; // index from file
	int parentIndex; // parent index from file
	Matrix4f transform; // transform relative to its parent
	std::vector< SceneGraphNode* > children; // list of children
};

typedef tuple< unsigned, 3 > Tuple3u;

struct Mesh
{
	// list of vertices from the OBJ file
	// in the "bind pose"
	std::vector< Vector3f > bindVertices;	

	// each face has 3 indices
	// referencing 3 vertices	
	std::vector< Tuple3u > faces;

	// current vertex positions after animation
	std::vector< Vector3f > currentVertices;

	// list of vertex to bone attachments
	// each element of attachments is a vector< float > containing
	// one attachment weight per bone
	std::vector< std::vector< float > > attachments;
};

// Accessing the values of sliders is a very lengthy function call.
// We use a macro VAL() to shorten it.
#define VAL(x) ( static_cast< float >( ModelerApplication::Instance()->GetControlValue( x ) ) )

// These are the internal variable names for the controls.
// Make extra sure that you list the item "NUMCONTROLS" last.
// This is functionally equivalent to the following code:
//
//   const int FX = 0;
//   const int FY = 1;
//   ...
//   const int NUMCONTROLS = 3;
//
// ... but doing it with an "enum" saves you from having to manually
// label everything.
enum SampleModelControls
{
	FX, FY, FZ,
	NUMCONTROLS
};

// To make a SampleModel, we inherit off of ModelerView
class SampleModel : public ModelerView
{
public:

	SampleModel( int argc, char* argv[], int x, int y, int w, int h, char* label );

	// handles key presses, you don't have to touch this method
	virtual int handle( int event );

	// You should implement update(),
	// which gets called whenever sliders change
	virtual void update();

	// You should implement draw() to draw your mesh.
	// draw() gets called whenever a redraw is required
	// (after an update() occurs, when the camera moves, the window is resized, etc)
	virtual void draw();

private:	

	// Part 1: Understanding Hierarchical Modeling

	// 1.1. Implement method to load a skeleton.
	// This method should compute the following fields:
	// m_rootJoint
	// m_jointIndexToJode
	// m_nJoints
	// m_nBones (done for you)
	void loadSkeleton( const char* filename );

	// 1.1. Implement this method to draw a sphere at each joint.
	void drawJoints( SceneGraphNode* node );	

	// 1.2. Implement this method to draw a box between each pair of joints
	void drawSkeleton( SceneGraphNode* node );

	// 1.3. Implement this method to handle changes to your skeleton given
	// changes in the slider values
	void updateSkeleton();

	// Part 2: Skeletal Subspace Deformation

	// 2.1. Implement these methods to load and draw the bind pose mesh

	// 2.1.1. loadMesh() should populate m_mesh
	// be sure to update bindVertices, currentVertices, and faces
	void loadMesh( const char* filename );

	// 2.1.2. draw the current mesh using your matrix stack.	
	void drawMesh();

	// 2.2. Implement this method to load the per-vertex attachment weights
	// this method should update m_mesh.attachments
	void loadAttachments( const char* filename );

	// 2.3. Implement SSD

	// 2.3.1. Implement this method to compute a per-bone transform from
	// world-space to bone space in the BIND POSE.
	//
	// Note that this needs to be computed only once since there is only
	// a single bind pose.
	//
	// This method should populate m_bindWorldToBoneTransforms.	
	void computeBindWorldToBoneTransforms();

	// 2.3.2. Implement this method to compute a per-bone transform from
	// bone space to world space in the CURRENT POSE.
	//
	// The current pose is defined by the animations you've applied to the
	// skeleton and hence needs to be *updated* every time the skeleton changes.
	//
	// updateSkeleton() already calls this method.
	//
	// This method should update m_bindWorldToBoneTransforms.
	void updateCurrentBoneToWorldTransforms();

	// 2.3.2. This is the core of SSD.
	// Implement this method to update the vertices of the mesh
	// given the current state of the skeleton.
	// You will need both the bind pose world --> bone transforms.
	// and the current bone --> world transforms.
	void updateMesh();


	void drawAxes();

	// pointer to the root joint
	SceneGraphNode* m_rootJoint;
	// a map from the index of a joint in the file to its node
	std::map< int, SceneGraphNode* > m_jointIndexToNode;
	// the number of joints
	int m_nJoints;
	// the number of bones
	int m_nBones;

	std::vector< Matrix4f > m_bindWorldToBoneTransforms;	
	std::vector< Matrix4f > m_currentBoneToWorldTransforms;

	Mesh m_mesh;

	bool m_drawAxes;
	bool m_drawJoints;
	bool m_drawSkeleton;
	bool m_drawMesh;
};

#endif // SAMPLE_H
