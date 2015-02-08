#ifndef GLOBESCENE_H
#define GLOBESCENE_H

namespace zge {
class IGameState {};
}

class GlobeScene : public zge::IGameState {
public:
  // constructor
  GlobeScene();
  // destructor
  virtual ~GlobeScene() noexcept;
  // copy constructor
  GlobeScene(const GlobeScene& other);
  // assignment operator
  GlobeScene& operator=(const GlobeScene& other);
  // move constructor (C++11)
  GlobeScene(GlobeScene&& other) noexcept;
  // move assignment operator (C++11)
  GlobeScene& operator=(GlobeScene&& other) noexcept;
};

#endif