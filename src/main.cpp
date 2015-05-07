#include "IGame.h"

#include "GameStates.h"
#include "BallScene.h"

int main(int argc, char const* argv[])
{
  zge::IGame* game = zge::IGame::getInstance();
  game->setWindowTitle("08964: Simulation and Concurrency");
  game->addGameState(GameStates::BALL_SCENE, new BallScene);
  game->setNextState(GameStates::BALL_SCENE);
  return game->run();
}
