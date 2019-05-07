#include "Demo.h"



Demo::Demo() {

}


Demo::~Demo() {
}



void Demo::Init() {
	// build and compile our shader program
	// ------------------------------------
	shaderProgram = BuildShader("vertexShader.vert", "fragmentShader.frag", nullptr);
	//shaderKomidi = BuildShader("vertexShader.vert", "fragmentShader.frag", nullptr);

	BuildColoredPlane();
	BuildGedung(5, 10, 10);

	//build kincir1
	{
		BuildKincir(0, 0.1, -0.1, 4, -4, 0.1, -0.1);
		BuildKincir(1, 4, -4, 0.1, -0.1, 0.1, -0.1);
		BuildKincir(2, 0.2, -0.2, 0.2, -0.2, 0.5, -0.5);

		BuildKakiKincir(0, 0.1, -0.1, 6, -6, 0.6, 0.4);
		BuildKakiKincir(1, 0.1, -0.1, 6, -6, -0.4, -0.7);

		//build kincir2
		BuildKincir(3, 0.1, -0.1, 4, -4, 0.1, -0.1);
		BuildKincir(4, 4, -4, 0.1, -0.1, 0.1, -0.1);
		BuildKincir(5, 0.2, -0.2, 0.2, -0.2, 0.5, -0.5);

		BuildKakiKincir(2, 0.1, -0.1, 6, -6, 0.6, 0.4);
		BuildKakiKincir(3, 0.1, -0.1, 6, -6, -0.4, -0.7);

		//build kincir3
		BuildKincir(6, 0.1, -0.1, 4, -4, 0.1, -0.1);
		BuildKincir(7, 4, -4, 0.1, -0.1, 0.1, -0.1);
		BuildKincir(8, 0.2, -0.2, 0.2, -0.2, 0.5, -0.5);

		BuildKakiKincir(4, 0.1, -0.1, 6, -6, 0.6, 0.4);
		BuildKakiKincir(5, 0.1, -0.1, 6, -6, -0.4, -0.7);

		//build kincir4
		BuildKincir(9, 0.1, -0.1, 4, -4, 0.1, -0.1);
		BuildKincir(10, 4, -4, 0.1, -0.1, 0.1, -0.1);
		BuildKincir(11, 0.2, -0.2, 0.2, -0.2, 0.5, -0.5);

		BuildKakiKincir(6, 0.1, -0.1, 6, -6, 0.6, 0.4);
		BuildKakiKincir(7, 0.1, -0.1, 6, -6, -0.4, -0.7);
	}

	//build komidi kotak alas
	BuildKomidiKotak(0, 2, -2, 0, -0.5, 2, -2, 0);
	BuildKomidiKotak(1, 2.5, -2.5, 0, -0.5, 2.5, -2.5, 0);

	//build komidi kotak atap
	BuildKomidiKotak(2, 2, -2, 0, -0.5, 2, -2, 0);
	BuildKomidiKotak(3, 2.5, -2.5, 0, -0.5, 2.5, -2.5, 0);

	//build komidi tiang
	{
		BuildKomidiKotak(4, 0.1, -0.1, 3, -3, 0.1, -0.1, 0); //tengah
		BuildKomidiKotak(5, 2.4, 2.3, 3, -3, 0.1, -0.1, 0); //kanan
		BuildKomidiKotak(6, 0.1, -0.1, 3, -3, 2.4, 2.3, 0); //depan
		BuildKomidiKotak(7, -2.4, -2.3, 3, -3, 0.1, -0.1, 0); //kiri
		BuildKomidiKotak(8, 0.1, -0.1, 3, -3, -2.4, -2.3, 0); //belakang
		BuildKomidiKotak(9, 2.4, 2.3, 3, -3, 2.4, 2.3, 0); //kanandepan
		BuildKomidiKotak(10, 2.4, 2.3, 3, -3, -2.4, -2.3, 0); //kananbelakang
		BuildKomidiKotak(11, -2.4, -2.3, 3, -3, 2.4, 2.3, 0); //kiridepan
		BuildKomidiKotak(12, -2.4, -2.3, 3, -3, -2.4, -2.3, 0); //kiribelakang
	}

	//build kuda
	{
		BuildKomidiKotak(13, 2.5, 2.3, 0.1, -0.1, 0.7, -0.7, 0); //kanan
		BuildKomidiKotak(14, 0.7, -0.7, 0.1, -0.1, 2.5, 2.3, 0); //depan
		BuildKomidiKotak(15, -2.5, -2.3, 0.1, -0.1, 0.7, -0.7, 0); //kiri
		BuildKomidiKotak(16, 0.7, -0.7, 0.1, -0.1, -2.5, -2.3, 0); //belakang
	}
	BuildBench();
	BuildSkybox();

	InitCamera();
}

