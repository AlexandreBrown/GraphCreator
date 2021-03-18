#include "GraphTp2FormatDataSource.h"
#include "../random/RandomValues.h"

using std::ofstream;
using std::to_string;
using std::endl;
using std::vector;

void GraphTp2FormatDataSource::exportToFormat(
	ofstream& file,
	const vector<Vertex>& vertices,
	size_t numberOfEdges
) {

	file << "Reseau Interurbain: GraphDataSet" << endl;
	file << to_string(vertices.size()) << " villes" << endl;
	file << "Liste des villes:" << endl;
	for (const auto& vertex: vertices) {
		file << "Vertex" << to_string(vertex.number) << endl;
	}
	file << "Liste des trajets:";
	if (numberOfEdges > 0) {
		file << endl;
	}
	for (int vertexIndex = 0; vertexIndex < vertices.size(); ++vertexIndex) {

		const auto& vertex = vertices[vertexIndex];

		for (int neighbourIndex = 0; neighbourIndex < vertex.neighbours.size(); ++neighbourIndex) {

			const auto& neighbour = vertex.neighbours[neighbourIndex];
			file << "Vertex" << to_string(vertex.number) << endl;
			file << "Vertex" << to_string(neighbour.number) << endl;

			std::ostringstream weight1;
			weight1 << std::fixed << std::setprecision(2) << static_cast<float>(RandomValues::random(1, 200));
			std::ostringstream weight2;
			weight2 << std::fixed << std::setprecision(2) << static_cast<float>(RandomValues::random(1, 200));
			file << weight1.str() << " "
			     << weight2.str();

			if (!(vertexIndex==(vertices.size() - 1) && neighbourIndex==(vertex.neighbours.size() - 1))) {
				file << endl;
			}
		}
	}
}