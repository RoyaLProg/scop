#ifndef TYPES_HPP
#define TYPES_HPP

#include <SDL2/SDL.h>
#include <string>
#include <vector>

class Connection {
   public:
	int a, b;

	Connection( int a = 0, int b = 0 );
};

class vec3 {
   public:
	vec3();
	vec3( float, float, float );

	void rotate( float x = 1, float y = 1, float z = 1 );

	float x, y, z;
};

class Object {
	std::vector<vec3>		points;
	std::vector<Connection> lines;
	std::vector<vec3>		textureCoods;
	std::vector<vec3>		normals;

   public:
	std::vector<vec3>&		 getPoints();
	std::vector<Connection>& getLines();
	std::vector<vec3>&		 getTextureCoords();
	std::vector<vec3>&		 getNormals();

	Object();
};

class ObjectBuilder {
	Object* o;

	int addPoint( std::vector<std::string> args );
	int addLine( std::vector<std::string> args );
	int addTextureCoord( std::vector<std::string> args );
	int addNormal( std::vector<std::string> args );

   public:
	~ObjectBuilder();
	ObjectBuilder();

	int	   build( std::string path );
	Object getObject();
};

class Screen {
   private:
	SDL_Event				e;
	SDL_Window*				window;
	SDL_Renderer*			renderer;
	std::vector<vec3>		points;
	std::vector<Connection> lines;

	bool _failed;

   public:
	SDL_Event	  getEvent();
	SDL_Window*	  getWindow();
	SDL_Renderer* getRenderer();
	bool		  getFailed();

	std::vector<vec3>&		 getPoints();
	std::vector<Connection>& getLines();

	Screen();

	void pixel( float x, float y );
	void line( Connection& c );
	void line( const Connection& c );
	void line( int a, int b );
	void show();
	void input();
	void clear();
};

class Vertex {
	float x, y, z, w;
};

class textureCoods {
	float u, v, w;
};

#endif
