#include <stdexcept>
#include "../../includes/types.hpp"

vec3::vec3() {
	x = y = z = 1.0;
}

vec3::vec3( float x, float y, float z ) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void vec3::rotate( float x, float y, float z ) {
	// rotate the point around the x y and z axis

	float x1 = this->x;
	float y1 = this->y;
	float z1 = this->z;

	this->x =
		x1 * cos( y ) * cos( z ) - y1 * cos( y ) * sin( z ) + z1 * sin( y );
	this->y = x1 * ( cos( x ) * sin( z ) + sin( x ) * sin( y ) * cos( z ) ) +
			  y1 * ( cos( x ) * cos( z ) - sin( x ) * sin( y ) * sin( z ) ) -
			  z1 * sin( x ) * cos( y );
	this->z = x1 * ( sin( x ) * sin( z ) - cos( x ) * sin( y ) * cos( z ) ) +
			  y1 * ( sin( x ) * cos( z ) + cos( x ) * sin( y ) * sin( z ) ) +
			  z1 * cos( x ) * cos( y );
}

float& vec3::operator[]( std::size_t idx ) {
	switch ( idx ) {
		case 0:
			return this->x;
		case 1:
			return this->y;
		case 2:
			return this->z;
		default:
			throw std::out_of_range(
				"vector index cannot be negative or superior to 2" );
	}
}
