#include "UI.hpp"
#include <format>

#include <ranges>
namespace stdr = std::ranges;
namespace stdv = std::views;
void SoundBoardUI::render(std::vector<fs::path> paths) {
  using namespace ftxui;
  paths_ = paths;

  auto searchInput = Input(&search_, "Search for samples");
  auto container = ftxui::Container::Vertical({});

  auto buttons = Renderer(container, [&] {
    for (const auto path : FindMatches(paths, search_)) {
      container->Add(MakeButton(path));
    }
    return vbox({
               searchInput->Render() | frame,
               separator(),
               container->Render() | vscroll_indicator | frame |
                   size(HEIGHT, LESS_THAN, 20),
           }) |
           border;
  });
  auto screen = ScreenInteractive::Fullscreen();
  screen.Loop(buttons);
}

void SoundBoardUI::SetOnClickCallback(std::function<void(fs::path)> callback) {
  onClickCallback_ = callback;
}

ftxui::Component SoundBoardUI::MakeButton(fs::path path) {
  using namespace ftxui;
  const auto style = ButtonOption::Animated(Color::Default, Color::GrayDark,
                                            Color::Default, Color::White);
  std::string name = path.stem().string();
  const auto callback = [path, this] { onClickCallback_(path); };
  auto button = Button(name, callback, style);
  return button;
}

std::vector<fs::path> SoundBoardUI::FindMatches(std::vector<fs::path> paths,
                                                std::string str) {
  if (str.empty()) {
    return paths;
  }
  std::vector<fs::path> outputs;
  for (const auto path : paths) {
    const auto asString = path.string();
    if (stdr::includes(asString, str)) {
      outputs.push_back(fs::path(path));
    }
  }

  return outputs;
}