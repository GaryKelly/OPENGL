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
	index = glGenLists(primatives);
	//generate list of obects
	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -6.0);
		glVertex3f(2.0, -2.0, -7.0);
	}
	glEnd();
	glEndList();
	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_POINTS);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -6.0);
		glVertex3f(2.0, -2.0, -7.0);
	}
	glEnd();
	glEndList();
	glNewList(index+2, GL_COMPILE);
	glBegin(GL_LINES);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -6.0);
		glVertex3f(2.0, -2.0, -7.0);
		glVertex3f(-2.0, 2.0, -5.0);
	}
	glEnd();
	glEndList();
	glNewList(index+3, GL_COMPILE);
	glBegin(GL_LINE_STRIP);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -6.0);
		glVertex3f(2.0, -2.0, -7.0);
	}
	glEnd();
	glEndList();
	glNewList(index+4, GL_COMPILE);
	glBegin(GL_LINE_LOOP);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -6.0);
		glVertex3f(2.0, -2.0, -7.0);
		glVertex3f(-2.0, 2.0, -5.0);
	}
	glEnd();
	glEndList();
	glNewList(index+5, GL_COMPILE);
	glBegin(GL_TRIANGLE_STRIP);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -6.0);
		glVertex3f(2.0, -2.0, -7.0);
		glColor3f(100.0f, 0.0f, 0.0f);
		glVertex3f(0.0, 1, -5.0);
		glVertex3f(-1, -1, -7.0);
		glVertex3f(1, -1, -6.0);
	}
	glEnd();
	glEndList();
	glNewList(index+6, GL_COMPILE);
	glBegin(GL_TRIANGLE_FAN);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -7.0);
		glVertex3f(2.0, -2.0, -6.0);
		glColor3f(100.0f, 0.0f, 0.0f);
		glVertex3f(0.0, 1, -7.0);
		glVertex3f(-1, -1, -5.0);
		glVertex3f(1, -1, -6.0);
	}
	glEnd();
	glEndList();
	glNewList(index+7, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.5);
		glVertex3f(2.0, -2.0, -6.0);
		glVertex3f(2.0, 2.0, -7.0);
	}
	glEnd();
	glEndList();
	glNewList(index+8, GL_COMPILE);
	glBegin(GL_QUAD_STRIP);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.5);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -6.0);
		glVertex3f(2.0, 2.0, -7.0);
	}
	glEnd();
	glEndList();
	glNewList(index+9, GL_COMPILE);
	glBegin(GL_POLYGON);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -6.0);
		glVertex3f(2.0, -2.0, -7.0);
		glVertex3f(1.0, 1.0, -5.0);
		glVertex3f(-1, 2, -5);
	}
	glEnd();
	glEndList();
	
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			glRotatef(m_roatate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(m_scale, m_scale, m_scale);
			glCallList(m_drawNum);
		}
		else
		{
			glCallList(m_drawNum);
		}
		break;
	case 2: // Points 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			glRotatef(m_roatate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(m_scale, m_scale, m_scale);
			glCallList(m_drawNum);
		}
		else
		{
			glCallList(m_drawNum);
		}
		break;
	case 3: // Lines
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			glRotatef(m_roatate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(m_scale, m_scale, m_scale);
			glCallList(m_drawNum);
		}
		else
		{
			glCallList(m_drawNum);
		}
		break;
	case 4: // Line Strip
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			glRotatef(m_roatate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(m_scale, m_scale, m_scale);
			glCallList(m_drawNum);
		}
		else
		{
			glCallList(m_drawNum);
		}
		break;
	case 5: // Line Loop
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			glRotatef(m_roatate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(m_scale, m_scale, m_scale);
			glCallList(m_drawNum);
		}
		else
		{
			glCallList(m_drawNum);
		}
		break;
	case 6: // Triangle Strip
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			glRotatef(m_roatate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(m_scale, m_scale, m_scale);
			glCallList(m_drawNum);
		}
		else
		{
			glCallList(m_drawNum);
		}
		break;
	case 7: // Triangle Fan
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			glRotatef(m_roatate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(m_scale, m_scale, m_scale);
			glCallList(m_drawNum);
		}
		else
		{
			glCallList(m_drawNum);
		}
		break;
	case 8: // Quads
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			glRotatef(m_roatate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(m_scale, m_scale, m_scale);
			glCallList(m_drawNum);
		}
		else
		{
			glCallList(m_drawNum);
		}
		break;
	case 9: // Quad Strip
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			glRotatef(m_roatate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(m_scale, m_scale, m_scale);
			glCallList(m_drawNum);
		}
		else
		{
			glCallList(m_drawNum);
		}
		break;
	case 10: // Polygon
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			glRotatef(m_roatate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(m_scale, m_scale, m_scale);
			glCallList(m_drawNum);
		}
		else
		{
			glCallList(m_drawNum);
		}
		break;
	default:
		break;
	}

	//glLoadIdentity();

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


