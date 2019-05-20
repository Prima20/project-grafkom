#include "Demo.h"



Demo::Demo() {

}


Demo::~Demo() {
}



void Demo::Init() {
	// build and compile our shader program
	// ------------------------------------
	shaderProgram = BuildShader("vertexShader.vert", "fragmentShader.frag", nullptr);
	tshaderProgram = BuildShader("texturedObject.vert", "texturedObject.frag", nullptr);

	//BuildColoredCube();

	BuildColoredPlane();

	//Gedung
	BuildGedung(0,"building.png",10,10, 7.0f,0.0f);
	BuildGedung(1, "building2.png", 10, -10.0f, 7.0f, -17.0f);
	BuildGedung(2, "building3.png", 10, 5.0f, 7.0f, -20.0f);

	BuildSlider(2, -7, 5);

	BuildVidioTrone(5,5,0,-5);
	BuildBench(5.0f,-2.0f);

	//Road Roller
	BuildRoadRoller(0, 0, -6.0f);
	BuildRoadRoller(1, 0, -9.0f);
	BuildRoadRoller(2, 0, -12.0f);


	//build komidi kotak alas                     //texture coordinate
	BuildKomidiKotak(0, 2, -2, 0, -0.5, 2, -2, 0, 0, 0.6, 1, 0.6, 1, 0.75, 0, 0.75);
	BuildKomidiKotak(1, 2.5, -2.5, 0, -0.5, 2.5, -2.5, 0, 0, 0.25, 1, 0.25, 1, 0.5, 0, 0.5);

	//build komidi kotak atap
	BuildKomidiKotak(2, 2, -2, 0, -0.5, 2, -2, 0, 0, 0.6, 1, 0.6, 1, 0.75, 0, 0.75);
	BuildKomidiKotak(3, 2.5, -2.5, 0, -0.5, 2.5, -2.5, 0, 0, 0.25, 1, 0.25, 1, 0.5, 0, 0.5);

	//build komidi tiang
	{
		BuildKomidiKotak(4, 0.1, -0.1, 3, -3, 0.1, -0.1, 0, 0, 0, 1, 0, 1, 0.25, 0, 0.25); //tengah
		BuildKomidiKotak(5, 2.4, 2.3, 3, -3, 0.1, -0.1, 0, 0, 0, 1, 0, 1, 0.25, 0, 0.25); //kanan
		BuildKomidiKotak(6, 0.1, -0.1, 3, -3, 2.4, 2.3, 0, 0, 0, 1, 0, 1, 0.25, 0, 0.25); //depan
		BuildKomidiKotak(7, -2.4, -2.3, 3, -3, 0.1, -0.1, 0, 0, 0, 1, 0, 1, 0.25, 0, 0.25); //kiri
		BuildKomidiKotak(8, 0.1, -0.1, 3, -3, -2.4, -2.3, 0, 0, 0, 1, 0, 1, 0.25, 0, 0.25); //belakang
		BuildKomidiKotak(9, 2.4, 2.3, 3, -3, 2.4, 2.3, 0, 0, 0, 1, 0, 1, 0.25, 0, 0.25); //kanandepan
		BuildKomidiKotak(10, 2.4, 2.3, 3, -3, -2.4, -2.3, 0, 0, 0, 1, 0, 1, 0.25, 0, 0.25); //kananbelakang
		BuildKomidiKotak(11, -2.4, -2.3, 3, -3, 2.4, 2.3, 0, 0, 0, 1, 0, 1, 0.25, 0, 0.25); //kiridepan
		BuildKomidiKotak(12, -2.4, -2.3, 3, -3, -2.4, -2.3, 0, 0, 0, 1, 0, 1, 0.25, 0, 0.25); //kiribelakang
	}

	//build kuda
	{
		BuildKomidiKotak(13, 2.5, 2.3, 0.1, -0.1, 0.7, -0.7, 0, 0, 0.6, 1, 0.6, 1, 0.75, 0, 0.75); //kanan
		BuildKomidiKotak(14, 0.7, -0.7, 0.1, -0.1, 2.5, 2.3, 0, 0, 0.6, 1, 0.6, 1, 0.75, 0, 0.75); //depan
		BuildKomidiKotak(15, -2.5, -2.3, 0.1, -0.1, 0.7, -0.7, 0, 0, 0.6, 1, 0.6, 1, 0.75, 0, 0.75); //kiri
		BuildKomidiKotak(16, 0.7, -0.7, 0.1, -0.1, -2.5, -2.3, 0, 0, 0.6, 1, 0.6, 1, 0.75, 0, 0.75); //belakang
	}

#pragma region kincir
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
#pragma endregion

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
	angle -= (float)((deltaTime * 1.5f) / 1000);
	gerakRollerCoster -= (float)((deltaTime * 1.5f) / 100);
	//std::cout << "angle: " << angle << std::endl;
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
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	// LookAt camera (position, target/direction, up)
	glm::mat4 view = glm::lookAt(glm::vec3(posCamX, posCamY, posCamZ), glm::vec3(viewCamX, viewCamY, viewCamZ), glm::vec3(upCamX, upCamY, upCamZ));
	GLint viewLoc = glGetUniformLocation(this->shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	// set lighting attributes
	GLint lightPosLoc = glGetUniformLocation(this->tshaderProgram, "lightPos");
	glUniform3f(lightPosLoc, 0, 1, 0);
	GLint viewPosLoc = glGetUniformLocation(this->tshaderProgram, "viewPos");
	glUniform3f(viewPosLoc, 0, 2, 3);
	GLint lightColorLoc = glGetUniformLocation(this->tshaderProgram, "lightColor");
	glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f);

	//Draw Object in scene
	//DrawColoredCube();

	DrawColoredPlane();

	DrawBench();

	DrawSkybox();

	DrawGedung(0);
	DrawGedung(1);
	DrawGedung(2);


	DrawVidioTrone();
	//DrawSlider();

	DrawRoadRoller(0);
	DrawRoadRoller(1);
	DrawRoadRoller(2);

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

#pragma region kincir
	{
		//draw kincir1 (kanan depan)
		DrawKincir(0, -5, 6, 0);
		DrawKincir(1, -5, 6, 0);
		DrawKincir(2, -5, 6, 0);

		DrawKakiKincir(0, -5, 0, 0);
		DrawKakiKincir(1, -5, 0, 0);

		//draw kincir2 (kiri depan)
		DrawKincir(3, -15, 6, 0);
		DrawKincir(4, -15, 6, 0);
		DrawKincir(5, -15, 6, 0);

		DrawKakiKincir(2, -15, 0, 0);
		DrawKakiKincir(3, -15, 0, 0);

		//draw kincir3 (kanan belakang)
		DrawKincir(6, -5, 6, -9);
		DrawKincir(7, -5, 6, -9);
		DrawKincir(8, -5, 6, -9);

		DrawKakiKincir(4, -5, 0, -9);
		DrawKakiKincir(5, -5, 0, -9);

		//draw kincir4 (kiri belakang)
		DrawKincir(9, -15, 6, -9);
		DrawKincir(10, -15, 6, -9);
		DrawKincir(11, -15, 6, -9);

		DrawKakiKincir(6, -15, 0, -9);
		DrawKakiKincir(7, -15, 0, -9);
	}
#pragma endregion



	glDisable(GL_DEPTH_TEST);
}

