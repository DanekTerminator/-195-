
import sys

try:
    number1 = int(input("Enter 1st number: "))
    number2 = int(input("Enter 2rd number: "))
    print("Divider result:", number1/number2)
except ValueError:
    print("Not a number!")
except ZeroDivisionError:
    print("You can not divide zero!")
except Exception:
    print("Global Exception")
print("The end of program!")
print(sys.getsizeof(int))
print(sys.getsizeof(float))
