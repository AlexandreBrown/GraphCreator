#include <Vertex.h>
#include "GraphCreationInteractor.h"
#include "../random/RandomValues.h"

using std::string;
using std::vector;
using std::find;

void GraphCreationInteractor::createGraph(
	size_t desiredVerticesCount,
	size_t desiredEdgesCount,
	const string& desiredOutputFormatCommand
) {

	creationInProgressPresenter.presentPreCreation(desiredVerticesCount, desiredEdgesCount);

	if (!graphRepository.createGraph()) {
		creationErrorPresenter.presentCreationError();
		return;
	}

	vector<Vertex> vertices{};
	createVertices(desiredVerticesCount, vertices);
	addEdges(desiredEdgesCount, vertices);

	creationInProgressPresenter.presentExportInProgress(desiredOutputFormatCommand);
	graphRepository.exportGraph(desiredOutputFormatCommand, vertices, desiredEdgesCount);

	const auto& graphFileName = graphRepository.getGraphFileName();
	creationDonePresenter.present(graphFileName);
}

void GraphCreationInteractor::addEdges(size_t desiredEdgesCount, vector<Vertex>& vertices) {
	for (size_t edge = 0; edge < desiredEdgesCount; ++edge) {

		try {
			auto sourceIndex = RandomValues::random(0, vertices.size() - 1);
			auto& source = vertices[sourceIndex];
			auto destinationIndex = getDestinationIndex(source.neighbours, vertices.size());
			const auto& destination = vertices[destinationIndex];

			creationInProgressPresenter.presentEdgeCreation(source.number, destination.number);

			source.neighbours.push_back(destination);
		} catch (std::out_of_range&) {
			// TODO improve code to remove this catch (get a random source that can still have a destination that the source is not already referencing instead of fast-fail on bad destination)
			// This catch can only occur when there is already an edge with a source that is already connected to all possible destinations in the graph.
		}
	}
}

void GraphCreationInteractor::createVertices(size_t desiredVerticesCount, vector<Vertex>& vertices) {
	for (size_t vertex = 1; vertex <= desiredVerticesCount; ++vertex) {
		creationInProgressPresenter.presentVertexCreation(vertex);
		vertices.emplace_back(vertex);
	}
}

size_t GraphCreationInteractor::getDestinationIndex(const vector<Vertex>& neighbours, size_t numberOfVerticesInGraph) {
	vector<size_t> neighboursNumbers{};
	neighboursNumbers.reserve(neighbours.size());

	for (const auto& neighbour: neighbours) {
		neighboursNumbers.push_back(neighbour.number);
	}

	vector<size_t> destinationNumbersNotAdded{};

	for (int i = 1; i <= numberOfVerticesInGraph; ++i) {
		if (find(neighboursNumbers.cbegin(), neighboursNumbers.cend(), i)==neighboursNumbers.cend()) {
			destinationNumbersNotAdded.push_back(i);
		}
	}

	return destinationNumbersNotAdded.at(RandomValues::random(0, destinationNumbersNotAdded.size() - 1)) - 1;
}