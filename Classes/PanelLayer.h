#pragma once
#include "cocos2d.h"
#include "GoldCounterLayer.h"
#include "ScheduleCounterDelegate.h"
#include "ScheduleCountDown.h"
#include "StaticData.h"
#include "MenuLayer.h"

using namespace cocos2d;

class PanelLayer:
	public CCLayer,public ScheduleCounterDelegate{
public:
	CREATE_FUNC(PanelLayer);
	CC_SYNTHESIZE_READONLY(GoldCounterLayer*, _goldCounterLayer, GoldCounterLayer);
	virtual bool init();
	void setScheduleNumber(int number);
	void scheduleTimeUp();
	void pause(CCObject *sender);
protected:
	CCLabelAtlas* _scheduleLabel;
};