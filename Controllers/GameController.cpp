#include"GameController.h"
//source:
//https://www.delftstack.com/howto/cpp/how-to-get-list-of-files-in-a-directory-cpp/
//https://stackoverflow.com/questions/48312460/c17-filesystem-is-not-a-namespace-name
//https://en.cppreference.com/w/cpp/experimental/fs/path
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 1
#if __cplusplus < 201703L// If the version of C++ is less than 17
// It was still in the experimental:: namespace
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif


GameController::GameController(ConsoleViewer* consoleViewer)
{
	viewer = consoleViewer;
}

String getPlayerNameFromPath(fs::path path) {
	int index = 0;
	char c[100];
	while (strcmp((const char*)(path.filename().c_str() + index), ".")) {
		c[index] = *(const char*)(path.filename().c_str() + index);
		index++;
	}
	c[index] = '\0';
	return c;
}

const char* GameController::selectPlayer()
{
	Vector<String> options;
	for (const auto& entry : fs::directory_iterator("./data/"))
	{
		//String n = getPlayerNameFromPath(entry.path());
		
		std::cout << getPlayerNameFromPath(entry.path()) << std::endl;
	}

	system("pause");
	return "";
}
