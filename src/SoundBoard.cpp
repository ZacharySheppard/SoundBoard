
#include "SoundBoard.h"
#include "Logger.hpp"
#include <iostream>
#include <ranges>

namespace stdr = std::ranges;
namespace stdv = std::views;

SoundBoard::SoundBoard(fs::path directory) noexcept {
  CreateAppDirectories(directory);
}

void SoundBoard::Run() {
  const auto samples = loadSamples();
  ui_.SetOnClickCallback(
      [this](fs::path path) { const auto success = player_.play(path); });
  ui_.render(samples);
}

void SoundBoard::CreateAppDirectories(fs::path directory) {
  if (!fs::exists(directory)) {
    fs::create_directories(directory);
  }
  configFilePath_ = directory / "config.sba";
  if (!fs::exists(configFilePath_)) {
  }

  samplesDirectory_ = directory / "samples";
  if (!fs::exists(samplesDirectory_)) {
    fs::create_directories(samplesDirectory_);
  }
}

std::vector<fs::path> SoundBoard::loadSamples() {
  auto samples =
      fs::directory_iterator{samplesDirectory_} |
      stdv::transform(&fs::directory_entry::path) |
      stdv::filter([](fs::path entry) { return entry.extension() == ".mp3"; }) |
      stdr::to<std::vector<fs::path>>();

  return samples;
}