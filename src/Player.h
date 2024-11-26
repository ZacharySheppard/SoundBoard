#pragma once
#include <filesystem>
#include <map>
#include <string>

namespace fs = std::filesystem;
class MP3Player {
public:
  [[nodiscard]] bool play(fs::path filename);

private:
  int count_ = 0;
};