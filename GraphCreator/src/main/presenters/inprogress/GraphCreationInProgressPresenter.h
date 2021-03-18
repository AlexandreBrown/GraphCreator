#ifndef GRAPHCREATOR_SRC_MAIN_PRESENTERS_GRAPHCREATIONINPROGRESSPRESENTER_H_
#define GRAPHCREATOR_SRC_MAIN_PRESENTERS_GRAPHCREATIONINPROGRESSPRESENTER_H_

#include <iostream>

class GraphCreationInProgressPresenter {

	public:
		void presentPreCreation(size_t desiredVerticesCount, size_t desiredEdgesCount);

		void presentVertexCreation(size_t vertex);

		void presentEdgeCreation(size_t source, size_t destination);

		void presentExportInProgress(const std::string& graphExportFormatCommand);

	private:
		std::string getFormat(const std::string& graphExportFormatCommand);
};

#endif
