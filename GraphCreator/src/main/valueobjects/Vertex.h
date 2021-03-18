#ifndef GRAPHCREATOR_SRC_MAIN_VALUEOBJECTS_VERTEX_H_
#define GRAPHCREATOR_SRC_MAIN_VALUEOBJECTS_VERTEX_H_

#include <cstdlib>
#include <vector>

struct Vertex {

	size_t number;

	std::vector<Vertex> neighbours = std::vector<Vertex>{};

	explicit Vertex(size_t vertexNumber) : number{vertexNumber} {}
};

#endif
