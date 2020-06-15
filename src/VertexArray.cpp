#include "VertexArray.h"
#include "Drawer.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &id);
}
VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &id);
}

void VertexArray::AddLayout(VertexBuffer& VBO, unsigned int index, unsigned int count, unsigned int stride, unsigned int offset)
{
	GLCall(Bind());
	GLCall(VBO.Bind());
	GLCall(glEnableVertexAttribArray(index));
	GLCall(glVertexAttribPointer(index, count, GL_FLOAT, false, stride*sizeof(float), (const void*) (offset*sizeof(float))));
	GLCall(Unbind());
}

void VertexArray::Bind()
{	
	glBindVertexArray(id);
}
void VertexArray::Unbind()
{
	glBindVertexArray(0);
}