target_sources(
    canopennode
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/CO_driver.c
        ${CMAKE_CURRENT_LIST_DIR}/eeprom.c
)

target_include_directories(
    canopennode
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
