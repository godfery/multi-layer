#include "CMainScene.h"

USING_NS_CC;



MainScene1::MainScene1(void)
{
	//_layer1=NULL;
	//_layer2=NULL;
	//_layer3=NULL;
	curLayerPos=0;
}


MainScene1::~MainScene1(void)
{

}

bool MainScene1::init()
{
	bool bRet=false;
	do 
	{
		if(!Scene::init()) {
			return bRet;	
		}

		_layer1=Layer1::create();
		_layer2=Layer2::create();
		_layer3=Layer3::create();

		_layerMuticomplex=LayerMultiplex::create(_layer1,_layer2,_layer3,NULL);
		this->addChild(_layerMuticomplex);

			Size visibleSize =Director::getInstance()->getVisibleSize();
		Point origin = Director::getInstance()->getVisibleOrigin();

		MenuItemImage *pCloseItem1 = MenuItemImage::create(
			"w_b.png",
			"w_b.png",
			CC_CALLBACK_1(MainScene1::menuCallback,this));
		pCloseItem1->setContentSize(CCSizeMake( visibleSize.width/3,pCloseItem1->getContentSize().height));
		//pCloseItem1->setPosition(Point(0,0));
		MenuItemImage *pCloseItem2 = MenuItemImage::create(
			"r_b.png",
			"r_b.png",
			CC_CALLBACK_1(MainScene1::menuCallback,this));

		pCloseItem2->setContentSize(CCSizeMake( visibleSize.width/3,pCloseItem2->getContentSize().height));
		//pCloseItem2->setContentSize(CCSizeMake(80, visibleSize.width/3));
		//pCloseItem2->setPosition(Point(origin.y+visibleSize.width/3,origin.y+visibleSize.width/3*2));
		MenuItemImage *pCloseItem3 = MenuItemImage::create(
			"g_b.png",
			"g_b.png",
			CC_CALLBACK_1(MainScene1::menuCallback,this));
		//pCloseItem3->setContentSize(CCSizeMake(80, visibleSize.width/3));
		//pCloseItem3->setPosition(Point(origin.y+visibleSize.width/3*2,visibleSize.width));
		// create menu, it's an autorelease object
		pCloseItem1->setTag(0);
		pCloseItem2->setTag(1);
		pCloseItem3->setTag(2);
		Menu* pMenu = Menu::create(pCloseItem1, pCloseItem2, pCloseItem3, NULL);
		pMenu->alignItemsHorizontallyWithPadding(-1);
		//pMenu->setPosition(visibleSize.width/2,300);
		pMenu->setPosition(visibleSize.width/2,25);
		this->addChild(pMenu, 1);
		bRet=true;
	} while (0);
	return bRet;
}

void MainScene1::menuCallback(Object* pSender)
{
	int item=((MenuItemImage*)pSender)->getTag();
	if (item!=curLayerPos)
	{
		_layerMuticomplex->switchTo(item);
		curLayerPos=item;
	}
}


