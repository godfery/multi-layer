#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "extensions/cocos-ext.h"
USING_NS_CC_EXT;
USING_NS_CC;



class HelloWorld : public cocos2d::Layer,public ScrollViewDelegate
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(Object* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);



private:
    //ScrollView�б���ʵ�ֵ�2���麯������
    virtual void scrollViewDidScroll(ScrollView* view);
    
    virtual void scrollViewDidZoom(ScrollView* view);
    
    Node* create9Sprite(float pWith,float pHeight);//����9�þ���
    
    bool onTouchBegan(Touch* touch, Event* event);//������ʼ����
    
    void onTouchMoved(Touch* touch, Event* event);//�����ƶ�����
    
    void onTouchEnded(Touch* touch, Event* event);//������������
    
private:
    
    
    int x;        //scrollView�ĵ�ǰ������
    
    ScrollView *scrollView;
};

#endif // __HELLOWORLD_SCENE_H__
