#include "Render3D.h"

using namespace std;
using namespace sf;

Render3D::Render3D(ScreenMatrix* screen, ProjectionMatrix* proj) {
	this->screen = screen;
	this->proj = proj;

	position = Vector3f(0, 0, 0);

	// swivle, tilt
	cam_angle = Vector2f(0, 0);
	axis = Vector3f(sin(cam_angle.x)* cos(cam_angle.y), cos(cam_angle.x) * cos(cam_angle.y), sin(cam_angle.y));

	backview = 1.0f / tan(proj->get_theta_y() / 2);
}

void Render3D::push_vector(Vector3f* v){
	vector_list.push_back(v);
}

bool sameSign(float num1, float num2)
{
	if (num1 > 0 && num2 < 0)
		return false;
	if (num1 < 0 && num2 > 0)
		return false;
	return true;
}

void Render3D::draw_vectors() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		cam_angle += Vector2f(0, 0.1f);
		if (cam_angle.y >= 1.57f) cam_angle.y = 1.57f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		cam_angle += Vector2f(0, -0.1f);
		if (cam_angle.y <= -1.57f) cam_angle.y = -1.57f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		cam_angle += Vector2f(0.1f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		cam_angle += Vector2f(-0.1f, 0);
	}

	axis = Vector3f(sin(cam_angle.x)* cos(cam_angle.y), cos(cam_angle.x) * cos(cam_angle.y), sin(cam_angle.y));

	Vector2f p1;
	Vector2f p2;
	Vector2f p3;

	for (int i = 0; i < vector_list.size(); i++) {
		bool isvisible = true;
		Vector2f proj = project_vector(*(vector_list[i]), isvisible);

		float x_proj = proj.x * screen->get_width() / 2;
		float y_proj = proj.y * screen->get_height() / 2;

		if (i == 0) {
			p1 = Vector2f(screen->get_width() / 2 + x_proj, screen->get_height() / 2 - y_proj);
		}
		else if (i == 1) {
			p2 = Vector2f(screen->get_width() / 2 + x_proj, screen->get_height() / 2 - y_proj);
		}
		else if (i == 2) {
			p3 = Vector2f(screen->get_width() / 2 + x_proj, screen->get_height() / 2 - y_proj);
		}

		if (screen->is_on_screen(proj) && isvisible) {
			if (!(abs(proj.x) > 1 || abs(proj.y) > 1)) {

				screen->setPixel(screen->get_width() / 2 + x_proj, screen->get_height() / 2 - y_proj, sf::Color::White);
			}
		}
	}

	Triangle tri(Vector3f(0,0,0), Vector3f(0, 0, 0), Vector3f(0, 0, 0));
	tri.draw_triangle(screen, p1, p2, p3);

	//draw_triangle(screen, p1, p2, p3);
}

sf::Vector2f Render3D::project_vector(const sf::Vector3f& v, bool& is_visible) {
	// project onto axis
	Vector3f projection_axis = project(v, axis);

	//if (axis.y / projection_axis.y < 0) { return *null_vector;  }

	// if projection axis is negative we dont care
	if (sameSign(projection_axis.x, axis.x) && sameSign(projection_axis.y, axis.y) && sameSign(projection_axis.y, axis.y)) {
		is_visible = true;
	}
	else {
		is_visible = false;
	}
	// Get difference from vectors
	Vector3f offset = v - projection_axis;

	// correct rotation
	offset = rotate(offset, cam_angle.x, -cam_angle.y);

	//scale down the vector
	float scaling_coefficient = (backview) / (backview + magnitude(projection_axis));

	offset.x *= scaling_coefficient;
	offset.y *= scaling_coefficient;
	offset.z *= scaling_coefficient;

	Vector2f proj(offset.x, offset.z);

	return proj;
}
