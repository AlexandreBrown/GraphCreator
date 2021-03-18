#include "controllers/GraphCreationController.h"

int main(int argc, const char* argv[]) {

	GraphCreationController controller{
		GraphCreationInteractor{
			GraphCreationInProgressPresenter{},
			GraphCreationErrorPresenter{},
			GraphCreationDonePresenter{},
			GraphRepository{
				GraphLocalDataSource{},
				GraphDotFormatDataSource{},
				GraphTp2FormatDataSource{}
			}
		}};

	controller.createGraph(argv);

	return 0;
}