void Demo::DeInit() {
	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	glDeleteVertexArrays(1, &VAOSkybox);
	glDeleteBuffers(1, &VBOSkybox);
	glDeleteBuffers(1, &EBOSkybox);

}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void Demo::ProcessInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
	
	// zoom camera
	// -----------
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
		if (fovy < 90) {
			fovy += 0.0001f;
		}
	}

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		if (fovy > 0) {
			fovy -= 0.0001f;
		}
	}

	// update camera movement 
	// -------------
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		MoveCamera(CAMERA_SPEED);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		MoveCamera(-CAMERA_SPEED);
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		StrafeCamera(-CAMERA_SPEED);
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		StrafeCamera(CAMERA_SPEED);
	}

	// update camera rotation
	// ----------------------
	double mouseX, mouseY;
	double midX = screenWidth/2;
	double midY = screenHeight/2;
	float angleY = 0.0f;
	float angleZ = 0.0f;

	// Get mouse position
	glfwGetCursorPos(window, &mouseX, &mouseY);
	if ((mouseX == midX) && (mouseY == midY)) {
		return;
	}

	// Set mouse position
	glfwSetCursorPos(window, midX, midY);

	// Get the direction from the mouse cursor, set a resonable maneuvering speed
	angleY = (float)((midX - mouseX)) / 1000;
	angleZ = (float)((midY - mouseY)) / 1000;

	// The higher the value is the faster the camera looks around.
	viewCamY += angleZ * 2;

	// limit the rotation around the x-axis
	if ((viewCamY - posCamY) > 8) {
		viewCamY = posCamY + 8;
	}
	if ((viewCamY - posCamY) < -8) {
		viewCamY = posCamY - 8;
	}
	RotateCamera(-angleY);


	

}

void Demo::Update(double deltaTime) {
	angle -= (float)((deltaTime * 1.5f) / 10000);
}

