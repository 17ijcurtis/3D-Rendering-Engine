#pragma once

/*
	State class
	key for states:

	000 - Splash Screen?
	001 - Menu?
*/

class State {
private:
	int state;
	int prev_state;
};