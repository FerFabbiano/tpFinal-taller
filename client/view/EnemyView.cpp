#include "EnemyView.h"
#include <iostream>

EnemyView::EnemyView(int x, int y, Animation *animation) {
	this->x = x;
	this->y = y;
	this->animation = animation;
	animation->set(FORWARD_STAND);
}

/*void EnemyView::init(int x, int y, Animation animation, SdlWindow &window){
	this->x = x;
	this->y = y;
	this->speed = 10;
	this->animation = animation;
	animation.init("assets/playerView.png", window);
	animation.set(FORWARD_STAND);
}*/

/*void PlayerView::stand(int xOffset, int yOffset){
	if(xOffset == 0 && yOffset < 0){
		animation.set(BACK_STAND);
	} else if (xOffset == 0 && yOffset > 0){
		animation.set(FORWARD_STAND);
	} else if (xOffset < 0 && yOffset == 0){
		animation.set(LEFT_STAND);
	} else if (xOffset > 0 && yOffset == 0){
		animation.set(RIGHT_STAND);
	}
}

void PlayerView::walk(int xOffset, int yOffset){
	if(xOffset == 0 && yOffset < 0){
		this->y += yOffset * speed;
		animation.set(BACK_WALK);
	} else if (xOffset == 0 && yOffset > 0){
		this->y += yOffset * speed;
		animation.set(FORWARD_WALK);
	} else if (xOffset < 0 && yOffset == 0){
		this->x += xOffset * speed;
		animation.set(LEFT_WALK);
	} else if (xOffset > 0 && yOffset == 0){
		this->x += xOffset * speed;
		animation.set(RIGHT_WALK);
	}

	if(this->x < 0)
		this->x = 0;
	if(this->y < 0)
		this->y = 0;
	if(this->x + 25 > 58 * 16)
		this->x = 58 * 16 - 25;
	if(this->y + 48 > 47 * 16)
		this->y = 47 * 16 - 48;
}*/

void EnemyView::move(int xDir, int yDir, int speed){
	if(xDir == 0 && yDir < 0){
		y += yDir * speed;
		animation->set(BACK_WALK);
	} else if (xDir == 0 && yDir > 0){
		y += yDir * speed;
		animation->set(FORWARD_WALK);
	} else if (xDir < 0 && yDir == 0){
		x += xDir * speed;
		animation->set(LEFT_WALK);
	} else if (xDir > 0 && yDir == 0){
		x += xDir * speed;
		animation->set(RIGHT_WALK);
	}
}

void EnemyView::paint(const Camera &camera, double scaleW, double scaleH){
	if (!camera.isInCameraRange(x, y)) return;

  animation->paint(x - camera.getX(), y - camera.getY(), 
  	scaleW, scaleH);
}

EnemyView::~EnemyView(){
	delete animation;
}
