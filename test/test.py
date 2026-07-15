import subprocess
import os
import sys

sys.stdout.reconfigure(encoding="utf-8")
INTERPRETER_PATH = os.path.join(os.path.dirname(__file__), "..", "cmake-build-debug", "untitled5.exe")



def run_interpreter(input_data):
    process = subprocess.Popen(
        [INTERPRETER_PATH],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )
    stdout, stderr = process.communicate(input_data)
    return stdout.strip(), stderr.strip()


tests = [
    {
        "name": "Арифметика",
        "input": "5 + 3 * 2\nexit\n",
        "expected_output": "11",
    },
    {
        "name": "Вбудовані функції",
        "input": "pow(2, 4)\nabs(3 - 8)\nmax(5, 2)\nmin(3, 4)\nexit\n",
        "expected_output": "16\n5\n5\n3",
    },
    {
        "name": "Вкладені вирази",
        "input": "max(min(3 * 2, 2), 2)\nexit\n",
        "expected_output": "2",
    },
    {
        "name": "Змінні (var)",
        "input": "var a = pow(2, 4)\na + 3\nexit\n",
        "expected_output": "19",
    },
    {
        "name": "Незмінність змінних (immutability)",
        "input": "var b = 5\nvar b = 10\nb\nexit\n",
        "expected_output": "Error: variable 'b' already defined\n5",
    },
]


def run_tests():
    for test in tests:
        output, error = run_interpreter(test["input"])
        expected = test["expected_output"]

        if error:
            print(f"[FAIL] {test['name']}")
            print(f"  Помилка виконання: {error}")
        elif output != expected:
            print(f"[FAIL] {test['name']}")
            print(f"  Очікували:\n{expected}")
            print(f"  Отримали:\n{output}")
        else:
            print(f"[OK]   {test['name']}")


if __name__ == "__main__":
    run_tests()
