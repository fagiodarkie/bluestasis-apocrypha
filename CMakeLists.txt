cmake_minimum_required(VERSION 3.15)
project(bluestasis_apocrypha)

set(CMAKE_CXX_STANDARD 17)

add_executable(bluestasis_apocrypha main.cpp GameState/IGameState.h GameState/IGameState.cpp Engine/Screen/ScreenLoader.cpp Engine/Screen/ScreenLoader.h Engine/Screen/Screen.cpp Engine/Screen/Screen.h Engine/Option/Option.cpp Engine/Option/Option.h Engine/Screen/ScreenUtils.h Engine/Chapter/Chapter.cpp Engine/Chapter/Chapter.h)