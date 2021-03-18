cmake_minimum_required(VERSION 3.5)
project(GraphCreator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main/main.cpp
        src/main/valueobjects/Vertex.h
        src/main/controllers/GraphCreationController.cpp
        src/main/controllers/GraphCreationController.h
        src/main/presenters/inprogress/GraphCreationInProgressPresenter.cpp
        src/main/presenters/inprogress/GraphCreationInProgressPresenter.h
        src/main/presenters/done/GraphCreationDonePresenter.cpp
        src/main/presenters/done/GraphCreationDonePresenter.h
        src/main/repositories/GraphRepository.cpp
        src/main/repositories/GraphRepository.h
        src/main/datasources/local/GraphLocalDataSource.h
        src/main/datasources/local/GraphLocalDataSource.cpp
        src/main/presenters/error/GraphCreationErrorPresenter.cpp
        src/main/presenters/error/GraphCreationErrorPresenter.h
        src/main/datasources/exports/GraphExportDataSource.h
        src/main/datasources/exports/dot/GraphDotFormatDataSource.cpp
        src/main/interactors/GraphCreationInteractor.cpp
        src/main/interactors/GraphCreationInteractor.h
        src/main/datasources/exports/tp2/GraphTp2FormatDataSource.cpp
        src/main/datasources/exports/dot/GraphDotFormatDataSource.h
        src/main/datasources/exports/tp2/GraphTp2FormatDataSource.h
        src/main/random/RandomValues.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE src/main/valueobjects)
