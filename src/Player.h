#pragma once
#include <map>
#include <string>

class MP3Player {
public:
  [[nodiscard]] bool play(std::string filename);

private:
  int count_ = 0;
};