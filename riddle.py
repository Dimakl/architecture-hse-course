from base_lines import BaseLines


class Riddle(BaseLines):
    def __init__(self, line: str, answer: str):
        super().__init__(line)
        self.answer = answer

    def __str__(self) -> str:
        return f"Riddle:\n{self.line}\n{self.answer}\nComparison value:\n{self.comparable}"
