#include "view/SDLAdapter.h"


void SDLAdapter::initGraphics(string windowTitle, int width, int height) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL could not initialize!\nSDL_Error:\t" << SDL_GetError() << endl;
	}

	this->window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		cout << "Window could not be created!\nSDL_Error:\t" << SDL_GetError() << endl;
	}

	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {
		cout << "Renderer could not be created!\nSDL_Error:\t" << SDL_GetError() << endl;
	}
}

void SDLAdapter::quitGraphics() {
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);

	this->window = nullptr;
	this->renderer = nullptr;

	SDL_Quit();
}

void SDLAdapter::render() {
	SDL_RenderPresent(this->renderer);
}

void SDLAdapter::setDrawColor(RGBAColor color) {
	SDL_SetRenderDrawColor(this->renderer, color.getR(), color.getG(), color.getB(), color.getA());
}

void SDLAdapter::clear() {
	SDL_RenderClear(this->renderer);
}

void SDLAdapter::drawPixel(int xpos, int ypos) {
	SDL_RenderDrawPoint(renderer, xpos, ypos);
}

void SDLAdapter::drawLine(int x1, int y1, int x2, int y2) {
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

Graphics::GraphicsCommand SDLAdapter::getUserInput(char * specifier) {
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) return Graphics::QUIT;
		
		else if (e.type == SDL_KEYDOWN) {
			/*else if ( e.key.keysym.sym >= 0 && e.key.keysym.sym < 256 )
				keys[e.key.keysym.sym] = true;*/

			if (e.key.keysym.sym == SDLK_ESCAPE) return Graphics::QUIT;
		}

		else if (e.type == SDL_KEYUP) {
			/*if ( e.key.keysym.sym >= 0 && e.key.keysym.sym < 256 )
				keys[e.key.keysym.sym] = false;*/
		}
	}

	return Graphics::NONE;
}
