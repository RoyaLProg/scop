#include "../../includes/types.hpp"

Object::Object() {}

std::vector<vec3>& Object::getPoints() {
	return points;
}

std::vector<Connection>& Object::getLines() {
	return lines;
}

std::vector<vec3>& Object::getTextureCoords() {
	return textureCoods;
}

std::vector<vec3>& Object::getNormals() {
	return normals;
}
