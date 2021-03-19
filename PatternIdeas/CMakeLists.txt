# CMakeList.txt : CMake project for PatternIdeas, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project ("PatternIdeas")
add_subdirectory(observer)


file(GLOB observer_src CONFIGURE_DEPENDS "*.h" "*.cpp")

# Add source to this project's executable.
add_executable (PatternIdeas ${observer_src} )

target_link_libraries(PatternIdeas observer_lib)
# TODO: Add tests and install targets if needed.

