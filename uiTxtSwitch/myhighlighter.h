#ifndef MYHIGHLIGHTER_H
#define MYHIGHLIGHTER_H

#include <QVector>
//#include <QTextDocument>
#include <QTextFormat>
#include <QSyntaxHighlighter>

class MyHighLighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    MyHighLighter(QTextDocument *parent =0);
    ~MyHighLighter();

    void Init();
    void setSearchMode(bool ok =false);
    void findTxt(QString &search_text);

protected:
    void highlightBlock(const QString &txt) Q_DECL_OVERRIDE;

signals:
    void searchRes(bool bFind);

private:
    struct HighLightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };

    QVector<HighLightingRule > highlightRules;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    //QTextCharFormat multiLineCommentFormat;

    bool bSearchMode;
    QRegExp searchePattern;
    QTextCharFormat searchFormat;

};

#endif // MYHIGHLIGHTER_H
