#ifndef GRAPHCREATOR_SRC_MAIN_DATASOURCES_GRAPHEXPORTDATASOURCE_H_
#define GRAPHCREATOR_SRC_MAIN_DATASOURCES_GRAPHEXPORTDATASOURCE_H_

#include <Vertex.h>
#include <fstream>

class GraphExportDataSource {

	public:
		virtual void exportToFormat(std::ofstream& file, const std::vector<Vertex>& vertices, size_t numberOfEdges) = 0;
};
#endif
