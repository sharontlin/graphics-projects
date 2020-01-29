#include "MatrixStack.h"

MatrixStack::MatrixStack()
{
}

void MatrixStack::clear()
{
}

Matrix4f MatrixStack::top()
{

	return Matrix4f::identity();
}

void MatrixStack::push( const Matrix4f& m )
{
}

void MatrixStack::pop()
{
}
