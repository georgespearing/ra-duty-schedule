

import Person
import Day
import Shift

import numpy as np

DEFAULT_DIRECTORY = "data"
BUILDING_NAMES = ["MSH", "WDW"]

def main():
    # Define and create some individuals. 
    # read the file, create people
    people = []
    shifts = []
    # msh_shifts = []
    # wdw_shifts = []

    people = get_people(DEFAULT_DIRECTORY)

    actual_weekdays = 0
    actual_weekends = 0

    # now that we have people, assign days
    shifts, actual_weekdays, actual_weekends = create_shifts(DEFAULT_DIRECTORY, BUILDING_NAMES)
    

    total_shifts = 0
    total_weekends = 0
    # for each day, check if person can do that. if so, assign them
    for shift in shifts:
        
        if not shift.date.is_weekend:

            for person in people: 
                person.fitness_primary, person.fitness_secondary = selection_fitness_weekday(shift, person, actual_weekdays)
                person.days_since_last_duty += 1

            # sort by primary
            person_match = sorted(people, key=lambda person: person.fitness_primary, reverse=True)
            primary = person_match[0]

            # schedule the person
            schedule_person_weekday(shift, primary, True)

            # update fitness
            primary.fitness_primary, primary.fitness_secondary = selection_fitness_weekday(shift, primary, actual_weekdays)

            # sort by secondary
            person_match = sorted(people, key=lambda person: person.fitness_secondary, reverse=True)
            secondary = person_match[0]
            
            # schedule the person
            schedule_person_weekday(shift, secondary, False)
        
            # reset days
            primary.days_since_last_duty = 0
            secondary.days_since_last_duty = 0

            # # add to the total shifts scheduled
            # total_shifts += 1


        else:

            for person in people: 
                person.weekend_fitness_primary, person.weekend_fitness_secondary = selection_fitness_weekend(shift, person, actual_weekends)
                person.days_since_last_weekend += 1

            # sort by primary
            person_match = sorted(people, key=lambda person: person.weekend_fitness_primary, reverse=True)
            primary = person_match[0]

            # schedule the person
            schedule_person_weekend(shift, primary, True)

            # update fitness
            primary.weekend_fitness_primary, primary.weekend_fitness_secondary = selection_fitness_weekend(shift, primary, actual_weekends)

            # sort by secondary
            person_match = sorted(people, key=lambda person: person.weekend_fitness_secondary, reverse=True)
            secondary = person_match[0]
            
            # schedule the person
            schedule_person_weekend(shift, secondary, False)
        
            # reset days
            primary.days_since_last_weekend = 0
            secondary.days_since_last_weekend = 0

            # # add to the total shifts scheduled
            # total_weekends += 1

        # print out the people in the list
    
    with open("outfile.csv", "w") as f_out:
        f_out.write('Date, Day of Week, Building, Primary, Secondary\n')
        for s in shifts:
            f_out.write(f'{s.to_string()}\n')

    print("Statistics: ")
    for p in people:
        print(p.string_results())


# function to calculate "fitness" of match
def selection_fitness_weekday(shift, person, total_shifts):
    primary_fitness = 0
    secondary_fitness = 0

    # if the days don't match, zero fitness. 
    if shift.date.day_of_week not in person.day_preference or  \
        shift.date.date in person.no_go_days or \
        shift.date in person.active_shifts:
        return 0, 0 # don't make a match if person don't want this day or is already scheduled

    # take into account building match, large weighting
    primary_fitness += int(person.building == shift.building) * 20

    # primary vs secondary split
    primary_fitness += (person.days_active - person.days_primary)
    secondary_fitness += person.days_active - (person.days_active - person.days_primary) * 3
    
    # average days on duty so far
    primary_fitness += 1 - (person.days_active / (total_shifts))
    secondary_fitness += 1 - (person.days_active / (total_shifts))

    # also take into account days since last duty, add some weight to it
    primary_fitness += (person.days_since_last_duty)
    secondary_fitness += (person.days_since_last_duty)

    # print(f'{primary_fitness}  ||  {secondary_fitness}')

    return primary_fitness, secondary_fitness


# function to calculate "fitness" of match
def selection_fitness_weekend(shift, person, total_weekends):
    weekend_primary_fitness = 0
    weekend_secondary_fitness = 0

    # if the days don't match, zero fitness. 
    if  shift.date.date in person.no_go_days or \
        shift.date in person.active_shifts:
        return 0, 0 # don't make a match if person don't want this day or is already scheduled

    # take into account building match, large weighting
    weekend_primary_fitness += int(person.building == shift.building) * 20

    # primary vs secondary split
    weekend_primary_fitness += (person.weekend_active - person.weekend_primary)
    weekend_secondary_fitness += person.weekend_active - (person.weekend_active - person.weekend_primary) * 3
    
    # average days on duty so far
    weekend_primary_fitness += 1 - (person.weekend_active / (total_weekends))
    weekend_secondary_fitness += 1 - (person.weekend_active / (total_weekends))

    # also take into account days since last duty, add some weight to it
    weekend_primary_fitness += (person.days_since_last_weekend)
    weekend_secondary_fitness += (person.days_since_last_weekend)


    # print(f'{primary_fitness}  ||  {secondary_fitness}')

    return weekend_primary_fitness, weekend_secondary_fitness

# function to schedule RAs
def schedule_person_weekday(shift, person, primary):
    
    person.add_shift(shift.date)
    person.days_active += 1

    if primary:
        shift.primary=person.name
        person.days_primary += 1
    else:
        shift.secondary=person.name


# function to schedule RAs
def schedule_person_weekend(shift, person, primary):
    
    person.add_shift(shift.date)
    person.weekend_active += 1

    if primary:
        shift.primary=person.name
        person.weekend_primary += 1
    else: 
        shift.secondary=person.name

# read in people
def get_people(data_directory):
    people = []

    with open(f"{data_directory}/people.csv") as f:
        for line in f.readlines():
            people_components = line.rstrip().split(";")
            person = Person.Person(people_components[0], people_components[1])
            person.add_preference(people_components[2].split(", "))
            person.add_no_go(people_components[3].split(", "))
            people.append(person)

    return people

def create_shifts(data_directory, building_names):
    # msh_shifts = []
    # wdw_shifts = []
    shifts = []

    total_weekday = 0
    total_weekend = 0

    with open(f"{DEFAULT_DIRECTORY}/days-to-cover.csv") as f: 
        for line in f.readlines():
            components = line.rstrip().split(",")
            for building in building_names:
                new_day = Day.Day(components[0], components[1], components[2]=='1')
                new_shift = Shift.Shift(new_day, building)
                # new_day2 = Day.Day(components[0], components[1], components[2]=='1')
                # new_shift2 = Shift.Shift(new_day2, "WDW")
                # msh_shifts.append(Shift.Shift(Day.Day(components[0], components[1], components[2]=='1'), "MSH"))
                # wdw_shifts.append(Shift.Shift(Day.Day(components[0], components[1], components[2]=='1'), "WDW"))
                shifts.append(new_shift)
                # shifts.append(new_shift2)
                if components[2]=='1':
                    total_weekend += 1
                else:
                    total_weekday += 1
    
    return shifts, total_weekday, total_weekend


if __name__ == '__main__':
    main()