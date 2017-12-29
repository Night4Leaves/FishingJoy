#include "PanelLayer.h"
#include "GameScene.h"

bool PanelLayer::init(){
	do{
		CC_BREAK_IF(!CCLayer::init());

		CCSprite *pauseNormalBgSprite = CCSprite::createWithSpriteFrameName("ui_button_01.png");
		CCSprite *pauseSelectBgSprite = CCSprite::createWithSpriteFrameName("ui_button_02.png");
		
		CCMenuItemSprite* pauseMenuItem = CCMenuItemSprite::create(pauseNormalBgSprite,
		pauseSelectBgSprite,this,menu_selector(PanelLayer::pause));

		CCMenu* menu = CCMenu::create(pauseMenuItem,NULL);
		this->addChild(menu);
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		menu->setPosition(CCPointMake(winSize.width * 0.05,winSize.height * 0.95));


		_goldCounterLayer = GoldCounterLayer::create(0);
		this->addChild(_goldCounterLayer);
		_goldCounterLayer->setPosition(ccp(600, 17));

		ScheduleCountDown* countDown = ScheduleCountDown::create(this,10,true);
		this->addChild(countDown,0, 99);
		_scheduleLabel=CCLabelAtlas::create(CCString::createWithFormat("%d",10)->getCString(),"baoshiyu_shuzi_02-ipadhd.png",50,54,'0');
		addChild(_scheduleLabel);
		_scheduleLabel->setPosition(ccp(100,1200));
		return true;
	}while(0);
	return false;
}

void PanelLayer::setScheduleNumber(int number){
	_scheduleLabel->setString(CCString::createWithFormat("%d",number)->getCString());
}

void PanelLayer::scheduleTimeUp(){
	((GameScene *)getParent())->alterGold(200);
	ScheduleCountDown *countDown =(ScheduleCountDown *)getChildByTag(99);
	if(countDown->getLoop()==false){
		_scheduleLabel->setVisible(false);
	}
}

void PanelLayer::pause(CCObject *sender){
	//((GameScene *)this->getParent())->pause();
}