#!/bin/bash

# Simple one-command test
echo "=== Simple Diff Test ==="

# Check if we have the log file
if [ ! -f "19920104_091532.log" ]; then
    echo "❌ 19920104_091532.log not found in current directory!"
    exit 1
fi

# Compile and run, then compare
echo "Compiling and testing..."
make clean > /dev/null 2>&1
make > /dev/null 2>&1

if [ $? -ne 0 ]; then
    echo "❌ Compilation failed!"
    make
    exit 1
fi

# Run and compare (remove timestamps)
./account | sed 's/\[[^]]*\] //g' > my_clean.txt
sed 's/\[[^]]*\] //g' 19920104_091532.log > expected_clean.txt

if diff -q expected_clean.txt my_clean.txt > /dev/null; then
    echo "✅ PERFECT MATCH! Your implementation is correct!"
else
    echo "❌ Output differs from expected. First few differences:"
    diff expected_clean.txt my_clean.txt | head -10
    echo ""
    echo "For detailed analysis, run: bash test_against_log.sh"
fi

# Cleanup
rm -f my_clean.txt expected_clean.txt