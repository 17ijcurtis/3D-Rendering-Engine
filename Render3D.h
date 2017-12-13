#pragma once
#include <vector>

#include "SFML\Graphics.hpp"
#include "ScreenMatrix.h"
#include "ProjectionMatrix.h"

#include "MathFunc.h"
#include "Shape.h"
#include "Triangle.h"


class Render3D {
private:
	ScreenMatrix* screen;
	ProjectionMatrix* proj;

	std::vector<sf::Vector3f*> vector_list;
	
	sf::Vector3f position;
	sf::Vector3f axis;
	sf::Vector2f cam_angle;

	// for projection to screen;
	float backview;

	const sf::Vector2f* null_vector = new sf::Vector2f(-1.0f, -1.0f);

public:
	Render3D(ScreenMatrix* screen, ProjectionMatrix* proj);

	void push_vector(sf::Vector3f* v);
	void draw_vectors();

	sf::Vector2f project_vector(const sf::Vector3f& v, bool& is_visible);
};