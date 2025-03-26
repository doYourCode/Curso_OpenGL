#pragma once

#include <string>

namespace Common
{
	class TextureUtility
	{
	public:

		static unsigned int LoadFromFile(const std::string_view filePath);

		static unsigned int LoadFromFile(const std::array<const std::string_view, 6>& filesPaths);

		inline static const std::string& GetRootPath() { return s_RootPath; }

		inline static void SetRootPath(const std::string_view rootPath) { s_RootPath = rootPath; }

	private:

		static std::string s_RootPath;

		static void CheckFormat(void* data);

		static void Validate(unsigned int textureId);
	};
}