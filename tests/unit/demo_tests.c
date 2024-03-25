#include <unity.h>
#include <mathz.h>

void test_add_positive_numbers() 
{
    TEST_ASSERT_EQUAL(4, sum(2,2));
}

void test_add_negative_numbers() 
{
    TEST_ASSERT_EQUAL(0, sum(2,-2));
}

void setUp()
{

}

void tearDown()
{

}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_add_positive_numbers);
    RUN_TEST(test_add_negative_numbers);
    return UNITY_END();
}