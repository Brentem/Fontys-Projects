#include <protocol_handler.h>
#include <unity.h>

void test_protocol_handler_get_nibbles(void)
{
    uint8_t value = 255;
    uint8_t high = 0;
    uint8_t low = 0;

    TEST_ASSERT_EQUAL(0, protocol_handler_get_nibbles(value, &high, &low));
    TEST_ASSERT_EQUAL(0x0F, high);
    TEST_ASSERT_EQUAL(0x0F, low);
}

void test_protocol_handler_get_nibbles_nullptr(void)
{
    uint8_t value = 255;
    uint8_t high = 0;
    uint8_t low = 0;

    TEST_ASSERT_EQUAL(-1, protocol_handler_get_nibbles(value, NULL, NULL));
}

void test_protocol_handler_format_two_bytes()
{
    uint8_t nibbles[4];
    uint16_t value = 65535;
    uint8_t expectedNibbles[4] = {0x0F, 0x0F, 0x0F, 0x0F};

    TEST_ASSERT_EQUAL(0, protocol_handler_format_two_bytes(value, nibbles, sizeof(nibbles)/ sizeof(nibbles[0])));

    TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedNibbles, nibbles, 4);
}

void test_protocol_handler_format_two_bytes_bits_not_all_on()
{
    uint8_t nibbles[4];
    uint16_t value = 5000;
    uint8_t expectedNibbles[4] = {0x01, 0x03, 0x08, 0x08};

    TEST_ASSERT_EQUAL(0, protocol_handler_format_two_bytes(value, nibbles, sizeof(nibbles)/ sizeof(nibbles[0])));

    TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedNibbles, nibbles, 4);
}

void test_protocol_handler_format_byte()
{
    uint8_t nibbles[2];
    uint8_t value = 255;
    uint8_t expectedNibbles[2] = {0x0F, 0x0F};

    TEST_ASSERT_EQUAL(0, protocol_handler_format_byte(value, nibbles, sizeof(nibbles) / sizeof(nibbles[0])));

    TEST_ASSERT_EQUAL_UINT8_ARRAY(expectedNibbles, nibbles, 2);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_protocol_handler_get_nibbles);
    RUN_TEST(test_protocol_handler_get_nibbles_nullptr);
    RUN_TEST(test_protocol_handler_format_two_bytes);
    RUN_TEST(test_protocol_handler_format_two_bytes_bits_not_all_on);
    RUN_TEST(test_protocol_handler_format_byte);
    UNITY_END();

    return 0;
}