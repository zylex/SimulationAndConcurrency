#include "IGame.h"

#include "GameStates.h"
#include "GlobeScene.h"

int main(int argc, char const* argv[])
{
  zge::IGame* game = zge::IGame::getInstance();
  game->setWindowTitle("Snow Globe Demo");
  game->addGameState(GameStates::GLOBE_SCENE, new GlobeScene);
  game->setNextState(GameStates::GLOBE_SCENE);
  return game->run();
}
