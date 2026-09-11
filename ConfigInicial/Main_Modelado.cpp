/* Práctica 4			Marquez Abundis Mariana
11 de septiembre			320035014
*/

#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



// Shaders
#include "Shader.h"

void Inputs(GLFWwindow *window);


const GLint WIDTH = 800, HEIGHT = 600;
float movX=0.0f;
float movY=0.0f;
float movZ=-5.0f;
float rot = 0.0f;
int main() {
	glfwInit();
	//Verificación de compatibilidad 
	// Set all the required options for GLFW
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Modelado geometrico. Mariana Marquez Abundis", nullptr, nullptr);

	int screenWidth, screenHeight;

	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	//Verificación de errores de creacion  ventana
	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificación de errores de inicialización de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}


	// Define las dimensiones del viewport
	glViewport(0, 0, screenWidth, screenHeight);


	// Setup OpenGL options
	glEnable(GL_DEPTH_TEST);

	// enable alpha support
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	// Build and compile our shader program
	Shader ourShader("Shader/core.vs", "Shader/core.frag");


	// Set up vertex data (and buffer(s)) and attribute pointers

	

	// use with Perspective Projection
	float vertices[] = {
		-0.5f, -0.5f, 0.5f,	0.97f, 0.74f, 0.76f,//Front
		0.5f, -0.5f, 0.5f,	0.97f, 0.74f, 0.76f,
		0.5f,  0.5f, 0.5f,	0.97f, 0.74f, 0.76f,
		0.5f,  0.5f, 0.5f,	0.97f, 0.74f, 0.76f,
		-0.5f,  0.5f, 0.5f, 0.97f, 0.74f, 0.76f,
		-0.5f, -0.5f, 0.5f,	0.97f, 0.74f, 0.76f,
		
		-0.5f, -0.5f, -0.5f,  0.97f, 0.74f, 0.76f, // Back
		 0.5f, -0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f,  0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f,  0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f,  0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f, -0.5f, -0.5f,  0.97f, 0.74f, 0.76f,

		 0.5f, -0.5f,  0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f, -0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f,  0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f,  0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f,  0.5f,  0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f, -0.5f,  0.5f,  0.97f, 0.74f, 0.76f,

		-0.5f,  0.5f,  0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f,  0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f, -0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f, -0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f, -0.5f,  0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f,  0.5f,  0.5f,  0.97f, 0.74f, 0.76f,

		-0.5f, -0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f, -0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f, -0.5f,  0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f, -0.5f,  0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f, -0.5f,  0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f, -0.5f, -0.5f,  0.97f, 0.74f, 0.76f,

		-0.5f,  0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f,  0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f,  0.5f,  0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f,  0.5f,  0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f,  0.5f,  0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f,  0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
	};

	//vertices blancos 
	float verticesBlanco[] = {
		-0.5f, -0.5f, 0.5f,	1.0f, 1.0f, 1.0f,//Front
		0.5f, -0.5f, 0.5f,	1.0f, 1.0f, 1.0f,
		0.5f,  0.5f, 0.5f,	1.0f, 1.0f, 1.0f,
		0.5f,  0.5f, 0.5f,	1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.5f,	1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, 0.5f,	1.0f, 1.0f, 1.0f,

		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, // Back
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,

		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,

		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,

		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f,

		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f,
	};

	//vertices negros 
	float verticesNegro[] = {
		-0.5f, -0.5f, 0.5f,	0.0f, 0.0f, 0.0f,//Front
		0.5f, -0.5f, 0.5f,	0.0f, 0.0f, 0.0f,
		0.5f,  0.5f, 0.5f,	0.0f, 0.0f, 0.0f,
		0.5f,  0.5f, 0.5f,	0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, 0.5f,	0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, 0.5f,0.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // Back
		 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,

		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,

		-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
	};


	//vertices cafe 
	float verticesCafe[] = {
	-0.5f, -0.5f,  0.5f,  0.75f, 0.5f, 0.58f, // Front
		 0.5f, -0.5f,  0.5f,  0.75f, 0.5f, 0.58f,
		 0.5f,  0.5f,  0.5f,  0.75f, 0.5f, 0.58f,
		 0.5f,  0.5f,  0.5f,  0.75f, 0.5f, 0.58f,
		-0.5f,  0.5f,  0.5f,  0.75f, 0.5f, 0.58f,
		-0.5f, -0.5f,  0.5f,  0.75f, 0.5f, 0.58f,

		-0.5f, -0.5f, -0.5f,  0.75f, 0.5f, 0.58f, // Back
		 0.5f, -0.5f, -0.5f,  0.75f, 0.5f, 0.58f,
		 0.5f,  0.5f, -0.5f,  0.75f, 0.5f, 0.58f,
		 0.5f,  0.5f, -0.5f,  0.75f, 0.5f, 0.58f,
		-0.5f,  0.5f, -0.5f,  0.75f, 0.5f, 0.58f,
		-0.5f, -0.5f, -0.5f,  0.75f, 0.5f, 0.58f,

		 0.5f, -0.5f,  0.5f,  0.75f, 0.5f, 0.58f,
		 0.5f, -0.5f, -0.5f,  0.75f, 0.5f, 0.58f,
		 0.5f,  0.5f, -0.5f,  0.75f, 0.5f, 0.58f,
		 0.5f,  0.5f, -0.5f,  0.75f, 0.5f, 0.58f,
		 0.5f,  0.5f,  0.5f,  0.75f, 0.5f, 0.58f,
		 0.5f, -0.5f,  0.5f,  0.75f, 0.5f, 0.58f,

		-0.5f,  0.5f,  0.5f,  0.75f, 0.5f, 0.58f,
		-0.5f,  0.5f, -0.5f,  0.75f, 0.5f, 0.58f,
		-0.5f, -0.5f, -0.5f,  0.75f, 0.5f, 0.58f,
		-0.5f, -0.5f, -0.5f,  0.75f, 0.5f, 0.58f,
		-0.5f, -0.5f,  0.5f,  0.75f, 0.5f, 0.58f,
		-0.5f,  0.5f,  0.5f,  0.75f, 0.5f, 0.58f,

		-0.5f, -0.5f, -0.5f,  0.75f, 0.5f, 0.58f,
		 0.5f, -0.5f, -0.5f,  0.75f, 0.5f, 0.58f,
		 0.5f, -0.5f,  0.5f,  0.75f, 0.5f, 0.58f,
		 0.5f, -0.5f,  0.5f,  0.75f, 0.5f, 0.58f,
		-0.5f, -0.5f,  0.5f,  0.75f, 0.5f, 0.58f,
		-0.5f, -0.5f, -0.5f,  0.75f, 0.5f, 0.58f,

		-0.5f,  0.5f, -0.5f,  0.75f, 0.5f, 0.58f,
		 0.5f,  0.5f, -0.5f,  0.75f, 0.5f, 0.58f,
		 0.5f,  0.5f,  0.5f,  0.75f, 0.5f, 0.58f,
		 0.5f,  0.5f,  0.5f,  0.75f, 0.5f, 0.58f,
		-0.5f,  0.5f,  0.5f,  0.75f, 0.5f, 0.58f,
		-0.5f,  0.5f, -0.5f,  0.75f, 0.5f, 0.58f,
	};

	//vertices detalles 
	float verticesDetalles[] = {
-0.5f, -0.5f,  0.5f,  0.84f, 0.64f, 0.68f, // Front
	 0.5f, -0.5f,  0.5f,  0.84f, 0.64f, 0.68f,
	 0.5f,  0.5f,  0.5f,  0.84f, 0.64f, 0.68f,
	 0.5f,  0.5f,  0.5f,  0.84f, 0.64f, 0.68f,
	-0.5f,  0.5f,  0.5f,  0.84f, 0.64f, 0.68f,
	-0.5f, -0.5f,  0.5f,  0.84f, 0.64f, 0.68f,

	-0.5f, -0.5f, -0.5f,  0.84f, 0.64f, 0.68f, // Back
	 0.5f, -0.5f, -0.5f,  0.84f, 0.64f, 0.68f,
	 0.5f,  0.5f, -0.5f,  0.84f, 0.64f, 0.68f,
	 0.5f,  0.5f, -0.5f,  0.84f, 0.64f, 0.68f,
	-0.5f,  0.5f, -0.5f,  0.84f, 0.64f, 0.68f,
	-0.5f, -0.5f, -0.5f,  0.84f, 0.64f, 0.68f,

		 0.5f, -0.5f,  0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f, -0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f,  0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f,  0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f,  0.5f,  0.5f,  0.97f, 0.74f, 0.76f,
		 0.5f, -0.5f,  0.5f,  0.97f, 0.74f, 0.76f,

		-0.5f,  0.5f,  0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f,  0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f, -0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f, -0.5f, -0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f, -0.5f,  0.5f,  0.97f, 0.74f, 0.76f,
		-0.5f,  0.5f,  0.5f,  0.97f, 0.74f, 0.76f,

	-0.5f, -0.5f, -0.5f,  0.84f, 0.64f, 0.68f,
	 0.5f, -0.5f, -0.5f,  0.84f, 0.64f, 0.68f,
	 0.5f, -0.5f,  0.5f,  0.84f, 0.64f, 0.68f,
	 0.5f, -0.5f,  0.5f,  0.84f, 0.64f, 0.68f,
	-0.5f, -0.5f,  0.5f,  0.84f, 0.64f, 0.68f,
	-0.5f, -0.5f, -0.5f,  0.84f, 0.64f, 0.68f,

	-0.5f,  0.5f, -0.5f,  0.84f, 0.64f, 0.68f,
	 0.5f,  0.5f, -0.5f,  0.84f, 0.64f, 0.68f,
	 0.5f,  0.5f,  0.5f,  0.84f, 0.64f, 0.68f,
	 0.5f,  0.5f,  0.5f,  0.84f, 0.64f, 0.68f,
	-0.5f,  0.5f,  0.5f,  0.84f, 0.64f, 0.68f,
	-0.5f,  0.5f, -0.5f,  0.84f, 0.64f, 0.68f,
	};

	//CONFIG ROSAS-----------------------------------------------------------
	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);
	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);
	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	/*glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/
	// 4. Despues colocamos las caracteristicas de los vertices
	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);
	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	//CONFIG BLANCO ----------------------------------------------------------
	GLuint VBO2, VAO2;
	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);

	glBindVertexArray(VAO2);
	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesBlanco), verticesBlanco, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	//FIN CONFIG BLANCO ----------------------------------------------------------

	//CONFIG NEGRO ----------------------------------------------------------
	GLuint VBO3, VAO3;
	glGenVertexArrays(1, &VAO3);
	glGenBuffers(1, &VBO3);

	glBindVertexArray(VAO3);
	glBindBuffer(GL_ARRAY_BUFFER, VBO3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesNegro), verticesNegro, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	//FIN CONFIG NEGRO ----------------------------------------------------------

	//CONFIG CAFE ROSA ----------------------------------------------------------
	GLuint VBO4, VAO4;
	glGenVertexArrays(1, &VAO4);
	glGenBuffers(1, &VBO4);

	glBindVertexArray(VAO4);
	glBindBuffer(GL_ARRAY_BUFFER, VBO4);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesCafe), verticesCafe, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	//FIN CONFIG CAFE ROSA ----------------------------------------------------------

	//CONFIG DETALLES ----------------------------------------------------------
	GLuint VBO5, VAO5;
	glGenVertexArrays(1, &VAO5);
	glGenBuffers(1, &VBO5);

	glBindVertexArray(VAO5);
	glBindBuffer(GL_ARRAY_BUFFER, VBO5);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesDetalles), verticesDetalles, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	//FIN CONFIG DETALLES----------------------------------------------------------
	
	glm::mat4 projection=glm::mat4(1);

	projection = glm::perspective(glm::radians(45.0f), (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);//FOV, Radio de aspecto,znear,zfar
	//projection = glm::ortho(0.0f, (GLfloat)screenWidth, 0.0f, (GLfloat)screenHeight, 0.1f, 1000.0f);//Izq,Der,Fondo,Alto,Cercania,Lejania
	while (!glfwWindowShouldClose(window))
	{
		
		Inputs(window);
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);


		// Draw our first triangle
		ourShader.Use();
		glm::mat4 model=glm::mat4(1);
		glm::mat4 view=glm::mat4(1);
	

		view = glm::translate(view, glm::vec3(movX,movY, movZ));
		view = glm::rotate(view, glm::radians(rot), glm::vec3(0.0f, 1.0f, 0.0f));

		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projecLoc = glGetUniformLocation(ourShader.Program, "projection");


		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	
		//CUBOS ROSAS------------------------------------------------------------------------
		glBindVertexArray(VAO);

		//cuerpo
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
		model = glm::scale(model, glm::vec3(3.0f, 2.0f, 2.0f)); //ancho, grosor y profundidad
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//cabeza
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.96f, 0.8f, 0.0f));//posición de la cabeza
		model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f)); //tamaño de la cabeza
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); //se manda a llamar info al shader
		glDrawArrays(GL_TRIANGLES, 0, 36); 

		//pata 1
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.1f, -1.5f, -0.6f));//posición de la pata
		model = glm::scale(model, glm::vec3(0.8f, 1.0f, 0.8f)); //tamaño de la pata
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); //se manda a llamar info al shader
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//pata 2
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.1f, -1.5f, 0.6f));//posición de la pata
		model = glm::scale(model, glm::vec3(0.8f, 1.0f, 0.8f)); //tamaño de la pata
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); //se manda a llamar info al shader
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//pata 3
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(1.1f, -1.5f, 0.6f));//posición de la pata
		model = glm::scale(model, glm::vec3(0.8f, 1.0f, 0.8f)); //tamaño de la pata
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); //se manda a llamar info al shader
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//pata 4
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(1.1f, -1.5f, -0.6f));//posición de la pata
		model = glm::scale(model, glm::vec3(0.8f, 1.0f, 0.8f)); //tamaño de la pata
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); //se manda a llamar info al shader
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//nariz
		
		//OBJETOS BLANCOS---------------------------------------------------
		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		glBindVertexArray(VAO2);

		//ojo blanco izq
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.71f, 1.0f, 0.35f));
		model = glm::scale(model, glm::vec3(0.01f, 0.28f, 0.28f));  
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// ojo blanco der
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.71f, 1.0f, -0.35f)); 
		model = glm::scale(model, glm::vec3(0.01f, 0.28f, 0.28f));    
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//OBJETOS NEGROS ------------------------------------------------------
		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		glBindVertexArray(VAO3);

		//ojo negro izq
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.71f, 1.0f, 0.62f));
		model = glm::scale(model, glm::vec3(0.01f, 0.28f, 0.28f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		// ojo negro der
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.71f, 1.0f, -0.62f));
		model = glm::scale(model, glm::vec3(0.01f, 0.28f, 0.28f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//CAFE ROSA DETALLES
		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		glBindVertexArray(VAO4);

		//deditos izq
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3 (-1.52f, -1.85f, -0.86f));
		model = glm::scale(model, glm::vec3(0.01f, 0.28f, 0.25f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.52f, -1.85f, -0.50f));
		model = glm::scale(model, glm::vec3(0.01f, 0.28f, 0.25f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//deditos dere
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.52f, -1.85f, 0.34f));
		model = glm::scale(model, glm::vec3(0.01f, 0.28f, 0.25f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.52f, -1.85f, 0.75f));
		model = glm::scale(model, glm::vec3(0.01f, 0.28f, 0.25f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//dedos atras izq
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.70f, -1.85f, -0.83f));
		model = glm::scale(model, glm::vec3(0.01f, 0.28f, 0.25f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.70f, -1.85f, -0.45f));
		model = glm::scale(model, glm::vec3(0.01f, 0.28f, 0.25f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//dados atras dere
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.70f, -1.85f, 0.3f));
		model = glm::scale(model, glm::vec3(0.01f, 0.28f, 0.25f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.70f, -1.85f, 0.7f));
		model = glm::scale(model, glm::vec3(0.01f, 0.28f, 0.25f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);
		
		//nariz 
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.875f, 0.5f, 0.3f));//posición de la pata
		model = glm::scale(model, glm::vec3(0.01f, 0.2f, 0.22f)); //tamaño de la pata
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); //se manda a llamar info al shader
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.875f, 0.5f, -0.3f));//posición de la pata
		model = glm::scale(model, glm::vec3(0.01f, 0.2f, 0.22f)); //tamaño de la pata
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); //se manda a llamar info al shader
		glDrawArrays(GL_TRIANGLES, 0, 36);
		
		//DETALLES
		glUniformMatrix4fv(projecLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		glBindVertexArray(VAO5);
		//nariz
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.8f, 0.5f, 0.0f));//posición
		model = glm::scale(model, glm::vec3(0.15f, 0.4f, 0.8f)); //tamaño 
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); //se manda a llamar info al shader
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//lado frente 
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.5f, 0.5f, 1.0f));//posición
		model = glm::scale(model, glm::vec3(1.2f, 0.1f, 0.01f)); 
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); 
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.5f, 0.5f, -1.0f));
		model = glm::scale(model, glm::vec3(1.2f, 0.1f, 0.01f)); 
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-0.1f, 0.1f, 1.0f));
		model = glm::scale(model, glm::vec3(1.2f, 0.1f, 0.01f));  
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); 
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-0.1f, 0.1f, -1.0f));
		model = glm::scale(model, glm::vec3(1.2f, 0.1f, 0.01f));  
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); 
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-0.2f, -0.2f, -1.0f));
		model = glm::scale(model, glm::vec3(1.2f, 0.1f, 0.01f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-0.2f, -0.2f, 1.0f));
		model = glm::scale(model, glm::vec3(1.2f, 0.1f, 0.01f));
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-1.5f, -1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(0.5f, 0.05f, 0.01f));  
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); 
		glDrawArrays(GL_TRIANGLES, 0, 36);



		//orejas
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.2f, 0.9f, 0.75f));//posición
		model = glm::scale(model, glm::vec3(0.2f, 0.6f, 0.01f)); //tamaño 
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); //se manda a llamar info al shader
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.3f, 0.9f, 0.75f));//posición
		model = glm::scale(model, glm::vec3(0.2f, 0.3f, 0.01f)); //tamaño 
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); //se manda a llamar info al shader
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.2f, 0.9f, -0.75f));//posición
		model = glm::scale(model, glm::vec3(0.2f, 0.6f, 0.01f)); //tamaño 
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); //se manda a llamar info al shader
		glDrawArrays(GL_TRIANGLES, 0, 36);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-2.3f, 0.9f, -0.75f));//posición
		model = glm::scale(model, glm::vec3(0.2f, 0.3f, 0.01f)); //tamaño 
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model)); //se manda a llamar info al shader
		glDrawArrays(GL_TRIANGLES, 0, 36);

		//-------------------------------
		glBindVertexArray(0);
		// Swap the screen buffers
		glfwSwapBuffers(window);
	
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO2);
	glDeleteBuffers(1, &VBO2);


	glfwTerminate();
	return EXIT_SUCCESS;
 }

 void Inputs(GLFWwindow *window) {
	 if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  //GLFW_RELEASE
		 glfwSetWindowShouldClose(window, true);
	 if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		 movX += 0.02f;
	 if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		 movX -= 0.02f;
	 if (glfwGetKey(window, GLFW_KEY_PAGE_UP) == GLFW_PRESS)
		 movY += 0.02f;
	 if (glfwGetKey(window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS)
		 movY -= 0.02f;
	 if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		 movZ -= 0.02f;
	 if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		 movZ += 0.02f;
	 if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		 rot += 0.4f;
	 if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		 rot -= 0.4f;
 }


