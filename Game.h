#ifndef __Game__
#define __Game__
#include <SDL.h>
class Game {

public:
	Game() { }
	~Game() { }

	bool init(const char* title, int xpos, int ypos, int w, int h, int flags);

	void render();
	void update();
	void handleEvents();
	void clean();

	bool running() { return m_bRunning; }

private:

	SDL_Window* win;
	SDL_Renderer* ren;

	SDL_Texture* tex;
	SDL_Rect srcRect;
	SDL_Rect destRect;

	bool m_bRunning;
};


#endif // !__Game__

