set(MODULE_NAME StringCapacity)

set(SOURCES
        src/Capacity.cpp
)

add_library(${MODULE_NAME} ${SOURCES} ${HEADERS})
add_library(str::${MODULE_NAME} ALIAS ${MODULE_NAME})

target_include_directories(${MODULE_NAME} PUBLIC include)
target_link_libraries(${MODULE_NAME}
    PUBLIC
        fmt::fmt
        str::GeneralString
    PRIVATE
)

add_subdirectory(ut)
