cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 23)
set_property(TARGET ${PROJECT_NAME} PROPERTY
             MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")


include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG main # Important: Specify a version or a commit hash here.
)
FetchContent_MakeAvailable(ftxui)
project(SoundBoard LANGUAGES CXX VERSION 0.0.1)

set(PROJECT_NAME SoundBoard)
set(PROJECT_SOURCE 
  src/Logger.cpp
  src/Player.cpp
  src/SoundBoard.cpp
  src/main.cpp
  src/Platform.windows.cpp
  src/UI.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE})



target_link_libraries(${PROJECT_NAME} 
  winmm.lib
  ftxui::screen
  ftxui::dom
  ftxui::component
)

target_include_directories(${PROJECT_NAME} PRIVATE 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
  $<INSTALL_INTERFACE:include/>  
)

install(TARGETS ${PROJECT_NAME})
