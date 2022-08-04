cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(arduinojson-playground)

find_package(ArduinoJson 6.19.4 REQUIRED PATHS "${ARDUINOJSON_ROOT}")
if (ArduinoJson_FOUND)
    message("arduinojson found")
else (ArduinoJson_FOUND)
    message("arduinojson not found")
endif()

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_executable(${PROJECT_NAME} 
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME} ArduinoJson)