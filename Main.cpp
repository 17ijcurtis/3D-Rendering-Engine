#include <SFML\Graphics.hpp>

#include "Render3D.h"

using namespace sf;

int main()
{
	const float FPS = 60.0f; //The desired FPS. (The number of updates each second).

	RenderWindow window(VideoMode(800, 800, 32), "Runescape");
	window.setFramerateLimit(FPS);

	ScreenMatrix* screen = new ScreenMatrix(800, 800);
	ProjectionMatrix* proj = new ProjectionMatrix(0.785f, 0.785f);
	Render3D* renderEngine = new Render3D(screen, proj);

	Vector3f* particle1 = new Vector3f(1.0f, 0.0f, 1.0f);
	Vector3f* particle2 = new Vector3f(1.2f, -1.0f, 0.0f);
	Vector3f* particle3 = new Vector3f(0.7f, 0.0f, 1.0f);

	renderEngine->push_vector(particle1);
	renderEngine->push_vector(particle2);
	renderEngine->push_vector(particle3);

	Event ev;
	while (window.isOpen())
	{
		//Handle events
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::Closed) window.close();
		}

		// Move stuff
		particle1->y += 0.01f;
		particle2->y += 0.01f;
		particle3->y += 0.01f;

		// Draw stuff
		screen->clear();
		renderEngine->draw_vectors();
		window.draw(*screen->getVertexArray());
		window.display();
	}

	delete screen;

	return 0;
}