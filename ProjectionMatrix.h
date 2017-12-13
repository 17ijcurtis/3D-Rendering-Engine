#pragma once
class ProjectionMatrix {
private:
	float theta_y;
	float theta_x;
public:
	ProjectionMatrix(float theta_x, float theta_y) { this->theta_x = theta_x; this->theta_y = theta_y; }

	float get_theta_x() { return theta_x; }
	float get_theta_y() { return theta_y; }
};