#ifndef GRAPHCREATOR_SRC_MAIN_DATASOURCES_EXPORTS_DOT_GRAPHDOTFORMATDATASOURCE_H_
#define GRAPHCREATOR_SRC_MAIN_DATASOURCES_EXPORTS_DOT_GRAPHDOTFORMATDATASOURCE_H_

#include "../GraphExportDataSource.h"
#include <iomanip>
#include <sstream>
#include <fstream>

class GraphDotFormatDataSource : public GraphExportDataSource {

	public:
		void exportToFormat(std::ofstream& file, const std::vector<Vertex>& vertices, size_t numberOfEdges) override;

	private:
		std::string outputEdgeConnectorDotFormat();

		std::string outputVertexDotFormat(const Vertex& vertex);

		std::string outputEdgeDotFormat(const Vertex& source, const Vertex& destination);

		std::string createRandomWeightDotFormat();
};

#endif
