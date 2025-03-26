#pragma once

#include <string>
#include <vector>

namespace Common
{
    class FileUtility
    {
    public:
        /**
         * @brief Carrega o conte�do de um arquivo para uma string.
         *
         * @param filename O nome do arquivo a ser carregado.
         * @return Uma string contendo o conte�do do arquivo.
         */
        static std::string LoadToString(const std::string_view filename);

        /**
         * @brief Salva o conte�do de uma string em um arquivo.
         *
         * @param filename O nome do arquivo onde o conte�do ser� salvo.
         * @param content O conte�do a ser salvo no arquivo.
         */
        static void SaveFromString(const std::string_view filename, std::string_view content);

        /**
         * @brief Remove o caminho (diret�rios) do nome do arquivo.
         *
         * @param filePath O caminho completo do arquivo.
         * @return O nome do arquivo, sem o caminho de diret�rios.
         */
        static std::string RemovePathFromFileName(const std::string_view filePath);

        /**
         * @brief Abre um di�logo para carregar um arquivo.
         *
         * @param dialogText O texto exibido no di�logo (padr�o: "Selecione um arquivo").
         * @param filtersArray Um vetor contendo os filtros de arquivos dispon�veis.
         * @return O caminho do arquivo selecionado.
         */
        static std::string LoadDialog(const std::string_view dialogText = "Selecione um arquivo", const std::vector<const char*>& filtersArray = {});

        /**
         * @brief Abre um di�logo para salvar um arquivo.
         *
         * @param dialogText O texto exibido no di�logo (padr�o: "Selecione um arquivo").
         * @param currentFileName O nome do arquivo atual (opcional).
         * @param filtersArray Um vetor contendo os filtros de arquivos dispon�veis.
         * @return O caminho onde o arquivo ser� salvo.
         */
        static std::string SaveDialog(const std::string_view dialogText = "Selecione um arquivo", const std::string_view currentFileName = {}, const std::vector<const char*>& filtersArray = {});
    };
} // namespace Common


