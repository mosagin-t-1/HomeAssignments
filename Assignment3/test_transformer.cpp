#include "Autobot.h"
#include "Decepticon.h"
#include "Minicon.h"
#include <gtest/gtest.h>

TEST(TransformerTest, LevelCheck) {
    Transformer t;
    t.setLevel(10);
    EXPECT_EQ(t.getLevel(), 10u);
}

TEST(AutobotTest, ColorCheck) {
    Autobot a;
    a.setColor("blue");
    EXPECT_EQ(a.getColor(), "blue");
}

TEST(DecepticonTest, WeaponPowerCheck) {
    Decepticon d;
    d.setWeaponPower(200);
    EXPECT_EQ(d.getWeaponPower(), 200u);
}

TEST(MiniconTest, SpeedCheck) {
    Minicon m;
    m.setSpeed(150);
    EXPECT_EQ(m.getSpeed(), 150u);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