void Demo::Render() {
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);

	// Pass perspective projection matrix
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 200.0f);
	GLint projLoc = glGetUniformLocation(this->shaderProgram, "projection");
	GLint projLocKomidi = glGetUniformLocation(this->shaderKincir, "projection");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(projLocKomidi, 1, GL_FALSE, glm::value_ptr(projection));

	// LookAt camera (position, target/direction, up)
	glm::mat4 view = glm::lookAt(glm::vec3(posCamX, posCamY, posCamZ), glm::vec3(viewCamX, viewCamY, viewCamZ), glm::vec3(upCamX, upCamY, upCamZ));
	GLint viewLoc = glGetUniformLocation(this->shaderProgram, "view");
	GLint viewLocKomidi = glGetUniformLocation(this->shaderKincir, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(viewLocKomidi, 1, GL_FALSE, glm::value_ptr(view));

	//DrawColoredCube();

	DrawColoredPlane();
	DrawBench();
	DrawSkybox();
	DrawGedung();

	//draw kincir1
	{
		DrawKincir(0, 5, 6, 0);
		DrawKincir(1, 5, 6, 0);
		DrawKincir(2, 5, 6, 0);

		DrawKakiKincir(0, 5, 0, 0);
		DrawKakiKincir(1, 5, 0, 0);

		//draw kincir2
		DrawKincir(3, 15, 6, 0);
		DrawKincir(4, 15, 6, 0);
		DrawKincir(5, 15, 6, 0);

		DrawKakiKincir(2, 15, 0, 0);
		DrawKakiKincir(3, 15, 0, 0);

		//draw kincir3
		DrawKincir(6, 5, 6, -9);
		DrawKincir(7, 5, 6, -9);
		DrawKincir(8, 5, 6, -9);

		DrawKakiKincir(4, 5, 0, -9);
		DrawKakiKincir(5, 5, 0, -9);

		//draw kincir4
		DrawKincir(9, 15, 6, -9);
		DrawKincir(10, 15, 6, -9);
		DrawKincir(11, 15, 6, -9);

		DrawKakiKincir(6, 15, 0, -9);
		DrawKakiKincir(7, 15, 0, -9);
	}
	//draw Komidi alas
	DrawKomidiKotak(0, 12, 0.5, 12);
	DrawKomidiKotak(1, 12, 0, 12);
	//draw Komidi atap
	DrawKomidiKotak(2, 12, 5, 12);
	DrawKomidiKotak(3, 12, 5.5, 12);
	//draw komidi tiang
	{
		DrawKomidiKotak(4, 12, 2.5, 12);
		DrawKomidiKotak(5, 12, 2.5, 12);
		DrawKomidiKotak(6, 12, 2.5, 12);
		DrawKomidiKotak(7, 12, 2.5, 12);
		DrawKomidiKotak(8, 12, 2.5, 12);
		DrawKomidiKotak(9, 12, 2.5, 12);
		DrawKomidiKotak(10, 12, 2.5, 12);
		DrawKomidiKotak(11, 12, 2.5, 12);
		DrawKomidiKotak(12, 12, 2.5, 12);
	}
	//draw kuda
	{
		DrawKomidiKotak(13, 12, 2.5, 12);
		DrawKomidiKotak(14, 12, 2.5, 12);
		DrawKomidiKotak(15, 12, 2.5, 12);
		DrawKomidiKotak(16, 12, 2.5, 12);
	}
	glDisable(GL_DEPTH_TEST);
}


