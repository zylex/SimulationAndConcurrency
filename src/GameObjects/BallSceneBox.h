#ifndef BALLSCENEBOX_H
#define BALLSCENEBOX_H

#include "CompositeObject.h"

#include "MeshObject.h"

class BallSceneBox : public zge::CompositeObject
{
private:
  zge::MeshObject* topTray;
  zge::MeshObject* bottomTray;
  zge::MeshObject* trayWithHoles[9];

  // zge::CompositeObject* trayWithHoles;

public:
  // constructor
  BallSceneBox();
  // destructor
  virtual ~BallSceneBox() NOEXCEPT;
  // copy constructor
  BallSceneBox(const BallSceneBox&);
  // assignment operator
  BallSceneBox& operator=(const BallSceneBox&);
  // move constructor (C++11)
  BallSceneBox(BallSceneBox&&) NOEXCEPT;
  // move assignment operator (C++11)
  BallSceneBox& operator=(BallSceneBox&&) NOEXCEPT;
};

#endif
