#include "GraphCreationController.h"
#include <string>

using std::string;
using std::stoi;

void GraphCreationController::createGraph(const char** commandLineArguments) {

	size_t desiredVerticesCount = stoi(commandLineArguments[1]);
	size_t desiredEdgesCount = stoi(commandLineArguments[2]);
	string desiredOutputFormatCommand = commandLineArguments[3];

	graphCreationInteractor.createGraph(desiredVerticesCount, desiredEdgesCount, desiredOutputFormatCommand);
}
