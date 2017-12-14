#pragma once
#include "cocos2d.h"
#include "Fish.h"

using namespace cocos2d;

class FishLayer:
	public CCLayer{
public:
	FishLayer();
	virtual ~FishLayer();
	virtual bool init();
	CREATE_FUNC(FishLayer)
};