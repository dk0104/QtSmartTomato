#include "gtest/gtest.h"

class TimerTestFixture: public ::testing::Test
{
public:
    TimerTestFixture():Test() {

    }
    ~TimerTestFixture(){

    }
protected:
    virtual void SetUp(){

    }

    virtual void TearDown(){

    }
};

TEST_F(TimerTestFixture,TimerElapsed_TimerEventRecieved){
    EXPECT_EQ(1,1);
}
