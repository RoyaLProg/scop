#include <SDL2/SDL.h>
#include <iostream>
#include "../includes/types.hpp"

int main() {
	Screen screen;

	if ( screen.getFailed() )
		return false;

	std::vector<vec3> points;
	points.emplace_back( 100, 100, 100 ), points.emplace_back( 200, 100, 100 ),
	    points.emplace_back( 200, 200, 100 ),
	    points.emplace_back( 100, 200, 100 ),

	    points.emplace_back( 100, 100, 200 ),
	    points.emplace_back( 200, 100, 200 ),
	    points.emplace_back( 100, 200, 200 ),
	    points.emplace_back( 200, 200, 200 );

	vec3 c( 0, 0, 0 );

	for ( vec3& point : points ) {
		c.x += point.x;
		c.y += point.y;
		c.z += point.z;
	}

	c.x /= points.size();
	c.y /= points.size();
	c.z /= points.size();

	std::vector<connection> connections;
	connections.push_back( { .a = 0, .b = 4} ),
	connections.push_back( { .a = 1, .b = 5} ),
	connections.push_back( { .a = 2, .b = 6} ),
	connections.push_back( { .a = 3, .b = 7} );

	while ( true ) {
		for ( vec3& point : points ) {
			point.x -= c.x;
			point.y -= c.y;
			point.z -= c.z;

			point.rotate( 0.002f, 0.001f, 0.004f );

			point.x += c.x;
			point.y += c.y;
			point.z += c.z;

			screen.pixel( point.x, point.y );
		}

		for ( struct connection& c : connections )
		{
			screen.line( points[c.a].x, points[c.a].y, points[c.b].x,
			      points[c.b].y );
		}

		screen.show();
		screen.clear();
		screen.input();
	}

	return 0;
}
