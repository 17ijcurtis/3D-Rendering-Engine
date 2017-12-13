#pragma once
#include <cmath>

#include "SFML\Graphics.hpp"

float dot_product(sf::Vector2f u, sf::Vector2f v);
float dot_product(sf::Vector3f u, sf::Vector3f v);
float magnitude(sf::Vector3f u);
float magnitude(sf::Vector2f u);
sf::Vector3f project(const sf::Vector3f& u, const sf::Vector3f& v);

sf::Vector3f rotate_u_about_axis(sf::Vector3f u, float angle, sf::Vector3f normalized_axis);
sf::Vector3f rotate(sf::Vector3f u, float swivel, float tilt);