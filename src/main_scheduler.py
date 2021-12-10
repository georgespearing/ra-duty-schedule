

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

    # now that we have people, assign days
    shifts = create_shifts(DEFAULT_DIRECTORY, BUILDING_NAMES)
    

    total_shifts = 0
    # for each day, check if person can do that. if so, assign them
    for shift in shifts:
        
        if not shift.date.is_weekend:

            for person in people: 
                person.fitness_primary, person.fitness_secondary = selection_fitness(shift, person, total_shifts)
                person.days_since_last_duty += 1

            # sort by primary
            person_match = sorted(people, key=lambda person: person.fitness_primary, reverse=True)
            primary = person_match[0]

            # schedule the person
            schedule_person(shift, primary, True)

            # update fitness
            primary.fitness_primary, primary.fitness_secondary = selection_fitness(shift, primary, total_shifts)

            # sort by secondary
            person_match = sorted(people, key=lambda person: person.fitness_secondary, reverse=True)
            secondary = person_match[0]
            
            # schedule the person
            schedule_person(shift, secondary, False)
        
            # reset days
            primary.days_since_last_duty = 0
            secondary.days_since_last_duty = 0

            # add to the total shifts scheduled
            total_shifts += 1

        # print out the people in the list
    
    with open("outfile.csv", "w") as f_out:
        f_out.write('Date, Building, Primary, Secondary\n')
        for s in shifts:
            f_out.write(f'{s.to_string()}\n')

    print("Statistics: ")
    for p in people:
        print(p.string_results())


# function to calculate "fitness" of match
def selection_fitness(shift, person, total_shifts):
    primary_fitness = 0
    secondary_fitness = 0

    # if the days don't match, zero fitness. 
    if shift.date.day_of_week in person.day_preference or  \
        shift.date.date in person.no_go_days or \
        shift in person.active_shifts:
        return 0, 0 # don't make a match if person don't want this day or is already scheduled

    # take into account building match, large weighting
    primary_fitness += int(person.building == shift.building) * 10

    primary_fitness += (person.days_active - person.days_primary)
    secondary_fitness += person.days_active - (person.days_active - person.days_primary)
    
    # average days on duty so far
    primary_fitness += 1 - (person.days_active / (total_shifts+1))
    secondary_fitness += 1 - (person.days_active / (total_shifts+1))

    # also take into account days since last duty, add some weight to it
    primary_fitness += (person.days_since_last_duty)
    secondary_fitness += (person.days_since_last_duty)

    # print(f'{primary_fitness}  ||  {secondary_fitness}')

    return primary_fitness, secondary_fitness

# function to schedule RAs
def schedule_person(shift, person, primary):
    shift.primary=person.name
    person.add_shift(shift)
    person.days_active += 1

    if primary:
        person.days_primary += 1

# read in people
def get_people(data_directory):
    people = []

    with open(f"{data_directory}/people.txt") as f:
        for line in f.readlines():
            people_components = line.rstrip().split("; ")
            person = Person.Person(people_components[0], people_components[1])
            person.add_preference(people_components[2].split(", "))
            person.add_no_go(people_components[3].split(", "))
            people.append(person)

    return people

def create_shifts(data_directory, building_names):
    # msh_shifts = []
    # wdw_shifts = []
    shifts = []

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
    
    return shifts


if __name__ == '__main__':
    main()