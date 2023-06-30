#!/bin/bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
TEST_DIR=$1
CAT_DIR=$2
PATTERN="$TEST_DIR/pattern.txt"
FILE_1="$TEST_DIR/s21_grep_c.txt"
FILE_2="$TEST_DIR/s21_grep_h.txt"
FILE_3="$TEST_DIR/Makefile.txt"
GREP="$CAT_DIR/s21_grep"
echo "" >>log.txt

for var in -v -c -l -n -h -o; do
        TEST1="for( $FILE_1 $FILE_2 $FILE_3"
        echo "$TEST1"
        $GREP $TEST1 >s21_grep.txt
        grep $TEST1 >grep.txt
        DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
        if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
          ((COUNTER_SUCCESS++))
        else
          echo "$TEST1" >>log.txt
          ((COUNTER_FAIL++))
        fi
        rm s21_grep.txt grep.txt

        TEST2="for $FILE_1"
        echo "$TEST2"
        $GREP $TEST2 >s21_grep.txt
        grep $TEST2 >grep.txt
        DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
        if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
          ((COUNTER_SUCCESS++))
        else
          echo "$TEST2" >>log.txt
          ((COUNTER_FAIL++))
        fi
        rm s21_grep.txt grep.txt

        TEST3="-e ^int $FILE_1 $FILE_2 $FILE_3"
        echo "$TEST3"
        $GREP $TEST3 >s21_grep.txt
        grep $TEST3 >grep.txt
        DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
        if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
          ((COUNTER_SUCCESS++))
        else
          echo "$TEST3" >>log.txt
          ((COUNTER_FAIL++))
        fi
        rm s21_grep.txt grep.txt

        TEST4="-e ^int $FILE_1"
        echo "$TEST4"
        $GREP $TEST4 >s21_grep.txt
        grep $TEST4 >grep.txt
        DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
        if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]; then
          ((COUNTER_SUCCESS++))
        else
          echo "$TEST4" >>log.txt
          ((COUNTER_FAIL++))
        fi
        rm s21_grep.txt grep.txt
done

echo "GREP_SUCCESS: $COUNTER_SUCCESS" >>log.txt
echo "GREP_FAIL: $COUNTER_FAIL" >>log.txt
