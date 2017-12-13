#include "Shape.h"

using namespace sf;
using namespace std;

void draw_triangle(ScreenMatrix*& screen, Vector2f p1, Vector2f p2, Vector2f p3) {
	// draw line between p1 and p2
	

	if (p2.x - p1.x != 0) {
		float slope12 = (p2.y - p1.y) / (p2.x - p1.x);
		float inter12 = p2.y - slope12 * p2.x;

		if (p2.x < p1.x) {

			int pos = p2.x;
			for (int i = pos; i <= p1.x; i++) {

				cout << "(" << i << "," << slope12 * i + inter12 << ")" << endl;
				screen->setPixel(i, slope12 * (i) + inter12, Color::White);
			}
		}
		else if (p2.x > p1.x) {
			int pos = p1.x;
			for (int i = pos; i <= p2.x; i++) {
				screen->setPixel(pos, slope12 * pos + inter12, Color::White);
			}
		}
	}
	else if (p2.y - p1.y != 0) {
		float slope12 = (p2.x - p1.x) / (p2.y - p1.y);
		float inter12 = p2.x - slope12 * p2.y;

		if (p2.y < p1.y) {
			int pos = p2.y;
			for (int i = pos; i <= p1.y; i++) {
				screen->setPixel(slope12 * pos + inter12, pos, Color::White);
			}
		}
		else if (p2.y > p1.y) {
			int pos = p1.y;
			for (int i = pos; i <= p2.y; i++) {
				screen->setPixel(slope12 * pos + inter12, pos, Color::White);
			}
		}

	}

}