#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include "../../includes/types.hpp"

ObjectBuilder::ObjectBuilder() {
	this->o = new Object();
}

ObjectBuilder::~ObjectBuilder() {
	delete this->o;
}

std::vector<std::string> split( std::string s, std::string delimiter ) {
	std::vector<std::string> v;
	size_t					 pos = 0;

	while ( ( pos = s.find( delimiter ) ) != std::string::npos ) {
		v.push_back( s.substr( 0, pos ) );
		s.erase( 0, pos + delimiter.length() );
	}

	v.push_back( s );

	return v;
}

int ObjectBuilder::addPoint( std::vector<std::string>& args ) {
	std::vector<vec3>& points = this->o->getPoints();

	if ( args.size() != 4 )
		return ( 1 );

	args.erase( args.begin() );

	points.push_back( vec3( std::stof( args[0] ), std::stof( args[1] ),
							std::stof( args[2] ) ) );

	return 0;
}

bool is_comment( std::string s ) {
	for ( const char c : s ) {
		if ( isspace( c ) )
			continue;
		if ( c == '#' )
			return true;
		return false;
	}
	return false;
}

int ObjectBuilder::build( std::string path ) {
	std::ifstream file( path );

	if ( !file.is_open() ) {
		return 1;
	}

	std::string line;

	while ( std::getline( file, line ) ) {
		if ( is_comment( line ) )
			continue;
		if ( line.find( "mtllib" ) != std::string::npos )
			continue;
		if ( line.find( "usemtl" ) != std::string::npos )
			continue;
		std::vector<std::string> args = split( line, " " );
		if ( !args[0].compare( "v" ) ) {
			if ( this->addPoint( args ) )
				std::cout << "ERROR : vertex is invalid" << std::endl;
		} else if ( !args[0].compare( "l" ) ) {
			if ( this->addLine( args ) )
				std::cout << "ERROR : " << std::endl;
		} else if ( !args[0].compare( "vt" ) ) {
			if ( this->addTextureCoord( args ) )
				std::cout << "ERROR : texture vertex is invalid" << std::endl;
		} else if ( !args[0].compare( "vn" ) ) {
			if ( this->addNormal( args ) )
				std::cout << "ERROR : vertex's norlmal is invalid" << std::endl;
		} else if ( !args[0].compare( "f" ) ) {
			if ( this->addFace( args ) )
				std::cout << "ERROR : face is invalid" << std::endl;
		} else if ( !args[0].compare( "o" ) || !args[0].compare("s") ) {
			continue;
		} else {
			std::cout << "ERROR : unreconnized line : " << line << std::endl;
			return ( 1 );
		}
	}
	return ( 0 );
}

int ObjectBuilder::addLine( std::vector<std::string>& args ) {
	std::vector<Connection>& lines = this->o->getLines();

	if ( args.size() != 3 )
		return ( 1 );

	args.erase( args.begin() );

	lines.push_back( Connection( std::stof( args[0] ), std::stof( args[1] ) ) );

	return 0;
}

int ObjectBuilder::addTextureCoord( std::vector<std::string>& args ) {
	std::vector<vec3>& texturesCoords = this->o->getTextureCoords();

	if ( args.size() != 4 )
		return ( 1 );

	args.erase( args.begin() );

	texturesCoords.push_back(
		vec3( std::stof( args[0] ), std::stof( args[1] ), stof( args[2] ) ) );

	return ( 0 );
}

int ObjectBuilder::addNormal( std::vector<std::string>& args ) {
	std::vector<vec3>& normals = this->o->getNormals();

	if ( args.size() != 4 )
		return ( 1 );

	args.erase( args.begin() );

	normals.push_back(
		vec3( std::stof( args[0] ), std::stof( args[1] ), stof( args[2] ) ) );
	return ( 0 );
}

int ObjectBuilder::addFace( std::vector<std::string>& args ) {
	std::vector<Matrix3>& faces = this->o->getFaces();

	if ( args.size() != 4 )
		return ( 1 );

	args.erase( args.begin() );
	Matrix3 m;

	for ( int i = 0; i < 3; i++ ) {
		const std::vector<std::string> values = split( args[i + 1], "/" );
		m[i].x								  = std::stof( values[0] );
		m[i].y								  = std::stof( values[1] );
		m[i].z								  = std::stof( values[2] );
	}

	faces.push_back( m );
	return ( 0 );
}
