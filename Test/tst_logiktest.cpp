#include <QString>
#include <QtTest>

class LogikTest : public QObject
{
    Q_OBJECT

public:
    LogikTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

LogikTest::LogikTest()
{
}

void LogikTest::initTestCase()
{
}

void LogikTest::cleanupTestCase()
{
}

void LogikTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(LogikTest)

#include "tst_logiktest.moc"
