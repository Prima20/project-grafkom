#pragma once
#include "RenderEngine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <SOIL/SOIL.h>

#define OBJECTNUMBER 25

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
	GLuint shaderKincir, VBOKincir[OBJECTNUMBER], VAOKincir[OBJECTNUMBER], EBOKincir[OBJECTNUMBER], textureKincir[OBJECTNUMBER];
	GLuint shaderkKincir, VBOkKincir[OBJECTNUMBER], VAOkKincir[OBJECTNUMBER], EBOkKincir[OBJECTNUMBER], texturekKincir[OBJECTNUMBER];
	GLuint VBORoadRoller[OBJECTNUMBER], VAORoadRoller[OBJECTNUMBER], EBORoadRoller[OBJECTNUMBER], textureRoadRoller[OBJECTNUMBER];
	GLuint shaderKomidi, VBOKomidi[OBJECTNUMBER], VAOKomidi[OBJECTNUMBER], EBOKomidi[OBJECTNUMBER], textureKomidi[OBJECTNUMBER];
	float viewCamX, viewCamY, viewCamZ, upCamX, upCamY, upCamZ, posCamX, posCamY, posCamZ, CAMERA_SPEED, fovy;
	float angle = 0, gerak = 1.5, gerakRollerCoster = 0;
	virtual void Init();
	virtual void DeInit();
	void BuildGedung(int size,float xpos,float ypos);
	void DrawGedung();
	void BuildSlider(int size, float xpos, float ypos);
	void DrawSlider();
	void BuildKolam(int size, float xpos, float ypos);
	void BuildKomidiKotak(int index, float xplus, float xmin, float yplus, float ymin, float zplus, float zmin, float atap);
	void DrawKolam();
	void DrawKomidiKotak(int index, float xpos, float ypos, float zpos);
	virtual void Update(double deltaTime);
	virtual void Render();
	virtual void ProcessInput(GLFWwindow *window);
	void BuildColoredCube();
	void BuildColoredPlane();
	void BuildBench(float xpos, float zpos);
	void BuildVidioTrone(int size, float xpos, float ypos, float zpos);
	void BuildRoadRoller(int index, float xpos, float zpos);
	void BuildSkybox();
	void BuildKincir(int index, float xplus, float xmin, float ypos, float ymin, float zplus, float zmin);
	void BuildKakiKincir(int index, float xplus, float xmin, float yplus, float ymin, float zplus, float zmin);
	void DrawColoredCube();
	void DrawColoredPlane();
	void DrawVidioTrone();
	void DrawBench();
	void DrawRoadRoller(int index);
	void DrawSkybox();
	void DrawKincir(int index, float xpos, float ypos, float zpos);
	void DrawKakiKincir(int index, float xpos, float ypos, float zpos);
	void MoveCamera(float speed);
	void StrafeCamera(float speed);
	void RotateCamera(float speed);

	void InitCamera();
};