void Demo::BuildColoredPlane()
{
	// Load and create a texture 
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height;
	unsigned char* image = SOIL_load_image("brick_tile.jpg", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// Build geometry
	GLfloat vertices[] = {
		// format position, tex coords
		// bottom
		-50.0, -0.5, -50.0,  0,  0,
		 50.0, -0.5, -50.0, 50,  0,
		 50.0, -0.5,  50.0, 50, 50,
		-50.0, -0.5,  50.0,  0, 50,


	};

	GLuint indices[] = { 0,  2,  1,  0,  3,  2 };

	glGenVertexArrays(1, &VAO2);
	glGenBuffers(1, &VBO2);
	glGenBuffers(1, &EBO2);

	glBindVertexArray(VAO2);

	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// TexCoord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0); // Unbind VAO
}

void Demo::DrawColoredPlane()
{
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 1);

	glBindVertexArray(VAO2); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glm::mat4 model;
	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void Demo::BuildSkybox() {
	// Load and create a texture 
	glGenTextures(1, &textureSkybox);
	glBindTexture(GL_TEXTURE_2D, textureSkybox);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height;
	unsigned char* image = SOIL_load_image("skybox1.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// Build geometry
	GLfloat vertices[] = {
		// format position, tex coords
		-100.0, 80.0, -100.0,  1,  0.75, //0
		100.0, 80.0 , -100.0, 1,  0.5, //1
		100.0, 80.0 ,  100.0, 0.75, 0.5, //2
		-100.0, 80.0 ,  100.0,  0.75, 0.75, //3

		100.0, 80.0 , -100.0, 1,  0.5, //4
		100.0, 80.0 ,  100.0, 0.75, 0.5, //5
		100.0 , -80.0 , -100.0 , 1, 0.25, //6
		100.0 , -80 , 100 , 0.75 , 0.25, //7

		100.0, 80.0 ,  100.0, 0.75, 0.5, //8
		-100.0, 80.0 ,  100.0,  0.5, 0.5, //9
		100.0 , -80 , 100 , 0.75 , 0.25, //10
		-100, -80, 100 ,  0.5, 0.25, //11         

		-100.0, 80.0 ,  100.0,  0.5, 0.5, //12
		-100.0, 80.0, -100.0,  0.25,  0.5, //13
		-100, -80, 100 ,  0.5 , 0.25, //14
		-100, -80 , -100 , 0.25 , 0.25,//15

		-100.0, 80.0, -100.0,  0.25,  0.5, //16
		100.0, 80.0 , -100.0, 0,  0.5, //17
		-100, -80 , -100.0 , 0.25, 0.25,//18
		100.0 , -80.0 , -100.0 , 0, 0.25 //19
	};

	GLuint indices[] = {
		0,  2,  1,  0,  3,  2,
		5,  6 , 4 , 5 , 6 , 7,
		9 , 8 , 10 , 9 , 10 , 11,
		12 , 15, 13  , 12 , 15, 14,
		16 , 19 , 17 , 16 , 19 , 18
	};

	glGenVertexArrays(1, &VAOSkybox);
	glGenBuffers(1, &VBOSkybox);
	glGenBuffers(1, &EBOSkybox);

	glBindVertexArray(VAOSkybox);

	glBindBuffer(GL_ARRAY_BUFFER, VBOSkybox);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOSkybox);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	// TexCoord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0); // Unbind VAO
}

void Demo::DrawSkybox() {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE10);
	glBindTexture(GL_TEXTURE_2D, textureSkybox);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 10);

	glBindVertexArray(VAOSkybox); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glm::mat4 model;
	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 10 * 3, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void Demo::BuildBench() {
	glGenTextures(1, &textureBuilding);
	glBindTexture(GL_TEXTURE_2D, textureBuilding);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width = 2, height = 2;
	unsigned char* image = SOIL_load_image("bench_wood.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	float vertices[] = {
		// format position, tex coords

		// right
		0.85,  -0.1,  0.25, 0, 0,  // 0
		0.85,  -0.1, -0.45, 1, 0,  // 1
		0.85, -0.5, -0.45, 1, 1,  // 2
		0.85, -0.5,  0.25, 0, 1,  // 3

		// back
		-0.85, -0.1, -0.5, 0, 0, // 4
		0.85,  -0.1, -0.5, 1, 0, // 5
		0.85,   0.8, -0.5, 1, 1, // 6
		-0.85,  0.8, -0.5, 0, 1, // 7

		// left
		-0.85, -0.1, -0.45, 0, 0, // 8
		-0.85, -0.1,  0.25, 1, 0, // 9
		-0.85,  -0.5,  0.25, 1, 1, // 10
		-0.85,  -0.5, -0.45, 0, 1, // 11

		// upper
		0.85, -0.1,  0.3, 0, 0,   // 12
		-0.85, -0.1,  0.3, 1, 0,  // 13
		-0.85, -0.1, -0.5, 1, 1,  // 14
		0.85, -0.1, -0.5, 0, 1,   // 15
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
	};

	glGenVertexArrays(1, &VAOBuilding);
	glGenBuffers(1, &VBOBuilding);
	glGenBuffers(1, &EBOBuilding);
	glBindVertexArray(VAOBuilding);
	glBindBuffer(GL_ARRAY_BUFFER, VBOBuilding);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOBuilding);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Demo::DrawBench() {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureBuilding);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 0);

	glBindVertexArray(VAOBuilding); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void Demo::BuildGedung(int size, float xpos, float ypos) {
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	glGenTextures(1, &textureGedung);
	glBindTexture(GL_TEXTURE_2D, textureGedung);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image("bench_wood.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float t = 10.0;
	float w = size;
	float rightX = (0.5f*w / 2)+xpos;
	float leftX = (-0.5f *w / 2)+xpos;
	float topY = 0.5f *t;
	float botY = -0.5f *t;
	float frontZ = 0.5f *w / 2;
	float backZ = -0.5f *w / 2;
	float tinggiAtap = 4;
	float atapWidth = w;

	float vertices[] = {
		// format position, tex coords
		// front
		leftX, botY, frontZ, 0, 0,  // 0
		rightX, botY, frontZ, 0.75, 0,   // 1
		rightX,  topY, frontZ, 0.75, 0.75,   // 2
		leftX,  topY, frontZ, 0, 0.75,  // 3

		// right
		rightX,  topY,  frontZ, 0, 0,  // 4
		rightX,  topY, backZ, 0.75, 0,  // 5
		rightX, botY, backZ, 0.75, 0.75,  // 6
		rightX, botY,  frontZ, 0, 0.75,  // 7

		// back
		leftX, botY, backZ, 0, 0, // 8 
		rightX,  botY, backZ, 0.75, 0, // 9
		leftX,   topY, backZ, 0, 0.75, // 10
		rightX,  topY, backZ, 0.75, 0.75, // 11

		// left
		leftX, botY, backZ, 0, 0, // 12
		leftX, botY,  frontZ, 0.75, 0, // 13
		leftX,  topY,  frontZ, 0.75, 0.75, // 14
		leftX,  topY, backZ, 0, 0.75, // 15

		// upper
		rightX, topY,  frontZ, 0, 0,   // 16
		leftX, topY,  frontZ, 0.75, 0,  // 17
		leftX, topY, backZ, 0.75, 0.75,  // 18 // 
		rightX, topY, backZ, 0, 0.75,   // 19 //

		// bottom
		leftX, botY, backZ, 0, 0, // 20
		rightX, botY, backZ, 0.75, 0,  // 21
		rightX, botY,  frontZ, 0.75, 0.75,  // 22
		leftX, botY,  frontZ, 0, 0.75, // 23

		// atap
		(leftX + rightX) / 2,topY + tinggiAtap,(frontZ + backZ) / 2,0.5,1 //24
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 9,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22,   // bottom
		24,16,17,  24,17,18,     // atap
		24,18,19, 24,19,16
	};

	glGenVertexArrays(1, &VAOGedung);
	glGenBuffers(1, &VBOGedung);
	glGenBuffers(1, &EBOGedung);
	glBindVertexArray(VAOGedung);
	glBindBuffer(GL_ARRAY_BUFFER, VBOGedung);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOGedung);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Demo::DrawGedung()
{
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureGedung);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 0);

	glBindVertexArray(VAOGedung); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glDrawElements(GL_TRIANGLES, 48, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void Demo::BuildKincir(int index, float xplus, float xmin, float yplus, float ymin, float zplus, float zmin) {
	glGenTextures(1, &textureKincir[index]);
	glBindTexture(GL_TEXTURE_2D, textureKincir[index]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image("crate.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	float vertices[] = {
		// front
		xmin, ymin, zplus, 0, 0,  // 0
		xplus, ymin, zplus, 1, 0,   // 1
		xplus,  yplus, zplus, 1, 1,   // 2
		xmin,  yplus, zplus, 0, 1,  // 3

								// right
								xplus,  yplus,  zplus, 0, 0,  // 4
								xplus,  yplus, zmin, 1, 0,  // 5
								xplus, ymin, zmin, 1, 1,  // 6
								xplus, ymin,  zplus, 0, 1,  // 7

														// back
														xmin, ymin, zmin, 0, 0, // 8 
														xplus,  ymin, zmin, 1, 0, // 9
														xplus,   yplus, zmin, 1, 1, // 10
														xmin,  yplus, zmin, 0, 1, // 11

																				// left
																				xmin, ymin, zmin, 0, 0, // 12
																				xmin, ymin, zplus, 1, 0, // 13
																				xmin,  yplus,  zplus, 1, 1, // 14
																				xmin,  yplus, zmin, 0, 1, // 15

																										// upper
																										xplus, yplus,  zplus, 0, 0,   // 16
																										xmin, yplus,  zplus, 1, 0,  // 17
																										xmin, yplus, zmin, 1, 1,  // 18
																										xplus, yplus, zmin, 0, 1,   // 19

																																// bottom
																																xmin, ymin, zmin, 0, 0, // 20
																																xplus, ymin, zmin, 1, 0,  // 21
																																xplus, ymin,  zplus, 1, 1,  // 22
																																xmin, ymin,  zplus, 0, 1, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22,   // bottom
	};


	glGenVertexArrays(1, &VAOKincir[index]);
	glGenBuffers(1, &VBOKincir[index]);
	glGenBuffers(1, &EBOKincir[index]);
	glBindVertexArray(VAOKincir[index]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOKincir[index]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOKincir[index]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);//*/
}

void Demo::DrawKincir(int index, float xpos, float ypos, float zpos) {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureKincir[index]);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 0);

	glBindVertexArray(VAOKincir[index]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glm::mat4 modelkomidi;
	modelkomidi = glm::translate(modelkomidi, glm::vec3(xpos, ypos, zpos));
	modelkomidi = glm::rotate(modelkomidi, angle, glm::vec3(0, 0, 1));

	modelkomidi = glm::scale(modelkomidi, glm::vec3(1, 1, 1));

	GLint modelLocKomidi = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLocKomidi, 1, GL_FALSE, glm::value_ptr(modelkomidi));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void Demo::BuildKakiKincir(int index,float xplus ,float xmin,float yplus, float ymin, float zplus, float zmin) {
	glGenTextures(1, &texturekKincir[index]);
	glBindTexture(GL_TEXTURE_2D, texturekKincir[index]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image("crate.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// front
		xmin, ymin, zplus, 0, 0,  // 0
		xplus, ymin, zplus, 1, 0,   // 1
		xplus,  yplus, zplus, 1, 1,   // 2
		xmin,  yplus, zplus, 0, 1,  // 3

									// right
									xplus,  yplus,  zplus, 0, 0,  // 4
									xplus,  yplus, zmin, 1, 0,  // 5
									xplus, ymin, zmin, 1, 1,  // 6
									xplus, ymin,  zplus, 0, 1,  // 7

																// back
																xmin, ymin, zmin, 0, 0, // 8 
																xplus,  ymin, zmin, 1, 0, // 9
																xplus,   yplus, zmin, 1, 1, // 10
																xmin,  yplus, zmin, 0, 1, // 11

																						  // left
																						  xmin, ymin, zmin, 0, 0, // 12
																						  xmin, ymin, zplus, 1, 0, // 13
																						  xmin,  yplus,  zplus, 1, 1, // 14
																						  xmin,  yplus, zmin, 0, 1, // 15

																													// upper
																													xplus, yplus,  zplus, 0, 0,   // 16
																													xmin, yplus,  zplus, 1, 0,  // 17
																													xmin, yplus, zmin, 1, 1,  // 18
																													xplus, yplus, zmin, 0, 1,   // 19

																																				// bottom
																																				xmin, ymin, zmin, 0, 0, // 20
																																				xplus, ymin, zmin, 1, 0,  // 21
																																				xplus, ymin,  zplus, 1, 1,  // 22
																																				xmin, ymin,  zplus, 0, 1, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22,   // bottom
	};


	glGenVertexArrays(1, &VAOkKincir[index]);
	glGenBuffers(1, &VBOkKincir[index]);
	glGenBuffers(1, &EBOkKincir[index]);
	glBindVertexArray(VAOkKincir[index]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOkKincir[index]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOkKincir[index]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Demo::DrawKakiKincir(int index, float xpos, float ypos, float zpos) {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texturekKincir[index]);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 0);

	glBindVertexArray(VAOkKincir[index]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glm::mat4 model;
	model = glm::translate(model, glm::vec3(xpos, ypos, zpos));
	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void Demo::BuildKomidiKotak(int index, float xplus, float xmin, float yplus, float ymin, float zplus, float zmin, float atap) {
	glGenTextures(1, &textureKomidi[index]);
	glBindTexture(GL_TEXTURE_2D, textureKomidi[index]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image("crate.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	float vertices[] = {
		// front
		xmin, ymin, zplus, 0, 0,  // 0
		xplus, ymin, zplus, 1, 0,   // 1
		xplus,  yplus, zplus, 1, 1,   // 2
		xmin,  yplus, zplus, 0, 1,  // 3

									// right
									xplus,  yplus,  zplus, 0, 0,  // 4
									xplus,  yplus, zmin, 1, 0,  // 5
									xplus, ymin, zmin, 1, 1,  // 6
									xplus, ymin,  zplus, 0, 1,  // 7

																// back
																xmin, ymin, zmin, 0, 0, // 8 
																xplus,  ymin, zmin, 1, 0, // 9
																xplus,   yplus, zmin, 1, 1, // 10
																xmin,  yplus, zmin, 0, 1, // 11

																						  // left
																						  xmin, ymin, zmin, 0, 0, // 12
																						  xmin, ymin, zplus, 1, 0, // 13
																						  xmin,  yplus,  zplus, 1, 1, // 14
																						  xmin,  yplus, zmin, 0, 1, // 15

																													// upper
																													xplus, yplus,  zplus, 0, 0,   // 16
																													xmin, yplus,  zplus, 1, 0,  // 17
																													xmin, yplus, zmin, 1, 1,  // 18
																													xplus, yplus, zmin, 0, 1,   // 19

																																				// bottom
																																				xmin, ymin, zmin, 0, 0, // 20
																																				xplus, ymin, zmin, 1, 0,  // 21
																																				xplus, ymin,  zplus, 1, 1,  // 22
																																				xmin, ymin,  zplus, 0, 1, // 23
	
	(xmin + xplus) / 2,yplus + atap,(zplus + zmin) / 2,0.5,1 //24
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22,   // bottom
		//24,16,17,  24,17,18,     // atap
		24,18,19, //24,19,16
	};


	glGenVertexArrays(1, &VAOKomidi[index]);
	glGenBuffers(1, &VBOKomidi[index]);
	glGenBuffers(1, &EBOKomidi[index]);
	glBindVertexArray(VAOKomidi[index]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOKomidi[index]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOKomidi[index]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);//*/
}

void Demo::DrawKomidiKotak(int index, float xpos, float ypos, float zpos) {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureKomidi[index]);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 0);

	glBindVertexArray(VAOKomidi[index]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glm::mat4 modelkomidi;
	modelkomidi = glm::translate(modelkomidi, glm::vec3(xpos, ypos, zpos));
	modelkomidi = glm::rotate(modelkomidi, angle, glm::vec3(0, 1, 0));

	modelkomidi = glm::scale(modelkomidi, glm::vec3(1, 1, 1));

	GLint modelLocKomidi = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLocKomidi, 1, GL_FALSE, glm::value_ptr(modelkomidi));

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}
//Setting Camera
void Demo::InitCamera()
{
	posCamX = 0.0f;
	posCamY = 1.0f;
	posCamZ = 8.0f;
	viewCamX = 0.0f;
	viewCamY = 1.0f;
	viewCamZ = 0.0f;
	upCamX = 0.0f;
	upCamY = 1.0f;
	upCamZ = 0.0f;
	CAMERA_SPEED = 0.001f;
	fovy = 50.0f;
	glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Demo::MoveCamera(float speed)
{
	float x = viewCamX - posCamX;
	float z = viewCamZ - posCamZ;
	// forward positive cameraspeed and backward negative -cameraspeed.
	posCamX = posCamX + x * speed;
	posCamZ = posCamZ + z * speed;
	viewCamX = viewCamX + x * speed;
	viewCamZ = viewCamZ + z * speed;
}

void Demo::StrafeCamera(float speed)
{
	float x = viewCamX - posCamX;
	float z = viewCamZ - posCamZ;
	float orthoX = -z;
	float orthoZ = x;

	// left positive cameraspeed and right negative -cameraspeed.
	posCamX = posCamX + orthoX * speed;
	posCamZ = posCamZ + orthoZ * speed;
	viewCamX = viewCamX + orthoX * speed;
	viewCamZ = viewCamZ + orthoZ * speed;
}

void Demo::RotateCamera(float speed)
{
	float x = viewCamX - posCamX;
	float z = viewCamZ - posCamZ;
	viewCamZ = (float)(posCamZ + glm::sin(speed) * x + glm::cos(speed) * z);
	viewCamX = (float)(posCamX + glm::cos(speed) * x - glm::sin(speed) * z);
}


int main(int argc, char** argv) {
	RenderEngine &app = Demo();
	app.Start("Park", 800, 600, false, false);
}