#include "FileUtility.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "external/tinyfiledialogs.h"

namespace Common
{
	std::string FileUtility::LoadToString(const std::string_view filename)
	{
		try
		{
			std::ifstream inputFile(filename.data(), std::ios::binary);
			if (!inputFile)
			{
				std::cerr << "Error: Failed to open file: " << filename << std::endl;
				return std::string();
			}
			return { std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>() };
		}
		catch (const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
			return std::string();
		}
	}

	void FileUtility::SaveFromString(const std::string_view filename, std::string_view content)
	{
		std::ofstream outputStr(filename.data(), std::ios::binary);
		if (!outputStr)
		{
			std::cerr << "Error: Failed to open file " << filename << " for writing.\n";
			return;
		}

		outputStr.write(content.data(), content.size());

		if (!outputStr) // Check if the write was successful
		{
			std::cerr << "Error: Failed to write to file " << filename << ".\n";
		}
	}

	std::string FileUtility::RemovePathFromFileName(const std::string_view filePath)
	{
		return std::filesystem::path(filePath).filename().string();
	}

	std::string FileUtility::LoadDialog(const std::string_view dialogText, const std::vector<const char*>& filtersArray)
	{
		if (auto filePath = tinyfd_openFileDialog(dialogText.data(), "", (int)filtersArray.size(), filtersArray.data(), nullptr, false))
			return filePath;
		
		return {}; // https://stackoverflow.com/questions/26587110/returning-an-empty-string-efficient-way-in-c
	}

	std::string FileUtility::SaveDialog(const std::string_view dialogText, const std::string_view currentFileName, const std::vector<const char*>& filtersArray)
	{
		if (auto filePath = tinyfd_saveFileDialog(dialogText.data(), currentFileName.data(), (int)filtersArray.size(), filtersArray.data(), nullptr))
			return filePath;

		return {};
	}
}