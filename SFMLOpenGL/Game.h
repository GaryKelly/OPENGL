#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();
	int m_drawNum;
	const int primatives = 1;
	int index;
	double m_roatate = 90 * (3.1415 / 180);
	double m_translate = 1.5;
	double m_scale = 1;
	//create triangle
	GLuint VertexArray;
	void processInputs(sf::Event &event);
	

	// // Uncomment for Part 2
	// // ********************
	// const int primatives;

	//GLuint index;
	//Clock clock;
	//Time elapsed;

	//float rotationAngle = 0.0f;
	// // ********************
};