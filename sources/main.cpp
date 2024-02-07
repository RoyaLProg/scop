#include <SDL2/SDL.h>
#include <iostream>
#include "../includes/types.hpp"

int main() {
	Screen screen;

	if ( screen.getFailed() ) {
		return 1;
	}

	std::vector<vec3>& points = screen.getPoints();

	points.emplace_back( 100, 100, 100 );
	points.emplace_back( 200, 100, 100 );
	points.emplace_back( 200, 200, 100 );
	points.emplace_back( 100, 200, 100 );

	points.emplace_back( 100, 100, 200 );
	points.emplace_back( 200, 100, 200 );
	points.emplace_back( 200, 200, 200 );
	points.emplace_back( 100, 200, 200 );

	screen.line( Connection( 0, 4 ) );
	screen.line( Connection( 1, 5 ) );
	screen.line( Connection( 2, 6 ) );
	screen.line( Connection( 3, 7 ) );
	screen.line( Connection( 0, 1 ) );
	screen.line( Connection( 1, 2 ) );
	screen.line( Connection( 2, 3 ) );
	screen.line( Connection( 3, 0 ) );
	screen.line( Connection( 4, 5 ) );
	screen.line( Connection( 5, 6 ) );
	screen.line( Connection( 6, 7 ) );
	screen.line( Connection( 7, 4 ) );

	vec3 c( 0, 0, 0 );

	for ( vec3& point : points ) {
		c.x += point.x;
		c.y += point.y;
		c.z += point.z;
	}

	c.x /= points.size();
	c.y /= points.size();
	c.z /= points.size();

	while ( true ) {
		for ( vec3& point : points ) {
			point.x -= c.x;
			point.y -= c.y;
			point.z -= c.z;

			point.rotate( 0.0f, 0.0f, 0.05f );

			point.x += c.x;
			point.y += c.y;
			point.z += c.z;
		}

		screen.show();
		screen.input();
		SDL_Delay( 1000 / 60 );
	}

	return 0;
}
