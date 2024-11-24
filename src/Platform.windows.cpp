#include "Platform.hpp"
#include "shlobj.h"
#include <sstream>
std::filesystem::path LocalDataDirectory() {
  wchar_t *localAppData = 0;
  SHGetKnownFolderPath(FOLDERID_LocalAppData, 0, NULL, &localAppData);

  std::wstringstream ss;
  ss << localAppData;

  CoTaskMemFree(static_cast<void *>(localAppData));
  return std::filesystem::path(ss.str());
}