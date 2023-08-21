add_executable(lexerTest lexerTest.cpp)

target_link_libraries(lexerTest PUBLIC parser)

add_test(
	NAME lexerTest
	COMMAND lexerTest
)