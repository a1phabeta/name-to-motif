# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.15)
project(nametomotif VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(nametomotif nametomotif.cc)
target_compile_features(nametomotif INTERFACE cxx_std_20)
set_target_properties(nametomotif PROPERTIES CXX_EXTENSIONS OFF)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(nametomotif INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)
install(TARGETS nametomotif DESTINATION bin)