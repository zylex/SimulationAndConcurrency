#include "IResourceManager.h"

#include "BallSceneBowl.h"

#include "Material.h"

using namespace zge;

BallSceneBowl::BallSceneBowl()
{
  // constructor
  IResourceManager* resourceManager = IResourceManager::getInstance();

  this->setMeshId(resourceManager->getBowlMesh(20.0f, 5.0f));

  Material* material = new Material;

  material->setTextureId(
      resourceManager->loadTextureFromFile("Textures/FireDistortion.tga"));

  this->setMaterial(material);

  this->setRotation({ -90.0f, 0.0f, 0.0f });

  this->setScale({ 20.0f, 20.0f, 5.0f });

  this->setPosition({ 0.0f, -15.0f, 0.0f });
}

BallSceneBowl::~BallSceneBowl() NOEXCEPT
{
  // destructor
}

BallSceneBowl::BallSceneBowl(const BallSceneBowl& other)
{
  // copy constructor
}

BallSceneBowl& BallSceneBowl::operator=(const BallSceneBowl& rhs)
{
  // assignement operator
  if (this == &rhs)
  {
    return *this;
  }

  return *this;
}

BallSceneBowl::BallSceneBowl(BallSceneBowl&& other) NOEXCEPT
{
  // move constructor (C++11)
}

BallSceneBowl& BallSceneBowl::operator=(BallSceneBowl&& other) NOEXCEPT
{
  // move assignment operator (C++11)
  return *(new BallSceneBowl(other));
}
