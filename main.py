from extension import *
from datetime import datetime

INCORRECT_COMMAND_LINE_MESSAGE = """incorrect command line!
Waited:
command -f infile outfile01 outfile02
Or:
command -n number outfile01 outfile02"""

INCORRECT_INPUT_MESSAGE = """incorrect qualifier value!
Waited:
command -f infile outfile01 outfile02
Or:
command -n number outfile01 outfile02"""


# Main function from where program launches.
def main() -> None:
    if len(sys.argv) != 5:
        print(INCORRECT_COMMAND_LINE_MESSAGE)
        return
    print("Start")
    container = Container()
    if sys.argv[1] == "-f":
        if not container.input_from_file(sys.argv[2]):
            print(INCORRECT_INPUT_MESSAGE)
            return
    elif sys.argv[1] == "-r":
        size = int(sys.argv[2])
        if size < 1 or size > 10000:
            print(f"incorrect number of objects = {size}. Set 0 < number <= 10000")
            return
        container.random_input(size)
        pass
    else:
        print(INCORRECT_INPUT_MESSAGE)
        return
    container.out_to_file(sys.argv[3], f"Sorted container:\nContainer contains {len(container.lines)} elements.\n")
    container.sort()
    container.out_to_file(sys.argv[4], f"Filled container:\nContainer contains {len(container.lines)} elements.\n")
    print("Stop")
    return


# Launching our program.
if __name__ == '__main__':
    start = datetime.now()
    main()
    print(datetime.now() - start)
