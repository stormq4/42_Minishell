#!/bin/bash

# /*
# Test if equal
# EXPECTED_TO_ARGS[0]* -> expected exit status (integer)
# RESPONSE -> actual output (stdout or stderr)
# */

run_verb_be_equal()
{
  read line < ${RESPONSE}
  if [ "$line" == "${EXPECTED_TO_ARGS[0]}" ]
  then
    return 0
  else
    return 1
  fi
}
