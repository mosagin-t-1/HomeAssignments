#include "Autobot.h"
#include "Decepticon.h"
#include "Minicon.h"
#include "Team.h"
#include <gtest/gtest.h>
#include <sstream>
#include <vector>

TEST(TransformerTest, ParamConstructor) {
    Autobot t(1, 2, 3, 4, 5, "blue");
    EXPECT_EQ(t.getLevel(), 1u);
    EXPECT_EQ(t.getStrength(), 2u);
    EXPECT_EQ(t.getRange(), 3u);
    EXPECT_EQ(t.getFuel(), 4u);
    EXPECT_EQ(t.getAmmo(), 5u);
}

TEST(AutobotTest, ColorAndAmmo) {
    Autobot a(1, 2, 3, 4, 5, "blue");
    EXPECT_EQ(a.getColor(), "blue");
    EXPECT_EQ(a.getAmmo(), 5u);
}

TEST(DecepticonTest, WeaponPower) {
    Decepticon d(1, 2, 3, 4, 5, 123);
    EXPECT_EQ(d.getWeaponPower(), 123u);
}

TEST(MiniconTest, Speed) {
    Minicon m(1, 2, 3, 4, 5, 250);
    EXPECT_EQ(m.getSpeed(), 250u);
}

TEST(OperatorTest, OutputNotEmpty) {
    Autobot t(1, 2, 3, 4, 5, "blue");
    std::ostringstream os;
    os << t;
    std::string s = os.str();
    EXPECT_FALSE(s.empty());
}

TEST(PolymorphismTest, VirtualCallsFromBasePointer) {
    Autobot a1;
    Decepticon d1;
    Minicon m1;
    std::vector<Transformer *> v;
    v.push_back(&a1);
    v.push_back(&d1);
    v.push_back(&m1);
    for (Transformer *t : v) {
        t->printClass();
        t->printAction();
    }
    SUCCEED();
}

TEST(AutobotCompositionTest, InternalMiniconAccessibleAndIndependent) {
    Autobot a1;
    Autobot a2;
    a1.setMiniconSpeed(111);
    EXPECT_EQ(a1.getMinicon().getSpeed(), 111u);
    EXPECT_EQ(a2.getMinicon().getSpeed(), 200u);
    a2.setMiniconSpeed(222);
    EXPECT_EQ(a2.getMinicon().getSpeed(), 222u);
    EXPECT_EQ(a1.getMinicon().getSpeed(), 111u);
}

TEST(TeamAssociationTest, TeamHoldsPointersAndDoesNotOwn) {
    Autobot* a = new Autobot();
    Decepticon* d = new Decepticon();
    a->setLevel(7);
    d->setLevel(9);
    Team team;
    team.addMember(a);
    team.addMember(d);
    EXPECT_EQ(team.size(), 2u);
    delete d;
    team.removeMember(d);
    EXPECT_EQ(team.size(), 1u);
    EXPECT_EQ(a->getLevel(), 7u);
    delete a;
}

TEST(VectorPolymorphismTest, IterateAndCall) {
    Autobot a1;
    Decepticon d1;
    Minicon m1;
    std::vector<Transformer*> v = { &a1, &d1, &m1 };
    for (auto t : v) {
        EXPECT_NE(t, nullptr);
        t->printClass();
    }
    SUCCEED();
}

/* New tests added to reach 15 total */

TEST(TransformerActionTest, FireDecreasesAmmo) {
    Autobot t;
    t.setAmmo(3);
    EXPECT_EQ(t.getAmmo(), 3u);
    EXPECT_TRUE(t.fire());
    EXPECT_EQ(t.getAmmo(), 2u);
}

TEST(TransformerMoveTransformTest, MoveAndTransformReturnTrue) {
    Autobot t;
    EXPECT_TRUE(t.move());
    EXPECT_TRUE(t.transform());
}

TEST(DecepticonAttackTest, AttackReturnsTrue) {
    Decepticon d;
    EXPECT_TRUE(d.attack());
}

TEST(MiniconAssistTest, AssistReturnsTrue) {
    Minicon m;
    EXPECT_TRUE(m.assist());
}

TEST(AutobotCopyTest, CopyHasIndependentMinicon) {
    Autobot original;
    original.setMiniconSpeed(42);
    Autobot copy = original;
    EXPECT_EQ(original.getMinicon().getSpeed(), 42u);
    EXPECT_EQ(copy.getMinicon().getSpeed(), 42u);
    copy.setMiniconSpeed(99);
    EXPECT_EQ(original.getMinicon().getSpeed(), 42u);
    EXPECT_EQ(copy.getMinicon().getSpeed(), 99u);
}

TEST(TeamRemoveNonMemberTest, RemovingNonMemberDoesNothing) {
    Autobot a;
    Decepticon d;
    Team team;
    team.addMember(&a);
    EXPECT_EQ(team.size(), 1u);
    team.removeMember(&d);
    EXPECT_EQ(team.size(), 1u);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

