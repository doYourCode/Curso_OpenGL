#pragma once

#include <string>
#include <vector>

namespace Common
{
    class FileUtility
    {
    public:
        /**
         * @brief Carrega o conteúdo de um arquivo para uma string.
         *
         * @param filename O nome do arquivo a ser carregado.
         * @return Uma string contendo o conteúdo do arquivo.
         */
        static std::string LoadToString(const std::string_view filename);

        /**
         * @brief Salva o conteúdo de uma string em um arquivo.
         *
         * @param filename O nome do arquivo onde o conteúdo será salvo.
         * @param content O conteúdo a ser salvo no arquivo.
         */
        static void SaveFromString(const std::string_view filename, std::string_view content);

        /**
         * @brief Remove o caminho (diretórios) do nome do arquivo.
         *
         * @param filePath O caminho completo do arquivo.
         * @return O nome do arquivo, sem o caminho de diretórios.
         */
        static std::string RemovePathFromFileName(const std::string_view filePath);

        /**
         * @brief Abre um diálogo para carregar um arquivo.
         *
         * @param dialogText O texto exibido no diálogo (padrão: "Selecione um arquivo").
         * @param filtersArray Um vetor contendo os filtros de arquivos disponíveis.
         * @return O caminho do arquivo selecionado.
         */
        static std::string LoadDialog(const std::string_view dialogText = "Selecione um arquivo", const std::vector<const char*>& filtersArray = {});

        /**
         * @brief Abre um diálogo para salvar um arquivo.
         *
         * @param dialogText O texto exibido no diálogo (padrão: "Selecione um arquivo").
         * @param currentFileName O nome do arquivo atual (opcional).
         * @param filtersArray Um vetor contendo os filtros de arquivos disponíveis.
         * @return O caminho onde o arquivo será salvo.
         */
        static std::string SaveDialog(const std::string_view dialogText = "Selecione um arquivo", const std::string_view currentFileName = {}, const std::vector<const char*>& filtersArray = {});
    };
} // namespace Common


