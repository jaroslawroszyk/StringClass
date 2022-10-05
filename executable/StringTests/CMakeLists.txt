cmake_minimum_required(VERSION 3.3)
set(MODULE_NAME StringTests)

set(SOURCES 
    src/main.cpp
)

set(HEADERS 
)

add_executable(${MODULE_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${MODULE_NAME}
        PRIVATE
        str::GeneralString)
