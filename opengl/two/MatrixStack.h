#ifndef MATRIX_STACK_H
#define MATRIX_STACK_H

#include <vector>
#include <vecmath.h>

class MatrixStack
{
public:

	// Initialize a matrix stack
	// You probably want to initialize your stack with the identity matrix	
	MatrixStack();

	// Clear the matrix stack to identity
	void clear();

	// Return the top of the stack
	Matrix4f top();

	// Push m onto the stack.
	// Your stack should have OpenGL semantics:
	// the new top should be the old top multiplied by m
	void push( const Matrix4f& m );

	// Remove the top element from the stack
	void pop();

private:

	std::vector< Matrix4f > m_matrices;

};

#endif // MATRIX_STACK_H
