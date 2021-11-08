from string import punctuation


class BaseLines:
    def __init__(self, line: str):
        self.line = line
        self.comparable = self.__compute_comparable()

    def __compute_comparable(self) -> float:
        punctuation_count = 0
        for let in self.line:
            if let in punctuation:
                punctuation_count += 1
        length = len(self.line)
        if length == 0:
            return 0
        return punctuation_count / length
