#pragma once

#include <string>

namespace Common
{
	class ShaderUtility
	{
	public:

		static unsigned int LoadFromFile(const std::string_view vsFilePath, const std::string_view fsFilePath, const std::string_view tcsFilePath = {}, const std::string_view tesFilePath = {}, const std::string_view gsFilePath = {});

		static unsigned int LoadFromFile(const std::string_view vsFilePath, const std::string_view fsFilePath, const std::string_view gsFilePath);

		static unsigned int CreateFromString(const std::string_view vsString, const std::string_view fsString, const std::string_view tcsString = {}, const std::string_view tesString = {}, const std::string_view gsString = {});

		static unsigned int CreateFromString(const std::string_view vsString, const std::string_view fsString, const std::string_view gsString);

		inline const std::string& GetRootPath() const { return s_RootPath; }

		inline void SetRootPath(const std::string_view rootPath) const { s_RootPath = rootPath; }

	private:

		static std::string s_RootPath;

		static void Validate(unsigned int shaderId);

		static void ValidateProgram(unsigned int programId);
	};
}