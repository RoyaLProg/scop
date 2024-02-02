#include <iostream>
#include "../../includes/types.hpp"

Screen::Screen() {

	_failed = false;
	if ( SDL_Init( SDL_INIT_VIDEO ) )
	{
		std::cout << "Screen initialisation failed : " << SDL_GetError() << " \n";
		_failed = true;
	}
	if ( SDL_CreateWindowAndRenderer( 640 * 2, 480 * 2, 0, &window,
	                                  &renderer ) )
	{
		std::cout << "Screen window initialisation failed : " << SDL_GetError() << " \n";
		_failed = true;
	}
	if ( SDL_RenderSetScale( renderer, 2, 2 ) )
	{
		std::cout << "Screen scale initialisation failed : " << SDL_GetError() << " \n";
		_failed = true;	
	}

	return;
}

void Screen::pixel( float x, float y ) {
	points.emplace_back( x, y, 0.0 );
}

void Screen::line( Connection &c ) {
	lines.push_back(c);
}

void Screen::line( const Connection &c ) {
	lines.push_back(c);
}

void Screen::line( int a, int b ) {
	Connection c(a, b);

	lines.push_back(c);
}

void Screen::show() {
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
	SDL_RenderClear( renderer );

	SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

	std::cout << "lines : " << lines.size() << " points : " << points.size() << "\n";
	
	for (Connection &c : lines)
		SDL_RenderDrawLineF(renderer, points[c.a].x, points[c.a].y, points[c.b].x, points[c.b].y);

	SDL_RenderPresent( renderer );
	// SDL_Delay(1000);
}

void Screen::input() {
	while ( SDL_PollEvent( &e ) ) {
		if ( e.type == SDL_QUIT ) {
			SDL_DestroyRenderer( renderer );
			SDL_DestroyWindow( window );
			SDL_Quit();
			exit( 0 );
		}
	}
}

void Screen::clear() {
	points.clear();
	lines.clear();
}

SDL_Event Screen::getEvent() {
	return e;
}
SDL_Window* Screen::getWindow() {
	return window;
}
SDL_Renderer* Screen::getRenderer() {
	return renderer;
}

bool Screen::getFailed() {
	return _failed;
}

std::vector<vec3>& Screen::getPoints() {
	return points;
}

std::vector<Connection>& Screen::getLines() {
	return lines;
}
