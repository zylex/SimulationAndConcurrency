#include "IResourceManager.h"

#include "BallSceneBox.h"

#include "MeshObject.h"
#include "Material.h"

using namespace zge;

BallSceneBox::BallSceneBox()
{
  // constructor
  IResourceManager* resourceManager = IResourceManager::getInstance();
  Material* material = new Material;
  unsigned textureId =
      resourceManager->loadTextureFromFile("Textures/Fieldstone.tga");
  material->setTextureId(textureId);
  unsigned squareMeshId = resourceManager->getSquareMesh();
  MeshObject* back = new MeshObject;
  back->setMaterial(material);
  back->setMeshId(squareMeshId);
  back->setScale({ 10.0f, 15.0f, 1.0f });
  back->setPosition({ 0.0f, -7.5f, -5.0f });
  back->setRotation({ 0.0f, 0.0f, 0.0f });
  this->addChild(back);

  MeshObject* right = new MeshObject;
  right->setMaterial(material);
  right->setMeshId(squareMeshId);
  right->setScale({ 10.0f, 15.0f, 1.0f });
  right->setPosition({ 5.0f, -7.5f, 0.0f });
  right->setRotation({ 0.0f, -90.0f, 0.0f });
  this->addChild(right);

  MeshObject* left = new MeshObject;
  left->setMaterial(material);
  left->setMeshId(squareMeshId);
  left->setScale({ 10.0f, 15.0f, 1.0f });
  left->setPosition({ -5.0f, -7.5f, 0.0f });
  left->setRotation({ 0.0f, 90.0f, 0.0f });
  this->addChild(left);

  MeshObject* front = new MeshObject;
  front->setMaterial(material);
  front->setMeshId(squareMeshId);
  front->setScale({ 10.0f, 15.0f, 1.0f });
  front->setPosition({ 0.0f, -7.5f, 5.0f });
  front->setRotation({ 0.0f, 180.0f, 0.0f });
  this->addChild(front);

  this->topTray = new MeshObject;
  this->topTray->setMaterial(material);
  this->topTray->setMeshId(squareMeshId);
  this->topTray->setScale({ 10.0f, 10.0f, 1.0f });
  this->topTray->setPosition({ 0.0f, -3.0f, 0.0f });
  this->topTray->setRotation({ -90.0f, 0.0f, 0.0f });
  this->addChild(this->topTray);

  this->bottomTray = new MeshObject;
  this->bottomTray->setMaterial(material);
  this->bottomTray->setMeshId(squareMeshId);
  this->bottomTray->setScale({ 10.0f, 10.0f, 1.0f });
  this->bottomTray->setPosition({ 0.0f, -12.0f, 0.0f });
  this->bottomTray->setRotation({ -90.0f, 0.0f, 0.0f });
  this->addChild(this->bottomTray);

  unsigned meshWithHoleId = resourceManager->getSquareMeshWithHole();
  for (int i = 0; i < 9; ++i)
  {
    this->trayWithHoles[i] = new MeshObject;
    this->trayWithHoles[i]->setMaterial(material);
    this->trayWithHoles[i]->setMeshId(meshWithHoleId);
    this->trayWithHoles[i]->setScale({ 1.0f, 1.0f, 1.0f });
    this->trayWithHoles[i]->setRotation({ -90.0f, 0.0f, 0.0f });
    this->addChild(this->trayWithHoles[i]);
  }

  this->trayWithHoles[0]->setPosition({ -3.0f, -7.5f, -3.0f });
  this->trayWithHoles[1]->setPosition({ -3.0f, -7.5f, 0.0f });
  this->trayWithHoles[2]->setPosition({ -3.0f, -7.5f, 3.0f });
  this->trayWithHoles[3]->setPosition({ 0.0f, -7.5f, -3.0f });
  this->trayWithHoles[4]->setPosition({ 0.0f, -7.5f, 0.0f });
  this->trayWithHoles[5]->setPosition({ 0.0f, -7.5f, 3.0f });
  this->trayWithHoles[6]->setPosition({ 3.0f, -7.5f, -3.0f });
  this->trayWithHoles[7]->setPosition({ 3.0f, -7.5f, 0.0f });
  this->trayWithHoles[8]->setPosition({ 3.0f, -7.5f, 3.0f });
}

BallSceneBox::~BallSceneBox() NOEXCEPT
{
  // destructor
}

BallSceneBox::BallSceneBox(const BallSceneBox& other)
{
  // copy constructor
}

BallSceneBox& BallSceneBox::operator=(const BallSceneBox& rhs)
{
  // assignement operator
  if (this == &rhs)
  {
    return *this;
  }

  return *this;
}

BallSceneBox::BallSceneBox(BallSceneBox&& other) NOEXCEPT
{
  // move constructor (C++11)
}

BallSceneBox& BallSceneBox::operator=(BallSceneBox&& other) NOEXCEPT
{
  // move assignment operator (C++11)
  return *(new BallSceneBox(other));
}
