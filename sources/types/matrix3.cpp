#include <stdexcept>
#include "../../includes/types.hpp"

vec3& Matrix3::operator[]( std::size_t idx ) {
	if ( idx > 2 )
		throw std::out_of_range(
			"vector index cannot be negative or superior to 2" );
	return vecs[idx];
}

vec3 Matrix3::getV1() {
	return vecs[0];
}

vec3 Matrix3::getV2() {
	return vecs[1];
}

vec3 Matrix3::getV3() {
	return vecs[2];
}

vec3* Matrix3::getVecs() {
	return vecs;
}

float Matrix3::getX1() {
	return vecs[0][0];
}

float Matrix3::getX2() {
	return vecs[1][0];
}

float Matrix3::getX3() {
	return vecs[2][0];
}

float Matrix3::getY1() {
	return vecs[0][1];
}

float Matrix3::getY2() {
	return vecs[1][1];
}

float Matrix3::getY3() {
	return vecs[2][1];
}

float Matrix3::getZ1() {
	return vecs[0][2];
}

float Matrix3::getZ2() {
	return vecs[1][2];
}

float Matrix3::getZ3() {
	return vecs[2][2];
}

void Matrix3::setV1( vec3 v ) {
	vecs[0] = v;
}

void Matrix3::setV2( vec3 v ) {
	vecs[1] = v;
}

void Matrix3::setV3( vec3 v ) {
	vecs[2] = v;
}

void Matrix3::setVecs( vec3 vs[3] ) {
	vecs[0] = vs[0];
	vecs[1] = vs[1];
	vecs[2] = vs[2];
}

void Matrix3::setX1( float x ) {
	vecs[0][0] = x;
};
void Matrix3::setX2( float x ) {
	vecs[1][0] = x;
};
void Matrix3::setX3( float x ) {
	vecs[2][0] = x;
};
void Matrix3::setY1( float x ) {
	vecs[0][1] = x;
};
void Matrix3::setY2( float x ) {
	vecs[1][1] = x;
};
void Matrix3::setY3( float x ) {
	vecs[2][1] = x;
};
void Matrix3::setZ1( float x ) {
	vecs[0][2] = x;
};
void Matrix3::setZ2( float x ) {
	vecs[1][2] = x;
};
void Matrix3::setZ3( float x ) {
	vecs[2][2] = x;
};
