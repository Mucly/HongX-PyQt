#include "myhighlighter.h"

#include <QDebug>
#include <QRegExp>

MyHighLighter::MyHighLighter(QTextDocument *parent)
    :QSyntaxHighlighter(parent)
{
    Init();
}

MyHighLighter::~MyHighLighter()
{

}

void MyHighLighter::Init()
{
    bSearchMode = false;

    // @ keyword format
    HighLightingRule rule;
    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);

    QStringList ltKeywordPatterns;
    ltKeywordPatterns << "\\bchar\\b" << "\\bclass\\b" << "\\bdouble\\b"
                      << "\\bnumber\\b" << "\\bUInt\\b" << "\\blonglong\\b"
                      << "\\bpixmap\\b" << "\\bbool\\b" << "\\bend\\b";
    foreach (const QString &pattern, ltKeywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightRules.append(rule);
    }

    // @ class format
    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::green);
    rule.format = classFormat;
    rule.pattern = QRegExp("\\b[0-9]?Ctm[A-Za-z0-9]+\\b");
    highlightRules.append(rule);

    // @ single line format
    singleLineCommentFormat.setForeground(Qt::yellow);
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightRules.append(rule);

    // @ search format
    searchFormat.setFontWeight(QFont::Bold);
    searchFormat.setForeground(Qt::red);
    searchFormat.setBackground(Qt::lightGray);
}

void MyHighLighter::setSearchMode(bool ok)
{
    bSearchMode = ok;
    rehighlight();
}

void MyHighLighter::findTxt(QString &search_text)
{
    bSearchMode = true;
    //searchePattern = QRegExp("\\bend\\b");
    searchePattern = QRegExp(QString("\\b%1\\b").arg(search_text));
    rehighlight();

}

/*
 * 高亮显示指定子串
 */
void MyHighLighter::highlightBlock(const QString &txt)
{   
    //if(bSearchMode)
    //qDebug() << "*********** txt =" << txt.length();

    if(txt.isEmpty()) return;

    foreach (const HighLightingRule &rule, highlightRules) {
        QRegExp expression(rule.pattern);
        //int index = txt.indexOf(expression);
        int index = expression.indexIn(txt);

        while(index>=0){
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            //index = txt.indexOf(expression, index+length);
            index = expression.indexIn(txt, index+length);
        }
    }

    if(bSearchMode){
        bool flag = false;
        QRegExp expression(searchePattern);
        //int index = txt.indexOf(expression);
        int index = expression.indexIn(txt);
        while(index>=0){
            int length = expression.matchedLength();
            setFormat(index, length, searchFormat);
            //index = txt.indexOf(expression, index+length);
            index = expression.indexIn(txt, index+length);
            flag = true;
        }
        //bSearchMode =false;
        emit searchRes(flag);
        //qDebug() << "********* flag =" << flag << ", expression =" << expression;
    }
}
