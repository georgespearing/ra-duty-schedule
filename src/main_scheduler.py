

import Person
import Day
import Shift

def main():
    # Define and create some individuals. 
    # read the file, create people
    people = []
    shifts = []

    with open("people.txt") as f:
        for line in f.readlines():
            people_components = line.rstrip().split("; ")
            person = Person.Person(people_components[0])
            person.add_preference(people_components[1].split(", "))
            person.add_no_go(people_components[2])
            people.append(person)
            

    # now that we have people, assign days
    with open("days-to-cover.csv") as f: 
        for line in f.readlines():
            components = line.rstrip().split(",")
            new_day = Day.Day(components[0], components[1], components[2]=='1')
            new_shift = Shift.Shift(new_day)
            shifts.append(new_shift)
    

    total_shifts = 0
    # for each day, check if person can do that. if so, assign them
    for shift in shifts:
        
        if not shift.date.is_weekend:

            for person in people: 
                person.fitness = selection_fitness(shift, person, total_shifts)
                person.days_since_last_duty += 1

            # sort by fitness
            person_match = sorted(people, key=lambda person: person.fitness, reverse=True)
            shift.primary=person_match[0].name
            person_match[0].active_shifts.append(shift)
            person_match[0].days_active += 1
            person_match[0].days_primary += 1
            person_match[0].days_since_last_duty = 0

            shift.secondary=person_match[1].name
            person_match[1].active_shifts.append(shift)
            person_match[1].days_active += 1
            person_match[1].days_since_last_duty = 0

        
            # get primary person
            # while shift.primary==None:
            #     for person in people:

                    # print(shift.date.day_of_week, person.day_preference)
                    # if (shift.date.day_of_week in person.day_preference) and person.days_active <= avg_shifts:
                    #     shift.primary = person.name
                    #     person.days_active += 1
                    #     person.days_primary += 1
                    #     break
                
            # get secondary person
            # while shift.secondary == None: 
                # for person in people:
                #     if shift.secondary==None and shift.date.day_of_week in person.day_preference and person.days_active <= avg_shifts and shift.primary!=person.name:
                #         shift.secondary = person.name
                #         person.days_active += 1
                #         break

            total_shifts += 1

        # print out the people in the list
    for p in people:
        print(p.to_string())

    for s in shifts:
        print(s.to_string())

    with open("outfile.csv", "w") as f_out:
        for s in shifts:
            f_out.write(f'{s.to_string()}\n')


# function to calculate "fitness" of match
def selection_fitness(shift, person, total_shifts):
    fitness = 0

    # if the days don't match, zero fitness. 
    if shift.date.day_of_week not in person.day_preference or shift.date.date in person.no_go_days:
        return 0 # don't make a match if person don't want this day

    # # get the last day of duty
    # last_shift_day = person.active_shifts[-1].split('/')[1]
    # current_day = shift.date.date.split('/')[1]

    # # take into accoutn time since last duty

    # prioritize days since last duty
    fitness += total_shifts - (total_shifts - person.days_active)

    # also take into account total days active, add some weight to it
    fitness += (person.days_since_last_duty+1)*1.1

    return fitness



# function to schedule RAs


if __name__ == '__main__':
    main()