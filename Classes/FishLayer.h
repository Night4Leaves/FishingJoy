#pragma once
#include "cocos2d.h"
#include "Fish.h"

#define FISH_MAX_COUNT 50

using namespace cocos2d;

class FishLayer:
	public CCLayer{
public:
	FishLayer();
	virtual ~FishLayer();
	bool init();
	CREATE_FUNC(FishLayer)
	void addFish(float dt);
<<<<<<< HEAD
	CCArray* getFishes();
	void resetFish(Fish* fish);
=======
>>>>>>> parent of ec185bd... install FishNet
protected:
	CCArray* _fishes;
};