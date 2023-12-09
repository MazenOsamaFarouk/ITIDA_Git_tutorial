#include <QCoreApplication>
#include <QString>
#include <QTextStream>
#include <map>
#include <vector>
#include <QFile>
#include "qtextensions.h"

enum Emotion 
{
    Happy,
    Sad,
    Angry,
    Calm,
    Excited,
    Bored,
    Wrong
};

class QuoteManager 
{
private:
    void initVector(std::vector<QString> &v, const QString &filePath);
    void displayVector(const std::vector<QString> &v);
    Emotion getOppositeEmotion(const QString &str);
    void quoteFunction(Emotion emo, qint32 &counter);

    std::map<Emotion, std::vector<QString>> m;
    qint32 countHappy, countSad, countAngry, countCalm, countExcited, countBored;
    QTextStream &qin;
    QTextStream &qout;
public:
    QuoteManager(QTextStream &input, QTextStream &output);
    void handleProject();
};

QuoteManager::QuoteManager(QTextStream &input, QTextStream &output):countHappy(0), countSad(0), countAngry(0), countCalm(0), countExcited(0), countBored(0),qin(input), qout(output) 
{
    // Define file paths
    QString happyFile = "/home/mohanad/QT_Quote/happy.txt";
    QString sadFile = "/home/mohanad/QT_Quote/sad.txt";
    QString angryFile = "/home/mohanad/QT_Quote/angry.txt";
    QString calmFile = "/home/mohanad/QT_Quote/calm.txt";
    QString excitedFile = "/home/mohanad/QT_Quote/excited.txt";
    QString boredFile = "/home/mohanad/QT_Quote/bored.txt";

    // Init all vectors
    initVector(m[Emotion::Happy], happyFile);
    initVector(m[Emotion::Sad], sadFile);
    initVector(m[Emotion::Angry], angryFile);
    initVector(m[Emotion::Calm], calmFile);
    initVector(m[Emotion::Excited], excitedFile);
    initVector(m[Emotion::Bored], boredFile);
}

void QuoteManager::initVector(std::vector<QString> &v, const QString &filePath) 
{
    QFile file(filePath);
    file.open(QFile::ReadOnly);
    QTextStream stream(&file);
    while (!stream.atEnd()) 
    {
        QString temp = stream.readLine();
        v.push_back(temp);
    }
    file.close();
}

void QuoteManager::displayVector(const std::vector<QString> &v) 
{
    for (qint32 i = 0; i < v.size(); i++) 
    {
        qout << v[i] << Qt::endl;
    }
}

Emotion QuoteManager::getOppositeEmotion(const QString &str) 
{
    if (str == "happy") 
    {
        return Emotion::Sad;
    } 
    else if (str == "sad") 
    {
        return Emotion::Happy;
    } 
    else if (str == "angry") 
    {
        return Emotion::Calm;
    } 
    else if (str == "calm") 
    {
        return Emotion::Angry;
    } 
    else if (str == "excited") 
    {
        return Emotion::Bored;
    } 
    else if (str == "bored") 
    {
        return Emotion::Excited;
    } 
    else 
    {
        return Emotion::Wrong;
    }
}

void QuoteManager::quoteFunction(Emotion emo, qint32 &counter) 
{
    auto vec = m[emo];
    qout << vec[counter] << Qt::endl;
    if (counter == 6) 
    {
        counter = 0;
    } 
    else 
    {
        counter++;
    }
}

void QuoteManager::handleProject() 
{
    while (true) 
    {
        qout << "Enter emotion [happy, sad, angry, calm, excited, bored]" << Qt::endl;
        QString userEmotion = qin.readLine();
        system("clear");
        Emotion realEmotion = getOppositeEmotion(userEmotion);
        switch (realEmotion) {
            case Emotion::Happy:
                quoteFunction(Emotion::Happy, countHappy);
                break;
            case Emotion::Sad:
                quoteFunction(Emotion::Sad, countSad);
                break;
            case Emotion::Angry:
                quoteFunction(Emotion::Angry, countAngry);
                break;
            case Emotion::Calm:
                quoteFunction(Emotion::Calm, countCalm);
                break;
            case Emotion::Excited:
                quoteFunction(Emotion::Excited, countExcited);
                break;
            case Emotion::Bored:
                quoteFunction(Emotion::Bored, countBored);
                break;
            case Emotion::Wrong:
                qout << "Wrong emotion. Try again" << Qt::endl;
                break;
        }
    }
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Create QTextStream instances for input and output
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    // Create an object of QuoteManager
    QuoteManager quoteManager(qin, qout);

    // Handle the project using QuoteManager
    quoteManager.handleProject();

    return a.exec();
}
