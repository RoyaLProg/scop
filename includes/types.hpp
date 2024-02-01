#ifndef TYPES_HPP
#define TYPES_HPP

#include <SDL2/SDL.h>
#include <vector>

class Screen {
   private:
	SDL_Event               e;
	SDL_Window*             window;
	SDL_Renderer*           renderer;
	std::vector<SDL_FPoint> points;

	bool _failed;

   public:
	SDL_Event     getEvent();
	SDL_Window*   getWindow();
	SDL_Renderer* getRenderer();
	bool          getFailed();

	std::vector<SDL_FPoint> getPoints();

	Screen();
	void pixel( float x, float y );
	void line( float x1, float y1, float x2, float y2 );
	void show();
	void input();
	void clear();
	// void	line();
};

class vec3 {
   public:
	vec3();
	vec3( float, float, float );

	void rotate( float x = 1, float y = 1, float z = 1 );

	float x, y, z;
};

class Vertex {
	float x, y, z, w;
};

class textureCoods {
	float u, v, w;
};

struct connection {
	int a, b;
};

#endif
