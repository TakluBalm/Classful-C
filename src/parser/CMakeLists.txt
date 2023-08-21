include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES
	lexer.c
)

add_library(parser STATIC ${SOURCES})
target_include_directories(parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)