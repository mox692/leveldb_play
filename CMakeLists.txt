cmake_minimum_required(VERSION 3.13.4)
project(leveldb_play)
add_subdirectory(third-party/leveldb)
add_executable(leveldb_play main.cc)
target_link_libraries(leveldb_play PUBLIC leveldb)
