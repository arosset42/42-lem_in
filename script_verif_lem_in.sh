#!/bin/sh/

echo "\n\033[31m=== TEST ERROR  1: \033[00m\n"
./lem-in < test/test_error_1

echo "\n\033[31m=== TEST ERROR  2: \033[00m\n"
./lem-in < test/test_error_2

echo "\n\033[31m=== TEST ERROR  3: \033[00m\n"
./lem-in < test/test_error_3

echo "\n\033[31m=== TEST ERROR  4: \033[00m\n"
./lem-in < test/test_error_4

echo "\n\033[31m=== TEST ERROR  5: \033[00m\n"
./lem-in < test/test_error_5

echo "\n\033[31m=== TEST ERROR  6: \033[00m\n"
./lem-in < test/test_error_6

echo "\n\033[31m=== TEST ERROR  7: \033[00m\n"
./lem-in < test/test_error_7

echo "\n\033[31m=== TEST ERROR  8: \033[00m\n"
./lem-in < test/test_error_8

echo "\n\033[31m=== TEST ERROR  9: \033[00m\n"
./lem-in < test/test_error_9

echo "\n\033[31m=== TEST ERROR  10: \033[00m\n"
./lem-in < test/test_error_10

echo "\n\033[31m=== TEST ERROR  11: \033[00m\n"
./lem-in < test/test_error_11

echo "\n\033[31m=== TEST ERROR  12: \033[00m\n"
./lem-in < test/test_error_12

echo "Test OK 1: \033[00m\n"
./lem-in < test/test_ok_1

echo "\n\033[31m=== TEST comments : \033[00m\n"
./lem-in < test/tests/comments

echo "\n\033[31m=== TEST duplicatepipe : \033[00m\n"
./lem-in < test/tests/duplicatepipe

echo "\n\033[31m=== TEST duplicatepipe : \033[00m\n"
./lem-in < test/tests/duplicatepipe1

echo "\n\033[31m=== TEST ERROR illegalname : \033[00m\n"
./lem-in < test/tests/illegalname

echo "\n\033[31m=== TEST ERROR illegalname : \033[00m\n"
./lem-in < test/tests/illegalname1

echo "\n\033[31m=== TEST in0 : \033[00m\n"
./lem-in < test/tests/in0

echo "\n\033[31m=== TEST invalidcommand : \033[00m\n"
./lem-in < test/tests/invalidcommand

echo "\n\033[31m=== TEST invalidcommand : \033[00m\n"
./lem-in < test/tests/invalidcommand1

echo "\n\033[31m=== TEST ERROR loop : \033[00m\n"
./lem-in < test/tests/loop

echo "\n\033[31m=== TEST ERROR loop : \033[00m\n"
./lem-in < test/tests/loop1

echo "\n\033[31m=== TEST ERROR noants : \033[00m\n"
./lem-in < test/tests/noants

echo "\n\033[31m=== TEST ERROR noend : \033[00m\n"
./lem-in < test/tests/noend

echo "\n\033[31m=== TEST ERROR nopath : \033[00m\n"
./lem-in < test/tests/nopath

echo "\n\033[31m=== TEST ERROR nostart : \033[00m\n"
./lem-in < test/tests/nostart

echo "\n\033[31m=== TEST ERROR overflow : \033[00m\n"
./lem-in < test/tests/overflow

echo "\n\033[31m=== TEST shortest : \033[00m\n"
./lem-in < test/tests/shortest

echo "\n\033[31m=== TEST  simple : \033[00m\n"
./lem-in < test/tests/simple
echo "\n\033[31m=== TEST  simple1 : \033[00m\n"
./lem-in < test/tests/simple1
echo "\n\033[31m=== TEST ERROR simple2 : \033[00m\n"
./lem-in < test/tests/simple2
echo "\n\033[31m=== TEST ERROR startisend : \033[00m\n"
./lem-in < test/tests/startisend
echo "\n\033[31m=== TEST ERROR underflow : \033[00m\n"
./lem-in < test/tests/underflow
echo "\n\033[31m=== TEST ERROR whitespaces : \033[00m\n"
./lem-in < test/tests/whitespaces
