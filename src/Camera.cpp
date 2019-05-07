#include "Camera.h"

Camera::Camera() {
	WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	Front = glm::vec3(0.0f, 0.0f, -1.0f);
	Position = glm::vec3(0.0f, 0.0f, 2.5f);
	Up = glm::vec3(0.0f, 1.0f, 0.0f);

	update();
}

Camera::~Camera() {}

void Camera::setPitch(float pitch) {
	Pitch = pitch;
}

void Camera::setYaw(float yaw) {
	Yaw = yaw;
}

void Camera::setPosition(glm::vec3 position) {
	Position = position;
}

void Camera::moveForward(float const distance) {
	Position += Front * distance;
}
void Camera::moveBack(float const distance) {
	Position -= Front * distance;
}
void Camera::moveRight(float const distance) {
	Position += glm::normalize(glm::cross(Front, Up)) * distance;
}
void Camera::moveLeft(float const distance) {
	Position -= glm::normalize(glm::cross(Front, Up)) * distance;
}

glm::mat4 Camera::GetViewMatrix() {
	return glm::lookAt(Position, Position + Front, Up);
}

void Camera::update() {
	glm::vec3 front;
	front.x = cos(glm::radians(Yaw))*cos(glm::radians(Pitch));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(Yaw))*cos(glm::radians(Pitch));
	Front = glm::normalize(front);

	Right = glm::normalize(glm::cross(Front, WorldUp));
	Up = glm::normalize(glm::cross(Right, Front));
}

void Camera::rotate(float const xoffset, float const yoffset) {
	//欧拉角更新
	Yaw += xoffset * MouseSensitivity;
	Pitch += yoffset * MouseSensitivity;
	//处理边界
	if (Pitch > 89.0f) Pitch = 89.0f;
	if (Pitch < -89.0f) Pitch = -89.0f;

	update();
}

