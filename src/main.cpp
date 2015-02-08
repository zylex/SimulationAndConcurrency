// #include <iostream>
// #include <stdlib.h>

// #include <GL/glew.h>
// #include <GLFW/glfw3.h>

// static void error_callback(int error, const char* description) {
//   std::cerr << description << std::endl;
// }

// static void key_callback(GLFWwindow* window, int key, int scancode, int
// action,
//                          int mods) {
//   if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
//     glfwSetWindowShouldClose(window, GL_TRUE);
//   }
// }
#include "Game.h"

int main(int argc, char const* argv[]) {

  // glfwSetErrorCallback(error_callback);

  // if (!glfwInit()) {
  //   std::cerr << "GLFW failed to initialise." << std::endl;
  //   // fprintf(stderr, "GLFW failed to initialise.");
  // }

  // glfwWindowHint(GLFW_SAMPLES, 4);
  // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // GLFWwindow* window = glfwCreateWindow(800, 600, "Test GLFW", NULL, NULL);

  // if (!window) {
  //   std::cerr << "GLFW failed to initialise window." << std::endl;
  //   glfwTerminate();
  //   exit(EXIT_FAILURE);
  // }

  // glfwMakeContextCurrent(window);

  // if (glewInit() != GLEW_OK) {
  //   std::cerr << "GLEW failed to initialise." << std::endl;
  //   glfwTerminate();
  //   exit(EXIT_FAILURE);
  // }

  // glfwSwapInterval(1);
  // glfwSetKeyCallback(window, key_callback);

  // while (!glfwWindowShouldClose(window)) {
  //   glfwSwapBuffers(window);
  //   glfwPollEvents();
  // }

  // glfwDestroyWindow(window);
  // glfwTerminate();
  zge::Game game;
  return game.run();
}