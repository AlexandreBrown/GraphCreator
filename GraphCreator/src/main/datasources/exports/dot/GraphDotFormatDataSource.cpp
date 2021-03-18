#include <Vertex.h>
#include "GraphDotFormatDataSource.h"
#include "../random/RandomValues.h"

using std::endl;
using std::to_string;
using std::ofstream;
using std::string;
using std::vector;

void GraphDotFormatDataSource::exportToFormat(
	ofstream& file,
	const vector<Vertex>& vertices,
	size_t numberOfEdges
) {
	file << "digraph GraphDataSet {" << endl;

	for (const auto& vertex : vertices) {
		const auto& neighbours = vertex.neighbours;

		if (neighbours.empty()) {
			file << "\t" << outputVertexDotFormat(vertex) << ";" << endl;
		} else {
			for (const auto& neighbour : neighbours) {
				file << "\t" << outputEdgeDotFormat(vertex, neighbour) << ";" << endl;
			}
		}
	}

	file << "}";
}

std::string GraphDotFormatDataSource::outputEdgeConnectorDotFormat() {
	return " -> ";
}

std::string GraphDotFormatDataSource::outputVertexDotFormat(const Vertex& vertex) {
	return "Vertex" + to_string(vertex.number);
}

std::string GraphDotFormatDataSource::outputEdgeDotFormat(const Vertex& source, const Vertex& destination) {
	return outputVertexDotFormat(source) +
		outputEdgeConnectorDotFormat() +
		outputVertexDotFormat(destination) +
		createRandomWeightDotFormat();
}

std::string GraphDotFormatDataSource::createRandomWeightDotFormat() {
	auto randomWeight = static_cast<float>(RandomValues::random(0, 200.0));
	std::ostringstream weight1;
	weight1 << std::fixed << std::setprecision(2) << randomWeight;

	return "[label=\"" + weight1.str() + "\", weight=\"" + weight1.str() + "\"]";
}