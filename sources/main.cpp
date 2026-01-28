#include <SDL2/SDL.h>
#include "../includes/types.hpp"

int main( int ac, char** av ) {
	if (ac != 2) return 1;

	Screen screen;

	if ( screen.getFailed() ) {
		return 1;
	}

	// std::vector<vec3>& points = screen.getPoints();

	//	points.emplace_back( 100, 100, 100 );
	//	points.emplace_back( 200, 100, 100 );
	//	points.emplace_back( 200, 200, 100 );
	//	points.emplace_back( 100, 200, 100 );
	//
	//	points.emplace_back( 100, 100, 200 );
	//	points.emplace_back( 200, 100, 200 );
	//	points.emplace_back( 200, 200, 200 );
	//	points.emplace_back( 100, 200, 200 );
	//
	//	screen.line( Connection( 0, 4 ) );
	//	screen.line( Connection( 1, 5 ) );
	//	screen.line( Connection( 2, 6 ) );
	//	screen.line( Connection( 3, 7 ) );
	//	screen.line( Connection( 0, 1 ) );
	//	screen.line( Connection( 1, 2 ) );
	//	screen.line( Connection( 2, 3 ) );
	//	screen.line( Connection( 3, 0 ) );
	//	screen.line( Connection( 4, 5 ) );
	//	screen.line( Connection( 5, 6 ) );
	//	screen.line( Connection( 6, 7 ) );
	//	screen.line( Connection( 7, 4 ) );

	// HEAD
	//  points.emplace_back(130, 240, 0);
	//  points.emplace_back(230, 290, 25);
	//  points.emplace_back(230, 290, -25);
	//  points.emplace_back(230, 190, 25);
	//  points.emplace_back(230, 190, -25);
	//
	//  screen.line(0, 1);
	//  screen.line(0, 2);
	//  screen.line(0, 3);
	//  screen.line(0, 4);
	//  screen.line(3, 4);
	//  screen.line(2, 4);
	//  screen.line(1, 2);
	//  screen.line(1, 3);
	//
	//  //BODY
	//
	//  points.emplace_back(330, 290, 25);
	//  points.emplace_back(330, 290, -25);
	//  points.emplace_back(330, 190, 25);
	//  points.emplace_back(330, 190, -25);
	//  points.emplace_back(380, 260, 25);
	//  points.emplace_back(380, 260, -25);
	//  points.emplace_back(380, 210, 25);
	//  points.emplace_back(380, 210, -25);
	//
	//  screen.line(4, 8);
	//  screen.line(1, 5);
	//  screen.line(2, 6);
	//  screen.line(3, 7);
	//  screen.line(7, 8);
	//  screen.line(6, 8);
	//  screen.line(5, 6);
	//  screen.line(5, 7);
	//  screen.line(11, 12);
	//  screen.line(10, 12);
	//  screen.line(9, 10);
	//  screen.line(9, 11);
	//  screen.line(8, 12);
	//  screen.line(7, 11);
	//  screen.line(6, 10);
	//  screen.line(5, 9);
	//
	//  //TAIL
	//
	//  points.emplace_back(390, 240, 25);
	//  points.emplace_back(390, 240, -25);
	//  points.emplace_back(430, 160, 0);
	//  points.emplace_back(430, 310, 0);
	//
	//  screen.line(13, 15);
	//  screen.line(13, 16);
	//  screen.line(14, 15);
	//  screen.line(14, 16);
	//  screen.line(12, 15);
	//  screen.line(11, 15);
	//  screen.line(10, 16);
	//  screen.line(9, 16);

	// vec3 c( 0, 0, 0 );
	//
	// for ( vec3& point : points ) {
	// 	c.x += point.x;
	// 	c.y += point.y;
	// 	c.z += point.z;
	// }
	//
	// c.x /= points.size();
	// c.y /= points.size();
	// c.z /= points.size();
	// while ( true ) {
	// 	for ( vec3& point : points ) {
	// 		point.x -= c.x;
	// 		point.y -= c.y;
	// 		point.z -= c.z;
	//
	// 		point.rotate( 0.0f, 0.05f, 0.00f );
	//
	// 		point.x += c.x;
	// 		point.y += c.y;
	// 		point.z += c.z;
	// 	}
	//
	// 	screen.show();
	// 	screen.input();
	// 	SDL_Delay( 1000 / 30 );
	// }

	ObjectBuilder ob;
	ob.build( av[1] );
	return 0;
}
