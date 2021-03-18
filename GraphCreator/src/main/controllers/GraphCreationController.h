#ifndef GRAPHCREATOR_SRC_MAIN_CONTROLLERS_GRAPHCREATIONCONTROLLER_H_
#define GRAPHCREATOR_SRC_MAIN_CONTROLLERS_GRAPHCREATIONCONTROLLER_H_

#include <utility>

#include "../interactors/GraphCreationInteractor.h"

class GraphCreationController {
	public:

		explicit GraphCreationController(GraphCreationInteractor interactor) :
			graphCreationInteractor{std::move(interactor)} {}

		void createGraph(const char* commandLineArguments[]);

	private:
		GraphCreationInteractor graphCreationInteractor;
};

#endif
