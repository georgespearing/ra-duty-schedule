
class Shift:

    def __init__(self, date, building):
        self.date = date # Day object wihch containts weekend
        self.building = building # which building duty is in
        self.primary = None # string name of person
        self.secondary = None # string name of person
        # self.is_weekend = is_weekend

    def add_primary(self, name):
        self.primary = name

    def add_secondary(self, name):
        self.secondary = name

    def to_string(self):
        return f'{self.date.date}, {self.date.day_of_week}, {self.building}, {self.primary}, {self.secondary}'