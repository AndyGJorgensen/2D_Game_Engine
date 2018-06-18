#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 framestart;
	int frametime;

	game = new Game();
	game->init("GameWindow", 800, 640, false);


	while (game->running())
	{
		framestart = SDL_GetTicks();



		game->handleEvents();
		game->update();
		game->render();

		frametime = SDL_GetTicks() - framestart;
		if (frametime < frameDelay) {
			SDL_Delay(frameDelay - frametime);


		}
	}

	game->clean();
	return 0;
}