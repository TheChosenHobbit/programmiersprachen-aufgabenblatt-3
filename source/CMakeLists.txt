# Build aufgabe3.1
add_executable(aufgabe1
  aufgabe1.cpp)
target_link_libraries(aufgabe1
  ${GLFW_LIBRARIES})

# Build aufgabe3.2
add_executable(aufgabe2
  aufgabe2bis4.cpp)
target_link_libraries(aufgabe2
  ${GLFW_LIBRARIES})
