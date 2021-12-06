
class Shift:

    def __init__(self, date):
        self.date = date # Day object wihch containts weekend
        self.primary = None # string name of person
        self.secondary = None # string name of person
        # self.is_weekend = is_weekend

    def add_primary(self, name):
        self.primary = name

    def add_secondary(self, name):
        self.secondary = name

    def to_string(self):
        return f'{self.date.date}, {self.primary}, {self.secondary}'