void Demo::BuildColoredCube() {
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
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
		-0.5, -0.5, 0.5, 0, 0,  // 0
		0.5, -0.5, 0.5, 1, 0,   // 1
		0.5,  0.5, 0.5, 1, 1,   // 2
		-0.5,  0.5, 0.5, 0, 1,  // 3

		// right
		0.5,  0.5,  0.5, 0, 0,  // 4
		0.5,  0.5, -0.5, 1, 0,  // 5
		0.5, -0.5, -0.5, 1, 1,  // 6
		0.5, -0.5,  0.5, 0, 1,  // 7

		// back
		-0.5, -0.5, -0.5, 0, 0, // 8 
		0.5,  -0.5, -0.5, 1, 0, // 9
		0.5,   0.5, -0.5, 1, 1, // 10
		-0.5,  0.5, -0.5, 0, 1, // 11

		// left
		-0.5, -0.5, -0.5, 0, 0, // 12
		-0.5, -0.5,  0.5, 1, 0, // 13
		-0.5,  0.5,  0.5, 1, 1, // 14
		-0.5,  0.5, -0.5, 0, 1, // 15

		// upper
		0.5, 0.5,  0.5, 0, 0,   // 16
		-0.5, 0.5,  0.5, 1, 0,  // 17
		-0.5, 0.5, -0.5, 1, 1,  // 18
		0.5, 0.5, -0.5, 0, 1,   // 19

		// bottom
		-0.5, -0.5, -0.5, 0, 0, // 20
		0.5, -0.5, -0.5, 1, 0,  // 21
		0.5, -0.5,  0.5, 1, 1,  // 22
		-0.5, -0.5,  0.5, 0, 1, // 23
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22   // bottom
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// define position pointer layout 0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	// define texcoord pointer layout 1
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Demo::DrawColoredCube()
{
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 0);

	glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
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

void Demo::BuildBench(float xpos, float zpos) {
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	glGenTextures(1, &textureBench);
	glBindTexture(GL_TEXTURE_2D, textureBench);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image("bench.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords

		// right
		0.85+xpos,  -0.1,  0.25+zpos, 0, 0,  // 0
		0.85 + xpos,  -0.1, -0.45 + zpos, 0.41, 0.41,  // 1
		0.85 + xpos, -0.5, -0.45 + zpos, 0.41, 0.41,  // 2
		0.85 + xpos, -0.5,  0.25 + zpos, 0, 0.41,  // 3

		// back
		-0.85 + xpos, -0.1, -0.5 + zpos, 0.41, 0.41, // 4
		0.85 + xpos,  -0.1, -0.5 + zpos, 1, 0.41, // 5
		0.85 + xpos,   0.8, -0.5 + zpos, 1, 1, // 6
		-0.85 + xpos,  0.8, -0.5 + zpos, 0.41, 1, // 7

		// left
		-0.85 + xpos, -0.1, -0.45 + zpos, 0, 0, // 8
		-0.85 + xpos, -0.1,  0.25 + zpos, 0.41, 0, // 9
		-0.85 + xpos,  -0.5,  0.25 + zpos, 0.41, 0.41, // 10
		-0.85 + xpos,  -0.5, -0.45 + zpos, 0, 0.41, // 11

		// upper
		0.85 + xpos, -0.1,  0.3 + zpos, 0.41, 0.41,   // 12
		-0.85 + xpos, -0.1,  0.3 + zpos, 1, 0.41,  // 13
		-0.85 + xpos, -0.1, -0.5 + zpos, 1, 1,  // 14
		0.85 + xpos, -0.1, -0.5 + zpos, 0.41, 1,   // 15
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
	};

	glGenVertexArrays(1, &VAOBench);
	glGenBuffers(1, &VBOBench);
	glGenBuffers(1, &EBOBench);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAOBench);

	glBindBuffer(GL_ARRAY_BUFFER, VBOBench);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOBench);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// define position pointer layout 0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	// define texcoord pointer layout 1
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Demo::BuildGedung(int index, char* textureName, int size, float xpos, float ypos, float zpos) {
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	glGenTextures(1, &textureGedung[index]);
	glBindTexture(GL_TEXTURE_2D, textureGedung[index]);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image(textureName, &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float t = 15.0;
	float w = size;
	float rightX = (0.5f*w / 2)+xpos;
	float leftX = (-0.5f *w / 2)+xpos;
	float topY = 0.5f *t +ypos;
	float botY = -0.5f *t +ypos ;
	float frontZ = 0.5f *w / 2 +zpos;
	float backZ = -0.5f *w / 2 +zpos;
	float tinggiAtap = 1;
	float atapWidth = w;

	float vertices[] = {
		// format position, tex coords
		// front
		leftX, botY, frontZ, 0, 0,  // 0
		rightX, botY, frontZ, 0.5, 0,   // 1
		rightX,  topY, frontZ, 0.5, 1,   // 2
		leftX,  topY, frontZ, 0, 1,  // 3

		// right
		rightX,  topY,  frontZ, 1.0, 1.0,  // 4
		rightX,  topY, backZ,   0.5, 1.0,  // 5
		rightX, botY, backZ,    0.5f, 0,  // 6
		rightX, botY,  frontZ,  1,    0,  // 7

		// back
		leftX, botY, backZ, 0.5, 0, // 8 
		rightX,  botY, backZ, 1.0f, 0, // 9
		leftX,   topY, backZ, 0.5f, 1.0f, // 10
		rightX,  topY, backZ, 1.0f, 1.0f, // 11

		// left
		leftX, botY, backZ, 0.5f, 0, // 12
		leftX, botY,  frontZ, 1.0f, 0, // 13
		leftX,  topY,  frontZ, 1.0f, 1.0f, // 14
		leftX,  topY, backZ,   0.5f, 1.0f, // 15

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
		24,16,17,  24,17,18, // atap
		24,18,19, 24,19,16


	};

	glGenVertexArrays(1, &VAOGedung[index]);
	glGenBuffers(1, &VBOGedung[index]);
	glGenBuffers(1, &EBOGedung[index]);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAOGedung[index]);

	glBindBuffer(GL_ARRAY_BUFFER, VBOGedung[index]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOGedung[index]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// define position pointer layout 0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	// define texcoord pointer layout 1
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Demo::BuildVidioTrone(int size, float xpos, float ypos, float zpos) {
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	glGenTextures(1, &textureTrone);
	glBindTexture(GL_TEXTURE_2D, textureTrone);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image("videotron.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// set up vertex data (and buffer(s)) and configure vertex attributes

	

	// ------------------------------------------------------------------
	float t = 10.0;
	float w = size;
	float rightX = 0.5f *w/2 + xpos;
	float leftX = -0.5f *w/2 + xpos;
	
	float xMidLeft = -0.1f *w/2 + xpos;
	float xMidRight = 0.1f *w/2 + xpos;
	float zMidFront = 0.1f * w/2 + zpos;
	float zMidBack = -0.1f *w/2 + zpos;
	float topY = 0.5f *t/2 + ypos;
	float botY = -0.5f *t/2 + ypos;
	float yMid = t/2 + ypos;
	float frontZ = 0.5f + zpos;
	float backZ = -0.5f + zpos;
	float tinggiAtap = 1;
	float atapWidth = w;

	float vertices[] = {
		// format position, tex coords
		// front
		xMidLeft, botY, zMidFront, 0.75, 0,  // 0
		xMidRight, botY, zMidFront, 1, 0,   // 1
		xMidRight,  yMid, zMidFront, 1, 0.25,   // 2
		xMidLeft,  yMid, zMidFront, 0.75f, 0.25f,  // 3
		leftX, yMid,frontZ,0.75f,0.5f, //4
		rightX,yMid,frontZ,1,0.5,//5
		leftX,topY,frontZ,0.75f,0.25f,//6
		rightX,topY,frontZ,1,0.25f,//7

		// right
		rightX,  topY,  frontZ, 0.5f, 0.5f,  // 8
		rightX, yMid,frontZ,0.25f, 0.5f,  //9
		rightX,  topY, backZ, 0.5, 0.25,  // 10
		rightX, yMid, backZ, 0.25, 0.25,  // 11
		xMidRight, botY,  zMidBack, 0.75, 0,  // 12
		xMidRight,botY,zMidFront,   1, 0,//13
		xMidRight, yMid, zMidBack,  0.75, 0.25,  // 14
		xMidRight, yMid, zMidFront, 1, 0.25,  // 15
		//left
		leftX,  topY,  frontZ, 0.5f, 0.5f,  // 16
		leftX, yMid,frontZ, 0.25f, 0.5f,  //17
		leftX,  topY, backZ, 0.5f, 0.25f,  // 18
		leftX, yMid, backZ, 0.25f, 0.25f,  // 19
		xMidLeft, botY,  zMidBack, 0.75, 0,  // 20
		xMidLeft,botY,zMidFront,   1, 0 ,//21
		xMidLeft, yMid, zMidBack,  0.75, 0.25,  // 22
		xMidLeft, yMid, zMidFront, 1, 0.25,  // 23


		// back
		xMidLeft, botY, zMidBack, 0, 0,  // 24
		xMidRight, botY, zMidBack, 1, 0,   // 25
		xMidRight,  yMid, zMidBack, 0.75, 0.75,   // 26
		xMidLeft,  yMid, zMidBack, 0, 0.75,  // 27
		leftX,    yMid   ,backZ,0,0.5f, //28
		rightX,    yMid      ,backZ,0,0,//29
		leftX,topY,backZ,0,0,//30
		rightX,topY,backZ,0,0,//31

		// upper
		rightX, topY,  frontZ, 1, 0.25,   // 32
		leftX, topY,  frontZ, 0.75, 0.25,  // 33
		leftX, topY, backZ, 0.75, 0,  // 34 // 
		rightX, topY, backZ, 1, 0,   // 35 //

		// bottom
		leftX, yMid, backZ, 0.75, 0, // 36
		rightX, yMid, backZ, 1, 0,  // 37
		rightX, yMid,  frontZ, 1, 0.25,  // 38
		leftX, yMid,  frontZ, 0.75, 0.25, // 39
		

		// atap
		(leftX + rightX) / 2,topY + tinggiAtap,(frontZ + backZ) / 2,0.5,1 //24



	};

	unsigned int indices[] = {
		// front
		0,  1,  2,  
		0,  2,  3, 
		4,  6,  5,
		6,  7, 5,
		//right
		9,8,10, //1 
		10,11,9,// 2
		14,12,13,//3
		13,14,15,//4 
		// left
		17,16,18, //1 
		18,19,17,
		22,20,21,
		21,22,23,
		//bawah 
		36,37,39,
		39,38,37,
		// atap
		32,33,34,
		32,34,35,
		//belakang
		24,  25,  26,
		24,  26,  29,
		28,  30,  29,
		30,  31, 29,
	};

	glGenVertexArrays(1, &VAOkakiTrone);
	glGenBuffers(1, &VBOkakiTrone);
	glGenBuffers(1, &EBOkakiTrone);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAOkakiTrone);

	glBindBuffer(GL_ARRAY_BUFFER, VBOkakiTrone);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOkakiTrone);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// define position pointer layout 0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	// define texcoord pointer layout 1
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Demo::BuildSlider(int size, float xpos, float ypos) {
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	glGenTextures(1, &textureSlider);
	glBindTexture(GL_TEXTURE_2D, textureSlider);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image("kuning.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float t = 2;
	float w = size;
	float rightX = (0.1f*w / 2) + xpos;
	float leftX = (-0.1f *w / 2) + xpos;
	float topY = 0.5f *t;
	float botY = -0.5f *t;
	float frontZ = 0.5f *w / 2;
	float backZ = -0.5f *w / 2;
	float tinggiAtap = 1;
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
		rightX, botY,  frontZ, 0, 1,  // 7

		// back
		leftX, botY, backZ, 0, 0, // 8 
		rightX,  botY, backZ, 0.4, 0, // 9
		leftX,   topY, backZ, 0, 1, // 10
		rightX,  topY, backZ, 0.4, 1, // 11

		// left
		leftX, botY, backZ, 0, 0, // 12
		leftX, botY,  frontZ, 0.4f, 0, // 13
		leftX,  topY,  frontZ, 0.4f, 1.0f, // 14
		leftX,  topY, backZ, 0, 1.0f, // 15

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
		(leftX + rightX) / 2,topY + tinggiAtap,(frontZ + backZ) / 2,0.5,1, //24
		rightX+5,botY,frontZ,1,0, //25
		rightX+5,botY,backZ,1,0//26



	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 9,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22,   // bottom
		26,4,26,4,25,5


	};

	glGenVertexArrays(1, &VAOSlider);
	glGenBuffers(1, &VBOSlider);
	glGenBuffers(1, &EBOSlider);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAOSlider);

	glBindBuffer(GL_ARRAY_BUFFER, VBOSlider);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOSlider);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// define position pointer layout 0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	// define texcoord pointer layout 1
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Demo::DrawVidioTrone()
{
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureTrone);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 0);
	

	glBindVertexArray(VAOkakiTrone); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glm::mat4 model;
	GLint modelLoc = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glDrawElements(GL_TRIANGLES, 48, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void Demo::DrawGedung(int index)
{
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureGedung[index]);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 0);

	glBindVertexArray(VAOGedung[index]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glDrawElements(GL_TRIANGLES, 48, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void Demo::DrawSlider()
{
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureSlider);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 0);

	glBindVertexArray(VAOSlider); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glDrawElements(GL_TRIANGLES, 48, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void Demo::DrawBench() {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureBench);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 0);

	glBindVertexArray(VAOBench); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void Demo::BuildRoadRoller(int index, float xpos, float zpos) {
	// load image into texture memory
	// ------------------------------
	// Load and create a texture 
	glGenTextures(1, &textureRoadRoller[index]);
	glBindTexture(GL_TEXTURE_2D, textureRoadRoller[index]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image("roadroller.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		// format position, tex coords
		// front
		-0.5+xpos, -0.3, 2+zpos, 0.75, 0.25,  // 0
		0.5 + xpos, -0.3,  2 + zpos, 1.0, 0.25,   // 1
		0.5 + xpos,  0.1,  2 + zpos, 1.0, 0.375,   // 2
		-0.5 + xpos,  0.1, 2 + zpos, 0.75, 0.375,  // 3

		// right bumper
		0.5 + xpos,  0.1,  2 + zpos, 0, 0.5,  // 4
		0.5 + xpos,  0.5, 1.2 + zpos, 0.25, 0.5,  // 5
		0.5 + xpos, -0.3, 1.2 + zpos, 0.25, 0.25,  // 6
		0.5 + xpos, -0.3,  2 + zpos,  0, 0.25,  // 7

		// right side
		0.5 + xpos,  0.5,  1.2 + zpos, 0, 0.5,  // 8
		0.5 + xpos,  0.5, -0.5 + zpos, 0.25, 0.5,  // 9
		0.5 + xpos, -0.3, -0.5 + zpos, 0.25, 0.25,  // 10
		0.5 + xpos, -0.3,  1.2 + zpos, 0, 0.25,  // 11

		// left side
		-0.5 + xpos,  0.5,  1.2 + zpos, 0.5, 0.5,  // 12
		-0.5 + xpos,  0.5, -0.5 + zpos, 0.75, 0.5,  // 13
		-0.5 + xpos, -0.3, -0.5 + zpos, 0.75, 0.25,  // 14
		-0.5 + xpos, -0.3,  1.2 + zpos, 0.5, 0.25,  // 15

		// back
		-0.5 + xpos, -0.3, -0.5 + zpos, 0.25, 0.25, // 16 
		0.5 + xpos,  -0.3, -0.5 + zpos, 0, 0.25, // 17
		0.5 + xpos,   0.5, -0.5 + zpos, 0.25, 0.5, // 18
		-0.5 + xpos,  0.5, -0.5 + zpos, 0, 0.5, // 19

		// left bumper
		-0.5 + xpos, 0.1,  2 + zpos,   0.5, 0.5, // 20
		-0.5 + xpos,  0.5,  1.2 + zpos, 0.75, 0.5, // 21
		-0.5 + xpos,  -0.3,  1.2 + zpos, 0.75, 0.25, // 22
		-0.5 + xpos,  -0.3,  2 + zpos,   0.5, 0.25, // 23

		// upper / front hood
		0.5 + xpos, 0.1,  2 + zpos,    1, 0.375,   // 24
		-0.5 + xpos, 0.1,  2 + zpos,   0.75, 0.375,  // 25
		-0.5 + xpos, 0.5,  1.2 + zpos, 0.75, 0.5,  // 26
		0.5 + xpos, 0.5,  1.2 + zpos,   1, 0.5,   // 27

		// bottom
		-0.5 + xpos, -0.3, -0.5 + zpos, 0, 0, // 28
		0.5 + xpos, -0.3, -0.5 + zpos, 1, 0,  // 29
		0.5 + xpos, -0.3,  2 + zpos, 1, 1,  // 30
		-0.5 + xpos, -0.3,  2 + zpos, 0, 1, // 31

	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right bumper
		8,  9,  10, 8,  10, 11,  // right side
		12, 14, 13, 12, 15, 14,  // left side
		16, 18, 17, 16, 19, 18,  // back
		20, 22, 21, 20, 23, 22,  // left bumper
		24, 25, 26, 24, 26, 27,  // upper
		28, 29, 30, 28, 31, 30,  // bottom
	};

	glGenVertexArrays(1, &VAORoadRoller[index]);
	glGenBuffers(1, &VBORoadRoller[index]);
	glGenBuffers(1, &EBORoadRoller[index]);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAORoadRoller[index]);

	glBindBuffer(GL_ARRAY_BUFFER, VBORoadRoller[index]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBORoadRoller[index]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// define position pointer layout 0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(0 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);

	// define texcoord pointer layout 1
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Demo::DrawRoadRoller(int index) {
	glUseProgram(shaderProgram);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureRoadRoller[index]);
	glUniform1i(glGetUniformLocation(this->shaderProgram, "ourTexture"), 0);

	glBindVertexArray(VAORoadRoller[index]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	
	glm::mat4 model;
	float jalan = abs(gerakRollerCoster);
	float posisi = index + 15;
	//gerak roller
	{
		if (jalan < 15 + posisi) {
			model = glm::translate(model, glm::vec3(0, 0, jalan));
		}
		else if (jalan >= 15 + posisi && jalan < 35 + posisi) {
			gerak = 1.55;
			model = glm::translate(model, glm::vec3((jalan-22), 0, 24));
			model = glm::rotate(model, gerak, glm::vec3(0, 1, 0));
		}
		else if (jalan >= 35 + posisi && jalan < 75 + posisi) {
			gerak = 3.15;
			model = glm::translate(model, glm::vec3(20, 0, gerakRollerCoster + 65));
			model = glm::rotate(model, gerak, glm::vec3(0, 1, 0));
		}
		else if (jalan >= 75 + posisi && jalan < 92 + posisi) {
			gerak = 4.7;
			model = glm::translate(model, glm::vec3(gerakRollerCoster + 100, 0, -17));
			model = glm::rotate(model, gerak, glm::vec3(0, 1, 0));
		}
		else if (jalan >= 92 +posisi && jalan < 115) {
			gerak = 6.3;
			model = glm::translate(model, glm::vec3(0, 0, jalan-115));
			model = glm::rotate(model, gerak, glm::vec3(0, 1, 0));
		}
		else {
			gerakRollerCoster = 0;
			model = glm::rotate(model, gerak, glm::vec3(0, 1, 0));
		}
	}
	model = glm::scale(model, glm::vec3(1, 1, 1));

	GLint modelLocKomidi = glGetUniformLocation(this->shaderProgram, "model");
	glUniformMatrix4fv(modelLocKomidi, 1, GL_FALSE, glm::value_ptr(model));

	glDrawElements(GL_TRIANGLES, 42, GL_UNSIGNED_INT, 0);

	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}

void Demo::BuildKomidiKotak(int index, float xplus, float xmin, float yplus, float ymin, float zplus, float zmin, float atap, float textureXpos1, float textureYpos1, float textureXpos2, float textureYpos2, float textureXpos3, float textureYpos3, float textureXpos4, float textureYpos4) {
	glGenTextures(1, &textureKomidi[index]);
	glBindTexture(GL_TEXTURE_2D, textureKomidi[index]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	unsigned char* image = SOIL_load_image("komidicolor.png", &width, &height, 0, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	float vertices[] = {
		// front
		xmin, ymin, zplus, textureXpos1, textureYpos1,  // 0
		xplus, ymin, zplus, textureXpos2, textureYpos2,   // 1
		xplus,  yplus, zplus, textureXpos3, textureYpos3,   // 2
		xmin,  yplus, zplus, textureXpos4, textureYpos4,  // 3

									// right
									xplus,  yplus,  zplus, textureXpos1, textureYpos1,  // 4
									xplus,  yplus, zmin, textureXpos2, textureYpos2,  // 5
									xplus, ymin, zmin, textureXpos3, textureYpos3,  // 6
									xplus, ymin,  zplus, textureXpos4, textureYpos4,  // 7

																// back
																xmin, ymin, zmin, textureXpos1, textureYpos1, // 8 
																xplus,  ymin, zmin, textureXpos2, textureYpos2, // 9
																xplus,   yplus, zmin, textureXpos3, textureYpos3, // 10
																xmin,  yplus, zmin, textureXpos4, textureYpos4, // 11

																						  // left
																						  xmin, ymin, zmin, textureXpos1, textureYpos1, // 12
																						  xmin, ymin, zplus, textureXpos2, textureYpos2, // 13
																						  xmin,  yplus,  zplus,textureXpos3, textureYpos3, // 14
																						  xmin,  yplus, zmin, textureXpos4, textureYpos4, // 15

																													// upper
																													xplus, yplus,  zplus, textureXpos1, textureYpos1,   // 16
																													xmin, yplus,  zplus, textureXpos2, textureYpos2,  // 17
																													xmin, yplus, zmin,textureXpos3, textureYpos3,  // 18
																													xplus, yplus, zmin,textureXpos4, textureYpos4,   // 19

																																				// bottom
																																				xmin, ymin, zmin, textureXpos1, textureYpos1, // 20
																																				xplus, ymin, zmin, textureXpos2, textureYpos2,  // 21
																																				xplus, ymin,  zplus, textureXpos3, textureYpos3,  // 22
																																				xmin, ymin,  zplus,textureXpos4, textureYpos4, // 23

	(xmin + xplus) / 2,yplus + atap,(zplus + zmin) / 2,0.5,1 //24
	};

	unsigned int indices[] = {
		0,  1,  2,  0,  2,  3,   // front
		4,  5,  6,  4,  6,  7,   // right
		8,  9,  10, 8,  10, 11,  // back
		12, 14, 13, 12, 15, 14,  // left
		16, 18, 17, 16, 19, 18,  // upper
		20, 22, 21, 20, 23, 22,   // bottom
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

void Demo::BuildKakiKincir(int index, float xplus, float xmin, float yplus, float ymin, float zplus, float zmin) {
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
	//CAMERA_SPEED = 0.0001f;
	//Change cam speed for debug
	CAMERA_SPEED = 0.005f;
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
	app.Start("Japari Park", 800, 600, false, false);
}