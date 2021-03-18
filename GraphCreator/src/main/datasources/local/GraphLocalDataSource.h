#ifndef GRAPHCREATOR_SRC_MAIN_DATASOURCES_GRAPHLOCALDATASOURCE_H_
#define GRAPHCREATOR_SRC_MAIN_DATASOURCES_GRAPHLOCALDATASOURCE_H_

#include <string>
#include <fstream>
#include <chrono>
#include <sstream>
#include <iomanip>

class GraphLocalDataSource {

	public:

		GraphLocalDataSource() = default;

		~GraphLocalDataSource();

		GraphLocalDataSource(const GraphLocalDataSource& rhs);

		GraphLocalDataSource& operator=(const GraphLocalDataSource& rhs);

		bool createGraph();

		std::string getFileName();

		std::ofstream& getFile();

	private:

		std::ofstream* graphFile{nullptr};

		std::string lastFileNameGenerated;

		std::string createFileName();
};

#endif
