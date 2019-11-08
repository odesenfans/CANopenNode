cmake_minimum_required(VERSION 3.5)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wshadow")

project(CANopenNode C)

set(STACK_DIR ${CMAKE_CURRENT_LIST_DIR}/stack)
add_library(
    canopennode
    STATIC
        ${CMAKE_CURRENT_LIST_DIR}/CANopen.c
        ${STACK_DIR}/CO_Emergency.c
        ${STACK_DIR}/CO_HBconsumer.c
        ${STACK_DIR}/CO_LSSmaster.c
        ${STACK_DIR}/CO_LSSslave.c
        ${STACK_DIR}/CO_NMT_Heartbeat.c
        ${STACK_DIR}/CO_PDO.c
        ${STACK_DIR}/CO_SDO.c
        ${STACK_DIR}/CO_SDOmaster.c
        ${STACK_DIR}/CO_SYNC.c
        ${STACK_DIR}/CO_trace.c
        ${STACK_DIR}/crc16-ccitt.c
)

set(TARGET_DRIVERS drvTemplate)
set(DRIVERS_DIR ${STACK_DIR}/${TARGET_DRIVERS})
message(STATUS "Using drivers: ${TARGET_DRIVERS}")
include(${DRIVERS_DIR}/CMakeLists.txt)

target_include_directories(
    canopennode
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${STACK_DIR}
        # TODO remove this hack
        ${EXAMPLE_DIR}
)

set(EXAMPLE_DIR ${CMAKE_CURRENT_LIST_DIR}/example)
set(EXAMPLE_STACK drvTemplate)
add_subdirectory(${STACK_DIR}/${EXAMPLE_STACK})
add_executable(
    canopennode_example
        ${EXAMPLE_DIR}/CO_OD.c
        ${EXAMPLE_DIR}/main.c
)
target_include_directories(
    canopennode_example
    PRIVATE
        ${EXAMPLE_DIR}
)
target_link_libraries(
    canopennode_example
    PRIVATE
        canopennode
)
# TODO remove this hack
target_include_directories(
    canopennode
    PUBLIC
        ${EXAMPLE_DIR}
)
