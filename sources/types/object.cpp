#include "../../includes/types.hpp"

Object::Object() {}

std::vector<vec3>& Object::getPoints() {
	return _points;
}

std::vector<Connection>& Object::getLines() {
	return _lines;
}

std::vector<vec3>& Object::getTextureCoords() {
	return _textureCoods;
}

std::vector<vec3>& Object::getNormals() {
	return _normals;
}

std::vector<Matrix3>& Object::getFaces() {
	return _faces;
}
