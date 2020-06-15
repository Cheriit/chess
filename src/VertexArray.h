#pragma once
#include <GL/glew.h>
#include "VertexBuffer.h"

class VertexArray
{
private:
	GLuint id;
public:
	VertexArray();
	~VertexArray();

	void AddLayout(VertexBuffer&VBO, unsigned int index, unsigned int count, unsigned int stride, unsigned int offset);

	void Bind();
	void Unbind();
};
