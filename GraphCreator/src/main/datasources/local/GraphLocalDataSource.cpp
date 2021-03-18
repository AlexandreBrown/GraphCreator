#include "GraphLocalDataSource.h"

using std::string;
using std::ofstream;

GraphLocalDataSource::~GraphLocalDataSource() {
	if(graphFile !=nullptr){
		graphFile->close();
	}
	delete graphFile;
}

GraphLocalDataSource::GraphLocalDataSource(const GraphLocalDataSource& rhs) {
	graphFile = new ofstream{rhs.lastFileNameGenerated};
}

GraphLocalDataSource& GraphLocalDataSource::operator=(const GraphLocalDataSource& rhs) {

	if (&rhs==this) {
		return *this;
	}

	delete graphFile;

	graphFile = new ofstream{rhs.lastFileNameGenerated};

	return *this;
}

bool GraphLocalDataSource::createGraph() {

	lastFileNameGenerated = createFileName();
	delete graphFile;
	graphFile = new ofstream{lastFileNameGenerated};

	return graphFile->is_open();
}

std::string GraphLocalDataSource::createFileName() {
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream time;
	time << std::put_time(localtime(&in_time_t), "%F_%X");

	return "graph_" + time.str() + ".txt";
}

std::string GraphLocalDataSource::getFileName() {
	return lastFileNameGenerated;
}

std::ofstream& GraphLocalDataSource::getFile() {
	return *graphFile;
}
