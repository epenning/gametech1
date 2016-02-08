#include <Ogre.h>

class PlayingField {
public:
    Ogre::SceneNode* rootNode;
    Ogre::Real pWidth;
    Ogre::Real pHeight;
    Ogre::Real pLength;

    PlayingField(Ogre::SceneManager* scnMgr);
    ~PlayingField();
    Ogre::SceneNode* getNode() {
        return rootNode;
    }
}