from base_lines import BaseLines


class Aphorism(BaseLines):
    def __init__(self, line: str, author: str):
        super().__init__(line)
        self.author = author

    def __str__(self) -> str:
        return f"Aphorism:\n{self.line}\n{self.author}\nComparison value:\n{self.comparable}"
