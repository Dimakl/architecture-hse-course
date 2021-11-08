from proberb import Proverb
from aphorism import Aphorism
from riddle import Riddle
import random
from string import punctuation, digits, ascii_letters

RANDOM_POOL = punctuation + digits + ascii_letters


def generate_string() -> str:
    s_builder = []
    for i in range(random.randint(0, 10000)):
        s_builder.append(RANDOM_POOL[random.randint(0, len(RANDOM_POOL) - 1)])
    return "".join(s_builder)


# Contains base line elements.
class Container:
    def __init__(self):
        self.lines = []

    # To string definition.
    def __str__(self):
        return '\n'.join([str(line) for line in self.lines])

    # Get input from file.
    def input_from_file(self, path: str) -> bool:
        with open(file=path, mode='r') as file:
            while True:
                inp = file.readline().replace("\n", "")
                if len(inp) == 0:
                    return True
                elif inp == "1":
                    self.lines.append(Aphorism(file.readline().replace("\n", ""), file.readline().replace("\n", "")))
                elif inp == "2":
                    self.lines.append(Proverb(file.readline().replace("\n", ""), file.readline().replace("\n", "")))
                elif inp == "3":
                    self.lines.append(Riddle(file.readline().replace("\n", ""), file.readline().replace("\n", "")))
                else:
                    print("Invalid value of baseLine was entered - it should be in range [1; 3]")
                    return False

    # Creates random input instead of file.
    def random_input(self, count: int) -> None:
        for i in range(count):
            inp = random.randint(1, 3)
            if inp == 1:
                self.lines.append(Aphorism(generate_string(), generate_string()))
            elif inp == 2:
                self.lines.append(Proverb(generate_string(), generate_string()))
            else:
                self.lines.append(Riddle(generate_string(), generate_string()))

    # Sort all elements of the container.
    def sort(self) -> None:
        for i in range(1, len(self.lines)):
            element = self.lines[i]
            j = i - 1
            while j >= 0 and element.comparable < self.lines[j].comparable:
                self.lines[j + 1] = self.lines[j]
                j -= 1
            self.lines[j + 1] = element

    # Print content to file.
    def out_to_file(self, path: str, prefix: str) -> None:
        with open(file=path, mode='w') as file:
            file.write(prefix + str(self))
