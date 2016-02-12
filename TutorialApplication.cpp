/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/
Tutorial Framework (for Ogre 1.9)
http://www.ogre3d.org/wiki/
-----------------------------------------------------------------------------
*/

#include "TutorialApplication.h"

//---------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
}
//---------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//---------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0, 0, 0));
    mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

    mSceneMgr->setSkyBox(true, "Examples/MorningSkyBox", 5000, false);

    PlayingField* bCourt = new PlayingField(mSceneMgr);
    ball = new Ball(mSceneMgr);
    ball->setPlayingField(bCourt);

    // Everything else

    /*Ogre::Light* directionalLight = mSceneMgr->createLight("DirectionalLight");
    directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);
    directionalLight->setDiffuseColour(Ogre::ColourValue(.3,.2,.6));
    directionalLight->setSpecularColour(Ogre::ColourValue(.1,.1,.1));
    directionalLight->setDirection(Ogre::Vector3(0,-1,0));*/

    Ogre::Light* pointLight = mSceneMgr->createLight("PointLight");
    pointLight->setType(Ogre::Light::LT_POINT);
    pointLight->setDiffuseColour(1,1,1);
    pointLight->setSpecularColour(1,1,1);
    pointLight->setPosition(Ogre::Vector3(0,30,0));

    // NINJA SECTION

    /*
    Ogre::Entity* ninjaEntity = mSceneMgr->createEntity("ninja.mesh");
    ninjaEntity->setCastShadows(true);
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(ninjaEntity);

    Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
    Ogre::MeshManager::getSingleton().createPlane(
        "ground",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane, 
        1500, 1500, 20, 20, 
        true, 
        1, 5, 5, 
        Ogre::Vector3::UNIT_Z);
    Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
    mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
    groundEntity->setCastShadows(false);
    groundEntity->setMaterialName("Examples/Rockwall");

    Ogre::Light* spotLight = mSceneMgr->createLight("SpotLight");
    spotLight->setDiffuseColour(0,0,1.0);
    spotLight->setSpecularColour(0,0,1.0);
    spotLight->setType(Ogre::Light::LT_SPOTLIGHT);
    spotLight->setDirection(-1,-1,0);
    spotLight->setPosition(Ogre::Vector3(200,200,0));
    spotLight->setSpotlightRange(Ogre::Degree(35), Ogre::Degree(50));

    Ogre::Light* directionalLight = mSceneMgr->createLight("DirectionalLight");
    directionalLight->setType(Ogre::Light::LT_DIRECTIONAL);
    directionalLight->setDiffuseColour(Ogre::ColourValue(.4,0,0));
    directionalLight->setSpecularColour(Ogre::ColourValue(.4,0,0));
    directionalLight->setDirection(Ogre::Vector3(0,-1,1));

    Ogre::Light* pointLight = mSceneMgr->createLight("PointLight");
    pointLight->setType(Ogre::Light::LT_POINT);
    pointLight->setDiffuseColour(.3,.3,.3);
    pointLight->setSpecularColour(.3,.3,.3);
    pointLight->setPosition(Ogre::Vector3(0,150,250));*/

    // OGRE HEAD SECTION

    /*mCamera->setPosition(0, 47, 222);

    Ogre::Entity* ogreEntity = mSceneMgr->createEntity("ogrehead.mesh");
    Ogre::SceneNode* ogreNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    ogreNode->attachObject(ogreEntity);

    Ogre::Entity* ogreEntity2 = mSceneMgr->createEntity("ogrehead.mesh");
    Ogre::SceneNode* ogreNode2 = mSceneMgr->getRootSceneNode()->createChildSceneNode(
        Ogre::Vector3(84,48,0));
    ogreNode2->attachObject(ogreEntity2);

    Ogre::Entity* ogreEntity3 = mSceneMgr->createEntity("ogrehead.mesh");
    Ogre::SceneNode* ogreNode3 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    ogreNode3->setPosition(0,104,0);
    ogreNode3->setScale(2,1.2,1);
    ogreNode3->attachObject(ogreEntity3);

    Ogre::Entity* ogreEntity4 = mSceneMgr->createEntity("ogrehead.mesh");
    Ogre::SceneNode* ogreNode4 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
    ogreNode4->setPosition(-84,48,0);
    ogreNode4->roll(Ogre::Degree(-90));
    ogreNode4->attachObject(ogreEntity4);

    Ogre::Light* light = mSceneMgr->createLight("MainLight");
    light->setPosition(20, 80, 50);*/

}
//---------------------------------------------------------------------------
void TutorialApplication::createCamera()
{
    mCamera = mSceneMgr->createCamera("PlayerCam");
    mCamera->setPosition(Ogre::Vector3(0,0,40));
    mCamera->lookAt(Ogre::Vector3(0,0,0));
    mCamera->setNearClipDistance(5);
    mCamera->setFOVy(Ogre::Degree(90));

    mCameraMan = new OgreBites::SdkCameraMan(mCamera);
}
//---------------------------------------------------------------------------
void TutorialApplication::createViewports()
{
    Ogre::Viewport* vp = mWindow->addViewport(mCamera);
    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

    mCamera->setAspectRatio(
        Ogre::Real(vp->getActualWidth()) /
        Ogre::Real(vp->getActualHeight()));
}

