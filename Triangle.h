#pragma once

#include <cmath>

#include "SFML\Graphics.hpp"
#include "ScreenMatrix.h"

class Triangle {
private:
	sf::Vector3f p1;
	sf::Vector3f p2;
	sf::Vector3f p3;

public:
	Triangle(sf::Vector3f p1, sf::Vector3f p2, sf::Vector3f p3);

	sf::Vector3f get_p1() { return p1; }
	sf::Vector3f get_p2() { return p2; }
	sf::Vector3f get_p3() { return p3; }

	void set_p1(sf::Vector3f p1) { this->p1 = p1; }
	void set_p2(sf::Vector3f p1) { this->p2 = p2; }
	void set_p3(sf::Vector3f p1) { this->p3 = p3; }

	void draw_triangle(ScreenMatrix* screen, sf::Vector2f proj1, sf::Vector2f proj2, sf::Vector2f proj3);
};