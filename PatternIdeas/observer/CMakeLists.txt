cmake_minimum_required (VERSION 3.8)

project (PatternIdeas)

file(GLOB observer_include CONFIGURE_DEPENDS "*.h")
file(GLOB observer_src CONFIGURE_DEPENDS "*.cpp")

add_library (observer_lib STATIC ${observer_include} ${observer_src} )

source_group("include" FILES ${observer_include})
source_group("src" FILES ${observer_source})

