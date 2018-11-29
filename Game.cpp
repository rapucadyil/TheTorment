#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int w, int h, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		win = SDL_CreateWindow(title, xpos, ypos, w, h, flags);

		if (win != 0) {
			ren = SDL_CreateRenderer(win, -1, 0);

			if (ren != 0) {
				SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	m_bRunning = true;
	SDL_Surface* tempSurface = SDL_LoadBMP("bubba.bmp");

	tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	SDL_QueryTexture(tex, NULL, NULL, &srcRect.w, &srcRect.h);

	destRect.x = srcRect.x = 0;
	destRect.y = srcRect.y = 0;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

	return true;
}

void Game::render()
{
	SDL_RenderClear(ren);
	SDL_RenderCopy(ren, tex, &srcRect, &destRect);
	SDL_RenderPresent(ren);
}

void Game::update()
{
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::clean()
{
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();
}
