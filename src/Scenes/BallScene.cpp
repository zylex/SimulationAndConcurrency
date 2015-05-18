#include <iostream>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "IGame.h"
#include "IRenderer.h"
#include "IInputManager.h"
#include "IResourceManager.h"
#include "IShaderManager.h"

#include "Material.h"
#include "ModelFactory.h"
#include "MeshObject.h"
#include "CompositeObject.h"
#include "Shader.h"
#include "PsychedaelicShader.h"

#include "BallScene.h"

using namespace zge;

BallScene::BallScene()
    : instancePositions(4)
#ifdef USE_ANT
      ,
      bar(nullptr)
#endif
{
  // constructor
}

BallScene::~BallScene() NOEXCEPT
{

  // destructor
}

BallScene::BallScene(const BallScene& other)
{

  // copy constructor
}

BallScene& BallScene::operator=(const BallScene& rhs)
{
  // assignement operator
  if (this == &rhs)
  {
    return *this;
  }

  return *this;
}

BallScene::BallScene(BallScene&& other) NOEXCEPT
{

  // move constructor (C++11)
}

BallScene& BallScene::operator=(BallScene&& other) NOEXCEPT
{
  // move assignment operator (C++11)
  return *(new BallScene(other));
}

void BallScene::processEvent(const Event event)
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
        case ZGE_X:
        {
          static_cast<PsychedaelicShader*>(
              IShaderManager::getInstance()->getShader(SHADER_PSYCHEDAELIC))
              ->switchShowDepth();
          break;
        }
        case ZGE_W:
        {
          this->camera->moveForward();
          break;
        }
        case ZGE_S:
        {
          this->camera->moveBackward();
          break;
        }
        case ZGE_A:
        {
          this->camera->strafeLeft();
          break;
        }
        case ZGE_D:
        {
          this->camera->strafeRight();
          break;
        }
        case ZGE_R:
        {
          this->camera->strafeUp();
          break;
        }
        case ZGE_F:
        {
          this->camera->strafeDown();
          break;
        }

        case ZGE_ARROW_LEFT:
        {
          this->camera->turnLeft();
          break;
        }
        case ZGE_ARROW_RIGHT:
        {
          this->camera->turnRight();
          break;
        }
        case ZGE_ARROW_DOWN:
        {
          this->camera->turnDown();
          break;
        }
        case ZGE_ARROW_UP:
        {
          this->camera->turnUp();
          break;
        }
#ifdef USE_ANT
        case ZGE_Z:
        {
          IRenderer::getInstance()->toggleAntTweakBar();
          break;
        }
#endif
        default:
          break;
      }
      break;
    default:
      break;
  }
}

