#ifndef GLOBESCENE_H
#define GLOBESCENE_H
#include "Preprocessors.h"

#include "GameState.h"
#include "Event.h"
#include "MeshObject.h"

class GlobeScene : public zge::GameState
{
private:
  std::vector<glm::vec3> instancePositions;
  zge::MeshObject* squares[4];

public:
  // constructor
  GlobeScene();
  // destructor
  virtual ~GlobeScene() NOEXCEPT;
  // copy constructor
  GlobeScene(const GlobeScene& other);
  // assignment operator
  GlobeScene& operator=(const GlobeScene& other);
  // move constructor (C++11)
  GlobeScene(GlobeScene&& other) NOEXCEPT;
  // move assignment operator (C++11)
  GlobeScene& operator=(GlobeScene&& other) NOEXCEPT;

  void processEvent(const zge::Event);

  bool initialise();
  void update();
};

#endif