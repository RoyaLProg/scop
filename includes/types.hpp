#ifndef TYPES_HPP
#define TYPES_HPP

#include <SDL2/SDL.h>
#include <cstddef>
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

	float  x, y, z;
	float& operator[]( std::size_t );
};

class Matrix3;
class Object {
	std::vector<vec3>		_points;
	std::vector<Connection> _lines;
	std::vector<vec3>		_textureCoods;
	std::vector<vec3>		_normals;
	std::vector<Matrix3>	_faces;

   public:
	std::vector<vec3>&		 getPoints();
	std::vector<Connection>& getLines();
	std::vector<vec3>&		 getTextureCoords();
	std::vector<vec3>&		 getNormals();
	std::vector<Matrix3>&	 getFaces();

	Object();
};

class ObjectBuilder {
	Object* o;

	int addPoint( std::vector<std::string>& args );
	int addLine( std::vector<std::string>& args );
	int addTextureCoord( std::vector<std::string>& args );
	int addNormal( std::vector<std::string>& args );
	int addFace( std::vector<std::string>& args );

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

class Matrix3 {
   private:
	vec3 vecs[3];

   public:
	float getX1();
	float getX2();
	float getX3();
	float getY1();
	float getY2();
	float getY3();
	float getZ1();
	float getZ2();
	float getZ3();
	vec3  getV1();
	vec3  getV2();
	vec3  getV3();
	vec3* getVecs();
	void  setX1( float );
	void  setX2( float );
	void  setX3( float );
	void  setY1( float );
	void  setY2( float );
	void  setY3( float );
	void  setZ1( float );
	void  setZ2( float );
	void  setZ3( float );
	void  setV1( vec3 );
	void  setV2( vec3 );
	void  setV3( vec3 );
	void  setVecs( vec3[3] );
	void  setVecs( vec3, vec3, vec3 );

	vec3& operator[]( std::size_t );
};
#endif
