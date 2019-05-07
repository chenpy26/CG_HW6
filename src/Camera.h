#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class Camera {
public:
	Camera();
	~Camera();
	//获得view
	glm::mat4 GetViewMatrix();
	//四个方向的移动
	void moveForward(float const distance);
	void moveBack(float const distance);
	void moveRight(float const distance);
	void moveLeft(float const distance);
	//视角变换
	void rotate(float const pitch, float const yaw);

	glm::vec3 Position;

	void setYaw(float yaw);
	void setPitch(float pitch);
	void setPosition(glm::vec3 position);

private:
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;

	float MouseSensitivity = 0.1;

	void update();

	float Yaw;
	float Pitch;
};

#endif