#ifndef BALLSCENEBOWL_H
#define BALLSCENEBOWL_H

#include "Preprocessors.h"

#include "MeshObject.h"

class BallSceneBowl : public zge::MeshObject
{
public:
  // constructor
  BallSceneBowl();
  // destructor
  virtual ~BallSceneBowl() NOEXCEPT;
  // copy constructor
  BallSceneBowl(const BallSceneBowl&);
  // assignment operator
  BallSceneBowl& operator=(const BallSceneBowl&);
  // move constructor (C++11)
  BallSceneBowl(BallSceneBowl&&) NOEXCEPT;
  // move assignment operator (C++11)
  BallSceneBowl& operator=(BallSceneBowl&&) NOEXCEPT;
};

#endif
