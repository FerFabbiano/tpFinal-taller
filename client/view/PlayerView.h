#ifndef _PLAYER_VIEW_H_
#define _PLAYER_VIEW_H_

#include "PlayerAnimation.h"
#include "../entities/Entity.h"

class PlayerView : public Entity {
	public:
		PlayerView();
    ~PlayerView();
		void init(LTexture* texture, int x, int y);
		void stand(int xOffset, int yOffset);
		void move(int xDir, int yDir, int speed);
		void paint(double scaleW, double scaleH) override {}
    void paint(const Camera &camera, 
    	double scaleW, double scaleH) override;
    void setHead(LTexture* head);
		PlayerView(const PlayerView&) = delete;
    PlayerView& operator=(const PlayerView&) = delete;
	private:
	  Animation* animation;
	  LTexture* head;
	  SDL_Rect headFrame;
};

#endif
