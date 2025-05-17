cmake_minimum_required(VERSION 3.30)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_library(filmes filmes.c)
add_library(cinemas cinemas.c)

add_executable(app1 app1.c)
add_executable(app2 app2.c)

target_link_libraries(app1 PRIVATE filmes)
target_link_libraries(app2 PRIVATE cinemas)

#add_executable(app3 app3.c)
