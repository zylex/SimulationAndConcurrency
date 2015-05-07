#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "IGame.h"
#include "IRenderer.h"
#include "IInputManager.h"
#include "IResourceManager.h"
#include "IShaderManager.h"

#include "ModelFactory.h"
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
  // IResourceManager* resourceManager = IResourceManager::getInstance();
  // this->instancePositions = { { -0.5f, -0.5f, 0.0f },
  //                             { 0.5f, -0.5f, 0.0f },
  //                             { 0.5f, 0.5f, 0.0f },
  //                             { -0.5f, 0.5f, 0.0f } };
  // unsigned squareMesh = resourceManager->getSquareMesh();
  // for (int i = 0; i < 4; ++i)
  // {
  //   this->squares[i] = new MeshObject;
  //   this->squares[i]->setMeshId(squareMesh);
  //   this->squares[i]->setPosition(this->instancePositions[i]);
  //   this->squares[i]->setScale({ 0.2f, 0.2f, 0.2f });
  //   this->addGameObject(Shader::SHADER_PSYCHEDAELIC, this->squares[i]);
  // }

  ModelFactory modelFactory;

  this->box = modelFactory.createBoxObject(10.0f);

  this->box->setScale({ 1.0f, 1.5f, 1.0f });

  this->addGameObject(Shader::SHADER_PSYCHEDAELIC, this->box);

  this->camera = new Camera;
  this->camera->setPosition({ 0.0f, 0.0f, 500.0f });
  this->setCurrentCamera(this->camera);

  // #ifdef USE_ANT
  // this->antTweakBar = TwNewBar("08964: Simulation and Concurrency");
  // TwDefine(" GLOBAL help='This example shows how to integrate AntTweakBar
  // with "
  //          "GLFW and OpenGL.' ");
  // TwDefine("'08964: Simulation and Concurrency' position='0 0'");
  // TwDefine("'08964: Simulation and Concurrency' size='240 600'");
  // TwWindowSize(SCREEN_WIDTH(), SCREEN_HEIGHT());
  // TwCopyStdStringToClientFunc(BallScene::CopyStdStringToTW);
  // std::string str = "Simulation and Concurrency";
  // float fl = 10.506f;
  // TwAddVarRO(this->antTweakBar, "Main", TW_TYPE_FLOAT, &fl,
  //            "precision=2 group=Threads");
  // TwAddVarRO(this->antTweakBar, "Graphics", TW_TYPE_FLOAT, &fl,
  //            "precision=2 group=Threads");
  // TwAddVarRO(this->antTweakBar, "Network", TW_TYPE_FLOAT, &fl,
  //            "precision=2 group=Threads");
  // TwAddVarRO(this->antTweakBar, "Simulation", TW_TYPE_FLOAT, &fl,
  //            "precision=2 group=Threads");
  // #endif

  return true;
}

void BallScene::update()
{
  // update
  // static float translation = 0.0f;
  // translation += 0.01f;

  // glm::vec3 moveAmount =
  //     glm::vec3(sinf(translation) * 0.002f, cosf(translation) * 0.002f,
  //     0.0f);
  // glm::mat4 translationMatrix = glm::translate(moveAmount);

  // for (int i = 0; i < 4; ++i)
  // {
  //   this->instancePositions[i] += moveAmount;

  //   this->squares[i]->setPosition(this->instancePositions[i]);
  // }
}
