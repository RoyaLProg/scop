#include "../../includes/types.hpp"

vec3::vec3() {
	x = y = z = 1.0;
}

vec3::vec3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void vec3::rotate(float x, float y, float z) {
	float rad = 0;

	rad = x;
	this->y = std::cos(rad) * this->y - std::sin(rad) * this->z;
	this->z = std::sin(rad) * this->y - std::cos(rad) * this->z; 

	rad = y;
	this->x = std::cos(rad) * this->x - std::sin(rad) * this->z;
	this->z = -std::sin(rad) * this->x - std::cos(rad) * this->z;

	rad = z;
	this->x = std::cos(rad) * this->x - std::sin(rad) * this->y;
	this->y = std::sin(rad) * this->x - std::cos(rad) * this->y;
}
