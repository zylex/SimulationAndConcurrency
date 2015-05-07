#ifdef USE_ANT
#include <sstream>

#include "BallSceneTweakBar.h"

BallSceneTweakBar::BallSceneTweakBar(std::string title)
    : TweakBar(title), numberOfBalls(0), numberOfCubes(0)
{
  // constructor
  this->initialise();
}

BallSceneTweakBar::~BallSceneTweakBar() NOEXCEPT
{
  // destructor
}

BallSceneTweakBar::BallSceneTweakBar(const BallSceneTweakBar& other)
{
  // copy constructor
}

BallSceneTweakBar& BallSceneTweakBar::operator=(const BallSceneTweakBar& rhs)
{
  // assignement operator
  if (this == &rhs)
  {
    return *this;
  }

  return *this;
}

BallSceneTweakBar::BallSceneTweakBar(BallSceneTweakBar&& other) NOEXCEPT
{
  // move constructor (C++11)
}

BallSceneTweakBar& BallSceneTweakBar::operator=(
    BallSceneTweakBar&& other) NOEXCEPT
{
  // move assignment operator (C++11)
  return *(new BallSceneTweakBar(other));
}

void BallSceneTweakBar::initialise()
{
  // TODO: add stuff here
  TwBar* antTweakBar = this->getAntTweakBar();
  TwAddSeparator(antTweakBar, nullptr, "");
  TwAddVarRO(antTweakBar, "nb_balls", TW_TYPE_UINT32, &this->numberOfBalls,
             "group=BallScene label='Number Of Vertices'");
  TwAddVarRO(antTweakBar, "nb_cubes", TW_TYPE_UINT32, &this->numberOfCubes,
             "group=BallScene label='Number Of Triangles'");

  std::ostringstream stringStream;
  stringStream.str(std::string());
  stringStream << this->getTweakBarName() << "/BallScene opened=true";
  TwDefine(stringStream.str().c_str());
  stringStream.str(std::string());
  stringStream << this->getTweakBarName() << "/Threads opened=true";
  TwDefine(stringStream.str().c_str());
  stringStream.str(std::string());
  stringStream << this->getTweakBarName() << "/Main opened=true";
  TwDefine(stringStream.str().c_str());
  stringStream.str(std::string());
  stringStream << this->getTweakBarName() << "/Visualization opened=true";
  TwDefine(stringStream.str().c_str());
  stringStream.str(std::string());
  stringStream << this->getTweakBarName() << "/Network opened=true";
  TwDefine(stringStream.str().c_str());
  stringStream.str(std::string());
  stringStream << this->getTweakBarName() << "/Simulation opened=true";
  TwDefine(stringStream.str().c_str());
}

#endif
