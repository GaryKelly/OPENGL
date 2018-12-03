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
	cout << "1: Triangle\n";
	cout << "2: Points\n";
	cout << "3: Lines\n";
	cout << "4: Line Strip\n";
	cout << "5: Line Loop\n";
	cout << "6: triangle strip\n";
	cout << "7: triangle fan\n";
	cout << "8: Quad\n";
	cout << "9: Quad Strip\n";
	cout << "0: Polygon\n";
	cout << "---------------------------\n";
	cout << "R: Rotate\n";
	cout << "S: Scale\n";
	cout << "T: Translate\n";
	cout << "---------------------------\n";

	glPointSize(10.0f);
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
		glColor3f(1.0f, 0, 0);
		glVertex3f(-2.0, -2.0, -6.0);
		glColor3f(0, 0, 1.0f);
		glVertex3f(2.0, -2.0, -7.0);
	}
	glEnd();
	glEndList();
	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_POINTS);
	{
		glColor3f(0.0f, 100.0f, 0.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(-2.0, -2.0, -6.0);
		glColor3f(0.0f, 1.0f, 1.0f);
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
		glColor3f(100.0f, 0.0f, 0.0f);
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
		glColor3f(0, 1, 1);
		glVertex3f(-2.0, -2.0, -6.0);
		glColor3f(1, 1, 0);
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
		glColor3f(100.0f, 0.0f, 0.0f);
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
		glColor3f(1, 0, 1);
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
		glColor3f(0.0f, 100.0f, 100.0f);
		glVertex3f(-2.0, -2.0, -5.0);
		glColor3f(100.0f, 0.0f, 0.0f);
		glVertex3f(2.0, -2.0, -6.0);
		glColor3f(100.0f, 100.0f, 0.0f); 
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
		glColor3f(1.0f, 0, 0);
		glVertex3f(2.0, -2.0, -7.0);
		glVertex3f(1.0, 1.0, -5.0);
		glColor3f(0, 0, 1);
		glVertex3f(-1, 2, -5);
	}
	glEnd();
	glEndList();
	glFinish();
	
}

void Game::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		isRunning = false;
	}
	sf::Event event;
	processInputs(event);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		if (m_rotate < 360)
		{
			m_rotate += .05;
		}
		else
		{
			m_rotate = 0;
		}
	}
	else
	{
		m_rotate = 0;
	}

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) // rotate 
		{
			glRotatef(m_rotate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) // translate
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //scale
		{
			glScalef(1.5, m_scale, 1.5);
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
			glRotatef(m_rotate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(1.5, m_scale, 1.5);
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
			glRotatef(m_rotate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(1.5, m_scale, 1.5);
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
			glRotatef(m_rotate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(1.5, m_scale, 1.5);
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
			glRotatef(m_rotate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(1.5, m_scale, 1.5);
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
			glRotatef(m_rotate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(1.5, m_scale, 1.5);
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
			glRotatef(m_rotate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(1.5, m_scale, 1.5);
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
			glRotatef(m_rotate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(1.5, m_scale, 1.5);
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
			glRotatef(m_rotate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(1.5, m_scale, 1.5);
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
			glRotatef(m_rotate, 0, 0, 1);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
		{
			glTranslatef(m_translate, 0, 0);
			glCallList(m_drawNum);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			glScalef(1.5, m_scale, 1.5);
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
	
	window.display();
}

void Game::unload()
{

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


