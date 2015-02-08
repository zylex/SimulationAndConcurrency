#include "GlobeScene.h"

GlobeScene::GlobeScene() {
  // constructor
}

GlobeScene::~GlobeScene() noexcept {
  // destructor
}

GlobeScene::GlobeScene(const GlobeScene& other) {
  // copy constructor
}

GlobeScene& GlobeScene::operator=(const GlobeScene& rhs) {
  // assignement operator
  if (this == &rhs) {
    return *this;
  }

  return *this;
}

GlobeScene::GlobeScene(GlobeScene&& other) noexcept {
  // move constructor (C++11)
}

GlobeScene& GlobeScene::operator=(GlobeScene&& other) noexcept {
  // move assignment operator (C++11)
  return *(new GlobeScene(other));
}
