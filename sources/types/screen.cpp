#include <iostream>
#include "../../includes/types.hpp"

Screen::Screen() {
	if ( SDL_Init( SDL_INIT_VIDEO ) )
		goto failed;
	if ( SDL_CreateWindowAndRenderer( 640 * 2, 480 * 2, 0, &window,
	                                  &renderer ) )
		goto failed;
	if ( SDL_RenderSetScale( renderer, 2, 2 ) )
		goto failed;

	goto end;

failed:
	std::cout << "Screen initialisation failed : " << SDL_GetError() << " \n";
	_failed = true;

end:
	return;
}

void Screen::pixel( float x, float y ) {
	SDL_FPoint p = { .x = x, .y = y };

	points.emplace_back( p );
}

void Screen::line( float x1, float y1, float x2, float y2 ) {
	SDL_RenderDrawLineF( renderer, x1, y1, x2, y2 );
}

void Screen::show() {
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
	SDL_RenderClear( renderer );

	SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
	SDL_RenderDrawPointsF( renderer, points.data(), points.size() );
	SDL_RenderPresent( renderer );
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