bool TutorialApplication::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
    if(mWindow->isClosed())
        return false;

    if(mShutDown)
        return false;

    // Need to capture/update each device
    mKeyboard->capture();
    mMouse->capture();

    mTrayMgr->frameRenderingQueued(evt);

    if (!mTrayMgr->isDialogVisible())
    {
        mCameraMan->frameRenderingQueued(evt);   // If dialog isn't up, then update the camera
        if (mDetailsPanel->isVisible())          // If details panel is visible, then update its contents
        {
            mDetailsPanel->setParamValue(0, Ogre::StringConverter::toString(mCamera->getDerivedPosition().x));
            mDetailsPanel->setParamValue(1, Ogre::StringConverter::toString(mCamera->getDerivedPosition().y));
            mDetailsPanel->setParamValue(2, Ogre::StringConverter::toString(mCamera->getDerivedPosition().z));
            mDetailsPanel->setParamValue(4, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().w));
            mDetailsPanel->setParamValue(5, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().x));
            mDetailsPanel->setParamValue(6, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().y));
            mDetailsPanel->setParamValue(7, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().z));
        }
        // Move the ball
        ball->move(evt);
    }

    return true;
}

PlayingField::PlayingField(Ogre::SceneManager* scnMgr) {

    // Create room
    height = 100;
    length = 100;
    width  = 100;

    Ogre::Plane plane(Ogre::Vector3::UNIT_Y, -50);
    Ogre::MeshManager::getSingleton().createPlane( "ground",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane, 
        100, 100, 1, 1, 
        true, 
        1, 5, 5, 
        Ogre::Vector3::UNIT_Z);
    Ogre::Entity* groundEntity = scnMgr->createEntity("ground");
    scnMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
    groundEntity->setMaterialName("Examples/BumpyMetal");

    Ogre::Plane plane2(Ogre::Vector3::NEGATIVE_UNIT_Y, -50);
    Ogre::MeshManager::getSingleton().createPlane( "roof",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane2, 
        100, 100, 1, 1, 
        true, 
        1, 5, 5, 
        Ogre::Vector3::UNIT_Z);
    Ogre::Entity* roofEntity = scnMgr->createEntity("roof");
    scnMgr->getRootSceneNode()->createChildSceneNode()->attachObject(roofEntity);
    roofEntity->setMaterialName("Examples/BumpyMetal");

    Ogre::Plane plane3(Ogre::Vector3::UNIT_Z, -50);
    Ogre::MeshManager::getSingleton().createPlane( "wall1",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane3, 
        100, 100, 1, 1, 
        true, 
        1, 5, 5, 
        Ogre::Vector3::UNIT_Y);
    Ogre::Entity* wall1Entity = scnMgr->createEntity("wall1");
    scnMgr->getRootSceneNode()->createChildSceneNode()->attachObject(wall1Entity);
    wall1Entity->setMaterialName("Examples/BumpyMetal");

    Ogre::Plane plane4(Ogre::Vector3::NEGATIVE_UNIT_Z, -50);
    Ogre::MeshManager::getSingleton().createPlane( "wall2",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane4, 
        100, 100, 1, 1, 
        true, 
        1, 5, 5, 
        Ogre::Vector3::UNIT_Y);
    Ogre::Entity* wall2Entity = scnMgr->createEntity("wall2");
    scnMgr->getRootSceneNode()->createChildSceneNode()->attachObject(wall2Entity);
    wall2Entity->setMaterialName("Examples/BumpyMetal");

    Ogre::Plane plane5(Ogre::Vector3::UNIT_X, -50);
    Ogre::MeshManager::getSingleton().createPlane( "wall3",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane5, 
        100, 100, 1, 1, 
        true, 
        1, 5, 5, 
        Ogre::Vector3::UNIT_Z);
    Ogre::Entity* wall3Entity = scnMgr->createEntity("wall3");
    scnMgr->getRootSceneNode()->createChildSceneNode()->attachObject(wall3Entity);
    wall3Entity->setMaterialName("Examples/BumpyMetal");

    Ogre::Plane plane6(Ogre::Vector3::NEGATIVE_UNIT_X, -50);
    Ogre::MeshManager::getSingleton().createPlane( "wall4",
        Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
        plane6, 
        100, 100, 1, 1, 
        true, 
        1, 5, 5, 
        Ogre::Vector3::UNIT_Z);
    Ogre::Entity* wall4Entity = scnMgr->createEntity("wall4");
    scnMgr->getRootSceneNode()->createChildSceneNode()->attachObject(wall4Entity);
    wall4Entity->setMaterialName("Examples/BumpyMetal");
}

