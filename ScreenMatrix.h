#pragma once


#include <iostream>
#include <cmath>

#include "SFML\Graphics.hpp"


class ScreenMatrix {
private:
	int width;
	int height;

	sf::VertexArray* screen;

public:
	ScreenMatrix(int width, int height);

	void setPixel(int x, int y, sf::Color c);

	int get_height() { return height; }
	int get_width() { return width; }

	bool is_on_screen(sf::Vector2i pos);
	bool is_on_screen(sf::Vector2f pos);

	sf::VertexArray* getVertexArray() const;
	void clear();
};