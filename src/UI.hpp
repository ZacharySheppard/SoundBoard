#include <filesystem>
#include <functional>
namespace fs = std::filesystem;

class SoundBoardUI {
public:
  void render(std::vector<fs::path> paths);
  void SetOnClickCallback(std::function<void(void)> onClick);

private:
  std::function<void(void)> onClickCallback_{};
  std::string search_;
};