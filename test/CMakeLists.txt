project(unit_tests)

file(
	GLOB_RECURSE 
	SOURCE_LIST
	"*.cpp"
)

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

enable_testing()

add_executable(run_unit_tests ${SOURCE_LIST})
target_link_libraries(run_unit_tests GTest::gtest GTest::main)
target_link_libraries(run_unit_tests SP3D)

add_test(run_unit_tests run_unit_tests)