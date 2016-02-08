#include <Ogre.h>

class PlayingField {
public:
    Ogre::SceneNode* rootNode;

    PlayingField(Ogre::SceneManager* scnMgr);
    ~PlayingField();
    Ogre::SceneNode* getNode() {
        return rootNode;
    }
}