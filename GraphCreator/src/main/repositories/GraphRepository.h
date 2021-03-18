#ifndef GRAPHCREATOR_SRC_MAIN_REPOSITORIES_GRAPHREPOSITORY_H_
#define GRAPHCREATOR_SRC_MAIN_REPOSITORIES_GRAPHREPOSITORY_H_

#include <string>
#include <utility>
#include <vector>
#include "../datasources/local/GraphLocalDataSource.h"
#include "../datasources/exports/GraphExportDataSource.h"
#include "../datasources/exports/dot/GraphDotFormatDataSource.h"
#include "../datasources/exports/tp2/GraphTp2FormatDataSource.h"

class GraphRepository {

	public:
		GraphRepository(
			const GraphLocalDataSource& onDisk,
			GraphDotFormatDataSource dotFormat,
			GraphTp2FormatDataSource tp2Format
		) : onDiskDataSource{onDisk},
		    dotFormatDataSource{std::move(dotFormat)},
		    tp2FormatDataSource{std::move(tp2Format)} {}

		bool createGraph();

		std::string getGraphFileName();

		void exportGraph(
			const std::string& outputFormatCommand,
			const std::vector<Vertex>& vertices,
			size_t desiredEdgesCount
		);

	private:
		GraphLocalDataSource onDiskDataSource;

		GraphDotFormatDataSource dotFormatDataSource;

		GraphTp2FormatDataSource tp2FormatDataSource;
};

#endif
