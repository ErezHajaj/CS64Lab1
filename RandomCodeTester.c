#include <stdio.h>
#include "RandomCode.h"

/* To make:
 * $ gcc RandomCodeTester.c RandomCode.c -o random_tester
 *
 * To run:
 * $ ./random_tester
 */

#define NUM_TEST_CASES 12
#define NUM_FUNCS 12

/* forward decls */
static int printOriginalValue(int);
static int setBits4through9Wrapper(int);

struct func {
    int (* fptr)(int);
    char *name;
};

struct func FUNCS[NUM_FUNCS] = {
      { printOriginalValue, "printOriginalValue" }
    , { multiplyBy8, "multiplyBy8" }
    , { setBit6to1, "setBit6to1" }
    , { setBit3to0, "setBit3to0" }
    , { flipBit5, "flipBit5" }
    , { ifBit7is0, "ifBit7is0" }
    , { ifBit3is1, "ifBit3is1" }
    , { unsignedBits0through5, "unsignedBits0through5" }
    , { unsignedBits6through9, "unsignedBits6through9" }
    , { signedBits0through5, "signedBits0through5" }
	, { signedBits6through9, "signedBits6through9" }
	, { setBits4through9Wrapper, "setBits4through9" }
};

int TESTS[NUM_TEST_CASES][NUM_FUNCS] = {
    /* { { original value, setBit6to1, setBit3to0, flipBit5, ifBit7is0,
     *    ifBit3is1, unsignedBits0through5, unsignedBits6through9, signedBits0through5,
     *     signedBits6through9, setBits4through9 } }
     * [inner array is same order as FUNCS array ]
     */
      {  7, 56, 71, 7, 39, 1, 0, 7, 0, 7, 0, 119 }
    , {  1, 8, 65, 1, 33, 1, 0, 1, 0, 1, 0, 113 }
    , { 65535, 524280, 65535, 65527, 65503, 0, 1, 63, 15, -1, -1, 64639 }
    , { 119, 952, 119, 119, 87, 1, 0, 55, 1, -9, 1, 119 }
    , { 821, 6568, 885, 821, 789, 1, 0, 53, 12, -11, -4, 117 }
    , { 948, 7584, 1012, 948, 916, 0, 0, 52, 14, -12, -2, 116 }
    , { 1018, 8144, 1018, 1010, 986, 0, 1, 58, 15, -6, -1, 122 }
    , { 3319, 26552, 3319, 3319, 3287, 0, 0, 55, 3, -9, 3, 3191 }
    , { 911, 7288, 975, 903, 943, 0, 1, 15, 14, 15, -2, 127 }
    , { -1, -8, -1, -9, -33, 0, 1, 63, 15, -1, -1, -897 }
    , { -598, -4784, -534, -606, -630, 0, 1, 42, 6, -22, 6, -902 }
    , { -2004, -16032, -1940, -2012, -2036, 1, 1, 44, 0, -20, 0, -1924 }
};

int
main(
    int argc,
    char *argv[])
{
    int i, j, rv;
    int passed_all = 1;

    for (i = 0; i < NUM_TEST_CASES; i++) {
        int failed = 0;
        for (j = 0; j < NUM_FUNCS; j++) {
            if ((rv = FUNCS[j].fptr(TESTS[i][0])) != TESTS[i][j]) {
                failed++;
                printf("\tFunction '%s' failed (Expected: %d, Got %d)\n",
                    FUNCS[j].name, TESTS[i][j], rv);
            }
        }
        if (failed) {
            passed_all = 0;
            printf("\t...failed %d tests\n", failed);
        } else {
            printf("\t...passed.\n");
        }
    }
    if (passed_all) {
        printf("Passed all tests\n"
               "\t(WARNING: this test suite is not exhaustive and cannot be\n"
               "\tused to verify your code is working entirely correctly)\n");
    } else {
        printf("Failed one or more tests\n"
               "\t(WARNING: this test suite is not exhaustive and cannot be\n"
               "\tused to verify your code is working entirely correctly)\n");
    }
}

static int
printOriginalValue(
    int v)
{
    printf("Tests for '%d'\n", v);
    return (v);
}

static int
setBits4through9Wrapper(
    int v)
{
    return (setBits4through9(v, 7));
}
