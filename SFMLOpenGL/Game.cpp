#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
			processInputs(event);
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	glMatrixMode(GL_PROJECTION); 
	//glLoadIdentity(); 
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	isRunning = true;
	m_drawNum = 1;
	//// initialise triangle
	//glBegin(GL_TRIANGLES);
	//{
	//	glColor3f(0.0f, 1.0f, 0.0f); 
	//	glVertex3f(0.2, 0.0, -2.0);
	//	glVertex3f(-2.0, -2.0, -2.0);
	//	glVertex3f(2.0, -2.0, -2.0);
	//}
	//glEnd();
	
}

void Game::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		isRunning = false;
	}
	sf::Event event;
	processInputs(event);

	cout << "Update up" << endl;
}

void Game::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	//isRunning = true;
	// initialise triangle
	switch (m_drawNum)
	{
	case 1: // Triangle 
		glBegin(GL_TRIANGLES);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		break;
	case 2: // Points 
		glBegin(GL_POINTS);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		break;
	case 3: // Lines
		glBegin(GL_LINES);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
			glVertex3f(-2.0, 2.0, -5.0);
		}
		break;
	case 4: // Line Strip
		glBegin(GL_LINE_STRIP);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		break;
	case 5: // Line Loop
		glBegin(GL_LINE_LOOP);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
			glVertex3f(-2.0, 2.0, -5.0);
		}
		break;
	case 6: // Triangle Strip
		glBegin(GL_TRIANGLE_STRIP);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
			glColor3f(100.0f, 0.0f, 0.0f);
			glVertex3f(0.0, 1, -5.0);
			glVertex3f(-1, -1, -5.0);
			glVertex3f(1, -1, -5.0);
		}
		break;
	case 7: // Triangle Fan
		glBegin(GL_TRIANGLE_FAN);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
			glColor3f(100.0f, 0.0f, 0.0f);
			glVertex3f(0.0, 1, -5.0);
			glVertex3f(-1, -1, -5.0);
			glVertex3f(1, -1, -5.0);
		}
		break;
	case 8: // Quads
		glBegin(GL_QUADS);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
			glVertex3f(2.0, 2.0, -5.0);
		}
		break;
	case 9: // Quad Strip
		glBegin(GL_QUAD_STRIP);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
			glVertex3f(2.0, 2.0, -5.0);
		}
		break;
	case 10: // Polygon
		glBegin(GL_POLYGON);
		{
			glColor3f(0.0f, 100.0f, 0.0f);
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
			glVertex3f(1.0, 1.0, -5.0);
			glVertex3f(-1, 2, -5);
		}
		break;
	default:
		break;
	}
	glEnd();
	//glLoadIdentity();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		int rotationAngle = 3.14/45;
		glRotatef(rotationAngle, 0, 0, 0);
	}
	glLoadIdentity();
	cout << "Draw up" << endl;
	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

void Game::processInputs(sf::Event & event)
{

	if (sf::Event::KeyPressed == event.type)
	{
		switch (event.key.code)
		{
		case sf::Keyboard::Num1: // Triangle
			m_drawNum = 1;
			break;
		case sf::Keyboard::Num2: // Points
			m_drawNum = 2;
			break;
		case sf::Keyboard::Num3: // Lines
			m_drawNum = 3;
			break;
		case sf::Keyboard::Num4: // Line Strip
			m_drawNum = 4;
			break;
		case sf::Keyboard::Num5: // Line Loop
			m_drawNum = 5;
			break;
		case sf::Keyboard::Num6: // Triangle Strip
			m_drawNum = 6;
			break;
		case sf::Keyboard::Num7: // Triangle Fan
			m_drawNum = 7;
			break;
		case sf::Keyboard::Num8: // Quads
			m_drawNum = 8;
			break;
		case sf::Keyboard::Num9: // Quad Strip
			m_drawNum = 9;
			break;
		case sf::Keyboard::Num0: // Polygon
			m_drawNum = 10;
			break;
		default:
			break;
		}
	}
}


