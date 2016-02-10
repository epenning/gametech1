#ifndef __Ball_h_
#define __Ball_h_

#include <Ogre.h>
#include "PlayingField.h"

class Ball {
protected:
    Ogre::SceneNode* rootNode;
    Ogre::Real bRadius;
    Ogre::Vector3 bDirection;
    Ogre::Real bSpeed;
    PlayingField* grounds;
public:
    Ball(Ogre::SceneManager* scnMgr);
    ~Ball();
    void move(const Ogre::FrameEvent& evt);
    Ogre::SceneNode* getNode() {
        return rootNode;
    }
    void setPlayingField(PlayingField* pf) {
        grounds = pf;
    }
};

#endif