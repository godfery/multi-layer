#ifndef _MAINSCENE1_H_
#define  _MAINSCENE1_H_
#include "cocos2d.h"
#include "CLayer1.h"
#include "CLayer2.h"
#include "CLayer3.h"

USING_NS_CC;
using namespace cocos2d;
class MainScene1 :public cocos2d::Scene
{
public:
	
	MainScene1(void);
	~MainScene1(void);
	virtual bool init();
	CREATE_FUNC(MainScene1);
	

	void menuCallback(Object* pSender);

private:
	Layer1* _layer1;
	Layer2* _layer2;
	Layer3* _layer3;
	int curLayerPos;

	LayerMultiplex* _layerMuticomplex;
};
#endif

