cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Easylang")



# Set cpp standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find LLVM
set(LLVM_DIR "C:/build/lib/cmake/llvm")
find_package(LLVM REQUIRED CONFIG)

# Check if LLVM was found
if (NOT LLVM_FOUND)
    message(FATAL_ERROR "LLVM package can't be found. Please specify LLVM_DIR.")
endif()

# Include LLVM directories
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# Add source files for Easylang programming language
set(SOURCES
	"Easylang/src/Lexer.cpp"
	"Easylang/src/Parser.cpp"
	"Easylang/src/AST.cpp"
	"Easylang/src/Codegen.cpp"
	"Easylang/Easylang.cpp"
)

# Add executable
add_executable("Easylang" ${SOURCES})

# Link LLVM libraries
cmake_policy(SET CMP0079 NEW)

llvm_map_components_to_libnames(llvm_libs core orcjit native)
target_link_libraries(${PROJECT_NAME} ${llvm_libs})
