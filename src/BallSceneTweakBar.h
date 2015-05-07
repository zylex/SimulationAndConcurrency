#ifndef BALLSCENETWEAKBAR_H
#define BALLSCENETWEAKBAR_H

#include "TweakBar.h"

class BallSceneTweakBar : public zge::TweakBar
{
private:
  unsigned numberOfBalls;
  unsigned numberOfCubes;

public:
  // constructor
  BallSceneTweakBar(std::string);
  // destructor
  virtual ~BallSceneTweakBar() NOEXCEPT;
  // copy constructor
  BallSceneTweakBar(const BallSceneTweakBar&);
  // assignment operator
  BallSceneTweakBar& operator=(const BallSceneTweakBar&);
  // move constructor (C++11)
  BallSceneTweakBar(BallSceneTweakBar&&) NOEXCEPT;
  // move assignment operator (C++11)
  BallSceneTweakBar& operator=(BallSceneTweakBar&&) NOEXCEPT;

  virtual void initialise();
};

#endif
