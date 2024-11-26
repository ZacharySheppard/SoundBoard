#include "Player.h"
#include "Logger.hpp"
#include <filesystem>
#include <format>
#include <windows.h>

namespace {
namespace fs = std::filesystem;

void PlayAlias(const std::string &alias) {
  const auto playString = std::format("play {}", alias);
  log("[CMD] " + playString);
  mciSendString(playString.c_str(), NULL, 0, NULL);
}

std::string LoadFile(const std::string &filename, int count) {
  log("loading file " + filename);
  const std::string alias = std::format("sound{}", count);
  log("made alias " + alias + " for file " + filename);
  const auto openCmd =
      std::format("open {} type mpegvideo alias {}", filename, alias);
  log("[CMD] " + openCmd);
  mciSendString(openCmd.c_str(), NULL, 0, NULL);
  return alias;
}
} // namespace

bool MP3Player::play(fs::path filename) {
  if (!fs::exists(filename)) {
    log("couldn't find file");
    return false;
  };

  auto alias = LoadFile(filename.string(), count_);
  count_++;
  PlayAlias(alias);
  return true;
}