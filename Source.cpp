#include "Game.h"

Game* g = 0;

int main(int argc, char* argv[]) {
	g = new Game();

	g->init("Hello World", 100, 100, 1440, 800, 0);

	while (g->running()) {
		g->handleEvents();
		g->update();
		g->render();
	}
	g->clean();

	return 0;
}