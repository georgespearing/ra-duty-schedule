
class Person:

    def __init__(self, name, building): 
        self.name = name
        self.building = building
        self.day_preference = [] # M -> Su for preference of days
        self.no_go_days = [] # date as string "05/03/21" that are no go
        self.active_shifts = [] # date as string "05/03/21" that are assigned

        self.days_active = 0
        self.days_primary = 0
        self.days_since_last_duty = 0
        self.fitness_primary = 0
        self.fitness_secondary = 0

    # def __init__(self, name, days, no_go):
    #     self.__init__()
    #     self.add_preference(days)
    #     self.add_no_go(no_go)

    def add_shift(self, shift):
        self.active_shifts.append(shift)

    def add_no_go(self, date):
        self.no_go_days.append(date)

    def add_preference(self, day_of_week):
        for day in day_of_week:
            self.day_preference.append(day)

    def reset_all_dates(self):
        self.day_preference = []
        self.no_go_days = []
        self.active_shifts = []

    def string_person(self):
        return f'{self.name}; Prefers: {self.day_preference}; Cannot work {self.no_go_days}'

    def string_results(self):
        return f'{self.name}; Primary Shifts: {self.days_primary}; Secondary Shifts: {self.days_active-self.days_primary}'