Ball::Ball(Ogre::SceneManager* scnMgr) {
    Ogre::Entity* ball = scnMgr->createEntity("Sphere", "sphere.mesh");
    ball->setMaterialName("Examples/SphereMappedRustySteel");
    ball->setCastShadows(true);
    rootNode = scnMgr->getRootSceneNode()->createChildSceneNode("Ball");
    rootNode->attachObject(ball);
    rootNode->setScale(0.05,0.05,0.05);
    bRadius = 5.0f;
    bDirection = Ogre::Vector3(rand() % 100, rand() % 100, rand() % 100);
    bDirection.normalise();
    bSpeed = rand() % 200 + 100;
}

void Ball::move(const Ogre::FrameEvent& evt) {
    // Collision with walls
    Ogre::Vector3 bPosition = rootNode->getPosition();
    if (bPosition.y < -grounds->height/2.0f + bRadius && bDirection.y < 0.0f) 
        bDirection.y = -bDirection.y;
    if (bPosition.y > grounds->height/2.0f - bRadius && bDirection.y > 0.0f) 
        bDirection.y = -bDirection.y;
    if (bPosition.z < -grounds->length/2.0f + bRadius && bDirection.z < 0.0f) 
        bDirection.z = -bDirection.z;
    if (bPosition.z > grounds->length/2.0f - bRadius && bDirection.z > 0.0f) 
        bDirection.z = -bDirection.z;
    if (bPosition.x < -grounds->width/2.0f + bRadius && bDirection.x < 0.0f) 
        bDirection.x = -bDirection.x;
    if (bPosition.x > grounds->width/2.0f - bRadius && bDirection.x > 0.0f) 
        bDirection.x = -bDirection.x;
    // Move ball
    rootNode->translate(bSpeed * evt.timeSinceLastFrame * bDirection); 
}




#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        TutorialApplication app;

        try {
            app.go();
        } catch(Ogre::Exception& e)  {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox(NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occurred: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif

//---------------------------------------------------------------------------
