#pragma once

#include "Player.h"
#include "UI.hpp"
#include <filesystem>
#include <utility>
#include <vector>

namespace fs = std::filesystem;

class SoundBoard {
public:
  SoundBoard(fs::path directory) noexcept;
  void Run();

private:
  void CreateAppDirectories(fs::path directory);
  std::vector<fs::path> loadSamples();

private:
  fs::path samplesDirectory_;
  fs::path configFilePath_;
  bool shouldClose_ = false;
  uint32_t count_ = 1;
  MP3Player player_;
  SoundBoardUI ui_;
};