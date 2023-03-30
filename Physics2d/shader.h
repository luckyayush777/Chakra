#pragma once
#include"Chakra\core.h"
#include<string>
#include<fstream>
class Shader {
private :
	unsigned int vertexShader;
	unsigned int fragmentShader;
	unsigned int shaderProgram;

public:
	Shader( const std::string& vertexPath, const std::string& fragmentPath) {
		std::string testString;
		std::ifstream nameFileout;
		nameFileout.open(vertexPath);
		std::string line;
		std::string vertShaderString;
		while (std::getline(nameFileout, line))
		{
			vertShaderString += line;
			vertShaderString += "\n";
		}
		nameFileout.close();
		nameFileout.open(fragmentPath);
		std::string fragLine;
		std::string fragShaderString;
		while (std::getline(nameFileout, fragLine))
		{
			fragShaderString += fragLine;
			fragShaderString += "\n";
		}
		nameFileout.close();
		CompileVertShader(vertShaderString);
		CompileFragShader(fragShaderString);
		CreateProgram();
	}


	Shader() {};
	void CompileVertShader(const std::string& shaderSource)
	{
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		const char* shaderSourceCharString = shaderSource.data();
		glShaderSource(vertexShader, 1, &shaderSourceCharString, NULL);
		glCompileShader(vertexShader);
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		/*
		else {
			std::cout << "compiled succesfully";
		}
		*/

	}

	void CompileFragShader(const std::string& fragShaderSource)
	{
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		const char* fragShaderSourceCharString = fragShaderSource.data();
		glShaderSource(fragmentShader, 1, &fragShaderSourceCharString, NULL);
		glCompileShader(fragmentShader);
		int success;
		char infoLog[512];
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		/*
		else {
			std::cout << "compiled succesfully";
		}
		*/
		
	}

	void CreateProgram()
	{
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
			std::cout << "ERROR::PROGRAM::COMPILATION FAILED\n" << programSuccessLog << std::endl;
		}
	}

	void UseProgram()
	{
		glUseProgram(shaderProgram);
	}

	void DeleteProgram()
	{
		glDeleteProgram(shaderProgram);
	}
};
