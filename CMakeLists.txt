cmake_minimum_required(VERSION 3.2)
project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 14)

# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake_modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling
ADD_EXECUTABLE(SpaceInvaders src/main.cpp src/game/Game.cpp src/game/Game.h src/game/view/Observer.cpp src/game/view/Observer.h
        src/entity/Entity.cpp src/entity/Entity.h src/game/model/Subject.cpp src/game/model/Subject.h src/game/view/GameView.cpp src/game/view/GameView.h
        src/game/Stopwatch.cpp src/game/Stopwatch.h src/game/model/GameModel.cpp src/game/model/GameModel.h src/entity/Position.cpp src/entity/Position.h src/entity/Player.cpp src/entity/Player.h src/entity/Invader.cpp src/entity/Invader.h src/entity/Creature.cpp src/entity/Creature.h src/game/controller/GameController.cpp src/game/controller/GameController.h src/game/Transformation.cpp src/game/Transformation.h)

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(SpaceInvaders ${SFML_LIBRARIES})

INSTALL(TARGETS SpaceInvaders DESTINATION ${PROJECT_SOURCE_DIR}/bin)