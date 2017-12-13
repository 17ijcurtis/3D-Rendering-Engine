#include "ScreenMatrix.h"

using namespace sf;

ScreenMatrix::ScreenMatrix(int width, int height) {
	this->width = width;
	this->height = height;
	screen = new sf::VertexArray(sf::Points, width*height);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			(*screen)[width*i + j].position = Vector2f(j, i);
			(*screen)[width*i + j].color = Color::Black;
		}
	}
}


void ScreenMatrix::setPixel(int x, int y, Color c) {
	(*screen)[y * width + x].color = c;
}


bool ScreenMatrix::is_on_screen(Vector2i pos) {
	if (pos.x < 0 || pos.x >= width || pos.y < 0 || pos.y >= height) {
		return false;
	}
	return true;
}

bool ScreenMatrix::is_on_screen(Vector2f pos) {
	if ((int)pos.x < 0 || (int)pos.x >= width || (int)pos.y < 0 || (int)pos.y >= height) {
		return false;
	}
	return true;
}


VertexArray* ScreenMatrix::getVertexArray() const {
	return screen;
}

void ScreenMatrix::clear() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			(*screen)[width*i + j].color = Color::Black;
		}
	}
}