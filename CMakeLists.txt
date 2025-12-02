cmake_minimum_required(VERSION 3.16)

project(openscad-step-reader)

# ##############################################################################
# Set the search path for .cmake files.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})


# ##############################################################################
# This project requires C++20 or newer.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# Build a static binary.
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
# Add further warning levels.
set(CMAKE_CXX_FLAGS
  "${CMAKE_CXX_FLAGS} \
    -O3"
)
# -D_XOPEN_SOURCE=700 \
# -D_FORTIFY_SOURCE=2 \
# -fstack-protector \
# -fomit-frame-pointer \
# -pipe \
# -Weffc++ \
# -Wall -Wextra -Wshadow -Wdeprecated \
# -Wdiv-by-zero -Wfloat-equal -Wfloat-conversion -Wsign-compare -Wpointer-arith \
# -Wuninitialized -Wunreachable-code \
# -Wunused -Wunused-function -Wunused-label -Wunused-parameter -Wunused-but-set-parameter -Wunused-but-set-variable \
# -Wunused-value -Wunused-variable -Wunused-result \
# -Wmissing-field-initializers -Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn"
include_directories(SYSTEM ${CMAKE_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# ##############################################################################
# opencascade lib
find_package(OCC REQUIRED)
include_directories(${OCC_INCLUDE_DIR})
set(LIBRARIES ${LIBRARIES} ${OCC_LIBRARIES})



# ##############################################################################
# Create executable.
add_executable(
  ${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/${PROJECT_NAME}.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/explore-shape.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/openscad-triangle-writer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/tessellation.cpp

)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION bin COMPONENT ${PROJECT_NAME})