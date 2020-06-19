#include "PlayerView.h"
#include "AnimationTypes.h"

PlayerView::PlayerView() {}

void PlayerView::init(LTexture* texture, int x, int y) {
	this->x = x;
	this->y = y;
	animation = new PlayerAnimation(texture);
  animation->init();
	animation->set(FORWARD_STAND);
}

void PlayerView::move(int xDir, int yDir, int speed, bool isMoving) {
	if(isMoving){
		if(xDir == 0 && yDir < 0){
			y += yDir * speed;
			animation->set(BACK_WALK);
			headFrame = {48, 0, 16, 16};
		} else if (xDir == 0 && yDir > 0){
				y += yDir * speed;
				animation->set(FORWARD_WALK);
				headFrame = {0, 0, 16, 16};
		} else if (xDir < 0 && yDir == 0){
				x += xDir * speed;
				animation->set(LEFT_WALK);
				headFrame = {32, 0, 16, 16};
		} else if (xDir > 0 && yDir == 0){
				x += xDir * speed;
				animation->set(RIGHT_WALK);
				headFrame = {16, 0, 16, 16};
		}
	} else {
		if(xDir == 0 && yDir < 0){
			animation->set(BACK_STAND);
			headFrame = {48, 0, 16, 16};
		} else if (xDir == 0 && yDir > 0){
				animation->set(FORWARD_STAND);
				headFrame = {0, 0, 16, 16};
		} else if (xDir < 0 && yDir == 0){
				animation->set(LEFT_STAND);
				headFrame = {32, 0, 16, 16};;
		} else if (xDir > 0 && yDir == 0){
				animation->set(RIGHT_STAND);
				headFrame = {16, 0, 16, 16};
		}
	}
}

void PlayerView::paint(const Camera &camera, double scaleW, double scaleH) {
	animation->paint(x - camera.getX(), y - camera.getY(), 
		scaleW, scaleH);
	head->paint(x - camera.getX() + 2, y - camera.getY() - 9, 
		scaleW, scaleH, &headFrame);
}

void PlayerView::setHead(LTexture* head) {
	this->head = head;
}

PlayerView::~PlayerView() {
	if(animation == nullptr) return;
  delete animation;
}
