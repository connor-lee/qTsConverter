#pragma once

#include "Parser.hpp"

class CsvParser : public Parser
{
  public:
    CsvParser() = default;
    explicit CsvParser(InOutParameter parameter);
    CsvParser(const CsvParser &) = delete;
    CsvParser(CsvParser &&)      = delete;
    ~CsvParser() override        = default;

    CsvParser &operator=(const CsvParser &) = delete;
    CsvParser &operator=(CsvParser &&) = delete;

    std::pair<Translations, QString> parse() const override;

  private:
    std::pair<QString, int> decodeLocation(const QString &str) const;
    void removeEmptyFrontBack(QList<QStringList> &list) const;
    void splitMergedString(QList<QStringList> &list) const;
    void splitByRow(QList<QStringList> &list) const;
    void removeQuote(QList<QStringList> &list) const;
    const int m_minimumSize{ 4 };
    bool isLocation(const QString value) const;

    const int kNameIndex{ 0 };
    const int kSourceIndex{ 1 };
    const int kTranslationIndex{ 2 };
    const int kLocationsIndex{ 3 };
    const int kRowSize{ 8 };
};
