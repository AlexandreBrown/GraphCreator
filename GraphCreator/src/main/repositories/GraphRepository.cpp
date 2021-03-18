#include "GraphRepository.h"

using std::vector;
using std::string;

bool GraphRepository::createGraph() {
	return onDiskDataSource.createGraph();
}

void GraphRepository::exportGraph(
	const string& outputFormatCommand,
	const vector<Vertex>& vertices,
	size_t desiredEdgesCount
) {
	if (outputFormatCommand=="d") {
		dotFormatDataSource.exportToFormat(
			onDiskDataSource.getFile(),
			vertices,
			desiredEdgesCount
		);
	} else if (outputFormatCommand=="t") {
		tp2FormatDataSource.exportToFormat(
			onDiskDataSource.getFile(),
			vertices,
			desiredEdgesCount
		);
	}
}

std::string GraphRepository::getGraphFileName() {
	return onDiskDataSource.getFileName();
}