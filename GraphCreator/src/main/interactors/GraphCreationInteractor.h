#ifndef GRAPHCREATOR_SRC_MAIN_INTERACTORS_GRAPHCREATIONINTERACTOR_H_
#define GRAPHCREATOR_SRC_MAIN_INTERACTORS_GRAPHCREATIONINTERACTOR_H_

#include "cstdlib"
#include "../presenters/inprogress/GraphCreationInProgressPresenter.h"
#include "../presenters/error/GraphCreationErrorPresenter.h"
#include "../presenters/done/GraphCreationDonePresenter.h"
#include "../repositories/GraphRepository.h"
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

class GraphCreationInteractor {

	public:
		void createGraph(
			size_t desiredVerticesCount,
			size_t desiredEdgesCount,
			const std::string& desiredOutputFormatCommand
		);

		GraphCreationInteractor(
			GraphCreationInProgressPresenter inProgressPresenter,
			GraphCreationErrorPresenter errorPresenter,
			GraphCreationDonePresenter donePresenter,
			GraphRepository repository
		) : creationInProgressPresenter{inProgressPresenter},
		    creationErrorPresenter{errorPresenter},
		    creationDonePresenter{donePresenter},
		    graphRepository{std::move(repository)} {}

	private:

		GraphCreationInProgressPresenter creationInProgressPresenter;

		GraphCreationErrorPresenter creationErrorPresenter;

		GraphCreationDonePresenter creationDonePresenter;

		GraphRepository graphRepository;

		size_t getDestinationIndex(const std::vector<Vertex>& neighbours, size_t numberOfVerticesInGraph);

		void createVertices(size_t desiredVerticesCount, std::vector<Vertex>& vertices);

		void addEdges(size_t desiredEdgesCount, std::vector<Vertex>& vertices);
};

#endif
