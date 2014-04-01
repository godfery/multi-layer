#include "TestScene.h"

Scene* TestScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TestScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool TestScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	/*auto uiLayer = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("DemoLogin/DemoLogin.ExportJson");    
	
	addChild(uiLayer);

	*/

	/*_layer1=Layer1::create();
		_layer2=Layer2::create();
		_layer3=Layer3::create();

		_layerMuticomplex=LayerMultiplex::create(_layer1,_layer2,_layer3,NULL);
		this->addChild(_layerMuticomplex);

			Size visibleSize =Director::getInstance()->getVisibleSize();
		Point origin = Director::getInstance()->getVisibleOrigin();

		MenuItemImage *pCloseItem1 = MenuItemImage::create(
			"w_b.png",
			"w_b.png",
			CC_CALLBACK_1(TestScene::menuCallback,this));

		MenuItemImage *pCloseItem2 = MenuItemImage::create(
			"r_b.png",
			"r_b.png",
			CC_CALLBACK_1(TestScene::menuCallback,this));

		MenuItemImage *pCloseItem3 = MenuItemImage::create(
			"g_b.png",
			"g_b.png",
			CC_CALLBACK_1(TestScene::menuCallback,this));

		// create menu, it's an autorelease object
		pCloseItem1->setTag(0);
		pCloseItem2->setTag(1);
		pCloseItem3->setTag(2);
		Menu* pMenu = Menu::create(pCloseItem1, pCloseItem2, pCloseItem3, NULL);
		pMenu->alignItemsHorizontallyWithPadding(-1);
		pMenu->setPosition(visibleSize.width/2,25);
		this->addChild(pMenu, 1);*/

	return true;

}
void TestScene::menuCallback(Object* pSender)
{
	int item=((MenuItemImage*)pSender)->getTag();
	if (item!=curLayerPos)
	{
		_layerMuticomplex->switchTo(item);
		curLayerPos=item;
	}
}