#include "MathFunc.h"

using namespace std;
using namespace sf;

float dot_product(sf::Vector2f u, sf::Vector2f v) {
	return u.x * v.x + u.y * v.y;
}

float dot_product(sf::Vector3f u, sf::Vector3f v) {
	return u.x * v.x + u.y * v.y + u.z * v.z;
}




float magnitude(sf::Vector2f u) {
	return sqrt(pow(u.x, 2) + pow(u.y, 2));
}

float magnitude(sf::Vector3f u) {
	return sqrt(pow(u.x, 2) + pow(u.y, 2) + pow(u.z, 2));
}





sf::Vector3f project(const sf::Vector3f& u, const sf::Vector3f& v) {
	float coeff = dot_product(u, v) / (pow(magnitude(v), 2));
	return sf::Vector3f(v.x * coeff, v.y * coeff, v.z * coeff);
}


sf::Vector3f rotate_u_about_axis(sf::Vector3f u, float angle, sf::Vector3f normalized_axis) {
	sf::Vector3f out(0, 0, 0);
	out.x = u.x *(cos(angle) + pow(normalized_axis.x, 2) * (1 - cos(angle)))
		+ u.y * (normalized_axis.x*normalized_axis.y * (1 - cos(angle)) - normalized_axis.z*sin(angle))
		+ u.z * (normalized_axis.x* normalized_axis.z * (1 - cos(angle)) + normalized_axis.y*sin(angle));
	out.y = u.x * (normalized_axis.y * normalized_axis.x * (1 - cos(angle)) + normalized_axis.z* sin(angle))
		+ u.y * (cos(angle) + pow(normalized_axis.y, 2) * (1 - cos(angle)))
		+ u.z * (normalized_axis.y * normalized_axis.z * (1 - cos(angle)) - normalized_axis.x * sin(angle));
	out.z = u.x * (normalized_axis.z * normalized_axis.x * (1 - cos(angle)) - normalized_axis.y*sin(angle))
		+ u.y * (normalized_axis.z* normalized_axis.y * (1 - cos(angle)) + normalized_axis.x * sin(angle))
		+ u.z * (cos(angle) + pow(normalized_axis.z, 2) * (1 - cos(angle)));
	return out;
}

sf::Vector3f rotate(sf::Vector3f u, float swivel, float tilt) {
	// swivel
	sf::Vector3f out(0, 0, 0);

	//out = rotate_u_about_axis(u, tilt, normalized);
	// rotates to make it on the x,z plane
	out = rotate_u_about_axis(u, swivel, Vector3f(0, 0, 1.0f));
	out = rotate_u_about_axis(out, tilt, Vector3f(1.0f, 0, 0));


	return out;
}