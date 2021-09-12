include_directories(${event_SOURCE_DIR}/impl/inc)
add_library(dispatcher dispatcher.cpp)
add_library(events event.cpp)
add_library(eventHandler eventHandler.cpp)

add_executable(event main.cpp dispatcher.cpp event.cpp eventHandler.cpp)

target_link_libraries(event dispatcher events eventHandler)
