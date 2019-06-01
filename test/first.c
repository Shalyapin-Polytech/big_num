#include "big_num.h"
#include "test.h"

void test() {
    //test_from_string
    big_num num1 = from_string("1234567890");
    int num1_digits[4] = {890, 567, 234, 1};
    assert_int_equals(4, num1.size);
    assert_int_array_equals(num1_digits, num1.digits, 4);

    big_num zero = from_string("0");
    int zero_digits[1] = {0};
    assert_int_equals(1, zero.size);
    assert_int_array_equals(zero_digits, zero.digits, 1);

    //test_to_string
    assert_strings_equals("1234567890", to_string(num1));
    assert_strings_equals("0", to_string(zero));

    //test_add
    big_num add1 = from_string("1234567890");
    big_num add2 = from_string("8765432110");
    assert_big_nums_equals(from_string("10000000000"), add(add1, add2));

    big_num add3 = from_string("44455522223");
    assert_big_nums_equals(add3, add(add3, zero));

    //test_sub
    big_num sub2 = from_string("234000890");
    assert_big_nums_equals(from_string("1000567000"), sub(num1, sub2));

    big_num sub4 = from_string("98765432198");
    assert_big_nums_equals(from_string("97530864308"), sub(num1, sub4));

    assert_big_nums_equals(num1, sub(num1, zero));

    big_num diff3 = sub(num1, num1);
    assert_int_equals(1, diff3.size);
    assert_big_nums_equals(from_string("0"), diff3);

    //test_shift
    big_num sh1 = from_string("12345");
    assert_big_nums_equals(from_string("1234500000"), shift(sh1, 5));

    assert_big_nums_equals(sh1, shift(sh1, 0));

    assert_big_nums_equals(zero, shift(zero, 5));

    //test_mul
    big_num mul1 = from_string("123654789");
    big_num mul2 = from_string("369852147");
    assert_big_nums_equals(from_string("45733989198481983"), mul(mul1, mul2));

    assert_big_nums_equals(zero, mul(mul1, zero));

    big_num one = from_string("1");
    assert_big_nums_equals(from_string("123654789"), mul(mul1, one));

    //test_div
    big_num div1 = from_string("4365478943654789");
    assert_big_nums_equals(from_string("1"), div_euc(div1, div1).quotient);
    assert_big_nums_equals(from_string("0"), div_euc(div1, div1).remainder);

    big_num div2 = from_string("2182193923");
    assert_big_nums_equals(from_string("2000500"), div_euc(div1, div2).quotient);
    assert_big_nums_equals(from_string("693289"), div_euc(div1, div2).remainder);
}