bool BallScene::initialise()
{
#ifdef USE_ANT
  bar = new BallSceneTweakBar(IGame::getInstance()->getWindowTitle());
#endif
  // init
  IInputManager::getInstance()->enableKeyboard();
  IResourceManager* resourceManager = IResourceManager::getInstance();
  // this->instancePositions = { { -0.5f, -0.5f, 0.0f },
  //                             { 0.5f, -0.5f, 0.0f },
  //                             { 0.5f, 0.5f, 0.0f },
  //                             { -0.5f, 0.5f, 0.0f } };
  unsigned squareMesh = resourceManager->getSquareMesh();
  int i = 0;
  // material->setColor({ 1.0f, 0.0f, 0.0f, 1.0f });

  Material* material = new Material;
  unsigned textureId =
      resourceManager->loadTextureFromFile("Textures/FireBase.tga");
  material->setTextureId(textureId);

  Material* material2 = new Material;
  unsigned textureId2 =
      resourceManager->loadTextureFromFile("Textures/Fieldstone.tga");
  material2->setTextureId(textureId2);
  // for (int i = 0; i < 4; ++i)
  // {
  this->squares[i] = new MeshObject;
  this->squares[i]->setMeshId(squareMesh);
  // this->squares[i]->setPosition(this->instancePositions[i]);
  this->squares[i]->setPosition({ 0.0f, 0.0f, -2.0f });
  this->squares[i]->setScale({ 1.0f, 1.0f, 1.0f });
  static_cast<MeshObject*>(this->squares[i])->setMaterial(material);
  // this->addGameObject(Shader::SHADER_PSYCHEDAELIC, this->squares[i]);
  // this->addGameObject(Shader::SHADER_COLORED, this->squares[i]);
  this->addGameObject(Shader::SHADER_TEXTURED, this->squares[i]);
  // this->addGameObject(Shader::SHADER_TRANPARENT_TEXTURED, this->squares[i]);
  // }

  // Material* material2 = new Material;
  // textureId =
  // resourceManager->loadTextureFromFile("Textures/Fieldstone.tga");
  // material2->setTextureId(textureId);

  ModelFactory modelFactory;

  this->box = modelFactory.createBoxObject(1.0f);

  // this->box->setScale({ 0.2f, 0.2f, 0.2f });
  // this->box->setPosition({ 0.0f, 0.0f, 0.0f });
  // this->box->setPosition({ 0.0f, 0.0f, 1.0f });

  // material2* material2 = new material2;
  // material2->setColor({ 1.0f, 0.0f, 0.0f, 1.0f });
  // material2->setColor({ 1.0f, 1.0f, 1.0f, 1.0f });
  std::vector<IGameObject*> children =
      static_cast<CompositeObject*>(this->box)->getChildren();
  for (std::vector<IGameObject*>::iterator it = children.begin();
       it IS_NOT children.end(); ++it)
  {
    static_cast<MeshObject*>(*it)->setMaterial(material2);
  }

  this->box->setPosition({ 0.0f, 0.0f, 0.0f });
  // this->box->setPosition({ 0.0f, 0.0f, -2.0f });
  this->box->setScale({ 1.0f, 1.0f, 1.0f });

  // this->addGameObject(Shader::SHADER_PSYCHEDAELIC, this->box);
  // this->addGameObject(Shader::SHADER_COLORED, this->box);
  // this->addGameObject(Shader::SHADER_TEXTURED, this->box);
  this->addGameObject(Shader::SHADER_TRANPARENT_TEXTURED, this->box);

  this->camera = new Camera;
  this->camera->setPosition({ 0.0f, 0.0f, 3.0f });
  // this->camera->setRotation({ 0.0f, 180.0f, 0.0f });
  this->setCurrentCamera(this->camera);

  this->light.setPosition({ 0.0f, 0.0f, 5.0f });
  this->light.setLightDirection({ 0.0f, 0.0f, -1.0f });
  this->light.setAmbientColor({ 0.2f, 0.2f, 0.2f, 1.0f });
  // this->light.setAmbientColor({ 1.0f, 0.0f, 0.0f, 1.0f });
  this->light.setDiffuseColor({ 0.8f, 0.8f, 0.8f, 0.8f });
  // this->light.setDiffuseColor({ 1.0f, 1.0f, 1.0f, 1.0f });
  this->light.setSpecularColor({ 1.0f, 1.0f, 1.0f, 1.0f });
  // this->light.setSpecularPower(1.0f);
  this->light.setSpecularPower(0.5f);

  this->addLight(&this->light);

  return true;
}

void BallScene::update()
{
  // update
  static float translation = 0.0f;
  static glm::vec3 position = this->box->getPosition();
  static bool goingUp = false;
  static bool goingRight = false;

  translation += 0.01f;

  if (translation > 2 * M_PI)
  {
    if (position.y < -4.0f)
    {
      goingUp = true;
    }

    if (goingUp)
    {

      if (position.y > 4.0f)
      {
        translation = 0.0f;
        goingUp = false;
      }
      else if (position.y < 0.02f and position.y > -0.02f)
      {
        if (position.x < -4.0f)
        {
          goingRight = true;
        }
        if (goingRight)
        {
          position.x += 0.03f;
          if (position.x > 4.0f)
          {
            goingRight = false;
          }
        }
        else
        {
          position.x -= 0.03f;
          if (position.x > 0.0f and position.x < 0.05f)
          {
            position.y += 0.05f;
          }
        }
      }
      else
      {
        position.y += 0.03f;
      }
    }
    else
    {
      position.y -= 0.03f;
    }
  }
  else
  {
    position = glm::vec3(sinf(translation) * 4, cosf(translation) * 4, -10.0f);
  }

  // glm::mat4 translationMatrix = glm::translate(moveAmount);

  // for (int i = 0; i < 4; ++i)
  // {
  //   this->instancePositions[i] += moveAmount;

  //   this->squares[i]->setPosition(this->instancePositions[i]);
  // }

  // this->box->setPosition(/*this->box->getPosition() + */ position);
  // this->box->setScale(this->box->getScale() + moveAmount);

  // static glm::vec3 rotation;
  // rotation.x += 1.0f;
  // rotation.y += 1.0f;
  // rotation.z += 1.0f;

  // this->box->setRotation(rotation);
  // this->box->setPosition(rotation);
  // this->camera->turnLeft();
  // this->camera->turnUp();
  // this->camera->moveBackward();
}
