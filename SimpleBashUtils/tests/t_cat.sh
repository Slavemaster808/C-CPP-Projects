#!/bin/bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
TEST_DIR=$1
CAT_DIR=$2
TEST_FILE="$TEST_DIR/bytes.txt $TEST_DIR/test_1.txt $TEST_DIR/test_2.txt $TEST_DIR/test_3.txt"
CAT="$CAT_DIR/s21_cat"
echo "" >>log.txt

for var in -b -e -n -s -t -v; do
  TEST1="$var $TEST_FILE"
  echo "$TEST1"
  $CAT $TEST1 >s21_cat.txt
  cat $TEST1 >cat.txt
  DIFF_RES="$(diff -s s21_cat.txt cat.txt)"
  if [ "$DIFF_RES" == "Files s21_cat.txt and cat.txt are identical" ]; then
    ((COUNTER_SUCCESS++))
  else
    echo "$TEST1" >>log.txt
    ((COUNTER_FAIL++))
  fi
  rm s21_cat.txt cat.txt
done

echo "CAT_SUCCESS: $COUNTER_SUCCESS" >>log.txt
echo "CAT_FAIL: $COUNTER_FAIL" >>log.txt
