#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "IGame.h"
#include "IRenderer.h"
#include "IInputManager.h"
#include "IResourceManager.h"
#include "IShaderManager.h"

#include "Shader.h"
#include "PsychedaelicShader.h"

#include "GlobeScene.h"

using namespace zge;

GlobeScene::GlobeScene() : instancePositions(4)
{

  // constructor
}

GlobeScene::~GlobeScene() NOEXCEPT
{

  // destructor
}

GlobeScene::GlobeScene(const GlobeScene& other)
{

  // copy constructor
}

GlobeScene& GlobeScene::operator=(const GlobeScene& rhs)
{
  // assignement operator
  if (this == &rhs)
  {
    return *this;
  }

  return *this;
}

GlobeScene::GlobeScene(GlobeScene&& other) NOEXCEPT
{

  // move constructor (C++11)
}

GlobeScene& GlobeScene::operator=(GlobeScene&& other) NOEXCEPT
{
  // move assignment operator (C++11)
  return *(new GlobeScene(other));
}

void GlobeScene::processEvent(const Event event)
{
  // process event
  switch (event.eventType)
  {
    case KEY_UP:
      switch (event.key)
      {
        case ZGE_ESCAPE:
        {
          IGame::getInstance()->quit();
          break;
        }
        case ZGE_S:
        {
          static_cast<PsychedaelicShader*>(
              IShaderManager::getInstance()->getShader(SHADER_PSYCHEDAELIC))
              ->switchShowDepth();
          break;
        }
        default:
          break;
      }
      break;
    default:
      break;
  }
}

bool GlobeScene::initialise()
{
  // init
  IInputManager::getInstance()->enableKeyboard();
  IResourceManager* resourceManager = IResourceManager::getInstance();
  this->instancePositions = { { -0.5f, -0.5f, 0.0f },
                              { 0.5f, -0.5f, 0.0f },
                              { 0.5f, 0.5f, 0.0f },
                              { -0.5f, 0.5f, 0.0f } };
  unsigned squareMesh = resourceManager->getSquareMesh();
  for (int i = 0; i < 4; ++i)
  {
    this->squares[i] = new MeshObject;
    this->squares[i]->setMeshId(squareMesh);
    this->squares[i]->setPosition(this->instancePositions[i]);
    this->squares[i]->setScale({ 0.2f, 0.2f, 0.2f });
    this->addGameObject(Shader::SHADER_PSYCHEDAELIC, this->squares[i]);
  }

  return true;
}

void GlobeScene::update()
{
  // update
  static float translation = 0.0f;
  translation += 0.01f;

  glm::vec3 moveAmount =
      glm::vec3(sinf(translation) * 0.002f, cosf(translation) * 0.002f, 0.0f);
  glm::mat4 translationMatrix = glm::translate(moveAmount);

  for (int i = 0; i < 4; ++i)
  {
    this->instancePositions[i] += moveAmount;

    this->squares[i]->setPosition(this->instancePositions[i]);
  }
}
