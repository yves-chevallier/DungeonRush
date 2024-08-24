cmake_minimum_required(VERSION 3.5.1)
project(DungeonRush VERSION 0.1.0
                    DESCRIPTION "A game inspired by snake"
                    LANGUAGES C)

# Set output path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find SDL2 and additional SDL2 libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_net REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(BIN_NAME dungeon_rush)

file(GLOB SRC src/*.c)

add_executable(${BIN_NAME} ${SRC})

target_include_directories(${BIN_NAME} PUBLIC src)
target_include_directories(${BIN_NAME} PUBLIC ${SDL2_INCLUDE_DIR})

# Manually link SDL2 and its additional libraries
target_link_libraries(${BIN_NAME}
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_NET_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    m)

# If variables like ${SDL2_IMAGE_LIBRARIES} do not exist, replace with SDL2_image, SDL2_mixer, SDL2_net, SDL2_ttf as follows:
target_link_libraries(${BIN_NAME}
    SDL2
    SDL2_image
    SDL2_net
    SDL2_mixer
    SDL2_ttf
    m)

file(COPY res DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
