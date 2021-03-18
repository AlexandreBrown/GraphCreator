#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <iosfwd>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::to_string;
using std::string;
using std::stoi;
using std::max;
using std::ofstream;
using std::vector;

struct Vertex {

	size_t number;

	vector<Vertex> neighbours = vector<Vertex>{};

	explicit Vertex(size_t number) : number{number} {}
};

ofstream open(const string& fileName);

string createFileName();

size_t random(size_t fromInclusive, size_t toInclusive);

Vertex createVertex(size_t number);

string outputVertexDotFormat(const Vertex& vertex);

string outputEdgeDotFormat(const Vertex& source, const Vertex& destination);

string outputEdgeConnectorDotFormat();

string createRandomWeightDotFormat();

string getFormat(const string& desiredOutputFormatCommand);

void outputToDot(ofstream& output, const vector<Vertex>& vertices);

void outputToTp2(ofstream& output, const vector<Vertex>& vertices, size_t numberOfEdges);

size_t getDestinationIndex(const vector<Vertex>& neighbours, size_t numberOfVerticesInGraph);

int main(int argc, const char* argv[]) {

	size_t desiredVerticesCount = stoi(argv[1]);
	size_t desiredEdgesCount = stoi(argv[2]);
	string desiredOutputFormatCommand = argv[3];

	cout << "Generating graph with " << to_string(desiredVerticesCount) << " vertices and " << desiredEdgesCount
	     << " edges..." << endl;

	auto fileName = createFileName();
	auto output = open(fileName);
	if (!output.is_open()) {
		cout << "Could not generate graph!" << endl;
	}

	vector<Vertex> vertices{};

	for (size_t vertex = 1; vertex <= desiredVerticesCount; ++vertex) {
		cout << "Creating vertex " << to_string(vertex) << "..." << endl;
		vertices.push_back(createVertex(vertex));
	}

	for (size_t edge = 0; edge < desiredEdgesCount; ++edge) {

		try {
			auto sourceIndex = random(0, vertices.size() - 1);
			auto& source = vertices[sourceIndex];
			auto destinationIndex = getDestinationIndex(source.neighbours, vertices.size());
			const auto& destination = vertices[destinationIndex];

			cout << "Adding edge (" << to_string(source.number) << "," << to_string(destination.number) << ")..."
			     << endl;

			source.neighbours.push_back(destination);
		} catch (std::out_of_range&) {}

	}

	cout << endl << "Exporting graph to " << getFormat(desiredOutputFormatCommand) << " format..." << endl;

	if (desiredOutputFormatCommand=="d") {
		outputToDot(output, vertices);
	} else if (desiredOutputFormatCommand=="t") {
		outputToTp2(output, vertices, desiredEdgesCount);
	}

	output.close();

	cout << endl;
	cout << "===============================================================" << endl;
	cout << "      Graph created [" << fileName << "]" << endl;
	cout << "===============================================================" << endl;

	return 0;
}

size_t getDestinationIndex(const vector<Vertex>& neighbours, size_t numberOfVerticesInGraph) {

	vector<size_t> neighboursNumbers{};
	neighboursNumbers.reserve(neighbours.size());

	for (const auto& neighbour: neighbours) {
		neighboursNumbers.push_back(neighbour.number);
	}

	vector<size_t> destinationNumbersNotAdded{};

	for (int i = 1; i <= numberOfVerticesInGraph; ++i) {
		if (find(neighboursNumbers.cbegin(), neighboursNumbers.cend(), i)==neighboursNumbers.cend()) {
			destinationNumbersNotAdded.push_back(i);
		}
	}

	return destinationNumbersNotAdded.at(random(0, destinationNumbersNotAdded.size() - 1)) - 1;
}

void outputToDot(ofstream& output, const vector<Vertex>& vertices) {

	output << "digraph GraphDataSet {" << endl;

	for (const auto& vertex : vertices) {
		const auto& neighbours = vertex.neighbours;

		if (neighbours.empty()) {
			output << "\t" << outputVertexDotFormat(vertex) << ";" << endl;
		} else {
			for (const auto& neighbour : neighbours) {
				output << "\t" << outputEdgeDotFormat(vertex, neighbour) << ";" << endl;
			}
		}
	}

	output << "}";
}

void outputToTp2(ofstream& output, const vector<Vertex>& vertices, size_t numberOfEdges) {

	output << "Reseau Interurbain: GraphDataSet" << endl;
	output << to_string(vertices.size()) << " villes" << endl;
	output << "Liste des villes:" << endl;
	for (const auto& vertex: vertices) {
		output << "Vertex" << to_string(vertex.number) << endl;
	}
	output << "Liste des trajets:";
	if (numberOfEdges > 0) {
		output << endl;
	}
	for (int vertexIndex = 0; vertexIndex < vertices.size(); ++vertexIndex) {

		const auto& vertex = vertices[vertexIndex];

		for (int neighbourIndex = 0; neighbourIndex < vertex.neighbours.size(); ++neighbourIndex) {

			const auto& neighbour = vertex.neighbours[neighbourIndex];
			output << "Vertex" << to_string(vertex.number) << endl;
			output << "Vertex" << to_string(neighbour.number) << endl;

			std::ostringstream weight1;
			weight1 << std::fixed << std::setprecision(2) << static_cast<float>(random(1, 200));
			std::ostringstream weight2;
			weight2 << std::fixed << std::setprecision(2) << static_cast<float>(random(1, 200));
			output << weight1.str() << " "
			       << weight2.str();

			if (!(vertexIndex==(vertices.size() - 1) && neighbourIndex==(vertex.neighbours.size() - 1))) {
				output << endl;
			}
		}
	}
}

string getFormat(const string& desiredOutputFormatCommand) {
	if (desiredOutputFormatCommand=="d") {
		return "Dot";
	} else if (desiredOutputFormatCommand=="t") {
		return "TP2";
	}
	return "unknown";
}

Vertex createVertex(size_t number) {
	return Vertex(number);
}

string outputVertexDotFormat(const Vertex& vertex) {
	return "Vertex" + to_string(vertex.number);
}

string outputEdgeDotFormat(const Vertex& source, const Vertex& destination) {
	return outputVertexDotFormat(source) + outputEdgeConnectorDotFormat() + outputVertexDotFormat(destination)
		+ createRandomWeightDotFormat();
}

string outputEdgeConnectorDotFormat() {
	return " -> ";
}

size_t random(size_t fromInclusive, size_t toInclusive) {
	return static_cast<size_t>(rand()%(toInclusive - fromInclusive + 1) + fromInclusive);
}

string createRandomWeightDotFormat() {

	auto randomWeight = static_cast<float>(random(0, 200.0));
	std::ostringstream weight1;
	weight1 << std::fixed << std::setprecision(2) << randomWeight;

	return "[label=\"" + weight1.str() + "\", weight=\"" + weight1.str() + "\"]";
}

ofstream open(const string& fileName) {

	ofstream output{fileName};

	return output;
}

string createFileName() {

	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream time;
	time << std::put_time(localtime(&in_time_t), "%F_%X");

	return "graph_" + time.str() + ".txt";
}
