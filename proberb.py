from base_lines import BaseLines


class Proverb(BaseLines):
    def __init__(self, line: str, country: str):
        super().__init__(line)
        self.country = country

    def __str__(self) -> str:
        return f"Proverb:\n{self.line}\n{self.country}\nComparison value:\n{self.comparable}"
