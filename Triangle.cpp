#include "Triangle.h"

using namespace sf;
using namespace std;

Triangle::Triangle(Vector3f p1, Vector3f p2, Vector3f p3) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}


void Triangle::draw_triangle(ScreenMatrix* screen, sf::Vector2f proj1, sf::Vector2f proj2, sf::Vector2f proj3) {
	// proj1 - proj2
	if (screen->is_on_screen(proj1) || screen->is_on_screen(proj2)) {
		if ((int)(proj1.x - proj2.x) == 0 && (int)(proj1.y - proj2.y) == 0) {
			// they are in the same spot
			if (screen->is_on_screen(proj1)) {
				screen->setPixel(proj1.x, proj1.y, Color::White);
			}
		}
		else if ((int)abs(proj1.x - proj2.x) > (int)abs(proj1.y - proj2.y)) {
			float slope = (proj2.y - proj1.y) / (proj2.x - proj1.x);
			float intercept = proj1.y - slope * proj1.x;

			// if 1.x > 2.x
			if (proj1.x > proj2.x) {
				for (int i = proj2.x; i <= proj1.x; i++) {
					Vector2i pos(i, slope*i + intercept);
					if (screen->is_on_screen(pos)) {
						screen->setPixel(pos.x, pos.y, Color::White);
					}
				}
			}
			else if (proj1.x < proj2.x) {
				for (int i = proj1.x; i <= proj2.x; i++) {
					Vector2i pos(i, slope*i + intercept);
					if (screen->is_on_screen(pos)) {
						screen->setPixel(pos.x, pos.y, Color::White);
					}
				}
			}
		}
		else if ((int)abs(proj1.x - proj2.x) < (int)abs(proj1.y - proj2.y)) {
			float slope = (proj2.x - proj1.x) / (proj2.y - proj1.y);
			float intercept = proj1.x - slope * proj1.y;

			// if 1.x > 2.x
			if (proj1.y > proj2.y) {
				for (int i = proj2.y; i <= proj1.y; i++) {
					Vector2i pos(slope*i + intercept, i);
					if (screen->is_on_screen(pos)) {
						screen->setPixel(pos.x, pos.y, Color::White);
					}
				}
			}
			else if (proj1.y < proj2.y) {
				for (int i = proj1.y; i <= proj2.y; i++) {
					Vector2i pos(slope*i + intercept, i);
					if (screen->is_on_screen(pos)) {
						screen->setPixel(pos.x, pos.y, Color::White);
					}
				}
			}
		}
	}
}