#ifndef _BAR_H_
#define _BAR_H_

#include <SDL2/SDL.h>
#include "../sdl/LTexture.h"
#include "Entity.h"

#define BAR_X 55
#define BAR_W 106
#define BAR_H 11

class Bar : public Entity {
	private:
		SDL_Rect destRect;
		LTexture* texture;

	public:
		Bar();
		void init(LTexture* texture, int y);
		void update(int value, int maxValue);
		void paint(const Camera &camera, 
			double scaleW, double scaleH) override {};
		void paint(double scaleW, double scaleH) override;
};

#endif
