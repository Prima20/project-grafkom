#pragma once
#include "RenderEngine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <SOIL/SOIL.h>

class Demo :
	public RenderEngine
{
public:
	Demo();
	~Demo();
private:
	GLuint VBOGedung, VAOGedung, EBOGedung, textureGedung;
	GLuint VBOkakiTrone, VAOkakiTrone, EBOkakiTrone, textureTrone;
	GLuint VBOKepalaTrone, VAOKepalaTrone, EBOKepalaTrone, textureKepalaTrone;
	GLuint shaderProgram, VBO, VAO, EBO, texture, VBO2, VAO2, EBO2, texture2;
	GLuint VBOSkybox, VAOSkybox, EBOSkybox, textureSkybox;
	GLuint VBOBuilding, VAOBuilding, EBOBuilding, textureBuilding;
	GLuint VBOSlider, VAOSlider, EBOSlider, textureSlider;
	float viewCamX, viewCamY, viewCamZ, upCamX, upCamY, upCamZ, posCamX, posCamY, posCamZ, CAMERA_SPEED, fovy;
	virtual void Init();
	virtual void DeInit();
	void BuildGedung(int size,float xpos,float ypos);
	void DrawGedung();
	void BuildSlider(int size, float xpos, float ypos);
	void DrawSlider();
	void BuildKolam(int size, float xpos, float ypos);
	void DrawKolam();
	virtual void Update(double deltaTime);
	virtual void Render();
	virtual void ProcessInput(GLFWwindow *window);
	void BuildColoredCube();
	void BuildColoredPlane();
	void BuildBench();
	void BuildVidioTrone(int size, float xpos, float ypos);

	void BuildSkybox();
	void DrawColoredCube();
	void DrawColoredPlane();
	void DrawVidioTrone();
	void DrawBench();
	void DrawSkybox();
	void MoveCamera(float speed);
	void StrafeCamera(float speed);
	void RotateCamera(float speed);

	void InitCamera();
};

