/*
Práctica 2 							Márquez Abundis Mariana
28 de agosto de 2026							320035014
*/

#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	glfwInit();
	//Verificaci�n de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Dibujo de primitivas en 2D", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);
	
	//Verificaci�n de errores de creacion  ventana
	if (window== NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificaci�n de errores de inicializaci�n de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	// Define las dimensiones del viewport
	//glViewport(0, 0, screenWidth, screenHeight);

    Shader ourShader("Shader/core.vs", "Shader/core.frag");

	// Set up vertex data (and buffer(s)) and attribute pointers
	float vertices[] = {
		//cara
		-0.5f, -0.2f,  0.0f,    0.63f,  0.50f,  0.38f, //0
		-0.35f,  0.3f,  0.0f,    0.63f,  0.50f,  0.38f,//1
		-0.2f,  0.5f, 0.0f,    0.63f,  0.50f,  0.38f,//2
		 0.2f,  0.5f, 0.0f,    0.63f,  0.50f,  0.38f,//3
		 0.35f,  0.3f,  0.0f,    0.63f,  0.50f,  0.38f,//4
		 0.5f, -0.2f,  0.0f,    0.63f,  0.50f,  0.38f,//5
		 0.2f, -0.5f,  0.0f,    0.63f,  0.50f,  0.38f,//6
		-0.2f, -0.5f,  0.0f,    0.63f,  0.50f,  0.38f,//7

		//oreja izq
		-0.55f, 0.15f, 0.0f,    0.63f,  0.50f,  0.38f,//8
		-0.45f, 0.3f, 0.0f,     0.63f,  0.50f,  0.38f,//9
		-0.35f,  0.3f,  0.0f,    0.63f,  0.50f,  0.38f,//10
		-0.4f, -0.1f, 0.0f,     0.63f,  0.50f,  0.38f,//11

		//oreja der
		0.35f,  0.3f,  0.0f,    0.63f,  0.50f,  0.38f,//12
		0.45f, 0.3f, 0.0f,     0.63f,  0.50f,  0.38f,//13
		0.55f, 0.15f, 0.0f,    0.63f,  0.50f,  0.38f,//14
		0.4f, -0.1f, 0.0f,     0.63f,  0.50f,  0.38f,//15

		//nariz
		-0.3f, -0.4f, 0.0f, 0.88f, 0.78f, 0.65f,//16
		-0.1f, -0.1f, 0.0f,	0.88f, 0.78f, 0.65f,//17
		0.1f, -0.1f, 0.0f,	0.88f, 0.78f, 0.65f,//18
		0.3f, -0.4f, 0.0f, 0.88f, 0.78f, 0.65f,//19
		0.2f, -0.5f,  0.0f,	0.88f, 0.78f, 0.65f,//20
		-0.2f, -0.5f,  0.0f,	0.88f, 0.78f, 0.65f,//21

		//nariz triangulo
		-0.1f, -0.15f, 0.0f,	0.0f, 0.0f, 0.0f, //22
		0.1f, -0.15f, 0.0f,	0.0f, 0.0f, 0.0f,//23
		0.0f, -0.3f, 0.0f, 	0.0f, 0.0f, 0.0f,//24

		//ojos
		-0.2f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f,//25
		0.2f, 0.0f, 0.0f,    0.0f, 0.0f, 0.0f//26

	};
	unsigned int indices[] = {
		0, 1, 2,//cara
		0, 2, 3,
		0, 3, 4,
		0, 4, 5,
		0, 5, 6, 
		0, 6, 7, 

		8, 9, 10,//oreja izq
		8, 10, 11,

		12, 13, 14, //oreja der
		12, 14, 15,

		16, 17, 18, //nariz
		16, 18, 19,
		16, 19, 20, 
		16, 20, 21, 

		22, 23, 24 //nariz triangulo
	};



	GLuint VBO, VAO,EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)


	
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Draw our first triangle
        ourShader.Use();
        glBindVertexArray(VAO);
		// Renderizado
        
        //glDrawArrays(GL_LINES,0,2);
        //glDrawArrays(GL_LINE_LOOP,0,4);
        
        //glDrawArrays(GL_TRIANGLES,0,3);
        //glDrawElements(GL_TRIANGLES, 3,GL_UNSIGNED_INT,0);
		glDrawElements(GL_TRIANGLES, 45, GL_UNSIGNED_INT, 0);
        

		glPointSize(25);
		glDrawArrays(GL_POINTS, 25, 2);

        glBindVertexArray(0);
    
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}