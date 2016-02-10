#ifndef __PlayingField_h_
#define __PlayingField_h_

#include <Ogre.h>

class PlayingField {
public:
    Ogre::SceneNode* rootNode;

    PlayingField(Ogre::SceneManager* scnMgr);
    ~PlayingField();
    Ogre::SceneNode* getNode() {
        return rootNode;
    }
};

#endif