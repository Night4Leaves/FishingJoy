#pragma once
#include "cocos2d.h"

using namespace cocos2d;

typedef enum{
	k_Cannon_Type_1 = 0,
	k_Cannon_Type_2,
	k_Cannon_Type_3,
	k_Cannon_Type_4,
	k_Cannon_Type_5,
	k_Cannon_Type_6,
	k_Cannon_Type_7,
	k_Cannon_Count,
	k_Cannon_Invalid
}CannonType;

class Cannon:
	public CCNode{
public:
	Cannon();
	virtual ~Cannon();
	bool init(CannonType type = k_Cannon_Type_1);
	void setType(CannonType);
	CannonType getType(void);
	float getFireRange();
	static Cannon* create(CannonType type = k_Cannon_Type_1);
protected:
	CCArray* _cannonSprite;
	CannonType _type;
};