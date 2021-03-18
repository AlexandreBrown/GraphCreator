#ifndef GRAPHCREATOR_SRC_MAIN_DATASOURCES_EXPORTS_TP2_GRAPHTP2FORMATDATASOURCE_H_
#define GRAPHCREATOR_SRC_MAIN_DATASOURCES_EXPORTS_TP2_GRAPHTP2FORMATDATASOURCE_H_

#include "../GraphExportDataSource.h"
#include <sstream>
#include <fstream>
#include <iomanip>

class GraphTp2FormatDataSource : public GraphExportDataSource {

	public:
		void exportToFormat(std::ofstream& file, const std::vector<Vertex>& vertices, size_t numberOfEdges) override;
};

#endif