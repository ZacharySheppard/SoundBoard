#include "Platform.hpp"
#include "SoundBoard.h"

int main() {
  const auto localDataDirectory = LocalDataDirectory();
  const auto appDirectory = localDataDirectory / "SoundBoard";
  auto app = SoundBoard(appDirectory);

  app.Run();
  return EXIT_SUCCESS;
}