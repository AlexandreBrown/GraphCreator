#include "GraphCreationInProgressPresenter.h"

using std::cout;
using std::endl;
using std::string;

void GraphCreationInProgressPresenter::presentPreCreation(size_t desiredVerticesCount, size_t desiredEdgesCount) {
	cout << "Generating graph with " << desiredVerticesCount << " vertices and " << desiredEdgesCount
	     << " edges..." << endl;
}

void GraphCreationInProgressPresenter::presentVertexCreation(size_t vertex) {
	cout << "Creating vertex " << vertex << "..." << endl;
}

void GraphCreationInProgressPresenter::presentEdgeCreation(size_t source, size_t destination) {
	cout << "Adding edge (" << source << "," << destination << ")..."
	     << endl;
}

void GraphCreationInProgressPresenter::presentExportInProgress(const string& graphExportFormatCommand) {
	cout << endl << "Exporting graph to " << getFormat(graphExportFormatCommand) << " format..." << endl;
}

std::string GraphCreationInProgressPresenter::getFormat(const string& graphExportFormatCommand) {
	if (graphExportFormatCommand=="d") {
		return "Dot";
	} else if (graphExportFormatCommand=="t") {
		return "TP2";
	}
	return "unknown";
}
