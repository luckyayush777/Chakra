#include"Chakra\core.h"
#include<glad\glad.h>
#include<glfw3.h>
using namespace Chakra;
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource =
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n";
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
		a.x, a.y, a.z,
		b.x, b.y, b.z,
		c.x, c.y, c.z
	};

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}


	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	int fragSuccess;
	char fragInfoLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fragSuccess);
	if (!fragSuccess)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, fragInfoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << fragInfoLog << std::endl;
	}


	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	int programSuccess;
	char programSuccessLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &programSuccess);
	if (!programSuccess)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, programSuccessLog);
		std::cout << "ERROR::PROGRAM::COMPILATION FAILED\n" << fragInfoLog << std::endl;
	}

	glUseProgram(shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
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