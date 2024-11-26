#include <filesystem>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <functional>

namespace fs = std::filesystem;

class SoundBoardUI {
public:
  void render(std::vector<fs::path> paths);
  void SetOnClickCallback(std::function<void(fs::path)> onClick);

private:
  ftxui::Component MakeButton(fs::path path);
  std::vector<fs::path> FindMatches(std::vector<fs::path> paths,
                                    std::string filter);

private:
  ftxui::Component ui_;
  ftxui::Component buttons_;
  std::function<void(fs::path)> onClickCallback_{};
  std::vector<fs::path> paths_;
  std::string search_;
};