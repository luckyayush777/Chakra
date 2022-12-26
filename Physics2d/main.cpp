#include"Chakra\core.h"
#include<glad\glad.h>
#include<glfw3.h>
using namespace Chakra;
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	float triangleSideLength = 0.2; // this is normalised
	Vector3 a(0.5, 0.5, 0);
	Vector3 b(0.5 + triangleSideLength, 0.5, 0);
	Vector3 c(0.5 + triangleSideLength / 2, 0.5 + triangleSideLength / 2, 0);

	float vertices[] = {

	}
	GLFWwindow* window = glfwCreateWindow(800, 600, "Physics Engine", NULL, NULL);
	if (!window)
	{
		std::cout << "FAILED TO CREATE WINDOW" << "\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "FAILED TO INITIALIZE GLAD";
		return -1;

	}
	glViewport(0, 0, 800, 600);
	while (!glfwWindowShouldClose(window))
	{
		

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		
		glfwPollEvents();
		glfwSwapBuffers(window);

	}
	glfwTerminate();
	Chakra::Vector3 test(0, 1, 1);
	test.Display();
	std::cout << "\n"<<test.magnitude();
	test.normalize();
	test.Display();
	std::cout << "\n" << test.magnitude();
}