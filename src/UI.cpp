#include "UI.hpp"
#include <format>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
void SoundBoardUI::render(std::vector<fs::path> paths) {
  using namespace ftxui;

  auto style = ButtonOption::Animated(Color::Default, Color::GrayDark,
                                      Color::Default, Color::White);

  const auto searchInput = Input(&search_, "Search for samples");

  auto container = Container::Vertical({searchInput});
  for (const auto path : paths) {
    std::string name = path.stem().string();
    auto button = Button(name, onClickCallback_, style);
    container->Add(button);
  }

  auto ui = Renderer(container, [&] {
    return vbox({
               container->Render() | vscroll_indicator | frame |
                   size(HEIGHT, LESS_THAN, 20),
           }) |
           border;
  });

  auto screen = ScreenInteractive::Fullscreen();
  screen.Loop(ui);
}

void SoundBoardUI::SetOnClickCallback(std::function<void(void)> callback) {
  onClickCallback_ = callback;
}