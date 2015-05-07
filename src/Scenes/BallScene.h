#ifndef BALLSCENE_H
#define BALLSCENE_H

#ifdef USE_ANT
#include "BallSceneTweakBar.h"
#endif

#include "Preprocessors.h"

#include "GameState.h"
#include "Event.h"
#include "MeshObject.h"

class BallScene : public zge::GameState
{
private:
  std::vector<glm::vec3> instancePositions;
  // zge::MeshObject* squares[4];
  zge::Camera* camera;
  zge::IGameObject* box;
#ifdef USE_ANT
  BallSceneTweakBar* bar;
#endif

public:
  // constructor
  BallScene();
  // destructor
  virtual ~BallScene() NOEXCEPT;
  // copy constructor
  BallScene(const BallScene& other);
  // assignment operator
  BallScene& operator=(const BallScene& other);
  // move constructor (C++11)
  BallScene(BallScene&& other) NOEXCEPT;
  // move assignment operator (C++11)
  BallScene& operator=(BallScene&& other) NOEXCEPT;

  void processEvent(const zge::Event);

  bool initialise();
  void update();
};

#endif
