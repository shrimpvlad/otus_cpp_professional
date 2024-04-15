#include <gtest/gtest.h>
#include "version.h"

TEST(CheckVersionNumber, correct_version) {
    ASSERT_GT(int(VERSION), 1);
}